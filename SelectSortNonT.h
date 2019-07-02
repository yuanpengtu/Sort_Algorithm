#pragma once

/*
* author:haohaosong
* date:2017/2/25
* note:ѡ�������Լ��Ż� 
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

//ѡ��������Ż��汾
//ʱ�临�Ӷȣ�O(N* N)
//˼�룺
//ÿ��ѭ�����ҳ���Сֵ��ͬʱ���ҳ����ֵ
//Ч�ʻ����һ��������ʱ�临�Ӷȵ���������û�б�
//ע�⣺
//  ͬʱ�û����ֵ����Сֵʱ��������ֵ������begin��λ���ϣ��������λ����
//���û���ʱ����Ҫ����һ���жϣ������������ʾ
//
//  [begin,end]
void SelectSort(int* a, size_t n)
{
	assert(a);

	size_t begin = 0;
	size_t end = n - 1;
	size_t minIndex = 0;
	size_t maxIndex = 0;

	while (begin < end)
	{
		minIndex = begin;
		maxIndex = end;
		for (size_t i = begin + 1; i <= end; ++i)
		{
			//�ҳ���С�������±����������±�
			if (a[i] < a[minIndex])
				minIndex = i;

			if (a[i] > a[maxIndex])
				maxIndex = i;
		}
		//������С�����͵�һ����
		swap(a[minIndex], a[begin]);

		//��ֹλ�ó�ͻ��������
		if (maxIndex == begin)
			maxIndex = minIndex;

		//���������������һ����
		swap(a[maxIndex], a[end]);

		//�������м����
		begin++;
		end--;
	}
}

void TestSelectSort()
{
	int a[10] = { 2, 5, 4, 9, 3, 6, 8, 7, 1, 0 };
	SelectSort(a, sizeof(a) / sizeof(a[0]));
	Print(a, sizeof(a) / sizeof(a[0]));
}
