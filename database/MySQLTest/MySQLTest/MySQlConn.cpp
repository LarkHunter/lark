
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

bool MySQlConn::setString(const char* pszItem)
{
	if(!pszItem)
	{
		return false;
	}

	std::string strAddSql("insert"); //insert LocalTable(info) VALUES("Brazil")
	strAddSql.append(" ");
	strAddSql.append(m_pszTable);
	strAddSql.append("(info) VALUES('");
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

bool MySQlConn::deleteValue(int iID)
{
	if(iID <0)
	{
		return false;
	}

	std::string strDeleteSql("delete from"); //insert LocalTable(info) VALUES("Brazil")
	strDeleteSql.append(" ");
	strDeleteSql.append(m_pszTable);
	strDeleteSql.append(" ");
	strDeleteSql.append("where id = ");
	strDeleteSql.append(std::to_string(iID));

	const char* pszDeleteSql = strDeleteSql.c_str();

	int iRet = mysql_query(m_mysql, pszDeleteSql);// Zero for success. Nonzero if an error occurred.
	if(iRet)
	{
		return false;
	}

	return true;
}

bool MySQlConn::modifyValue(int iID, const char*pszValue)
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
	strModifySQL.append("set info = '");
	strModifySQL.append(pszValue);
	strModifySQL.append("' where id = ");
	strModifySQL.append(std::to_string(iID));

	const char* pszModifySQl = strModifySQL.c_str();
	
	int iRet= mysql_query(m_mysql, pszModifySQl);// Zero for success. Nonzero if an error occurred.
	if(iRet)
	{
		return false;
	}

	return true;
}
