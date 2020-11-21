#include "BInsertSort.h"



BInsertSort::BInsertSort()
{
}


BInsertSort::~BInsertSort()
{
}

void BInsertSort::Sort(ISortObj* objs[], int len)
{
	for (int i = 2; i <= len; ++i) {
		int high = i - 1;
		int low = 1;

		objs[0] = objs[i];
		while (low <= high) {
			int m = (high + low) / 2;
			if (objs[0]->LT(objs[m])) {
				high = m - 1;
			}
			else {
				low = m + 1;
			}
		}
		this->Move(objs, low, i - low, low + 1);
		objs[low] = objs[0];
	}
}