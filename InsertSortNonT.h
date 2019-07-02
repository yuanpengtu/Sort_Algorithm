#pragma once

/*
* author:haohaosong 
* date:2017/2/25
* note:�������� 
*/ 

#include<iostream>
using namespace std;

#include<assert.h>

void Print(int* a,size_t n)
{
	assert(a);
	for (size_t i = 0; i < n; ++i)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}

//��������
//ʱ�临�Ӷ�:O(N* N)
//˼��:
//���������Ԫ�ؿ�ʼ����һ����ǰ���������ڶ�����ǰ������...�Դ�����
//��֤ǰ���ĵ�Ԫ�����������£����ĺ�һ��Ԫ��ʱ���������αȽ��ҵ��ʺϵĲ���λ��
//��������£����������ʱ�临�Ӷ�ΪO(N)
//�����£�Ҳ�������������ʱ�临�Ӷ�ΪO(N* N)
//
// [0,i]
void InsertSort(int* a, size_t n)
{
	assert(a);

	//��һ����ǰ���������ڶ�����ǰ����...
	for (size_t i = 1; i < n; ++i)
	{
		int end = i - 1;//end��ʾ���һ������ǰһ����
		int tmp = a[i];
		while (end >= 0)
		{
			//�Ƿ��Ǻ��ʵ�λ�ã����ǵĻ�����
			//�ǵĻ�break����
			if (tmp >= a[end])
				break;

			a[end + 1] = a[end];
			end--;
		}

		//������break���������в��ҵ����ʵ�λ��
		//Ҳ������end == -1��whileѭ����������Ҫ���ڵ�һ��Ԫ��
		a[end + 1] = tmp;
	}
}

void TestInsertSort()
{
	int a[10] = { 2, 5, 4, 9, 3, 6, 8, 7, 1, 0 };
	InsertSort(a, sizeof(a) / sizeof(a[0]));
	Print(a, sizeof(a) / sizeof(a[0]));
}
