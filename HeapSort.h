#pragma once 

//a i 0
void AdjustDown(int* a, size_t n, size_t i)
{
	int parent = i;
	int child = parent * 2 + 1;
	while (child < n)
	{
		//�ҳ����ӵ����ֵ
		if (child + 1 < n && a[child+1] > a[child])
			child++;

		if (a[child]>a[parent])
		{
			swap(a[child], a[parent]);
			parent = child;
			child = child * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

void HeapSort(int* a,size_t n)
{
	//����һ����
	int* heap = new int[n];

	for (size_t i = 0; i < n; i++)
	{
		heap[i] = a[i];
	}

	//���µ���
	for (int i = (n-2)/2; i >= 0; --i)
	{
		AdjustDown(heap, n, i);
	}

	//cout << Check(heap, 10) << endl;

	//�������ʵ���Բ���
	int end = n - 1;

	//�Ƚ���һ��Ԫ�غ����һ��Ԫ�ص�ֵ���н���
	//Ȼ�����һ��Ԫ�ز�����Ϊ���ڵ�����
	while (end>0)
	{
		swap(heap[0], heap[end]);
		end--; 
		AdjustDown(heap, end, 0);
	}

	//��ӡ
	for (size_t i = 0; i < 10; i++)
	{
		cout << heap[i] << " ";
	}
	cout << endl;
}

void TestHeapSort()
{
	int a[] = { 10, 16, 18, 12, 11, 13, 15, 17, 14, 19 };
	HeapSort(a,sizeof(a)/sizeof(a[0]));
}
