#include <iostream>
#include <Windows.h>
#include "Sort.h"
using namespace std;

void test()
{
	Sort sort;

	//循环执行以下do-while部分，除非用户退出程序
	bool exit_flag = false;
	bool array_flag = false;
	do
	{
		char input;

		//输入并检测输入合法性 
		bool error_flag = false;
		do
		{
			error_flag = false;

			cout << "选择将要进行的操作(输入对应序号)(可输入0获取帮助)：";
			cin >> input;

			switch (input)
			{

			case '0'://输出帮助
			{
				cout << "1.退出程序\n2.清屏\n3.创建数组\n4.打印数组\n5.执行直接插入排序\n6.执行希尔排序\n7.执行冒泡排序\n8.快速排序\n\n";
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
				//判断数组是否为空，为空则不允许对对象进行操作
				if (array_flag == false)
				{
					cout << "请先创建数组！\n";
					error_flag = true;
				}
				break;
			}

			default://用户输入不属于上述任意选项时，将error_flag置1并输出提示语句，重新开始循环
				cout << "输入非法！\n";
				error_flag = 1;
				break;

			}

		} while (error_flag == true);

		//执行对应命令
		try
		{
			switch (input)
			{

			case '1'://退出程序
			{
				exit_flag = 1;
				break;
			}

			case '2'://清屏
			{
				system("cls");
				break;
			}

			case '3':
			{
				sort.RandomData();
				cout << "	已创建数组。\n";
				cout << "	数组为：\n	";
				sort.PrintData();
				cout << "\n\n";
				break;
			}

			case '4':
			{
				cout << "	数组为：\n	";
				sort.PrintData();
				cout << "\n\n";
				break;
			}

			case '5':
			{
				sort.InsertSort(sort.GetData());
				cout << "	已执行直接插入排序。\n";
				cout << "	数组为：\n	";
				sort.PrintData();
				cout << "\n\n";
				break;
			}

			case '6':
			{
				sort.ShellSort();
				cout << "	已执行希尔排序。\n";
				cout << "	数组为：\n	";
				sort.PrintData();
				cout << "\n\n";
				break;
			}

			case '7':
			{
				sort.BubbleSort();
				cout << "	已执行冒泡排序。\n";
				cout << "	数组为：\n	";
				sort.PrintData();
				cout << "\n\n";
				break;
			}

			case '8':
			{
				sort.QuickSort(0, MAXSIZE - 1);
				cout << "	已执行快速排序。\n";
				cout << "	数组为：\n	";
				sort.PrintData();
				cout << "\n\n";
				break;
			}
			}
		}
		catch (char* s)
		{
			cout << "	未知错误！" << s << endl;
		}
	} while (!exit_flag);
	cout << "程序已正常退出。\n";
}

int main()
{
	test();

	////用于调试
	//sort.RandomData();
	//sort.PrintData();
	//cout << endl << endl;
	//sort.InsertSort(sort.GetData());
	//sort.ShellSort();
	//sort.PrintData();
}
