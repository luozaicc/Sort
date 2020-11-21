#pragma once
#include "ISort.h"

/**
 * 选择排序算法
 * 稳定的
 * 思路：每趟都选择当前最小的元素交换到“无序块”的最前，共N-1趟则完成排序
 * 时间复杂度：O(N的平方)
 * 最好情况：原始序列非递减有序（正序）
 * 最坏情况：原始序列非递增有序（逆序）
 */
class SelectSort :
	public ISort
{
public:
	SelectSort();
	~SelectSort();
	virtual void Sort(ISortObj* objs[], int len);
};

