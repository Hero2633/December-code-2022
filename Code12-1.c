#include"Stack.h"
void Swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void PrintfArr(int* nums, int len)
{
	for (int i = 0; i < len; i++)
		printf("%d ",i[nums]);
	printf("\n");
}
void Quick1(int*nums,int left,int right)//hoare版本
{
	if (left >= right)
		return;
	int keyi = left;
	int begin = left;
	int end = right;
	while (left < right)
	{
		while (left < right && nums[right] >= nums[keyi])
			right--;
		while (left < right && nums[left] <= nums[keyi])
			left++;
		Swap(left+nums,right+nums);
	}
	Swap(left+nums,keyi+nums);
	Quick1(nums, begin, left - 1);
	Quick1(nums,right+1,end);
}
void Quick2(int* nums, int left, int right)//挖坑法
{
	if (left >= right)
		return;
	int hole = left;
	int HoleKey = nums[hole];
	int begin = left;
	int end = right;
	while (left < right)
	{
		while (left < right && nums[right] >= HoleKey)
			right--;
		Swap(nums + right, hole + nums);
		hole = right;
		while (left < right && nums[left] <= HoleKey)
			left++;
			Swap(nums + left, nums + hole);
		hole = left;
	}
	nums[left] = HoleKey;
	Quick2(nums, begin, left - 1);
	Quick2(nums,right+1,end);

}
void Quick3(int*nums,int left,int right)//双指针法
{
	if (left >= right)
		return;
	int prev = left;
	int keyi = left;
	int cur = left + 1;
	int begin = left;
	int end = right;
	while (cur <= right)
	{
		if (nums[cur] >nums[keyi])
			cur++;
		else
			Swap(nums+(++prev), (cur++)+ nums);
	}
	Swap(keyi+nums,prev+nums);
	Quick3(nums, begin, prev - 1);
	Quick3(nums,prev+1,end);
}
void QuickSort(int*nums,int len)
{
	Quick3(nums,0,len-1);
}

/// ///////////////////////非递归

int QSortPrat(int* nums, int left, int right)
{
	int keyi = left;
	int prev = left;
	int cur = left + 1;
	while (cur <= right)
	{
		if (nums[cur] >= nums[keyi])
			cur++;
		else
		{
			prev++;
			Swap(nums+prev,nums+cur);
			cur++;
		}
	}
	Swap(nums+prev,nums+keyi);
	return prev;
}
void QuickSort2(int* nums, int len)//快排非递归
{
	Stack st;
	StackInit(&st);
	if (0 >= len-1)
		return;
	StackPush(&st, len - 1);
	StackPush(&st,0);
	while (StackEmpty(&st) == false)
	{
		int left = StackTop(&st);
		StackPop(&st);
		int right = StackTop(&st);
		StackPop(&st);
		int mid=QSortPrat(nums,left,right);
		if (mid + 1 < right)
		{
			StackPush(&st, right);
			StackPush(&st, mid + 1);
		}
		if (left < mid - 1)
		{
			StackPush(&st, mid-1);
			StackPush(&st,left);
		}
	}
	StackDestroy(&st);
}
void test1()
{
	int nums[] = {6,4,5,2,8,0,1,3,7,9,10};
	//int nums[] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 };
	int len = sizeof(nums) / sizeof(int);
	QuickSort2(nums,len);
	PrintfArr(nums,len);
}
int main()
{
	test1();
	return 0;
}