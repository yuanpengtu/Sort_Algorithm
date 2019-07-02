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
//ʱ�临�Ӷ�:O(N* lgN)
//˼��:
//��һ�������ҳ����һ��Ԫ�صĶ�Ӧλ�ã�����������λ�ã�
//�Ը�Ԫ�طֳ�����ռ䣬�ֱ�����������
//ֱ��һ��ռ��Ԫ�ز�����1ʱ������

//��һ������
//[left,right]
size_t PartSort(int* a, int left, int right)
{
	int key = a[right];
	
	while (left < right)
	{
		while (left < right && a[left] <= key)
			left++;

		a[right] = a[left];

		while (left < right && a[right] >= key)
			right--;

		a[left] = a[right];
	}

	a[left] = key;
	return left;
}

//[left,right]
void QuickSort(int* a, int left, int right)
{
	if (left < right)
	{
		int mid = PartSort(a, left, right);
		QuickSort(a, left, mid - 1);
		QuickSort(a, mid + 1, right);
	}
}

void TestQuickSort()
{
	int a[10] = { 2, 5, 4, 9, 3, 6, 8, 7, 1, 0 };
	QuickSort(a, 0, sizeof(a) / sizeof(a[0])-1);
	Print(a, sizeof(a) / sizeof(a[0]));
}
