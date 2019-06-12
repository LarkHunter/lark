#include <iostream>
#include <windows.h>
#include "MySQlConn.h"
#include "DatabaseDefine.h"

int main()
{
	MySQlConn m_MySQlConn;

	// ��ʼ�����ݿ�
 	bool bResult = m_MySQlConn.Init();
 	if(!bResult)
 	{
 		return 0;
 	}
 
	

	VecField vecField;
	STField stField;

	stField.strSTFieldName = D_PLAYER_ID;
	stField.strSTFieldType = D_INT;
	vecField.push_back(stField);
	stField.Clear();
	
	stField.strSTFieldName = D_PLAYER_NAME;
	stField.strSTFieldType = D_VARCHAR;
	vecField.push_back(stField);
	stField.Clear();

	stField.strSTFieldName = D_NATION;
	stField.strSTFieldType = D_VARCHAR;
	vecField.push_back(stField);
	stField.Clear();

	stField.strSTFieldName = D_AGE;
	stField.strSTFieldType = D_INT;
	vecField.push_back(stField);
	stField.Clear();

	// ������
// 	bResult = m_MySQlConn.CreateTable(D_LOCAL_TABLE, vecField);
// 	if(!bResult)
// 	{
// 		return 0;
// 	}

	// ѡ���
 	bResult = m_MySQlConn.SelectTable(D_LOCAL_TABLE);
 	if(!bResult)
 	{
 		return 0;
 	}

	VecFieldValue vecFieldValue;
	STFieldValue stFieldValue;

	stFieldValue.strSTFieldName = D_PLAYER_ID;
	stFieldValue.strSTFieldValue = "10";
	vecFieldValue.push_back(stFieldValue);
	stFieldValue.Clear();

	stFieldValue.strSTFieldName = D_PLAYER_NAME;
	stFieldValue.strSTFieldValue = "DECO";
	vecFieldValue.push_back(stFieldValue);
	stFieldValue.Clear();

	stFieldValue.strSTFieldName = D_NATION;
	stFieldValue.strSTFieldValue = "Portugal";
	vecFieldValue.push_back(stFieldValue);
	stFieldValue.Clear();

	stFieldValue.strSTFieldName = D_AGE;
	stFieldValue.strSTFieldValue = "27";
	vecFieldValue.push_back(stFieldValue);
	stFieldValue.Clear();

// 	bResult = m_MySQlConn.insertValue(vecFieldValue);
// 	if(bResult)
// 	{
// 		return 0;
// 	}
	//vecFieldValue.
	// ����ֵ
// 	bResult = m_MySQlConn.insertString(D_PLAYER_NAME, "GIGI");
// 	if(!bResult)
// 	{
// 		return 0;
// 	}


	// ɾ��ֵ
//  	bResult = m_MySQlConn.deleteValue(D_PLAYER_ID,3); // �д�
//  	if(!bResult)
//  	{
// 		return 0;
//  	}

	// �ı�ֵ
// 	bResult = m_MySQlConn.modifyValue(D_PLAYER_ID,4, D_NATION,"China");
// 	if(!bResult)
// 	{
// 		return 0;
// 	}

	// ��ѯֵ
// 	std::string strResult;
// 	bResult = m_MySQlConn.queryValue(D_PLAYER_ID,7, D_NATION, strResult);
// 	if(!bResult)
// 	{ 
// 		return 0;
// 	}
// 
// 	const char* pszFinal = strResult.c_str();

	VecResult vecResult;

	// ��ѯĳ�����
 	bResult = m_MySQlConn.queryAllValueByID(D_PLAYER_ID,6, vecResult);
 	if(bResult)
 	{
 		return 0;
 	}

	VecResult::iterator itResult = vecResult.begin();
	for(;itResult!= vecResult.end();itResult++)
	{
		std::cout <<*itResult << std::endl;
	}
	//bResult = m_MySQlConn.queryAllValue();

	std::cout <<"...." << std::endl;
	system("pause");
	return 0;
}