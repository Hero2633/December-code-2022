#include<stdio.h>
#include<time.h>
#include<stdlib.h>
void Swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void PrintfArr(int* nums, int len)
{
	for (int i = 0; i < len; i++)
		printf("%d ", nums[i]);
	printf("\n");
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
			if (nums[right] > nums[left])
				return right;
			else
				return left;
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
void InsertSort(int* nums, int len)
{
	for (int i = 0; i < len - 1; i++)
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
void PartSort(int* nums, int begin, int end)
{
	if (begin >= end)
		return;
	if (end - begin + 1 < 10)
	{
		InsertSort(nums + begin, end - begin + 1);
		return;
	}

	int mid = GetMid(nums, begin, end);
	Swap(nums + mid, nums + begin);
	int cur = begin;
	int left = begin;
	int right = end;
	int key = nums[left];
	while (cur <= right)
	{
		if (nums[cur] < key)
		{
			Swap(nums + cur++, left++ + nums);
		}
		else if (nums[cur] == key)
			cur++;
		else
		{
			Swap(nums + cur, right-- + nums);
		}
	}
	PartSort(nums, begin, left - 1);
	PartSort(nums, right + 1, end);
}
void QuickSort(int* nums, int begin, int end)
{
	PartSort(nums,begin,end);
}
void test1()
{
	int nums[] = {1,2,3,4,5,6,7,8,9,0,6,7,6,3,6,1,6,9,6,3};
	int len = sizeof(nums) / sizeof(int);

	QuickSort(nums,0,len-1);//��·����,��������ظ����ݵ�����
	
}
void Merge(int* nums, int left, int right,int*tmp)
{
	if (left >= right)
		return;
	int mid = (right - left) / 2 + left;
	Merge(nums, left, mid,tmp);
	Merge(nums,mid+1,right,tmp);
	int begin1 = left, end1 = mid;
	int begin2 = mid + 1, end2 = right;
	int k = left;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (nums[begin1] < nums[begin2])
			tmp[k++] = nums[begin1++];
		else
			tmp[k++] = nums[begin2++];
	}
	if (begin2 <= end2)
	{
		for (int i = left; i < k; i++)
			nums[i] = tmp[i];
		return;
	}
	while (begin1 <= end1)
		tmp[k++] = nums[begin1++];
	for (int i = left; i < k; i++)
		nums[i] = tmp[i];
}
void Mergeort(int*nums,int len)
{
	int* tmp = (int*)malloc(sizeof(int)*len);
	if (!tmp)
		exit(-1);
	Merge(nums,0,len-1,tmp);
	free(tmp);
}
#include"Queue.h"
#include"Stack.h"
void MergeStackQueue(int* nums, int len)
{
	int* tmp = (int*)malloc(sizeof(int) * len);
	if (!tmp)
		exit(-1);
	Stack st;
	StackInit(&st);
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 0);
	QueuePush(&q,len-1);
	//1�����������ò��������ջO(N)
	while (QueueEmpty(&q) == false)
	{
		int left = QueueFront(&q);
		QueuePop(&q);
		int right = QueueFront(&q);
		QueuePop(&q);
		StackPush(&st, right);
		StackPush(&st,left);
		if (left != right)//������û�к��ӽڵ㣬�亢�Ӳ������
		{
			int mid = (right - left) / 2 + left;
			//��[left,mid] [mid+1,right] �����
			QueuePush(&q, left);
			QueuePush(&q, mid);
			QueuePush(&q, mid+1);
			QueuePush(&q,right);
		}
	}
	//2����ʼ��������й鲢����ÿ�δ�ջ�е�����������O(n*logn)
	int begin1=0;
	int end1=0;
	int begin2=0;
	int end2=0;
	while (StackSize(&st) > 2)
	{
		begin2 = StackTop(&st);
		StackPop(&st);
		end2 = StackTop(&st);
		StackPop(&st);
		begin1 = StackTop(&st);
		StackPop(&st);
		end1= StackTop(&st);
		StackPop(&st);
		int L = begin1, R = end2;//����С����ϲ���һ��������
		int k = L;
		while (begin1 <= end1 && begin2 <= end2)
		{
			if (nums[begin1] < nums[begin2])
				tmp[k++] = nums[begin1++];
			else
				tmp[k++] = nums[begin2++];
		}
		if (begin2 <= end2)//����ȹ��꣬�ұ߻���ʣ�࣬�ұ߲���Ҫ�����鲢��ֱ�ӿ���ԭ����ͺ���
		{
			for (int i = L; i < k; i++)
				nums[i] = tmp[i];
			continue;
		}
		while (begin1 <= end1)
			tmp[k++] = nums[begin1++];
		for (int i = L; i < k; i++)
			nums[i] = tmp[i];
	}
	free(tmp);
	StackDestroy(&st);
	QueueDestroy(&q);
}
void MergeSortNoR(int* nums, int len)
{
	int* tmp = (int*)malloc(sizeof(int) * len);
	if (!tmp)
		exit(-1);
	int gap = 1;//ÿ��С�����Ԫ�ظ���
	while (gap < len)
	{
		for (int i = 0; i < len; i +=2*gap)
		{
			int begin1 = i, end1 = i + gap - 1;
			int begin2 = i + gap, end2 = 2 * gap - 1+i;
			int L = begin1;
			int R = end2;
			int k = begin1;
			if (end1 >= len || begin2 >= len)//end1Խ��,begin2ҲԽ�磬˵���ҵ��Ұ����䲻���ڣ��ҾͲ��������¹鲢��
				break;
			else if (end2 >= len)//������ֻ����һ���֣���������һ��
				end2 = len - 1;
			//���½��й鲢
			while (begin1 <= end1 && begin2 <= end2)
			{
				if (nums[begin1] < nums[begin2])
					tmp[k++] = nums[begin1++];
				else
					tmp[k++] = nums[begin2++];
			}
			if (begin2 <= end2)//����ȹ��꣬�ұ߻���ʣ�࣬�ұ߲���Ҫ�����鲢��ֱ�ӿ���ԭ����ͺ���
			{
				for (int i = L; i < k; i++)
					nums[i] = tmp[i];
				continue;
			}
			while (begin1 <= end1)
				tmp[k++] = nums[begin1++];
			for (int i = L; i < k; i++)
				nums[i] = tmp[i];
		}
		gap *= 2;
	}
	free(tmp);
}
void test2()
{
	int nums[] = {9,8,7,6,5,4,3,2,1 };
	int len = sizeof(nums) / sizeof(int);
	MergeSortNoR(nums,len);
	PrintfArr(nums,len);
}
int main()
{
	test2();
	return 0;
}