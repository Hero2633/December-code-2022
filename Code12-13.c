#include<stdio.h>
#pragma warning (disable:4996)
//#define L 47.123e-2
//#define N 600
//#define R1 2
//#define R2 11e3
//#define n 75
//#define S 1.3273e-6
//#define C2 1e-6
//int main() {
//	double u1;
//	double u2;
//	scanf("%lf%lf",&u1,&u2);
//	u1 = u1 * 1e-3;
//	u2 = u2 * 1e-3;
//	double H = (N * u1) / (L * R1);
//	double B = (C2 * R2 * u2) / (n * S);
//	printf("H=%lf A/m\nB=%lf T",H,B);
//
//	return 0;
//}
//#include<string.h>
//#include<stdlib.h>
//int* GetNext(char* str, int len)
//{
//	int* next = (int*)malloc(sizeof(int) * len);
//	if (!next)
//		exit(EXIT_FAILURE);
//	next[0] = -1;
//	int j = 0;
//	int k = next[0];
//	while (j < len - 1)
//	{
//		if ((j+1<len)&&(k == -1 || str[k] == str[j]))
//	   {		
//		next[j + 1] = k + 1;
//		k += 1;
//		j++;
//	   }
//		else
//		{
//			k = next[k];
//		}
//	}
//	return next;
//}
//int KMP(char* dest, char* str)
//{
//	if (!str)
//		return 0;
//	int i = 0;
//	int j = 0;
//	int len1 = strlen(dest);
//	int len2 = strlen(str);
//	int* next = GetNext(str,len2);
//	while (i<len1)
//	{
//		while (j==-1||i < len1 && j < len2 && dest[i] == str[j])
//		{
//			i++;
//			j++;
//		}
//		if (j >= len2)
//		{
//			free(next);
//			return i - j;
//		}
//		j = next[j];
//	}
//	free(next);
//	return -1;
//}
//int main()
//{
//	char ch1[] = "abcabcdgffjdhk";
//	char ch2[] = "abfcd";
//	int ret = KMP(ch1,ch2);
//	printf("%d\n",ret);
//	return 0;
//}