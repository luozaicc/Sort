#include "SortInt.h"
#include <stdio.h>



SortInt::SortInt() :
	_data(0)
{
}


SortInt::SortInt(int n) :
	_data(n)
{
}

SortInt::~SortInt()
{
}

bool SortInt::LT(ISortObj* pObj) {
	if (!pObj) {
		return false;
	}
	SortInt* p = (SortInt*)pObj;
	return this->_data < p->_data;
}

bool SortInt::GT(ISortObj* pObj) {
	if (!pObj) {
		return false;
	}
	SortInt* p = (SortInt*)pObj;
	return this->_data > p->_data;
}

void SortInt::PrintObj() {
	printf("%d", this->_data);
}