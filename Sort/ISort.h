#include "ISortObj.h"
#pragma once
class ISort
{
public:
	ISort();
	virtual ~ISort();

	/**
	 * 按照从小到大的顺序进行排序
	 * [IN, OUT] ISortObj* objs[]: 排序序列元素的指针数组，返回排序完成的有序序列。
	 * [IN] int len: 指针数组长度
	 * 默认objs[0]不存储数据，数组指针存放在下标从1到len中。
	 */
	virtual void Sort(ISortObj* objs[], int len) = 0;

	/**
	 * 数组元素移动，将[start, start + len]移动到[pos, pos + len]的位置
	 */
	static void Move(ISortObj* objs[], int start, int len, int pos);
	static void Print(ISortObj* objs[], int len);
};

