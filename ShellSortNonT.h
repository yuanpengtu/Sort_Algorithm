#pragma once

/*
* author:haohaosong 
* date:2017/2/25
* note:ϣ������ 
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

//ϣ������
//ʱ�临�Ӷȣ�O(N* N)
//˼��:
//������ֳ�gap�飬Ȼ������ò�������
//��gapΪ1ʱ�����ǽ���ֱ�Ӳ�������
//ϣ��������������߽ӽ�����ʱ������߲��������Ч��
//�����Ԫ���Ƶ�ǰ���λ�û��ѵĴ���������
void ShellSort(int* a, size_t n)
{
	assert(a);
	size_t gap = n;

	//whileѭ�������Ŷ�β�������
	while (gap > 1)
	{
		//�ù�ʽ���Ա�֤���һ�������gapΪ1
		gap = gap / 3 + 1;

		//�ӵ�һ��ĵڶ���Ԫ�ؿ�ʼ������ѭ������ֱ�Ӳ�������
		for (size_t i = gap; i < n; ++i)
		{
			int end = i - gap;
			int tmp = a[i];

			//���в�������ÿһ��Ĳ�ֵΪgap
			//�Ӻ���ǰ��ÿ���һ��Ԫ�ص�ǰһ��ֵһ��С��0
			while (end >= 0)
			{
				//���tmp����ǰ������ҵ�tmp�Ĳ���λ�ã�break����
				//����endԪ�ؽ��е���ĺ���
				if (a[end] <= tmp)
					break;

				a[end + gap] = a[end];
				end -= gap;
			}

			//���в���
			a[end + gap] = tmp;
		}
	}
}

void TestShellSort()
{
	int a[10] = { 2, 5, 4, 9, 3, 6, 8, 7, 1, 0 };
	ShellSort(a, sizeof(a) / sizeof(a[0]));
	Print(a, sizeof(a) / sizeof(a[0]));
}


//���������ϣ������ıȽ�
//ϣ�����������нӽ������ͨ�����ٻ��ƶ��Ĵ����Ӷ���߲��������Ч��
//���ǵ�Ԫ����ʱ�����������٣��������򲢲����ϣ������໻����λ��
//��Ԫ�غܶ�ʱ���ܶ�����õ��ǿ��źͶ���
//����ϣ��������һ������������
