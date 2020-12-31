#pragma once
#include <stdlib.h>
#include <time.h>

const int MAXSIZE = 8;

class Sort
{
private:
	int data[MAXSIZE];
public:
	void RandomData();//创建随机数组
	void PrintData();//打印数组
	int* GetData();//返回数组
	void InsertSort(int data[], int index = 0, int gap = 1);//插入排序
	void ShellSort();//希尔排序
	void BubbleSort();//冒泡排序
	void QuickSort(int left, int right);//快速排序
};
