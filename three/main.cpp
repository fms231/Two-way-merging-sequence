#include<iostream>

using namespace std;

//���飬��ʼ���ȣ���Ҫ�����ĳ���
int greedy(int* arr, int len0, int len)
{
	//���պϲ���һ�����У������ټ����Ƚϣ�����0�αȽ�
	if (len == 2 * len0 - 1)
		return 0;
	//���еĳ�����಻����1000
	int min1 = 1000;
	int min2 = 1000;
	int index = -1;
	//�ҵ���һС����
	for (int i = 0; i < len; i++)
	{
		if (min1 > arr[i] && arr[i] != -1)
		{
			min1 = arr[i];
			index = i;
		}
	}
	arr[index] = -1;
	//�ҵ��ڶ�С����
	for (int i = 0; i < len; i++)
	{
		if (min2 > arr[i] && arr[i] != -1)
		{
			min2 = arr[i];
			index = i;
		}
	}
	arr[index] = -1;
	//��¼�����ɵ������г���
	arr[len] = min1 + min2;
	//�ϲ�һ�εıȽϴ�������ʣ�����еıȽϴ���
	return min1 + min2 - 1 + greedy(arr, len0, len + 1);
}

int main()
{
	int k;
	//���и���
	cout << "Please input the number of sequences:" << endl;
	cin >> k;
	//ÿ�����еĳ���
	cout << "Please input the length of sequences:" << endl;
	int* arr = new int[2 * k - 1]; //��Ŀռ����ڴ�źϲ������еĳ���
	for (int i = 0; i < k; i++) 
	{
		cin >> arr[i];
	}
	int sum = 0;
	sum = greedy(arr, k, k);
	cout << "The smallest numbers is:" << endl;
	cout << sum;
}
