#pragma once
#include "ISort.h"

/**
 * ѡ�������㷨
 * �ȶ���
 * ˼·��ÿ�˶�ѡ��ǰ��С��Ԫ�ؽ�����������顱����ǰ����N-1�����������
 * ʱ�临�Ӷȣ�O(N��ƽ��)
 * ��������ԭʼ���зǵݼ���������
 * ������ԭʼ���зǵ�����������
 */
class SelectSort :
	public ISort
{
public:
	SelectSort();
	~SelectSort();
	virtual void Sort(ISortObj* objs[], int len);
};

