#include <iostream>
#include "Sort.h"
using namespace std;

//���������
void Sort::RandomData()
{
	srand(time(NULL));
	//ʹ�������Ϊdata�е�Ԫ�ظ�ֵ
	for (int index = 0; index < MAXSIZE; index++)
	{
		data[index] = rand();
	}
}

//����б�
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

//��������
void Sort::InsertSort(int data[], int index, int gap)
{
	int length = MAXSIZE / gap;
	for (int index = gap; index < length; index++)
	{
		int temp = data[index];//��indexָ��ָ���Ԫ���ݴ�
		int index1 = index;
		//��indexָ��ָ��Ԫ�ص���һ��Ԫ��С��indexָ��ָ��Ԫ�أ�����һ��Ԫ�ص�ֵ����indexָ��ָ��Ԫ��
		for (; index1 > 0 && temp < data[index1 - gap]; index1 = index1 - gap)
		{
			data[index1] = data[index1 - gap];
		}
		data[index1] = temp;
	}
}

//ϣ������
void Sort::ShellSort()
{
	//���з��飬�ʼʱ������gapΪ���鳤�ȵ�һ��
	for (int gap = MAXSIZE / 2; gap > 0; gap = gap / 2)
	{
		for (int gapindex = 0; gapindex < MAXSIZE; gapindex = gapindex + gap)
		{
			InsertSort(data, gapindex, gap);
		}
	}
}

//ð������
void Sort::BubbleSort()
{
	for (int index = 0, temp; index < MAXSIZE - 1; index++)
		for (int index1 = 0; index1 < MAXSIZE - 1 - index; index1++)
			if (data[index1] > data[index1 + 1])
			{
				temp = data[index1];
				data[index1] = data[index1 + 1];
				data[index1 + 1] = temp;
			}
}

//��������
void Sort::QuickSort(int left, int right)
{
	if (left < right)
	{
		int index1 = left, index2 = right, mid = data[left];
		while (index1 < index2)
		{
			while (index1 < index2 && data[index2] >= mid)//���������ҵ�һ��С��mid����
				index2--;
			if (index1 < index2)
				data[index1++] = data[index2];
			while (index1 < index2 && data[index1] < mid)//���������ҵ�һ�����ڵ���mid����
				index1++;
			if (index1 < index2)
				data[index2--] = data[index1];
		}
		data[index1] = mid;
		QuickSort(left, index1 - 1);//�ݹ���� 
		QuickSort(index1 + 1, right);
	}
}
