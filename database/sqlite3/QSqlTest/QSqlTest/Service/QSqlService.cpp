#include "QSqlService.h"
#include <QSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>
#include <QVariantList>
#include <QDebug>

/*---------------------------------------------------------------------------
** 名称 : QSqlService
** 功能 : 初始化
**---------------------------------------------------------------------------
** 参数 : NULL
** 返值 : NULL
**---------------------------------------------------------------------------
** Date			Name
** 19.04.08		任伟
**---------------------------------------------------------------------------*/
QSqlService::QSqlService()
{

}

/*---------------------------------------------------------------------------
** 名称 : ~QSqlService
** 功能 : 初始化
**---------------------------------------------------------------------------
** 参数 : NULL
** 返值 : NULL
**---------------------------------------------------------------------------
** Date			Name
** 19.04.08		任伟
**---------------------------------------------------------------------------*/
QSqlService::~QSqlService()
{

}
/*---------------------------------------------------------------------------
** 名称 : StartService
** 功能 : 开启服务
**---------------------------------------------------------------------------
** 参数 : NULL
** 返值 : NULL
**---------------------------------------------------------------------------
** Date			Name
** 19.04.08		任伟
**---------------------------------------------------------------------------*/
bool QSqlService::StartService(const char* pszDatabase, const char *pszTable)
{
	if( (!pszDatabase) ||
		(!pszTable) )
	{

	}

	bool bResult = InitDatabase(pszDatabase); // 初始化数据库
	if (!bResult)
	{
		return bResult;
	}

	bResult = InitTable(pszTable); // 初始化表
	if(!bResult)
	{
		return bResult;
	}

	return true;
}
/*---------------------------------------------------------------------------
** 名称 : addItem
** 功能 : 新增条目
**---------------------------------------------------------------------------
** 参数 : NULL
** 返值 : NULL
**---------------------------------------------------------------------------
** Date			Name
** 19.04.08		任伟
**---------------------------------------------------------------------------*/
bool QSqlService::addItem(const char *pszTable,const char*pszItem)
{
	if( (!pszTable)|| 
		(!pszItem) )
	{
		return false;
	}

	std::string strQuerySQl("select count(*) as value from");
	strQuerySQl.append(" ");
	strQuerySQl.append(pszTable);

	const char* pszQuerySql = strQuerySQl.c_str();

	QSqlQuery query;

	query.exec(pszQuerySql);

	int iCount = 0;
	while(query.next())
	{
		qDebug() << query.value(0).toInt();
		iCount = query.value(0).toInt();

	}
	//int iCount = query.value(0).toInt();
	iCount += 1;

	std::string strInsert("insert into");
	strInsert.append(" ");
	strInsert.append(pszTable);
	strInsert.append(" ");
	strInsert.append("values (");
	strInsert.append(std::to_string(iCount));
	strInsert.append(",");
	strInsert.append("'");
	strInsert.append(pszItem);
	strInsert.append("'");
	strInsert.append(")");

	const char* pszInsert = strInsert.c_str();
	bool bResult = query.exec(pszInsert);

	return bResult;
}
/*---------------------------------------------------------------------------
** 名称 : deleteItem
** 功能 : 删除条目
**---------------------------------------------------------------------------
** 参数 : NULL
** 返值 : NULL
**---------------------------------------------------------------------------
** Date			Name
** 19.04.08		任伟
**---------------------------------------------------------------------------*/
bool QSqlService::deleteItem(const char *pszTable, int iItemID)
{
	if(!pszTable)
	{
		return false;
	}
	if(iItemID <0)
	{
		return false;
	}

	std::string strDeleteSQl("delete from");
	strDeleteSQl.append(" ");
	strDeleteSQl.append(pszTable);
	strDeleteSQl.append(" ");
	strDeleteSQl.append("where id = ");
	strDeleteSQl.append(std::to_string(iItemID));

	const char* pszDeleteSQL = strDeleteSQl.c_str();

	QSqlQuery query;
	bool bResult = query.exec(pszDeleteSQL);

	return bResult;

}
/*---------------------------------------------------------------------------
** 名称 : updateItem
** 功能 : 更改条目
**---------------------------------------------------------------------------
** 参数 : NULL
** 返值 : NULL
**---------------------------------------------------------------------------
** Date			Name
** 19.04.08		任伟
**---------------------------------------------------------------------------*/
bool QSqlService::updateItem(const char *pszTable, const char* pszInfo, int iItemID)
{
	if( (!pszTable) ||
		(!pszInfo) )
	{
		return false;
	}

	if(iItemID < 0)
	{
		return false;
	}

	std::string strUpdateSQL("update");
	strUpdateSQL.append(" ");
	strUpdateSQL.append(pszTable);
	strUpdateSQL.append("set info=");
	strUpdateSQL.append(pszInfo);
	strUpdateSQL.append("where id = ");
	strUpdateSQL.append(std::to_string(iItemID));

	const char* pszUpdateSQl = strUpdateSQL.c_str();
	QSqlQuery query;
	bool bResult = query.exec(pszUpdateSQl);

	return bResult;

}
/*---------------------------------------------------------------------------
** 名称 : QueryItemById
** 功能 : 查看某ID信息
**---------------------------------------------------------------------------
** 参数 : NULL
** 返值 : NULL
**---------------------------------------------------------------------------
** Date			Name
** 19.04.09		Mark
**---------------------------------------------------------------------------*/
bool QSqlService::QueryItemById(const char *pszTable, int iItemId, std::string & strItem)
{
	if(!pszTable)
	{
		return false;
	}

	if(iItemId <0)
	{
		return false;
	}

	std::string strQuerySQl("select info from ");
	strQuerySQl.append(" ");
	strQuerySQl.append(pszTable);
	strQuerySQl.append("where id = ");
	strQuerySQl.append(std::to_string(iItemId));

	QSqlQuery query;

	const char* pszQuerySql = strQuerySQl.c_str();
	bool bResult = query.exec(pszQuerySql);

	while(query.next())
	{
		//取出当前行的内容
		qDebug() << query.value(0).toInt()
			<< query.value(1).toString();
		
		strItem = query.value(1).toString().toStdString();
	}
	return true;
}
/*---------------------------------------------------------------------------
** 名称 : QueryInfo
** 功能 : 查看当前表所有信息
**---------------------------------------------------------------------------
** 参数 : NULL
** 返值 : NULL
**---------------------------------------------------------------------------
** Date			Name
** 19.04.09		Mark
**---------------------------------------------------------------------------*/
bool QSqlService::QueryInfo(const char* pszTable, VecItemInfo& vecSumInfo)
{
	if(!pszTable)
	{
		return false;
	}

	std::string strQueryInfoSum("select info from");
	strQueryInfoSum.append(" ");
	strQueryInfoSum.append(pszTable);

	const char* pszQueryInfoSum = strQueryInfoSum.c_str();

	QSqlQuery query;
	bool bResult = query.exec(pszQueryInfoSum);
	while(query.next())
	{
		std::string strItem = query.value(0).toString().toStdString();
		vecSumInfo.push_back(strItem);
	}

	return true;
}

/*---------------------------------------------------------------------------
** 名称 : InitService
** 功能 : 初始化服务
**---------------------------------------------------------------------------
** 参数 : NULL
** 返值 : NULL
**---------------------------------------------------------------------------
** Date			Name
** 19.04.08		Mark
**---------------------------------------------------------------------------*/
bool QSqlService::InitDatabase(const char *pszDatabase /*= ""*/)
{
	if(!pszDatabase)
	{
		return false;
	}

	//打印Qt支持的数据库驱动
	qDebug() << QSqlDatabase::drivers();

	//添加Sqlite数据库
	QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");

	//设置数据库
	db.setDatabaseName("../info.db");

	//打开数据库
	if (!db.open())
	{
		qDebug() << "database open error";
		//QMessageBox::warning(this, "error", db.lastError().text());
		return false;
	}

	return true;
}

/*---------------------------------------------------------------------------
** 名称 : InitTable
** 功能 : 初始化表
**---------------------------------------------------------------------------
** 参数 : NULL
** 返值 : NULL
**---------------------------------------------------------------------------
** Date			Name
** 19.04.08		任伟
**---------------------------------------------------------------------------*/
bool QSqlService::InitTable(const char *pszTable)
{
	if(!pszTable)
	{
		return false;
	}
	std::string strSQl("create table if not exists");
	strSQl.append(" ");
	strSQl.append(pszTable);
	strSQl.append("(id int PRIMARY KEY AUTOINCREMENT , info varchar(255)");
	strSQl.append(")");
	const char*pszSQl = strSQl.c_str();

	QSqlQuery query;
	bool bResult = query.exec(pszSQl);
	//query.exec("select * from test");
	// 	query.prepare("insert into student(id,name, age, score) values(:id,:name, :age, :score)");
	// 
	// 	//给字段设置内容 list
	// 	QVariantList idList;
	// 	idList << 1 << 2 << 3;
	// 
	// 	QVariantList nameList;
	// 	nameList << "xiaoming" << "xiaolong" << "xiaojiang";
	// 
	// 	QVariantList ageList;
	// 	ageList << 11 << 22 << 33;
	// 
	// 	QVariantList scoreList;
	// 	scoreList << 59 << 69 << 70;
	// 
	// 	//给字段绑定相应的值 按顺序绑定
	// 	query.addBindValue(idList);
	// 
	// 	query.addBindValue(nameList);
	// 
	// 	query.addBindValue(ageList);
	// 
	// 	query.addBindValue(scoreList);

	//执行预处理命令
	//bool bResult = query.exec();

	return bResult;
}
