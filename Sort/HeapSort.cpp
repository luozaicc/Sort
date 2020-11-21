#include "HeapSort.h"



HeapSort::HeapSort()
{
}


HeapSort::~HeapSort()
{
}

void HeapSort::Sort(ISortObj* o[], int len)
{
	for (int i = len / 2; i > 0; --i) {
		this->HeapAdjust(o, len, i);
	}
	for (int i = len; i > 1; --i) {
		o[0] = o[i];
		o[i] = o[1];
		o[1] = o[0];
		this->HeapAdjust(o, i - 1, 1);
	}
}

void HeapSort::HeapAdjust(ISortObj* o[], int len, int root)
{
	o[0] = o[root];
	for (int i = root * 2; i <= len; i *= 2) {
		if (i < len && o[i]->LT(o[i + 1])) {
			++i;
		}
		if (o[0]->LT(o[i])) {
			o[root] = o[i];
			root = i;
		}
		else {
			break;
		}
	}
	o[root] = o[0];
}