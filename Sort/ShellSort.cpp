#include "ShellSort.h"



ShellSort::ShellSort()
{
	_dlta.resize(3);
	_dlta[2] = 5;
	_dlta[1] = 3;
	_dlta[0] = 1;
}


ShellSort::~ShellSort()
{
}

void ShellSort::Sort(ISortObj* objs[], int len)
{
	for (int i = 0; i < this->_dlta.size(); ++i) {
		ShellInsertSort(objs, len, this->_dlta[i]);
	}
}

void ShellSort::ShellInsertSort(ISortObj* objs[], int len, int dk)
{
	for (int i = dk + 1; i <= len; ++i) {
		objs[0] = objs[i];
		if (objs[0]->LT(objs[i - dk])) {
			int j = i - dk;
			for (; j >= 1 && objs[0]->LT(objs[j]); j -= dk) {
				objs[j + dk] = objs[j];
			}
			objs[j + dk] = objs[0];
		}
	}
}

