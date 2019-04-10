#pragma once
#include <string>
#include <vector>

typedef std::vector<std::string> VecItemInfo; // 保存数据表数据

/*---------------------------------------------------------------------------
** 类名 : QSqlService
**---------------------------------------------------------------------------
** 功能 : 数据库服务
**---------------------------------------------------------------------------
** Date			Name
** 19.04.08		Mark
**---------------------------------------------------------------------------*/
class QSqlService
{
public:
	
	// 初始化
 	QSqlService();

	// 析构
	~QSqlService();

public:

	// 开启服务
	bool StartService(const char* pszDatabase,const char *pszTable );

	// 新增条目-
	bool addItem(const char *pszTable,const char*pszItem);
	
	// 删除条目
	bool deleteItem(const char *pszTable, int iItemID);

	// 修改
	bool updateItem(const char *pszTable, const char* pszInfo,int iItemID);

	// 查看
	bool QueryItemById(const char *pszTable, int iItemId, std::string & strItem);

	// 查看所有信息-
	bool QueryInfo(const char* pszTable, VecItemInfo& vecSumInfo);

private:

	// 初始化服务
	bool InitDatabase(const char *pszDatabase = "");

	// 初始化表
	bool InitTable(const char *pszTable);
};

