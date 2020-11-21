#include "SelectSort.h"



SelectSort::SelectSort()
{
}


SelectSort::~SelectSort()
{
}

void SelectSort::Sort(ISortObj* objs[], int len)
{
	for (int i = 1; i < len; ++i) {
		int min = i;
		for (int j = i + 1; j <= len; ++j) {
			if (objs[j]->LT(objs[min])) {
				min = j;
			}
		}
		objs[0] = objs[i];
		objs[i] = objs[min];
		objs[min] = objs[0];
	}
}