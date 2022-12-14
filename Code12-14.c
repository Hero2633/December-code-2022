//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#pragma warning (disable:4996)
//int* GetNext(char const* str, int len)
//{
//	int* next = (int*)malloc(sizeof(int) * len);
//	if (!next)
//		exit(EXIT_FAILURE);
//	next[0] = -1;
//	int j = 0;
//	int k = -1;
//	while (j < len - 1)
//	{
//		if (k == -1 || str[j] == str[k])
//		{
//			next[j + 1] = k + 1;
//			k += 1;
//			j++;
//		}
//		else
//		{
//			k = next[k];
//		}
//	}
//	return next;
//}
//int KMP(char const* dest, const char* str)
//{
//	if (!str)
//		return 0;
//	int i = 0;
//	int j = 0;
//	int len1 = strlen(dest);
//	int len2 = strlen(str);
//	int* next = GetNext(str,len2);
//	while (i < len1)
//	{
//		while (j==-1||(i < len1 && j < len2 && dest[i] == str[j]))
//		{
//			i++;
//			j++;
//		}
//		if (j >= len2)
//		{
//			free(next);
//			return i - j;
//		}
//			j = next[j];
//	}
//	free(next);
//	return -1;
//}
//void test1()
//{
//	char dest[] ="abcabcdabcfkmjhuebd";
//	char str[] = "abcf";
//	int index = KMP(dest,str);
//	printf("%d\n",index);
//}
////#include <stdio.h>
////
////int main() {
////	int n = 0;
////	scanf("%d", &n);
////	if (!n)
////	{
////		printf("0\n");
////		return 0;
////	}
////	int tmp = n;
////	int i = 0;
////	char ch[10] = { 0 };
////	while (tmp)
////	{
////		sprintf(ch + i++, "%d", tmp % 10);
////		tmp /= 10;
////	}
////	printf("%s\n", ch);
////	return 0;
////}
////#include <stdio.h>
////#include<string.h>
////#include<stdlib.h>
////void reverse(char* ch, int left, int right)
////{
////	while (left < right)
////	{
////		char tmp = ch[left];
////		ch[left] = ch[right];
////		ch[right] = tmp;
////		left++;
////		right--;
////	}
////}
////int main() {
////	char ch[10001] = { 0 };
////	gets(ch);
////	int len = strlen(ch);
////	char* tmp = (char*)calloc(len+1, sizeof(char));
////	if (!tmp)
////		exit(EXIT_FAILURE);
////	int left = 0;
////	int right = 0;
////	right = left = len - 1;
////	int i = 0;
////	while (right >= 0)
////	{
////		while ((right >= 0) && ((ch[right] < 'a' || ch[right]>'z') && (ch[right] < 'A' || ch[right]>'Z')))
////			right--;
////		left = right;
////		while (left >= 0 && ((ch[left] >= 'a' && ch[left]<='z') || (ch[left] >='A' && ch[left]<='Z')))
////			left--;
////		//reverse(ch, left + 1, right);
////		strncpy(tmp + i, ch + left+1, sizeof(char) * (right - left));
////		i += (right - left);
////		tmp[i++] = ' ';
////		right = left;
////	}
////	tmp[--i] = '\0';
////	strcpy(ch, tmp);
////	free(tmp);
////	printf("%s\n", ch);
////	return 0;
////}
////#include <stdio.h>
////
////int FicBo(int n)
////{
////	int a = 1;
////	int b = 1;
////	int c = 0;
////	if (n <= 2)
////		return 1;
////	int i = 3;
////	while (i <= n)
////	{
////		c = a + b;
////		a = b;
////		b = c;
////		i++;
////	}
////	return c;
////}
////int main() {
////	int n = 0;
////	scanf("%d", &n);
////	printf("%d\n", FicBo(n));
////	return 0;
////}
////int main()
////{
////	test1();
////	char* str = "dd%dd";
////	printf(str);
////	return 0;
////}
////#include <stdio.h>
////#include<math.h>
////int main() {
////	int n = 0;
////	int m = 0;
////	while (EOF != scanf("%d%d", &n, &m))
////	{
////		double sum = 0.0;
////		double num = 0.0;
////		double key = n;
////		for (int i = 0; i < m; i++)
////		{
////			sum += key;
////			key = pow(key, 0.5);
////		}
////		printf("%.2lf\n", sum);
////	}
////
////	return 0;
////}
////int* masterMind(char* solution, char* guess, int* returnSize) {
////	int* answer = (int*)calloc(2, sizeof(int));
////	*returnSize = 2;
////	int i = 0;
////	for (i = 0; i < 4; i++)
////	{
////		if (solution[i] == guess[i])
////			answer[0]++;
////	}
////	int count = 0;
////	int tmp[26] = { 0 };
////	for (i = 0; i < 4; i++)
////		tmp[solution[i] - 'A']++;
////	for (i = 0; i < 4; i++)
////	{
////		if (tmp[guess[i] - 'A'])
////		{
////			count++;
////			tmp[guess[i] - 'A']--;
////		}
////	}
////	answer[1] = count - answer[0];
////	return answer;
////}
////struct Node
////{
////    int index;
////    int val;
////};
////void ShellSort(struct Node* nums, int len)
////{
////    int gap = len;
////    while (gap > 1)
////    {
////        gap /= 2;
////        for (int j = 0; j < gap; j++)
////        {
////            for (int i = j; i < len - gap; i += gap)
////            {
////                int end = i;
////                struct Node key = nums[end + gap];
////                while (end >= 0)
////                {
////                    if (key.val >= nums[end].val)
////                        break;
////                    else
////                    {
////                        nums[end + gap] = nums[end];
////                        end -= gap;
////                    }
////                }
////                nums[end + gap] = key;
////            }
////        }
////    }
////}
////int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
////
////    struct Node tmp[numsSize];
////    *returnSize = 2;
////    int* ret = (int*)malloc(sizeof(int) * (*returnSize));
////    for (int i = 0; i < numsSize; i++)
////    {
////        tmp[i].index = i;
////        tmp[i].val = nums[i];
////    }
////    //2¡¢ÅÅÐò
////    ShellSort(tmp, numsSize);
////    printf("1");
////    //3¡¢ÕÒÊý
////    int left = 0;
////    int right = numsSize - 1;
////    int sum = tmp[right].val + tmp[left].val;
////    while (sum != target)
////    {
////        if (sum > target)
////            right--;
////        else
////            left++;
////        sum = tmp[right].val + tmp[left].val;
////    }
////    ret[0] = tmp[left].index;
////    ret[1] = tmp[right].index;
////    return ret;
////}
//#include<stdio.h>
//
//void sort2(int* a, int* b, int* c)
//{
//	int* i = a, * j = b, k = 0;
//	for (k = 0; k < 10; k++)
//	{
//		if (*i < *j)
//		{
//			*(c + k) = *i;
//			i++;
//		}
//		else
//		{
//			*(c + k) = *j;
//			j++;
//		}
//	}
//}
//
//void sort(int* a)
//{
//	int* i, * j, k;
//	for (i = a; i - a < 5; i++)
//	{
//		for (j = a; j - a < 5 - (i - a) - 1; j++)
//		{
//			if (*(j + 1) < *j)
//			{
//				k = *j;
//				*j = *(j + 1);
//				*(j + 1) = k;
//			}
//		}
//	}
//}
//
//int main()
//{
//	int a[5] = { 2,3,4,5,6 }, b[5] = { 1,2,2,3,4 }, c[10] = {0};
//	int i;
//	//printf("Please input 5 numbers for a[5]\n");
//	//for (i = 0; i < 5; i++)
//	//	scanf_s("%d", &a[i]);
//	//printf("Please input 5 numbers for b[5]\n");
//	//for (i = 0; i < 5; i++)
//	//	scanf_s("%2d", &b[i]);
//	sort(a);
//	sort(b);
//	for (i = 0; i < 5; i++)
//		printf("%2d", a[i]);
//	printf("\n");
//	for (i = 0; i < 5; i++)
//		printf("%2d", b[i]);
//	printf("\n");
//	sort2(a, b, c);
//	for (i = 0; i < 10; i++)
//		printf("%2d", c[i]);
//	return 0;
//}