#pragma once
#include "ISort.h"

/**
 * 归并排序算法
 * 稳定
 * 思路：若长为1则直接填入即完成排序；对长为n的序列,假设稍短的都能排序,
	先对子列R[s..(s+t)/2]和R[(s+t)/2+1..t]排序(递归)，后调用归并函数进行归并
 * O(n*logn)
 */
class MergeSort :
	public ISort
{
public:
	MergeSort();
	~MergeSort();
	virtual void Sort(ISortObj* objs[], int len);
	void MSort(ISortObj* retObjs[], ISortObj* objs[], int low, int high);
	void Merge(ISortObj* r[], ISortObj* o[], int low, int m, int high);
};

