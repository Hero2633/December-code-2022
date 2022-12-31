#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#pragma warning (disable:4996)
int getInt(char n)//��'0'-'9'ת��Ϊ0-9��'a'-'z'ת����10-35
{
	if (n >= '0' && n <= '9')
		return n - '0';
	else
	{
		return n - 'a' + 10;
	}
}

char getChar(int n)//��0-9ת��Ϊ'0'-'9';a-zת���ɡ�a'-��z'
{
	if (n >= 0 && n <= 9)
		return n + '0';
	else
		return n - 10 + 'a';
}
void My_reverse(char* res,int left,int right)
{
	while (left < right)
	{
		char tmp = res[left];
		res[left] = res[right];
		res[right] = tmp;
		left++;
		right--;
	}
}
char* Add36(char* c1, char* c2)
{
	int len1 = (int)strlen(c1);
	int len2 = (int)strlen(c2);
	char* res = (char*)calloc((len1+len2+1),sizeof(char));
	if (!res)
		exit(EXIT_FAILURE);
	int i = len1 - 1;
	int j = len2 - 1;
	int tail = 0;
	int k = 0;
	while (j > -1 && i > -1)
	{
		int x = getInt(c1[i]);
		int y = getInt(c2[j]);
		int tmp = (x + y + tail) % 36;//������Ϊ��λ���
		tail = (x + y + tail) / 36;//�̵Ļ���Ϊ��λ
		res[k] = getChar(tmp);
		j--;
		--i;
		k++;
	}
	while (j > -1)//c1�����Ԫ�������ˣ�c2���滹��ʣ��
	{
		int y = getInt(c2[j]);
		int tmp = (y + tail) % 36;//������Ϊ��λ���
		tail = (y + tail) / 36;//��λ
		res[k] = getChar(tmp);
		j--;
		k++;
	}
	while (i > -1)//c2�����Ԫ�������ˣ�c1���滹��ʣ��
	{
		int x = getInt(c1[i]);
		int tmp = (x + tail) % 36;//������Ϊ��λ���
		tail = (x + tail) / 36;//��λ
		res[k] = getChar(tmp);
		i--;
		k++;
	}
	while (tail)//c1��c2�������ˣ����ǻ��н�λ��Ҫ�ѽ�λ����
	{
		int tmp = (tail) % 36;//������Ϊ��λ���
		tail = (tail) / 36;//��λ
		res[k] = getChar(tmp);
		k++;
	}
	My_reverse(res, 0,k-1);//���Ļ����ֲ�Ԫ��ת��һ�£�
	return res;
}
int multiply(int A, int B) {
	if (!A || !B)
		return 0;
	return A + multiply(A, B - 1);
}
//int main()
//{
//	char* s1 = "sb";
//	char* s2 = "2b";
//	char* ret = Add36(s1,s2);
//	printf(ret);
//
//	return 0;
//}
#include <stdio.h>
#include<stdbool.h>
bool is_relateSeven(int n)
{
	if (n % 7 == 0)
		return true;
	else
	{
		while (n)
		{
			if (n % 10== 7)
				return true;
			else
				n /= 10;
		}
	}
	return false;
}
int main() {

	int n = 0;
	int count = 0;
	scanf("%d", &n);
	for (int i = 7; i <=n; i++)
	{
		if (is_relateSeven(i))
		{
			count++;
			printf("%d\n", i);
		}
	}
	printf("%d\n", count);
	return 0;
}