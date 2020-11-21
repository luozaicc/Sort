#pragma once

#include "ISort.h"
#include "ISortObj.h"

/**
 * 直接插入排序算法
 * 稳定的
 * 思路：首元素有序，从[2, N]依次插入前面的有序表，并使其依然有序。
 * 时间复杂度：O(N的平方)
 * 最好情况：原始序列非递减有序（正序）
 * 最坏情况：原始序列非递增有序（逆序）
 */
class InsertSort : public ISort
{
public:
	InsertSort();
	~InsertSort();

	void Sort(ISortObj* objs[], int len);
};

