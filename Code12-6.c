#include<stdio.h>
#include<math.h>
#include<stdlib.h>
void CountSize(int* nums, int len)
{
	int max = nums[0];
	int min = nums[0];
	int absMin = 0;
	for (int i = 0; i < len; i++)
	{
		if (nums[i] > max)
			max = nums[i];
		if (nums[i] < min)
			min = nums[i];
	}
	if (min < 0)
		absMin = abs(min);
	int Countlen = max + absMin + 1;
	int* CountTmp = (int*)calloc(Countlen,sizeof(int));
	if (CountTmp == NULL)
		exit(-1);
	for (int i = 0; i < len; i++)
	{
		CountTmp[nums[i]+absMin]++;
	}
	int sum = 0;
	for (int i = 0; i < Countlen; i++)
	{
		for (int j = sum; j < CountTmp[i]+sum; j++)
		{
			nums[j] = i-absMin;
		}
		sum += CountTmp[i];
	}
	free(CountTmp);
}
void test1()
{
	int arr[] = {-1,-2,-3,-4,0,3,4,67,1,0,5,-9,-20,-99,-12,34};
	int len = sizeof(arr) / sizeof(int);
	CountSize(arr,len);
	for (int i = 0; i < len; i++)
		printf("%d ",arr[i]);
}
#define N 4
#define N 4
void test2()
{
	int arr[N][N] = { {1,1,1,1},{4,8,3,6},{1,0,1,2},{2,7,8,9} };
	int* col = (int*)malloc(sizeof(int) * N);
	int* row = (int*)malloc(sizeof(int) * N);
	if (!col || !row)
		exit(-1);
	for (int r = 0; r < N; r++)
	{
		int max = arr[r][0];
		for (int c = 0; c < N; c++)
		{
			if (arr[r][c] > max)
			{
				max = arr[r][c];
			}
		}
		row[r] = max;
	}
	for (int c = 0; c < N; c++)
	{
		int min = arr[0][c];
		for (int r = 0; r < N; r++)
		{
			if (arr[r][c] < min)
			{
				min = arr[r][c];
			}
		}
		col[c] = min;
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (arr[i][j] == col[j] && arr[i][j] == row[i])
			{
				printf("(x,y)=(%d,%d)\n",i,j);
			}
		}
	}
	free(col);
	free(row);
}
int main()
{
	test2();
	return 0;
}