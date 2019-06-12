
#include "MySQlConn.h"

MySQlConn::MySQlConn()
{
	m_mysql = NULL;
	m_pszTable = NULL;
}


MySQlConn::~MySQlConn()
{
	if(NULL != m_mysql)
	{
		std::cout << "Closing MySQL Connection" << std::endl;
		mysql_close(m_mysql);
	}
	if(!m_pszTable)
	{
		m_pszTable = NULL;
	}

}

bool MySQlConn::Init(const char* pszIp /*= "127.0.0.1"*/, const char*pszAccount /*= "root"*/, const char* pszPwd /*= "123456"*/,
	const char*pszDB /*= "test"*/, const char *unix_socket /*= NULL*/)
{
	m_mysql = mysql_init(NULL); // Allocates or initializes a MYSQL object suitable for mysql_real_connect(). 
	if(!m_mysql)
	{
		return false;
	}
	if(!mysql_real_connect(m_mysql, pszIp, pszAccount, pszPwd, pszDB, 0, unix_socket, 0))
	{
		fprintf(stderr, "Failed to connect to database: Error: %s\n",
			mysql_error(m_mysql));
	}

	int iRet = mysql_set_character_set(m_mysql, "utf8"); // set the default character set for the current connection.
	if(iRet) //Zero for success. Nonzero if an error occurred.
	{
		return false;
	}
	return true;
}

bool MySQlConn::CreateDatabase(const char* pszDatabase)
{
	std::string strCreateDbSQl("create database");
	strCreateDbSQl.append(" ");
	strCreateDbSQl.append(pszDatabase);

	const char* pszCreateSql = strCreateDbSQl.c_str();

	int iRet = mysql_query(m_mysql, pszCreateSql); // Zero for success. Nonzero if an error occurred.
	if(iRet)
	{
		return false;
	}
	return true;
}

bool MySQlConn::ShowDatabase(VecDatabase& vecDatabase)
{
	std::string strShowDB("show databases");
	const char* pszShowDB = strShowDB.c_str();

	int iRet = mysql_query(m_mysql, pszShowDB); // Zero for success. Nonzero if an error occurred.
	if(iRet)
	{
		return false;
	}
	//m_mysql->v

	MYSQL_RES *mysql_result; /* Result handle */

	mysql_result = mysql_store_result(m_mysql);

	return true;
	
}
// 创建表
bool MySQlConn::CreateTable(const char* pszTable, VecField& vecField)
{
	if(!pszTable)
	{
		return false;
	}

	std::string strCreateTableSQl("CREATE table");
	strCreateTableSQl.append(" ");
	strCreateTableSQl.append(pszTable);
	strCreateTableSQl.append("(");

	// 第一个字段设定为主键
	VecField::iterator itField = vecField.begin();
	if(itField != vecField.end())
	{
		const char* pszFieldName = itField->strSTFieldName.c_str();
		const char* pszFildType = itField->strSTFieldType.c_str();
		
		strCreateTableSQl.append(pszFieldName);
		strCreateTableSQl.append(" ");
		strCreateTableSQl.append("INT NOT NULL AUTO_INCREMENT PRIMARY KEY");
		strCreateTableSQl.append(",");

		itField++;
	}

	for( ;itField!= vecField.end(); itField++)
	{
		const char* pszFieldName = itField->strSTFieldName.c_str();
		const char* pszFildType = itField->strSTFieldType.c_str();
		
		strCreateTableSQl.append(pszFieldName);
		strCreateTableSQl.append(" ");
		strCreateTableSQl.append(pszFildType);

		strCreateTableSQl.append(",");

	}

	strCreateTableSQl.pop_back(); // 删除最后一个","
	strCreateTableSQl.append(")");

	const char* pszCreateSql = strCreateTableSQl.c_str();
	//const char* pszCreateSql = "CREATE table 欧冠(球员ID INT(3) NOT NULL AUTO_INCREMENT PRIMARY KEY,姓名 VARCHAR(255),国籍 VARCHAR(255),年龄 int(3))";

	DWORD dBufSize =MultiByteToWideChar(CP_ACP, 0,pszCreateSql,-1,0,0);
	wchar_t * dBuf = new wchar_t[dBufSize+1];
	wmemset(dBuf, 0, dBufSize+1);
	int iRet = MultiByteToWideChar(CP_ACP, 0, pszCreateSql, strlen(pszCreateSql), dBuf, dBufSize);

	int iUtf8Len = WideCharToMultiByte(CP_UTF8, 0, dBuf, -1, 0, 0, 0, 0);
	char* pszUtf8Buf = new char[iUtf8Len + 1];
	memset(pszUtf8Buf, 0, iUtf8Len + 1);

	iRet = WideCharToMultiByte(CP_UTF8, 0, dBuf, iUtf8Len, pszUtf8Buf, iUtf8Len, 0, 0);

	iRet = mysql_query(m_mysql, pszUtf8Buf); // Zero for success. Nonzero if an error occurred.
	if(iRet)
	{
		const char* pszError = mysql_error(m_mysql);
		fprintf(stderr, "%s\n", mysql_error(m_mysql));

		return false;
	}
	return true;

}

bool MySQlConn::SelectTable(const char* pszTable)
{
	m_pszTable = pszTable;

	return true;
}

// 新增值 
// Mark 2019-06-11
bool MySQlConn::insertString(const char*pszField,const char* pszItem)
{
	if(!pszItem)
	{
		return false;
	}

	std::string strAddSql("insert"); //insert LocalTable(info) VALUES("Brazil")
	strAddSql.append(" ");
	strAddSql.append(m_pszTable);
	strAddSql.append(" (");
	strAddSql.append(pszField);
	strAddSql.append(" )");
//	strAddSql.append("(info) VALUES('");
	strAddSql.append(" values('");
	strAddSql.append(pszItem);
	strAddSql.append("')");

	const char* pszaddSql = strAddSql.c_str();

	int iRet = mysql_query(m_mysql, pszaddSql); // Zero for success. Nonzero if an error occurred.
	if(iRet)
	{
		return false;
	}

	return true;
}
// add value 
// Mark 2019-06-11
bool MySQlConn::insertValue(VecFieldValue& vecField)
{
	VecFieldValue::iterator itInsert = vecField.begin();
	if(itInsert == vecField.end())
	{
		return false;
	}

	std::string strFields("(");
	std::string strValues("(");

	std::string strInsertSQL("insert ");
	strInsertSQL.append(" ");
	strInsertSQL.append(m_pszTable);
	for(;itInsert!=vecField.end();itInsert++)
	{
		strFields.append(itInsert->strSTFieldName);
		strFields.append(",");

		strValues.append("'");
		strValues.append(itInsert->strSTFieldValue);
		strValues.append("'");
		strValues.append(",");
	}
	
	strFields.pop_back();
	strFields.append(")");

	strValues.pop_back();
	strValues.append(")");

	strInsertSQL.append(strFields);
	strInsertSQL.append("values");
	strInsertSQL.append(strValues);

	const char*pszInsertValue = strInsertSQL.c_str();
	int iRet = mysql_query(m_mysql, pszInsertValue); // Zero for success. Nonzero if an error occurred.
	if(iRet)
	{
		return false;
	}

	return true;
}

// delete value
//Mark 2019 - 06 - 11
bool MySQlConn::deleteValue(const char* pszKeyID,int iID)
{
	if(iID <0)
	{
		return false;
	}

	std::string strDeleteSql("delete from"); //insert LocalTable(info) VALUES("Brazil")
	strDeleteSql.append(" ");
	strDeleteSql.append(m_pszTable);
	strDeleteSql.append(" ");
	strDeleteSql.append("where");
	strDeleteSql.append(" ");
	strDeleteSql.append(pszKeyID);
	strDeleteSql.append("=");

	strDeleteSql.append(std::to_string(iID));

	const char* pszDeleteSql = strDeleteSql.c_str();

	int iRet = mysql_query(m_mysql, pszDeleteSql);// Zero for success. Nonzero if an error occurred.
	if(iRet)
	{
		return false;
	}

	return true;
}
// modifyValue 
//Mark 2019 - 06 - 11
bool MySQlConn::modifyValue(const char*pszKeyID, int iID, const char* pszFieldName,const char*pszValue)
{
	if(iID<0)
	{
		return false;
	}

	if(!pszValue)
	{
		return false;
	}

	std::string strModifySQL("update");
	strModifySQL.append(" ");

	strModifySQL.append(m_pszTable);
	strModifySQL.append(" ");
	strModifySQL.append("set");
	strModifySQL.append(" ");
	strModifySQL.append(pszFieldName);
	strModifySQL.append(" ");
	strModifySQL.append("=");
	strModifySQL.append(" '");
	strModifySQL.append(pszValue);
	strModifySQL.append(" '");
	strModifySQL.append(" where");
	strModifySQL.append(" ");
	strModifySQL.append(" ");
	strModifySQL.append(pszKeyID);
	strModifySQL.append("=");
	strModifySQL.append(std::to_string(iID));

	const char* pszModifySQl = strModifySQL.c_str();
	
	int iRet= mysql_query(m_mysql, pszModifySQl);// Zero for success. Nonzero if an error occurred.
	if(iRet)
	{
		return false;
	}

	return true;
}
// modifyValue 
//Mark 2019 - 06 - 11
bool MySQlConn::queryValue(const char*KeyFieldname, int iID, const char* pszObjFieldName, std::string &strResult)
{
	if(iID < 0)
	{
		return false;
	}

// 	if(!pszValue)
// 	{
// 		return false;
// 	}

	std::string strQuerySQL("select");
	strQuerySQL.append(" ");
	strQuerySQL.append(pszObjFieldName);
	strQuerySQL.append(" ");
	strQuerySQL.append("from");
	strQuerySQL.append(" ");
	strQuerySQL.append(m_pszTable);
	strQuerySQL.append(" ");
	strQuerySQL.append("where ");
	strQuerySQL.append(" ");
	strQuerySQL.append(KeyFieldname);
	strQuerySQL.append("=");
	strQuerySQL.append(std::to_string(iID));

	const char* pszQuerySQL = strQuerySQL.c_str();

	//MYSQL_ROW row;
// 	unsigned int num_fields;
// 	unsigned int i;

 	int iRet = mysql_query(m_mysql, pszQuerySQL);// Zero for success. Nonzero if an error occurred.
 	if(iRet)
 	{
 		return false;
 	}

	MYSQL_RES *result;
	result = mysql_store_result(m_mysql); // NULL if the statement did not return a result set or an error occurred.
	if(!result)
	{
		return false;
	}

	MYSQL_ROW row;
	while(row = mysql_fetch_row(result))
	{
		int iFieldNum = mysql_num_fields(result);
		for(int t = 0;t<iFieldNum;t++)
		{
			if(NULL == row[t])
			{
				strResult = "";
			}
			else
			{
				strResult = row[t];
			}
			
			printf("%s  ", row[t]);
		}
	}

	mysql_free_result(result);
	return true;
}

// modifyValue 
//Mark 2019-06-11
bool MySQlConn::queryAllValueByID(const char*KeyFieldname, int iID, VecResult& vecResult)
{
	std::string strQueryAllSQL("select * from");
	strQueryAllSQL.append(" ");
	strQueryAllSQL.append(m_pszTable);
	strQueryAllSQL.append(" ");
	strQueryAllSQL.append(" where");
	strQueryAllSQL.append(" ");
	strQueryAllSQL.append(KeyFieldname);
	strQueryAllSQL.append("=");
	strQueryAllSQL.append(std::to_string(iID));

	const char* pszQueryAllSQL = strQueryAllSQL.c_str();
	int iRet = mysql_query(m_mysql, pszQueryAllSQL);// Zero for success. Nonzero if an error occurred.
	if(iRet)
	{
		return false;
	}

	MYSQL_RES *result;
	result = mysql_store_result(m_mysql); // NULL if the statement did not return a result set or an error occurred.
	if(!result)
	{
		return false;
	}

	MYSQL_ROW row;
	while (row = mysql_fetch_row(result))
	{
		int iFieldNum = mysql_num_fields(result);
		for(int t = 0; t < iFieldNum; t++)
		{
			std::string strResult;
			if(NULL == row[t])
			{
				strResult = "";
			}
			else
			{
				strResult = row[t];
			}
			
			vecResult.push_back(strResult);

			//printf("%s  ", row[t]);
		}
	}

	mysql_free_result(result);
	return true;
}
// modifyValue 
//Mark 2019-06-11
bool MySQlConn::queryAllValue(VecResult& vecResult)
{
	std::string strQueryAllSQL("select * from");
	strQueryAllSQL.append(" ");
	strQueryAllSQL.append(m_pszTable);
// 	strQueryAllSQL.append(" ");
// 	strQueryAllSQL.append(" where");
// 	strQueryAllSQL.append(" ");
// 	strQueryAllSQL.append(KeyFieldname);
// 	strQueryAllSQL.append("=");
// 	strQueryAllSQL.append(std::to_string(iID));

	const char* pszQueryAllSQL = strQueryAllSQL.c_str();
	int iRet = mysql_query(m_mysql, pszQueryAllSQL);// Zero for success. Nonzero if an error occurred.
	if(iRet)
	{
		return false;
	}

	MYSQL_RES *result;
	result = mysql_store_result(m_mysql); // NULL if the statement did not return a result set or an error occurred.
	if(!result)
	{
		return false;
	}

	MYSQL_ROW row;
	while(row = mysql_fetch_row(result))
	{
		int iFieldNum = mysql_num_fields(result);
		for(int t = 0; t < iFieldNum; t++)
		{
			std::string strResult;
			if(NULL == row[t])
			{
				strResult = "";
			}
			else
			{
				strResult = row[t];
			}

			vecResult.push_back(strResult);

			printf("%s  ", row[t]);
		}
	}

	mysql_free_result(result);

	return true;
}
