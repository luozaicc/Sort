#pragma once
#include "ISort.h"
/**
 * �۰���������㷨
 * �ȶ���
 * ˼·����һ��Ԫ�����򣬴�[2, N]���β���ǰ��������
 * Ȼ�����۰���ҵķ�ʽ��λ��һ���ȴ�����Ԫ�ش��Ԫ��
 * ʱ�临�Ӷȣ�O(N��ƽ��)
 */
class BInsertSort :
	public ISort
{
public:
	BInsertSort();
	~BInsertSort();
	virtual void Sort(ISortObj* objs[], int len);
};

