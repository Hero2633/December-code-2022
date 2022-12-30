#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#pragma warning (disable:4996)
//char* compressString(char* S) {
//    int len = strlen(S);
//    char* tmp = (char*)calloc(len, sizeof(char));
//    int target = 0;
//    int cur = 0;
//    int space = 0;
//    int j = 0;
//    while (cur < len)
//    {
//        while (cur < len && S[target] == S[cur])
//            cur++;
//        char ch[10] = { 0 };
//        space = sprintf(ch, "%d", cur - target);
//        if (j + space + 1 >= len)//Ô¤ÅÐÒ»ÊÖ
//            return S;
//        tmp[j++] = S[target];
//        sprintf(tmp + j, "%d", cur - target);
//        j += space;
//        target = cur;
//    }
//    return tmp;
//}
//int main()
//{
//    char a[] = "a";
//    compressString(a);
//    return 0;
//}
//int exchangeBits(int num) {
//	return ((num & 0xaaaaaaaa) >> 1) | ((num & 0x55555555) << 1);
//}