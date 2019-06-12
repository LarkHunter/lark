#pragma once
#include "winsock.h" 
#include "MySQL5.5/mysql.h" 
#include "MySQL5.5/mysqld_error.h"

#include <stdio.h>
#include <iostream>
#include <string>
#include <map>
#include <vector>

#ifdef _WIN64
#pragma comment(lib,"libmySQL.lib") 
#else
#pragma comment(lib,"libmysql(32)/libmySQL.lib") 
#endif

// 表字段
struct STField
{
	std::string strSTFieldType; // 字段类型
	std::string strSTFieldName; // 字段名称

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

// 表字段值
struct STFieldValue
{
	std::string strSTFieldName; // 字段名称
	std::string strSTFieldValue; // 字段值

	STFieldValue() : strSTFieldName(""),strSTFieldValue("")
	{

	}

	bool Clear()
	{
		strSTFieldName.clear();
		strSTFieldValue.clear();

		return true;
	};
};

typedef std::vector<STFieldValue> VecFieldValue; // 字段值

typedef std::vector<std::string> VecResult; // 结果
/*---------------------------------------------------------------------------
** 类名 : MySQlConn
**---------------------------------------------------------------------------
** 功能 : MySQL数据库操作
**---------------------------------------------------------------------------
** Date			Name
** 19.04.10		Mark
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

	// 新增某个区域数据
	bool insertString(const char*pszField,const char* pszItem);

	// 增加一条数据
	bool insertValue(VecFieldValue& vecField);

	// 删除一条数据
	bool deleteValue(const char*KeyID, int iID);

	// 修改一条数据
	bool modifyValue(const char*KeyFieldname, int iID, const char* pszObjFieldName,const char*pszValue);

	// 查询某字段数据
	bool queryValue(const char*KeyFieldname, int iID, const char* pszObjFieldName, std::string &strResult);

	// 查询一条数据
	bool queryAllValueByID(const char*KeyFieldname, int iID, VecResult& vecResult);

	// 查询全部数据
	bool queryAllValue(VecResult& vecResult);
public:

	MYSQL *m_mysql; // 数据库对象
	
	const char* m_pszTable; // 当前表
};

