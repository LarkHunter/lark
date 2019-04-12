#include <iostream>
#include <windows.h>
#include "MySQlConn.h"
#include "DatabaseDefine.h"

int main()
{
	MySQlConn m_MySQlConn;

	// 初始化数据库
 	bool bResult = m_MySQlConn.Init();
 	if(!bResult)
 	{
 		return 0;
 	}
 
	

	VecField vecField;
	STField stField;

	stField.strSTFieldName = "球员ID";
	stField.strSTFieldType = D_INT;
	vecField.push_back(stField);
	stField.Clear();
	
	stField.strSTFieldName = "球员姓名";
	stField.strSTFieldType = D_VARCHAR;
	vecField.push_back(stField);
	stField.Clear();

	stField.strSTFieldName = "国籍";
	stField.strSTFieldType = D_VARCHAR;
	vecField.push_back(stField);
	stField.Clear();

	stField.strSTFieldName = "年龄";
	stField.strSTFieldType = D_INT;
	vecField.push_back(stField);
	stField.Clear();

	// 创建表
	m_MySQlConn.CreateTable("欧洲杯", vecField);

	// 选择表
// 	bResult = m_MySQlConn.SelectTable(D_LOCAL_TABLE);
// 	if(!bResult)
// 	{
// 		return 0;
// 	}

	// 保存值 
// 	m_MySQlConn.setString("INZAGHI");
// 	if (!bResult)
// 	{
// 		return 0;
// 	}

	// 删除值
// 	bResult = m_MySQlConn.deleteValue(7); // 有错
// 	if(!bResult)
// 	{
// 		return 0;
// 	}

	std::cout <<"...." << std::endl;
	system("pause");
	return 0;
}