#pragma once 

#include<iostream>
using namespace std;

void Print(int* arr, size_t n)
{
	for (size_t i = 0; i < n; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

//����
template<typename T>
struct Greater
{
	bool operator()(T& t1, T& t2)
	{
		return t1 > t2;
	}
};

//����
template<typename T>
struct Less
{
	bool operator()(T& t1, T& t2)
	{
		return t1 < t2;
	}
};

//ð������
template<typename T,typename Com = Greater<T>>
void BubbleSort(T* arr,size_t n)
{	
	bool flag = true;
	//����n-1�ε���ѭ��
	for (size_t i = 0; i < n - 1; i++)
	{
		//ÿ��ѭ���Ƚ�n-i-1��
		for (size_t j = 0; j < n - i - 1; j++)
		{
			if (Com()(arr[j], arr[j + 1]))
			{
				swap(arr[j], arr[j + 1]);
				//���ı�ǣ������ж��Ƿ�����
				flag = false;
			}
		}
		//��ʾ�Ѿ�����ֱ�ӷ���
		if (false == true)
			return;
	}
}

void TestBubbleSort()
{
	int arr[10] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 0 };
	BubbleSort<int,Less<int>>(arr, 10);
	cout << "ð������:" << endl;
	Print(arr, 10);
}
