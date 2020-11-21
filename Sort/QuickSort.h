#pragma once
#include "ISort.h"

/**
 * ���������㷨
 * ���ȶ���
 * ˼·��ÿһ�����򽫵�ǰ���зֳ����飬������ߵ�Ԫ��ȫ��С�����ᣬ�ұߵ�ȫ�����ڵ�������
 * ����ÿһ�˷������£�
 * 1�������õ�һ��Ԫ����Ϊ���ᣬ���������±꣬highָ�����һ��Ԫ�أ�lowָ���һ��Ԫ�أ�
	ֻҪhigh����low�ͽ��в���2��3���������Ԫ�ط���lowλ��
 * 2���Ƚ�high�����᣺
			���highС����highԪ�ط���lowλ�ã�low���ƣ�low = low + 1�������в���3��
			����high���ƣ�high = high - 1����
 * 3���Ƚ�low�����᣺
			���lowС��low���ƣ�low = low + 1����
			����lowԪ�ط���highλ�ã�high���ƣ�high = high - 1�������в���2��
 * ʱ�临�Ӷȣ�ƽ��O(nLogn)���O(n��ƽ��)
 * ��������ԭʼ���зǵݼ���������
 * ������ԭʼ���зǵ�����������
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

