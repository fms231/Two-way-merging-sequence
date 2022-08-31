#include<iostream>

using namespace std;

//数组，初始长度，需要遍历的长度
int greedy(int* arr, int len0, int len)
{
	//最终合并成一个序列，不用再继续比较，返回0次比较
	if (len == 2 * len0 - 1)
		return 0;
	//序列的长度最多不超过1000
	int min1 = 1000;
	int min2 = 1000;
	int index = -1;
	//找到第一小的数
	for (int i = 0; i < len; i++)
	{
		if (min1 > arr[i] && arr[i] != -1)
		{
			min1 = arr[i];
			index = i;
		}
	}
	arr[index] = -1;
	//找到第二小的数
	for (int i = 0; i < len; i++)
	{
		if (min2 > arr[i] && arr[i] != -1)
		{
			min2 = arr[i];
			index = i;
		}
	}
	arr[index] = -1;
	//记录新生成的新序列长度
	arr[len] = min1 + min2;
	//合并一次的比较次数加上剩余序列的比较次数
	return min1 + min2 - 1 + greedy(arr, len0, len + 1);
}

int main()
{
	int k;
	//序列个数
	cout << "Please input the number of sequences:" << endl;
	cin >> k;
	//每个序列的长度
	cout << "Please input the length of sequences:" << endl;
	int* arr = new int[2 * k - 1]; //多的空间用于存放合并后序列的长度
	for (int i = 0; i < k; i++) 
	{
		cin >> arr[i];
	}
	int sum = 0;
	sum = greedy(arr, k, k);
	cout << "The smallest numbers is:" << endl;
	cout << sum;
}
