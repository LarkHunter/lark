#pragma once
#include "winsock.h" 
#include "include/mysql.h" 
#include <stdio.h>
#include <iostream>
#include <string>
#include <map>
#include <vector>

#pragma comment(lib,"libmySQL.lib") 

// 表字段
struct STField
{
	std::string strSTFieldType;
	std::string strSTFieldName;

	STField() :strSTFieldType(""), strSTFieldName("")
	{

	}

	bool Clear()
	{
		strSTFieldType.clear();
		strSTFieldName.clear();

		return true;
	};
};

typedef std::vector<std::string> VecDatabase;

typedef std::vector<STField> VecField; // 字段

typedef std::map<int, std::string > MapInfo; // 查询结果
/*---------------------------------------------------------------------------
** 类名 : MySQlConn
**---------------------------------------------------------------------------
** 功能 : MySQL数据库操作
**---------------------------------------------------------------------------
** Date			Name
** 19.04.10		任伟
**---------------------------------------------------------------------------*/
class MySQlConn
{

public:

	// 构造数据库
	MySQlConn();

	// 清理数据库
	~MySQlConn();
public:

	// 初始化数据库
	bool Init(const char* pszIp = "127.0.0.1", const char*pszAccount = "root",const char* pszPwd = "123456",
		const char*pszDB = "test", const char *unix_socket = NULL);

	// 创建数据库
	bool CreateDatabase(const char* pszDatabase);

	// 查看数据库
	bool ShowDatabase(VecDatabase& vecDatabase);

	// 创建表
	bool CreateTable(const char* pszTable,VecField& vecField);

	// 使用数据表
	bool SelectTable(const char* pszTable);

	// 增
	bool setString(const char* pszItem);

	// 删除
	bool deleteValue(int iID);

	// 改
	bool modifyValue(int iID, const char*pszValue);

	//查
	//bool queryValue(int iID,std::string& strValue);

	// 查询全部信息
	//bool queryAllValue(MapInfo & mapInfo);

public:

	MYSQL *m_mysql; // 数据库对象
	
	const char* m_pszTable; // 当前表
};

