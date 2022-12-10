#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
void Swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void PrintArr(int* nums, int len)
{
	int i = 0;
	for (i = 0; i < len; i++)
		printf("%d ",nums[i]);
	printf("\n");
}
void BubleSort(int* nums, int len)//时间复杂度O（N^2）//空间复杂度O(1)//稳定
{
	int i = 0;
	int j = 0;
	int flag = 0;
	for (i = 0; i < len - 1; i++)
	{
		flag = 0;
		for (int j = 0; j < len - 1-i; j++)
		{
			if (nums[j] > nums[j + 1])
			{
				Swap(nums+j,nums+j+1);
				flag = 1;
			}
		}
		if (!flag)
			break;
	}
}
int GetMid(int* nums, int left, int right)
{
	int mid = rand() % (right - left + 1) + left;
	if (nums[mid] > nums[left])
	{
		if (nums[mid] < nums[right])
			return mid;
		else
		{
			if (nums[left] > nums[right])
				return right;
			else
			{
				return left;
			}
		}
	}
	else
	{
		if (nums[mid] > nums[right])
			return mid;
		else
		{
			if (nums[left] < nums[right])
				return left;
			else
			{
				return right;
			}
		}
	}
}
void InsertSort(int* nums, int len)//时间复杂度:O(N^2)//空间复杂度：O(1)//稳定
{
	int i = 0;
	for (i = 0; i < len - 1; i++)
	{
		int end=i;
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
int PartSort1(int* nums, int left, int right)
{
	int mid = GetMid(nums,left,right);
	Swap(nums+left,nums+mid);
	int keyi = left;
	while (left < right)
	{
		while (left < right && nums[right] >= nums[keyi])
			right--;
		while (left < right && nums[left] <= nums[keyi])
			left++;
		Swap(nums+left,right+nums);
	}
	Swap(nums+keyi,nums+left);
	return right;
}
int PartSort2(int* nums, int left, int right)
{
	int mid = GetMid(nums, left, right);
	Swap(nums + left, nums + mid);
	int hole = left;
	int key = nums[hole];
	while (left < right)
	{
		while (left < right && nums[right] >= key)
			right--;
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
int PartSort3(int* nums, int left, int right)
{
	int mid = GetMid(nums, left, right);
	Swap(nums + left, nums + mid);
	int prev = left;
	int cur = prev + 1;
	int keyi = left;
	while (cur <= right)
	{
		if (nums[cur] <nums[keyi]&&++prev!=cur)
		{
			Swap(nums+prev,nums+cur);
		}
		cur++;
	}
	return prev;
}
void QuickSort(int*nums,int left,int right)//时间复杂度:O（N*logN）//空间复杂度O(logN)//不稳定
{
	if (left >= right)
		return;
	if ((right - left + 1) < 10)
	{
		InsertSort(nums+left,(right-left+1));
		return;
	}
	int mid = PartSort3(nums,left,right);
	QuickSort(nums, left, mid - 1);
	QuickSort(nums,mid+1,right);
}
void QuickSort2(int* nums, int left, int right)
{
	if (left >= right)
		return;
	int begin = left;
	int end = right;
	int cur = left + 1;
	int key = nums[left];
	while (cur <= right)
	{
		if (nums[cur] > key)
		{
			Swap(nums + cur, nums + right--);
		}
		else if (nums[cur] < key)
			Swap(nums+cur++,nums+left++);
		else
		{
			cur++;
		}
	}
	QuickSort2(nums, begin, left - 1);
	QuickSort2(nums,right+1,end);

}
#include"Stack.h"
#include"Queue.h"
void QuickSortNoR1(int* nums, int len)
{
	Stack st;
	StackInit(&st);
	StackPush(&st, len-1);
	StackPush(&st,0);
	while (!StackEmpty(&st))
	{
		int left = StackTop(&st);
		StackPop(&st);
		int right = StackTop(&st);
		StackPop(&st);
		int mid = PartSort1(nums,left,right);
		if (left < mid - 1)
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
void QuickSortNoR2(int* nums, int len)
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 0);
	QueuePush(&q,len-1);
	while (!QueueEmpty(&q))
	{
		int left = QueueFront(&q);
		QueuePop(&q);
		int right = QueueFront(&q);
		QueuePop(&q);
		int mid = PartSort1(nums,left,right);
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
void SelectSort(int* nums, int len)//时间复杂度：O（N^2）//空间复杂度：O（1）//不稳定
{
	int left = 0;
	int right = len - 1;
	while (left < right)
	{
		int maxi = left;
		int mini = left;
		for (int i = left; i <= right; i++)
		{
			if (nums[i] > nums[maxi])
				maxi = i;
			if (nums[i] < nums[mini])
				mini = i;
		}
		if (maxi == left)
			maxi = mini;
		Swap(nums + left, nums + mini);
		Swap(nums+right,nums+maxi);
		left++;
		right--;
	}
}
void AdjustDown(int* nusm, int top, int end)
{
	int parent = top;
	int child = 2 * top + 1;
	while (child < end)
	{
		if (child + 1 < end && nusm[child + 1] > nusm[child])
			child++;
		if (nusm[parent] >= nusm[child])
			break;
		else
		{
			Swap(nusm+parent,nusm+child);
			parent = child;
			child = 2 * parent + 1;
		}
	}
}
void HeapSort(int*nums,int len)//时间复杂度:O(N*logN)//空间复杂度：O（1）//不稳定
{
	for (int top = (len - 1 - 1) / 2; top >= 0; top--)
	{
		AdjustDown(nums,top,len);
	}
	int size = len;
	while (size > 1)
	{
		Swap(nums,nums+size-1);
		size--;
		AdjustDown(nums,0,size);
	}
}
void ShellSort(int* nums, int len)//时间复杂度:O^1.3 //空间复杂度：O（1）//不稳定
{
	int gap = len;
	while (gap > 1)
	{
		gap /= 2;
		for (int j = 0; j < gap; j++)
		{
			for (int i = j; i < len - gap; i += gap)
			{
				int end = i;
				int key = nums[end + gap];
				while (end >= 0)
				{
					if (key >= nums[end])
						break;
					else
					{
						nums[end + gap] = nums[end];
						end -= gap;
					}
				}
				nums[end + gap] = key;
			}
		}
	}
}
void Merge(int* nums, int left, int right,int*tmp)
{
	if (left >= right)
		return;
	int mid = (right - left) / 2 + left;
	int begin1 = left;
	int end1 = mid;
	int begin2 = mid + 1;
	int end2 = right;
	int k = left;
	Merge(nums, left, mid, tmp);
	Merge(nums,mid+1,right,tmp);
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (nums[begin1] <= nums[begin2])
			tmp[k++] = nums[begin1++];
		else
		{
			tmp[k++] = nums[begin2++];
		}
	}
	if (begin2 <= end2)
	{
		memcpy(nums+left,tmp+left,(k-left)*sizeof(int));
		return;
	}
	while (begin1 <= end1)
	{
		tmp[k++] = nums[begin1++];
	}
	memcpy(nums+left,tmp+left,(k-left)*sizeof(int));
}
void MergeSort(int* nums, int len)//时间复杂度：O（N*logN）//空间复杂度：O（N）//稳定
{
	int* tmp = (int*)malloc(sizeof(int)*len);
	if (!tmp)
		exit(EXIT_FAILURE);
	Merge(nums,0,len-1,tmp);
	free(tmp);
}
void MergeNoR(int* nums, int len)
{
	int* tmp = (int*)malloc(sizeof(int) * len);
	if (!tmp)
		exit(EXIT_FAILURE);
	int gap = 1;
	while (gap < len)
	{
		for (int i = 0; i < len; i += 2 * gap)
		{
			int begin1 = i;
			int end1 = i + gap - 1;
			int begin2 = i + gap;
			int end2 = i + 2 * gap - 1;
			int k = begin1;
			int left = begin1;
			if (end1 >= len || begin1 >= len)
				break;
			if (end2 >= len)
				end2 = len - 1;
			while (begin1 <= end1 && begin2 <= end2)
			{
				if (nums[begin1] <= nums[begin2])
					tmp[k++] = nums[begin1++];
				else
				{
					tmp[k++] = nums[begin2++];
				}
			}
			if (begin2 <= end2)
			{
				memcpy(nums + left, tmp + left, (k - left) * sizeof(int));
				continue;
			}
			while (begin1 <= end1)
			{
				tmp[k++] = nums[begin1++];
			}
			memcpy(nums + left, tmp + left, (k - left) * sizeof(int));
		}
		gap *= 2;
	}
}
void test1()
{
	int arr[] = {3,0,2,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,33,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,6,66,6,1,4,7,3,5};
	int len = sizeof(arr) / sizeof(int);
	QuickSort2(arr,0,len-1);
	PrintArr(arr,len);
} 
int main()
{
	test1();
	return 0;
}