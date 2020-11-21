#pragma once
#include "ISort.h"
/**
 * 折半插入排序算法
 * 稳定的
 * 思路：第一个元素有序，从[2, N]依次插入前面的有序表。
 * 然后用折半查找的方式定位第一个比带插入元素大的元素
 * 时间复杂度：O(N的平方)
 */
class BInsertSort :
	public ISort
{
public:
	BInsertSort();
	~BInsertSort();
	virtual void Sort(ISortObj* objs[], int len);
};

