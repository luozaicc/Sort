#pragma once
#include "ISort.h"
/**
 * 冒泡排序算法
 * 稳定的
 * 思路：每趟排序，从首元素开始相邻两元素进行比较，如果逆序则交换。
 * 这样每一趟都会找出当前最大的元素沉到当前的末尾。
 * 最多进行n-1趟排序可以完成，如果中间某趟不进行交换也可以结束。
 * 时间复杂度：O(N的平方)
 * 最好情况：原始序列非递减有序（正序）
 * 最坏情况：原始序列非递增有序（逆序）
 */
class BubbleSort :
	public ISort
{
public:
	BubbleSort();
	~BubbleSort();
	virtual void Sort(ISortObj* objs[], int len);
};

