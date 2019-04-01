#pragma once
#include <QString>
#include "DataOpration/DataOperation.h"

/*---------------------------------------------------------------------------
** 类名 : FileOpration
**---------------------------------------------------------------------------
** 功能 : 文件数据操作
**---------------------------------------------------------------------------
** Date			Name
** 2019.04.01	Mark
**---------------------------------------------------------------------------*/
class FileOpration
{
public:
	
	// 构造函数
	FileOpration();

	// 析构函数
	~FileOpration();

public:

	// 新增要保存的条目
	static bool addPlanItem(const char* pszFile, QString& qstrPlan);

	// 玩家删除条目之后，更新文件
	static bool UpdatePlanFile(const char* pszFile, MapItemPlan& mapItemPlan);
private:

};

