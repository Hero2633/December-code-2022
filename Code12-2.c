#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include"Stack.h"
#include"Queue.h"
void Swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void PrintfArr(int* nums, int len)
{
	for (int i = 0; i < len; i++)
		printf("%d ",nums[i]);
	printf("\n");
}
int GetMid(int* nums, int left, int right)
{
	int mid = (right - left) / 2 + left;
	if (nums[mid] > nums[left])
	{
		if (nums[mid] < nums[right])
			return mid;
		else
		{
			if (nums[left] > nums[right])
				return left;
			else
				return right;
		}
	}
	else
	{
		if (nums[mid] > nums[right])
			return mid;
		else
		{
			if (nums[right] < nums[left])
				return right;
			else
				return left;
		}
	}
}
int PartSort1(int* nums, int left, int right)
{
	int mid = GetMid(nums, left, right);//优化--三数取中
	Swap(nums + left, nums + mid);
	int keyi = left;
	while (left < right)
	{
		while (left < right && nums[right] >= nums[keyi])
			--right;
		while (left < right && nums[left] <= nums[keyi])
			++left;
		Swap(left+nums,right+nums);
	}
	Swap(nums+keyi,nums+left);
	return left;
}
int PartSort2(int* nums, int left, int right)
{
	int mid = GetMid(nums, left,right);//优化--三数取中
	Swap(nums+left, nums + mid);
	int hole = left;
	int key = nums[hole];
	while (left < right)
	{
		while (left < right && nums[right] >= key)
			--right;
		nums[hole] = nums[right];
		hole = right;
		while (left < right && nums[left] <= key)
			left++;
		nums[hole] = nums[left];
		hole = left;
	}
	nums[hole] = key;
	return hole;
}
int PartSort3(int* a, int begin, int end)
{
	int mid = GetMid(a,begin,end);//优化--三数取中
	Swap(a+begin,a+mid);
	int prev = begin;
	int cur = prev + 1;
	int keyi = begin;
	while (cur <= end)
	{
		if (a[cur] < a[keyi] && ++prev != cur)
			Swap(cur+a,a+prev);
		cur++;
	}
	Swap(keyi+a,a+prev);
	return prev;
}
void InsertSort(int* nums, int len)
{
	for (int i = 0; i < len - 1; i++)
	{
		int end = i;
		int key = nums[end + 1];
		while (end >= 0)
		{
			if (key >= nums[end])
				break;
			else
			{
				nums[end + 1] = nums[end];
				end--;
			}
		}
		nums[end + 1] = key;
	}
}
void QuickSort(int* nums,int left ,int right)
{
	if (left >= right)
		return;
	if (right - left + 1 <= 15)//小区间优化
	{
		InsertSort(nums+left,right-left+1);
		return;
	}
	int hole = PartSort1(nums,left,right);
	QuickSort(nums, left, hole - 1);
	QuickSort(nums,hole+1,right);
}
void QuickSortStack(int* nums, int left,int right)
{
	Stack st;
	StackInit(&st);
	StackPush(&st, right);
	StackPush(&st,left);
	while (StackEmpty(&st) == false)
	{
		int left = StackTop(&st);
		StackPop(&st);
		int right = StackTop(&st);
		StackPop(&st);
		if (right - left + 1 < 15)//小区间优化
		{
			InsertSort(nums+left,right-left+1);
			continue;
		}
		int mid = PartSort1(nums, left,right);
		if (mid -1> left)
		{
			StackPush(&st, mid - 1);
			StackPush(&st,left);
		}
		if (mid + 1 < right)
		{
			StackPush(&st, right);
			StackPush(&st,mid+1);
		}
	}
	StackDestroy(&st);
}
void QuickSortQueue(int* nums, int left, int right)
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, left);
	QueuePush(&q,right);
	while (!QueueEmpty(&q))
	{
		int left = QueueFront(&q);
		QueuePop(&q);
		int right = QueueFront(&q);
		QueuePop(&q);
		if (right - left + 1 < 15)//小区间优化
		{
			InsertSort(nums + left, right - left + 1);
			continue;
		}
		int mid = PartSort2(nums,left,right);
		if (left < mid - 1)
		{
			QueuePush(&q, left);
			QueuePush(&q,mid-1);
		}
		if (mid + 1 < right)
		{
			QueuePush(&q, mid + 1);
			QueuePush(&q,right);
		}
	}
	QueueDestroy(&q);
}
void test1()
{
	int arr[] = {6,1,2,7,9,5,5,5,5,5,5,53,4,5,10,83,44,54,6,57,68,7,87};
	int len = sizeof(arr) / sizeof(int);
	/*int len = 100000000;
	int* arr = (int*)malloc(sizeof(int) * len);
	if (!arr)
		return;
	for (int i = 0; i < len; i++)
	{
		arr[i] = rand()+i;
	}*/
	clock_t begin = clock();
	QuickSortQueue(arr,0,len-1);
	clock_t end = clock();
	printf("%ld\n",end-begin);
	PrintfArr(arr,len);
}


int main()
{
	srand((size_t)time(NULL));
	test1();
	return 0;
}