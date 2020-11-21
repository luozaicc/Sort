#pragma once
#include "ISort.h"

/**
 * �鲢�����㷨
 * �ȶ�
 * ˼·������Ϊ1��ֱ�����뼴������򣻶Գ�Ϊn������,�����Զ̵Ķ�������,
	�ȶ�����R[s..(s+t)/2]��R[(s+t)/2+1..t]����(�ݹ�)������ù鲢�������й鲢
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

