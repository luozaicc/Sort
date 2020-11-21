#include "BubbleSort.h"



BubbleSort::BubbleSort()
{
}


BubbleSort::~BubbleSort()
{
}

void BubbleSort::Sort(ISortObj* objs[], int len)
{
	for (int i = len; i > 1; --i) {
		bool hasChange = false;
		for (int j = 1; j < i; ++j) {
			if (objs[j + 1]->LT(objs[j])) {
				hasChange = true;
				objs[0] = objs[j];
				objs[j] = objs[j + 1];
				objs[j + 1] = objs[0];
			}
		}
		if (!hasChange) {
			break;
		}
	}
}
