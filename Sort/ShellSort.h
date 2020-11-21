#pragma once
#include "ISort.h"
#include <vector>
/**
 * 希尔排序算法（缩小增量排序）
 * 不稳定的
 * 思路：每一趟希尔排序将元素序列分为d个子序列，分别对各子序列进行直接插入排序
 * 最后一趟的d等于1，对全序列进行直接插入排序
 * 时间复杂度：O(N的1.3次方)
 */
class ShellSort :
	public ISort
{
public:
	ShellSort();
	~ShellSort();
	virtual void Sort(ISortObj *objs[], int len);
	void ShellInsertSort(ISortObj* objs[], int len, int d);
private:
	std::vector<int> _dlta;
};

