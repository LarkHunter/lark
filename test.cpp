// MySqlTest.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <mysql.h>
#include <string>
#include <map>
#include <vector>


#define BREAK_WITH_ERROR(err) {ret=err;break;}
enum KERRORNO
{
	kNoError = 0,
	kInitMySqlError,
	kConnectDbError,
	kSelectDbError,
	kExecSqlError,
};

typedef MySQLQuery QMysql;
int _tmain(int argc, _TCHAR* argv[])
{
	int ret = kNoError;
	QMysql qMysql;
	qMysql.ConnectDB("127.0.0.1", "root", "root", "world", 3306);
	//ret = qMysql.BeginWork();
	std::string insertStr = "insert into test(updataTime,name) values('2018-12-12 12:12:12','";// helloworld');";
	std::string outStr;
	std::string nameS = "\\\\hello,,,,..'''''''''''''''''\\\\";
	qMysql.EscapeString(nameS, outStr);
	int len = outStr.length();
	insertStr += outStr;
	insertStr += "');";
	qMysql.ExecDbSql(insertStr.c_str());
	//ret = qMysql.EndWork();
	qMysql.ExecDbSql("select * from test limit 0,100;");
	auto fields = qMysql.GetFields();
	for (auto it : fields)
	{
		printf("%s\t", it.c_str());
	}
	printf("\n");
	auto rows = qMysql.GetResultRows();
	for (auto it : rows)
	{
		for (auto itf:it.second)
			printf("%s\t", itf.c_str());
		printf("\n");
	}
	getchar();
	return 0;
}

