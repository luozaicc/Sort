#include "ISortObj.h"
#pragma once
class ISort
{
public:
	ISort();
	virtual ~ISort();

	/**
	 * ���մ�С�����˳���������
	 * [IN, OUT] ISortObj* objs[]: ��������Ԫ�ص�ָ�����飬����������ɵ��������С�
	 * [IN] int len: ָ�����鳤��
	 * Ĭ��objs[0]���洢���ݣ�����ָ�������±��1��len�С�
	 */
	virtual void Sort(ISortObj* objs[], int len) = 0;

	/**
	 * ����Ԫ���ƶ�����[start, start + len]�ƶ���[pos, pos + len]��λ��
	 */
	static void Move(ISortObj* objs[], int start, int len, int pos);
	static void Print(ISortObj* objs[], int len);
};

