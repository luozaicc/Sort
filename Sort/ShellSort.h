#pragma once
#include "ISort.h"
#include <vector>
/**
 * ϣ�������㷨����С��������
 * ���ȶ���
 * ˼·��ÿһ��ϣ������Ԫ�����з�Ϊd�������У��ֱ�Ը������н���ֱ�Ӳ�������
 * ���һ�˵�d����1����ȫ���н���ֱ�Ӳ�������
 * ʱ�临�Ӷȣ�O(N��1.3�η�)
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

