//#include<stdio.h>
//#define WEIGHT 10000
//#include<string.h>
//int FirstNotRepeatingChar(char* str) {
//    // write code here
//    int ch[26] = { 0 };
//    int last = 0;//每个字母最后一次出现的位置
//    int count = 0;//每个字母出现的次数
//    int message = 0;//每个字母的信息=count*WEIGHT+last
//    //给每个字母的信息初始化
//    int len = strlen(str);
//    int arr[26] = { 0 };
//    for (int i = 0; i < len; i++)
//    {
//        message = ch[str[i] - 'a'];
//        count = message / WEIGHT;
//        last = message % WEIGHT;
//        last = i;
//        count++;
//        message = (count) * WEIGHT + last;
//        ch[str[i] - 'a'] = message;
//        arr[str[i] - 'a'] = count;
//    }
// 
//   int index = len;
//   char a = 'a';
//    for (int i = 0; i < 26; i++)
//    {
//        printf("%c:%d %d\n",a++,ch[i]/WEIGHT,arr[i]);
//    }
//    for (int i = 0; i < 26; i++)
//    {
//        if (ch[i] / WEIGHT== 1)
//        {
//            if (ch[i] % WEIGHT < index)
//                index = ch[i] % WEIGHT;
//        }
//    }
//    return index == len ? -1 : index;
//}
//char firstUniqChar(char* s) {
//    int ret = FirstNotRepeatingChar(s);
//    return ret == -1 ? ' ' : s[ret];
//}
//int main()
//{
//    char arr[15000] = { 'a' };
//    for (int i = 0; i < 15000; i++)
//        arr[i] = 'a';
//    arr[14999] = '\0';
//    char firs = firstUniqChar(arr);
//    return 0;
//}
//bool isUnique(char* str) {
//    char ch[26] = { 0 };
//    for (int i = 0; str[i]; i++)
//    {
//        if (ch[str[i] - 'a'])
//            return false;
//        else
//        {
//            ch[str[i] - 'a']++;
//        }
//    }
//    return true;
//}