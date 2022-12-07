//#include<stdio.h>
//#include<math.h>
//#pragma warning (disable:4996)
//#define d 5e-3
//#define n 1.83e-5
//#define l 1.6e-3
//#define p 981
//#define g 9.792
//#define b 0.00823
//#define pa 101325
//#define PI 3.1415926
//#define e 1.602176634e-19
//int main()
//{
//	/*double t = 0.0;
//	double V = 0.0;
//	scanf("%lf%lf",&t,&V);
//	double v = l / t;
//	double a = pow((9*n*v)/(2*p*g),0.5);
//	printf("a=%e\n", a);
//	double K = ((18 * PI) / pow(2 * p * g, 0.5)) * d * pow(n*l/(1+b/(pa*a)), 1.5);
//	printf("K=%e\n", K);
//	double q = K * pow(1 / t, 1.5) * (1.0 / V);
//	printf("q=%e\n",q);
//	printf("n=%d\n",(int)(q/e));*/
//	double q1 = 5.34376e-19 / 3;
//	double q2 = 7.010144e-19 / 4;
//	double q3 = 7.021933e-19 / 4;
//	double E;
//	printf("e=%e\n",E=((q1+q2+q3)/3));
//	printf("x=%e\n",fabs(E-e)/e);
//
//	return 0;
//}
#include<stdio.h>
void Swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
int PartSort(int* nums, int left, int right)
{
	int keyi = left;
	int prev = left;
	int cur = prev + 1;
	while (cur <= right)
	{
		if (nums[cur] < nums[keyi] && ++prev != cur)
			Swap(nums + cur++, nums + prev);
		else
			cur++;
	}
	Swap(nums+keyi,nums+prev);
	return prev;
}
void QuickSort(int* nums, int left, int right)
{
	if (left >= right)
		return;
	/*int mid = PartSort(nums,left,right);*/
	int mia = 0;
	int begin = left;
	int end = right;
	int cur = begin + 1;
	int key = nums[begin];
	while (cur <= right)
	{
		if (nums[cur] > key)
		{
			Swap(nums+cur,nums+right);
			right--;
		}
		else if(nums[cur]<key)
		{
			Swap(nums+left,nums+cur);
			cur++;
			left++;
		}
		else
		{
			cur++;
		}
	}
	QuickSort(nums, begin, left-1);
	QuickSort(nums,right+1,end);
}
void test1()
{
	int arr[] = {4,3,5,2,6,7,1,3,9};
	int len = sizeof(arr) / sizeof(int);
	QuickSort(arr,0,len-1);
	for (int i = 0; i < len; i++)
		printf("%d ",arr[i]);
}
int main()
{
	test1();
	return 0;
}