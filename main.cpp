#include <iostream>
#include <Windows.h>
#include "Sort.h"
using namespace std;

void test()
{
	Sort sort;

	//ѭ��ִ������do-while���֣������û��˳�����
	bool exit_flag = false;
	bool array_flag = false;
	do
	{
		char input;

		//���벢�������Ϸ��� 
		bool error_flag = false;
		do
		{
			error_flag = false;

			cout << "ѡ��Ҫ���еĲ���(�����Ӧ���)(������0��ȡ����)��";
			cin >> input;

			switch (input)
			{

			case '0'://�������
			{
				cout << "1.�˳�����\n2.����\n3.��������\n4.��ӡ����\n5.ִ��ֱ�Ӳ�������\n6.ִ��ϣ������\n7.ִ��ð������\n8.��������\n\n";
				break;
			}

			case '1':case '2':break;

			case '3':
			{
				array_flag = true;
				break;
			}

			case '4':case '5':case '6':case '7':case '8':
			{
				//�ж������Ƿ�Ϊ�գ�Ϊ��������Զ�����в���
				if (array_flag == false)
				{
					cout << "���ȴ������飡\n";
					error_flag = true;
				}
				break;
			}

			default://�û����벻������������ѡ��ʱ����error_flag��1�������ʾ��䣬���¿�ʼѭ��
				cout << "����Ƿ���\n";
				error_flag = 1;
				break;

			}

		} while (error_flag == true);

		//ִ�ж�Ӧ����
		try
		{
			switch (input)
			{

			case '1'://�˳�����
			{
				exit_flag = 1;
				break;
			}

			case '2'://����
			{
				system("cls");
				break;
			}

			case '3':
			{
				sort.RandomData();
				cout << "	�Ѵ������顣\n";
				cout << "	����Ϊ��\n	";
				sort.PrintData();
				cout << "\n\n";
				break;
			}

			case '4':
			{
				cout << "	����Ϊ��\n	";
				sort.PrintData();
				cout << "\n\n";
				break;
			}

			case '5':
			{
				sort.InsertSort(sort.GetData());
				cout << "	��ִ��ֱ�Ӳ�������\n";
				cout << "	����Ϊ��\n	";
				sort.PrintData();
				cout << "\n\n";
				break;
			}

			case '6':
			{
				sort.ShellSort();
				cout << "	��ִ��ϣ������\n";
				cout << "	����Ϊ��\n	";
				sort.PrintData();
				cout << "\n\n";
				break;
			}

			case '7':
			{
				sort.BubbleSort();
				cout << "	��ִ��ð������\n";
				cout << "	����Ϊ��\n	";
				sort.PrintData();
				cout << "\n\n";
				break;
			}

			case '8':
			{
				sort.QuickSort(0, MAXSIZE - 1);
				cout << "	��ִ�п�������\n";
				cout << "	����Ϊ��\n	";
				sort.PrintData();
				cout << "\n\n";
				break;
			}
			}
		}
		catch (char* s)
		{
			cout << "	δ֪����" << s << endl;
		}
	} while (!exit_flag);
	cout << "�����������˳���\n";
}

int main()
{
	test();

	////���ڵ���
	//sort.RandomData();
	//sort.PrintData();
	//cout << endl << endl;
	//sort.InsertSort(sort.GetData());
	//sort.ShellSort();
	//sort.PrintData();
}
