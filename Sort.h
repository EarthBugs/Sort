#pragma once
#include <stdlib.h>
#include <time.h>

const int MAXSIZE = 8;

class Sort
{
private:
	int data[MAXSIZE];
public:
	void RandomData();//�����������
	void PrintData();//��ӡ����
	int* GetData();//��������
	void InsertSort(int data[], int index = 0, int gap = 1);//��������
	void ShellSort();//ϣ������
	void BubbleSort();//ð������
	void QuickSort(int left, int right);//��������
};
