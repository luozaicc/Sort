# 数据结构之排序算法

## 排序算法分类

​	排序算法分为：插入类排序、交换类排序、选择类排序、归并类排序和基数类排序。

## 插入类排序

### 直接插入排序

 * 思路

    * 首元素有序，从[2, N]依次插入前面的有序表，并使其依然有序。

 * 稳定性：稳定的

 * 时间复杂度：

    * 平均：O(N的平方)
    * 最好：原始序列非递减有序（正序）
    * 最坏：原始序列非递增有序（逆序）

 * 代码实现

   - 代码实现如下：

   ```
   void InsertSort::Sort(ISortObj* objs[], int len)
   {
   	for (int i = 2; i <= len; ++i) {
   		for (int j = 1; j < i; ++j) {
   			if (objs[i]->LT(objs[j])) {
   				objs[0] = objs[i];
   				this->Move(objs, j, i - j, j + 1);
   				objs[j] = objs[0];
   			}
   		}
   	}
   }
   ```
   * 代码说明（下同）
     - 其中"ISortObj* objs[]"为待排序元素的指针数组，"int len"为待排序元素数据个数，默认下标0位置不存放元素数据，故objs数组的长度应为len+1。
     - 函数void Move(ISortObj* objs[], int start, int len, int pos)：表示将objs数组的[start, start + len)数据移动到[pos, pos + len)位置，其具体实现在后文附录中给出。
     - 函数bool LT(ISortObj* pObj)：表示本元素小于pObj指向的元素。

### 折半插入排序

- 思路

  - 第一个元素有序，从[2, N]依次插入前面的有序表。然后用折半查找的方式定位第一个比带插入元素大的元素。

- 稳定性：稳定的

- 时间复杂度

  - 平均：O(N的平方)

- 代码实现

  ```
  void BInsertSort::Sort(ISortObj* objs[], int len)
  {
  	for (int i = 2; i <= len; ++i) {
  		int high = i - 1;
  		int low = 1;
  
  		objs[0] = objs[i];
  		while (low <= high) {
  			int m = (high + low) / 2;
  			if (objs[0]->LT(objs[m])) {
  				high = m - 1;
  			}
  			else {
  				low = m + 1;
  			}
  		}
  		this->Move(objs, low, i - low, low + 1);
  		objs[low] = objs[0];
  	}
  }
  ```


### 希尔排序（缩小增量排序）

- 思路

  - 每一趟希尔排序将元素序列分为d个子序列，分别对各子序列进行直接插入排序。

- 稳定性：不稳定

- 时间复杂度

  - 平均：O(N的1.X次方)
  - 最好：
  - 最坏：

- 代码实现

  ```
  void ShellSort::Sort(ISortObj* objs[], int len)
  {
  	for (int i = 0; i < this->_dlta.size(); ++i) {
  		ShellInsertSort(objs, len, this->_dlta[i]);
  	}
  }
  
  void ShellSort::ShellInsertSort(ISortObj* objs[], int len, int dk)
  {
  	for (int i = dk + 1; i <= len; ++i) {
  		objs[0] = objs[i];
  		if (objs[0]->LT(objs[i - dk])) {
  			int j = i - dk;
  			for (; j >= 1 && objs[0]->LT(objs[j]); j -= dk) {
  				objs[j + dk] = objs[j];
  			}
  			objs[j + dk] = objs[0];
  		}
  	}
  }
  ```

## 交换类排序

### 冒泡排序（改进）

- 思路

  - 每趟排序，从首元素开始相邻两元素进行比较，如果逆序则交换。这样每一趟都会找出当前最大的元素沉到当前的末尾。最多进行n-1趟排序可以完成，如果中间某趟不进行交换也可以结束。

- 稳定性：稳定的

- 时间复杂度

  - 平均：O(N的平方)
  - 最好：原始序列非递减有序（正序）
  - 最坏：原始序列非递增有序（逆序）

- 代码实现

  ```
  void BubbleSort::Sort(ISortObj* objs[], int len)
  {
  	for (int i = len; i > 1; --i) {
  		bool hasChange = false;
  		for (int j = 1; j < i; ++j) {
  			if (objs[j + 1]->LT(objs[j])) {
  				hasChange = true;
  				objs[0] = objs[j];
  				objs[j] = objs[j + 1];
  				objs[j + 1] = objs[0];
  			}
  		}
  		if (!hasChange) {
  			break;
  		}
  	}
  }
  ```

### 快速排序

- 思路

  - 每一趟排序将当前序列分成两块，中轴左边的元素全部小于中轴，右边的全部大于等于中轴。
   - 其中每一趟方法如下：
      * 1、首先拿第一个元素作为中轴，建立两个下标，high指向最后一个元素，low指向第一个元素，只要high大于low就进行步骤2、3，最后将中轴元素放在low位置
      * 2、比较high与中轴：
          如果high小，则high元素放在low位置，low右移（low = low + 1），进行步骤3；
          否则，high左移（high = high - 1）；
      * 3、比较low与中轴：
          如果low小，low右移（low = low + 1）；
          否则，low元素放在high位置，high左移（high = high - 1），进行步骤2；

- 稳定性：不稳定

- 时间复杂度

  - 平均：O(nLogn)
  - 最好：原始序列非递减有序（正序）
  - 最坏：O(N的平方)，正序或逆序时最坏时间复杂度

- 代码实现

  ```
  void QuickSort::QSort(ISortObj* objs[], int low, int high)
  {
  	if (low < high) {
  		int m = Partition(objs, low, high);
  		this->QSort(objs, low, m - 1);
  		this->QSort(objs, m + 1, high);
  	}
  }
  
  int QuickSort::Partition(ISortObj* objs[], int low, int high)
  {
  	int nLow = low;
  	int nHigh = high;
  	objs[0] = objs[nLow];
  	while (nLow < nHigh) {
  		while (nLow < nHigh && objs[0]->LT(objs[nHigh])) {
  			--nHigh;
  		}
  		if (nLow < nHigh) {
  			objs[nLow] = objs[nHigh];
  			++nLow;
  		}
  		while (nLow < nHigh && objs[nLow]->LT(objs[0])) {
  			++nLow;
  		}
  		if (nLow < nHigh) {
  			objs[nHigh] = objs[nLow];
  			--nHigh;
  		}
  	}
  	objs[nLow] = objs[0];
  	return nLow;
  }
  ```

## 选择类排序

### 堆排序

- 堆概念介绍

  - 将堆看作一颗完全二叉树的顺序存储序列，小顶堆对应的完全二叉树中任意结点均比其孩子小或相等；大顶堆对应的完全二叉树中任意结点均比其孩子大或相等；不满足这两个性质的完全二叉树其顺序存储序列不是堆。

- 思路

   - 将大顶堆的根节点与当前最后一个元素交换，之后将前面的元素序列重新调整为大顶堆，然后将新的大顶堆的根节点与当前最后一个元素（即整个序列倒数第二个）交换，重复此操作。
   - 调整大顶堆：比较堆顶与其两个孩子,若堆顶不是最大则将两孩子中的大者与堆顶“交换”，交换后的子树可能不再是堆，重复上述操作至最后。
   - 建立初始大顶堆：从最后一个非叶子结点开始向根结点方向逐步调整建堆。
   - 最坏时间复杂度O(nlogn),比快排好,且仅用一个记录辅助空间rc,但不稳定,
    建堆在正序时最慢,适合n大杂乱

- 稳定性：不稳定

- 时间复杂度

  - 平均：O(nlogn)
  - 最好：适合n大，且杂乱
  - 最坏：O(nlogn)，建堆在正序时最慢

- 代码实现

  ```
  void HeapSort::Sort(ISortObj* o[], int len)
  {
  	for (int i = len / 2; i > 0; --i) {
  		this->HeapAdjust(o, len, i);
  	}
  	for (int i = len; i > 1; --i) {
  		o[0] = o[i];
  		o[i] = o[1];
  		o[1] = o[0];
  		this->HeapAdjust(o, i - 1, 1);
  	}
  }
  
  void HeapSort::HeapAdjust(ISortObj* o[], int len, int root)
  {
  	o[0] = o[root];
  	for (int i = root * 2; i <= len; i *= 2) {
  		if (i < len && o[i]->LT(o[i + 1])) {
  			++i;
  		}
  		if (o[0]->LT(o[i])) {
  			o[root] = o[i];
  			root = i;
  		}
  		else {
  			break;
  		}
  	}
  	o[root] = o[0];
  }
  ```

## 归并类排序

### 归并排序

- 思路

  - 若长为1则直接填入即完成排序；对长为n的序列,假设稍短的都能排序，先对子列R[s..(s+t)/2]和R[(s+t)/2+1..t]排序(递归)，后调用归并函数进行归并。

- 稳定性：稳定的

- 时间复杂度：O(nlogn)

- 空间复杂度：O(n)

- 代码实现

  ```
  void MergeSort::Sort(ISortObj* objs[], int len)
  {
  	ISortObj** r = (ISortObj**)malloc(sizeof(ISortObj*) * (len + 1));
  	if (NULL == r) {
  		return;
  	}
  	MSort(r, objs, 1, len);
  	for (int i = 1; i <= len; ++i) {
  		objs[i] = r[i];
  	}
  }
  
  void MergeSort::MSort(ISortObj* r[], ISortObj* o[], int low, int high)
  {
  	if (low == high) {
  		r[low] = o[low];
  		return;
  	}
  	int m = (low + high) / 2;
  	this->MSort(r, o, low, m);
  	this->MSort(r, o, m + 1, high);
  
  	// 将r序列[]low, high]复制到o
  	for (int i = low; i <= high; ++i) {
  		o[i] = r[i];
  	}
  
  	Merge(r, o, low, m, high);
  }
  
  void MergeSort::Merge(ISortObj* r[], ISortObj* o[], int low, int m, int high)
  {
  	int i, j, k;
  	for (i = low, j = m + 1, k = low; i <= m && j <= high; ++k) {
  		if (o[i]->LT(o[j])) {
  			r[k] = o[i];
  			++i;
  		}
  		else {
  			r[k] = o[j];
  			++j;
  		}
  	}
  	while (i <= m) {
  		r[k++] = o[i++];
  	}
  	while (j <= high) {
  		r[k++] = o[j++];
  	}
  }
  ```

## 基数类排序

### 基数排序

- 思路

  - 不进行比较，将原关键字看成由多个数位或字符构成的多关键字，按最低/高位优先进行分配、收集
  - 单关键字可能的取值个数称为基数rd，分配和收集的趟数d为最大原始关键字的位数

- 稳定性：稳定

- 复杂度：链式基数排序时间复杂度O(d*(n+ rd ))，空间O(rd)


## 附录

### Move函数实现

```
void ISort::Move(ISortObj* objs[], int start, int len, int pos)
{
	if (pos == start) {
		return;
	}
	if (pos > start) {
		for (int i = 1; i <= len; ++i) {
			objs[pos + len - i] = objs[start + len - i];
		}
	}
	else {
		for (int i = 1; i <= len; ++i) {
			objs[pos + i] = objs[start + i];
		}
	}
}
```

