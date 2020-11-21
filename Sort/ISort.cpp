#include "ISort.h"
#include <stdio.h>



ISort::ISort()
{
}


ISort::~ISort()
{
}

void ISort::Move(ISortObj* objs[], int start, int len, int pos)
{
	if (pos == start) {
		return;
	}
	if (pos > start) {
		for (int i = 1; i <= len; ++i) {
			objs[pos + len - i] = objs[start + len - i];
		}
	}
	else {
		for (int i = 1; i <= len; ++i) {
			objs[pos + i] = objs[start + i];
		}
	}
}

void ISort::Print(ISortObj* objs[], int len)
{
	for (int i = 1; i <= len; ++i) {
		printf("[%d]: {(ori: %d), ", i, objs[i]->GetIndexOri());
		objs[i]->PrintObj();
		printf("}, ");
	}
}