#pragma once
#include "ISortObj.h"
class SortInt :
	public ISortObj
{
public:
	SortInt();
	SortInt(int n);
	~SortInt();
	virtual bool LT(ISortObj* pObj);
	virtual bool GT(ISortObj* pObj);

	virtual void PrintObj();
private:
	int _data;
};

