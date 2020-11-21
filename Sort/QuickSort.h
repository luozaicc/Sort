#pragma once
#include "ISort.h"

/**
 * 快速排序算法
 * 不稳定的
 * 思路：每一趟排序将当前序列分成两块，中轴左边的元素全部小于中轴，右边的全部大于等于中轴
 * 其中每一趟方法如下：
 * 1、首先拿第一个元素作为中轴，建立两个下标，high指向最后一个元素，low指向第一个元素，
	只要high大于low就进行步骤2、3，最后将中轴元素放在low位置
 * 2、比较high与中轴：
			如果high小，则high元素放在low位置，low右移（low = low + 1），进行步骤3；
			否则，high左移（high = high - 1）；
 * 3、比较low与中轴：
			如果low小，low右移（low = low + 1）；
			否则，low元素放在high位置，high左移（high = high - 1），进行步骤2；
 * 时间复杂度：平均O(nLogn)，最坏O(n的平方)
 * 最好情况：原始序列非递减有序（正序）
 * 最坏情况：原始序列非递增有序（逆序）
 */
class QuickSort :
	public ISort
{
public:
	QuickSort();
	~QuickSort();
	virtual void Sort(ISortObj* objs[], int len);
	void QSort(ISortObj* objs[], int low, int high);
	int Partition(ISortObj* objs[], int low, int high);
};

