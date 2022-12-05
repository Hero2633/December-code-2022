//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//void Swap(int* a, int* b)
//{
//	int tmp = *a;
//	*a = *b;
//	*b = tmp;
//}
//void QuickSort(int* nums, int left, int right)
//{
//	if (left >= right)
//		return;
//	int begin = left;
//	int end = right;
//	int cur = left;
//	int key = nums[cur];
//	while (cur <= right)
//	{
//		if (nums[cur] < key)
//		{
//			Swap(cur + nums, left + nums);
//			left++;
//			cur++;
//		}
//		else if (nums[cur] == key)
//			cur++;
//		else
//		{
//			Swap(nums+cur,nums+right);
//			right--;
//		}
//	}
//	QuickSort(nums, begin, left - 1);
//	QuickSort(nums,right+1,end);
//}
//void Merge(int* nums, int left, int right, int* tmp)
//{
//	if (left >= right)
//		return;
//	int mid = (right - left) / 2 + left;
//	Merge(nums, left, mid, tmp);
//	Merge(nums,mid+1,right,tmp);
//	int begin1 = left;
//	int end1 = mid;
//	int begin2 = mid + 1;
//	int end2 = right;
//	int k = left;
//	while (begin1<=end1&&begin2<=end2)
//	{
//		if (nums[begin1] < nums[begin2])
//		{
//			tmp[k++] = nums[begin1++];
//		}
//		else
//		{
//			tmp[k++] = nums[begin2++];
//		}
//	}
//	if (begin2 <= end2)//当左区间归并完过后，右区间还有剩余，那么没必要再去归并右区间了，直接将临时数组拷贝回去就行了；
//	{
//		memcpy(nums+left,tmp+left,(k-left) * sizeof(int));//注意此时的tmp元素数目
//		return;
//	}
//	while (begin1 <= end1)//左区间有剩余，继续归并左区间
//		tmp[k++] = nums[begin1++];
//	memcpy(nums+left,tmp+left,sizeof(int)* (k-left));
//}
//void MergeSort(int* nums, int len)
//{
//	int* tmp = (int*)malloc(sizeof(int) * len);
//	if (!tmp)
//		exit(-1);
//	Merge(nums,0,len-1,tmp);
//	free(tmp);
//}
//void MergeSortNoR(int* nums, int len)
//{
//	int* tmp = (int*)malloc(sizeof(int) * len);
//	if (!tmp)
//		exit(-1);
//	int gap = 1;
//	while (gap < len)
//	{
//		for (int i = 0; i < len; i+=2*gap)//i跳过一个大区间，来到下一个待归并的大区间
//		{
//			int begin1 = i, end1 = i + gap - 1;
//			int begin2 = i + gap, end2 = i + 2 * gap - 1;
//			if (end1 >= len || begin1 >= len)
//				break;
//			if (end2 >= len)
//				end2 = len - 1;
//			int k = begin1;
//			int left = begin1;
//			int right = end2;
//			while (begin1 <= end1 && begin2 <= end2)
//			{
//				if (nums[begin1] < nums[begin2])
//				{
//					tmp[k++] = nums[begin1++];
//				}
//				else
//				{
//					tmp[k++] = nums[begin2++];
//				}
//			}
//			if (begin2 <= end2)//当左区间归并完过后，右区间还有剩余，那么没必要再去归并右区间了，直接将临时数组拷贝回去就行了；
//			{
//				memcpy(nums +left, tmp + left, (k - left) * sizeof(int));//注意此时的tmp元素数目
//				continue;
//			}
//			while (begin1 <= end1)//左区间有剩余，继续归并左区间
//				tmp[k++] = nums[begin1++];
//			memcpy(nums + left, tmp + left, sizeof(int) * (k - left));
//			
//		}
//		gap *= 2;
//	}
//	free(tmp);
//}
//#include"Queue.h"
//#include"Stack.h"
//void MergeSortNoR1(int* nums, int len)
//{
//	int* tmp = (int*)malloc(sizeof(int) * len);
//	if (!tmp)
//		exit(-1);
//	Queue q;
//	QueueInit(&q);
//	Stack st;
//	StackInit(&st);
//	QueuePush(&q, 0);
//	QueuePush(&q,len-1);
//	//1、将区间入队列和进栈（两个操作一起进行）,时间复杂度度O(N)
//	while (false == QueueEmpty(&q))
//	{
//		int left = QueueFront(&q);
//		QueuePop(&q);
//		int right = QueueFront(&q);
//		QueuePop(&q);
//		StackPush(&st, right);
//		StackPush(&st,left);
//		int mid = (right - left) / 2 + left;
//		int begin1 = left, end1 = mid;
//		int begin2 = mid + 1, end2 = right;
//		if (left != right)
//		{
//			QueuePush(&q, begin1);
//			QueuePush(&q, end1);
//			QueuePush(&q, begin2);
//			QueuePush(&q, end2);
//		}
//	}
//	//2、开始进行归并排序O（N*logN）
//	while (StackSize(&st) > 2)
//	{
//		int begin2 = StackTop(&st);
//		StackPop(&st);
//		int end2 = StackTop(&st);
//		StackPop(&st);
//		int begin1 = StackTop(&st);
//		StackPop(&st);
//		int end1 = StackTop(&st);
//		StackPop(&st);
//		int left = begin1;
//		int right = end2;
//		int k = left;
//		while (begin1 <= end1 && begin2 <= end2)
//		{
//			if (nums[begin1] < nums[begin2])
//			{
//				tmp[k++] = nums[begin1++];
//			}
//			else
//			{
//				tmp[k++] = nums[begin2++];
//			}
//		}
//		if (begin2 <= end2)//当左区间归并完过后，右区间还有剩余，那么没必要再去归并右区间了，直接将临时数组拷贝回去就行了；
//		{
//			memcpy(nums + left, tmp + left, (k - left) * sizeof(int));//注意此时的tmp元素数目
//			continue;
//		}
//		while (begin1 <= end1)//左区间有剩余，继续归并左区间
//			tmp[k++] = nums[begin1++];
//		memcpy(nums + left, tmp + left, sizeof(int) * (k - left));
//	}
//	StackDestroy(&st);
//	QueueDestroy(&q);
//	free(tmp);
//}
//void test1()
//{
//	int nums[] = {9,1,2,3,4,5,6,7,8};
//	int len = sizeof(nums) / sizeof(int);
//	MergeSortNoR1(nums,len);
//	for (int i = 0; i < len; i++)
//		printf("%d ",nums[i]);
//}
//int main()
//{
//	test1();
//	return 0;
//}