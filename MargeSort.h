#pragma once

/*
* author:haohaosong
* date:2017/3/4
* note:�鲢����
*/

//�鲢����
//ʱ�临�Ӷ�:O(N* logN)
//˼��:
//���ù鲢��˼�룬����������������Ϊһ��
//��Ҫһ������������ϲ����ֵ
//Ҳ�ж��ֵ�˼��

//��������
void _Marge(int* a, int* tmp, int left, int mid, int right)
{
	int bgn1 = left;
	int end1 = mid;
	int bgn2 = mid + 1;
	int end2 = right;

	int index = left;

	//���й鲢����,���뵽tmp��
	while (bgn1 <= end1 && bgn2 <= end2)
	{
		if (a[bgn1] < a[bgn2])
			tmp[index++] = a[bgn1++];
		else
			tmp[index++] = a[bgn2++];
	} 

	//�鲢ʱ������һ��������û�з���ģ���Ҫ�б���bgn1����bgn2
	//Ȼ�������tmp
	while (bgn1 <= end1)
		tmp[index++] = a[bgn1++];
	while (bgn2 <= end2)
		tmp[index++] = a[bgn2++];

	//��tmp�е�Ԫ�طŻ�����a��
	for (size_t i = left; i <= right; ++i)
		a[i] = tmp[i];
}

//������Ŀ���
void _MargeSort(int* a,int* tmp ,int left, int right)
{
	//���Ԫ�ز�����һ�������ý�������
	if (left >= right)
		return;

	int mid = left + ((right - left) >> 1);

	//Ԫ�ز�ֹһ������Ҫ�ݹ�����
	_MargeSort(a, tmp, left, mid);
	_MargeSort(a, tmp, mid+1, right);

	//��������
	_Marge(a, tmp, left, mid, right);
}

//������������ͷ�tmp
void MargeSort(int* a, size_t n)
{
	assert(a);

	int* tmp = new int[n];

	//���ù鲢
	_MargeSort(a, tmp, 0, n-1);

	delete[] tmp;
}

void TestMargeSort()
{
	int a[10] = { 2, 0, 4, 9, 3, 6, 8, 7, 1, 5 };
	MargeSort(a, sizeof(a) / sizeof(a[0]));
	Print(a, sizeof(a) / sizeof(a[0]));
}