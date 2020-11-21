#include "MergeSort.h"
#include <malloc.h>



MergeSort::MergeSort()
{
}


MergeSort::~MergeSort()
{
}

void MergeSort::Sort(ISortObj* objs[], int len)
{
	ISortObj** r = (ISortObj**)malloc(sizeof(ISortObj*) * (len + 1));
	if (NULL == r) {
		return;
	}
	MSort(r, objs, 1, len);
	for (int i = 1; i <= len; ++i) {
		objs[i] = r[i];
	}
}

void MergeSort::MSort(ISortObj* r[], ISortObj* o[], int low, int high)
{
	if (low == high) {
		r[low] = o[low];
		return;
	}
	int m = (low + high) / 2;
	this->MSort(r, o, low, m);
	this->MSort(r, o, m + 1, high);

	// 将r序列[]low, high]复制到o
	for (int i = low; i <= high; ++i) {
		o[i] = r[i];
	}

	Merge(r, o, low, m, high);
}

void MergeSort::Merge(ISortObj* r[], ISortObj* o[], int low, int m, int high)
{
	int i, j, k;
	for (i = low, j = m + 1, k = low; i <= m && j <= high; ++k) {
		if (o[i]->LT(o[j])) {
			r[k] = o[i];
			++i;
		}
		else {
			r[k] = o[j];
			++j;
		}
	}
	while (i <= m) {
		r[k++] = o[i++];
	}
	while (j <= high) {
		r[k++] = o[j++];
	}
}