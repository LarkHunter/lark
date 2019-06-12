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

// ���ֶ�
struct STField
{
	std::string strSTFieldType; // �ֶ�����
	std::string strSTFieldName; // �ֶ�����

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

typedef std::vector<STField> VecField; // �ֶ�

// ���ֶ�ֵ
struct STFieldValue
{
	std::string strSTFieldName; // �ֶ�����
	std::string strSTFieldValue; // �ֶ�ֵ

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

typedef std::vector<STFieldValue> VecFieldValue; // �ֶ�ֵ

typedef std::vector<std::string> VecResult; // ���
/*---------------------------------------------------------------------------
** ���� : MySQlConn
**---------------------------------------------------------------------------
** ���� : MySQL���ݿ����
**---------------------------------------------------------------------------
** Date			Name
** 19.04.10		Mark
**---------------------------------------------------------------------------*/
class MySQlConn
{

public:

	// �������ݿ�
	MySQlConn();

	// �������ݿ�
	~MySQlConn();
public:

	// ��ʼ�����ݿ�
	bool Init(const char* pszIp = "127.0.0.1", const char*pszAccount = "root",const char* pszPwd = "123456",
		const char*pszDB = "test", const char *unix_socket = NULL);

	// �������ݿ�
	bool CreateDatabase(const char* pszDatabase);

	// �鿴���ݿ�
	bool ShowDatabase(VecDatabase& vecDatabase);

	// ������
	bool CreateTable(const char* pszTable,VecField& vecField);

	// ʹ�����ݱ�
	bool SelectTable(const char* pszTable);

	// ����ĳ����������
	bool insertString(const char*pszField,const char* pszItem);

	// ����һ������
	bool insertValue(VecFieldValue& vecField);

	// ɾ��һ������
	bool deleteValue(const char*KeyID, int iID);

	// �޸�һ������
	bool modifyValue(const char*KeyFieldname, int iID, const char* pszObjFieldName,const char*pszValue);

	// ��ѯĳ�ֶ�����
	bool queryValue(const char*KeyFieldname, int iID, const char* pszObjFieldName, std::string &strResult);

	// ��ѯһ������
	bool queryAllValueByID(const char*KeyFieldname, int iID, VecResult& vecResult);

	// ��ѯȫ������
	bool queryAllValue(VecResult& vecResult);
public:

	MYSQL *m_mysql; // ���ݿ����
	
	const char* m_pszTable; // ��ǰ��
};

