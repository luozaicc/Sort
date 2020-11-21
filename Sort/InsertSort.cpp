#include "InsertSort.h"



InsertSort::InsertSort()
{
}


InsertSort::~InsertSort()
{
}

void InsertSort::Sort(ISortObj* objs[], int len)
{
	for (int i = 2; i <= len; ++i) {
		for (int j = 1; j < i; ++j) {
			if (objs[i]->LT(objs[j])) {
				objs[0] = objs[i];
				this->Move(objs, j, i - j, j + 1);
				objs[j] = objs[0];
			}
		}
	}
}