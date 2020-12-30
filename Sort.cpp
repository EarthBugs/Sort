#include <iostream>
#include "Sort.h"
using namespace std;

//生成随机数
void Sort::RandomData()
{
	srand(time(NULL));
	//使用随机数为data中的元素赋值
	for (int index = 0; index < MAXSIZE; index++)
	{
		data[index] = rand();
	}
}

//输出列表
void Sort::PrintData()
{
	for (int index = 0; index < MAXSIZE; index++)
	{
		cout << data[index] << " ";
	}
}

int* Sort::GetData()
{
	return data;
}

//插入排序
void Sort::InsertSort(int data[], int index, int gap)
{
	int length = MAXSIZE / gap;
	for (int index = gap; index < length; index++)
	{
		int temp = data[index];//将index指针指向的元素暂存
		int index1 = index;
		//若index指针指向元素的上一个元素小于index指针指向元素，则将上一个元素的值赋予index指针指向元素
		for (; index1 > 0 && temp < data[index1 - gap]; index1 = index1 - gap)
		{
			data[index1] = data[index1 - gap];
		}
		data[index1] = temp;
	}
}

//希尔排序
void Sort::ShellSort()
{
	//进行分组，最开始时的增量gap为数组长度的一半
	for (int gap = MAXSIZE / 2; gap > 0; gap = gap / 2)
	{
		for (int gapindex = 0; gapindex < MAXSIZE; gapindex = gapindex + gap)
		{
			InsertSort(data, gapindex, gap);
		}
	}
}
