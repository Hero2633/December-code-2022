////bool CheckPermutation(char* s1, char* s2) {
////    int ch1[26] = { 0 };
////    int ch2[26] = { 0 };
////    for (int i = 0; s1[i]; i++)
////    {
////        ch1[s1[i] - 'a']++;
////    }
////    for (int i = 0; s2[i]; i++)
////    {
////        ch2[s2[i] - 'a']++;
////    }
////    for (int i = 0; i < 26; i++)
////    {
////        if (ch1[i] != ch2[i])
////            return false;
////    }
////    return true;
////}
////bool canPermutePalindrome(char* s) {
////    int ch[128] = { 0 };
////    int flag = 0;
////    for (int i = 0; s[i]; i++)
////    {
////        ch[s[i]]++;
////    }
////    for (int i = 0; i < 128; i++)
////    {
////        if (ch[i] % 2)
////            flag++;
////    }
////    return flag > 1 ? false : true;
////}
////#include<stdio.h>
////#include<string.h>
//#pragma warning (disable:4996)
////char* f(char* str, char ch)
////{
////	char* it1 = str;
////	char* it2 = str;
////	while (*it2 != '\0')
////	{
////		while (*it2 == ch)
////		{
////			it2++;
////		} 
////		*it1++ = *it2++;
////	} 
////	return str;
////} 
////int main() {
////	char a[10];
////	strcpy(a, "abcdcccd");
////	printf("%s", f(a, 'c'));
////	return 0;
////}
//#include <stdio.h>
////#include <string.h>
////int main() {
////    int n = 0;
////    scanf("%d", &n);
////    getchar();
////    char ch[101] = { 0 };
////    for (int i = 0; i < n; i++)
////    {
////        gets(ch);
////        int len = strlen(ch);
////        if (len < 10)
////            printf("%s\n", ch);
////        else
////        {
////            printf("%c", ch[0]);
////            printf("%d", len - 2);
////            printf("%c\n", ch[len - 1]);
////        }
////    }
////    return 0;
////}
//#include<string.h>
//char* replaceSpaces(char* S, int length) {
//    char tmp[length + 1];
//    strncpy(tmp, S, length + 1);
//    int i = 0;
//    int j = 0;
//    for (i = 0; i < length; i++)
//    {
//        if (tmp[i] != ' ')
//            S[j++] = tmp[i];
//        else
//        {
//            S[j] = '%';
//            S[j + 1] = '2';
//            S[j + 2] = '0';
//            j += 3;
//        }
//    }
//    S[j] = '\0';
//    return S;
//////}
//int main()
//{
//    char s[50]="Mr John Smith";
//    replaceSpaces(s,13);
//   ///*s
//    printf("%s\n",s);
//    return 0;
//}
