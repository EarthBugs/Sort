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
