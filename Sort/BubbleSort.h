#pragma once
#include "ISort.h"
/**
 * ð�������㷨
 * �ȶ���
 * ˼·��ÿ�����򣬴���Ԫ�ؿ�ʼ������Ԫ�ؽ��бȽϣ���������򽻻���
 * ����ÿһ�˶����ҳ���ǰ����Ԫ�س�����ǰ��ĩβ��
 * ������n-1�����������ɣ�����м�ĳ�˲����н���Ҳ���Խ�����
 * ʱ�临�Ӷȣ�O(N��ƽ��)
 * ��������ԭʼ���зǵݼ���������
 * ������ԭʼ���зǵ�����������
 */
class BubbleSort :
	public ISort
{
public:
	BubbleSort();
	~BubbleSort();
	virtual void Sort(ISortObj* objs[], int len);
};

