#include "QuickSort.h"



QuickSort::QuickSort()
{
}


QuickSort::~QuickSort()
{
}

void QuickSort::Sort(ISortObj* objs[], int len)
{
	this->QSort(objs, 1, len);
}

void QuickSort::QSort(ISortObj* objs[], int low, int high)
{
	if (low < high) {
		int m = Partition(objs, low, high);
		this->QSort(objs, low, m - 1);
		this->QSort(objs, m + 1, high);
	}
}

int QuickSort::Partition(ISortObj* objs[], int low, int high)
{
	int nLow = low;
	int nHigh = high;
	objs[0] = objs[nLow];
	while (nLow < nHigh) {
		while (nLow < nHigh && objs[0]->LT(objs[nHigh])) {
			--nHigh;
		}
		if (nLow < nHigh) {
			objs[nLow] = objs[nHigh];
			++nLow;
		}
		while (nLow < nHigh && objs[nLow]->LT(objs[0])) {
			++nLow;
		}
		if (nLow < nHigh) {
			objs[nHigh] = objs[nLow];
			--nHigh;
		}
	}
	objs[nLow] = objs[0];
	return nLow;
}