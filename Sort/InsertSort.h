#pragma once

#include "ISort.h"
#include "ISortObj.h"

/**
 * ֱ�Ӳ��������㷨
 * �ȶ���
 * ˼·����Ԫ�����򣬴�[2, N]���β���ǰ����������ʹ����Ȼ����
 * ʱ�临�Ӷȣ�O(N��ƽ��)
 * ��������ԭʼ���зǵݼ���������
 * ������ԭʼ���зǵ�����������
 */
class InsertSort : public ISort
{
public:
	InsertSort();
	~InsertSort();

	void Sort(ISortObj* objs[], int len);
};

