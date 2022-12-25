////#include <stdio.h>
////#include<stdbool.h>
////bool is_SelfNum(int n)
////{
////    int Number = 0;
////    int tmp = n;
////    while (tmp)
////    {
////        Number++;
////        tmp /= 10;
////    }
////    int sqrt = n * n;
////    n = sqrt - n;
////    while (Number)
////    {
////        if (n % 10)
////            return false;
////        n /= 10;
////        Number--;
////    }
////    return true;
////}
////int main() {
////    int count = 0;
////    int n = 0;
////    scanf("%d", &n);
////    int i = 0;
////    for (i = 0; i <= n; i++)
////    {
////        if (is_SelfNum(i))
////            count++;
////    }
////    printf("%d\n", count);
////    return 0;
////}
#include <stdio.h>
#include<stdbool.h>
#include<math.h>
bool is_prime(int n)
{
    int i = 2;
    int side = (int)sqrt(n);
    for (i = 2; i <= side; i++)
        if (n % i == 0)
            return false;
    return true;
}
//int main() {
//    int n = 0;
//    scanf("%d", &n);
//    int count = 0;
//    if (n < 2)
//        count = 0;
//    else if (n == 2)
//        count = 1;
//    else
//    {
//        count++;
//        int i = 3;
//        for (i = 3; i <= n; i += 2)
//        {
//            if (is_prime(i))
//            {
//                count++;
//            }
//        }
//    }
//    printf("%d\n", count);
//    return 0;
//}
//#pragma warning (disable:4996)
//#include <stdio.h>
//#include<stdlib.h>
//int main() {
//    int arr[] = { 2,3,5,7 };
//    int n = 0;
//    scanf("%d", &n);
//    int mark = 0;//标记的质数个数
//    int* nums = (int*)calloc(n, sizeof(int));
//    nums[0] = 1;
//    nums[1] = 1;
//    mark = n - 2;
//    for (int i = 0; i < 4; i++)
//    {
//        int j = arr[i];
//        int index = arr[i] * j;
//        while (index < n)
//        {
//            if (!nums[index])
//            {
//                nums[index] = 1;
//                mark--;
//            }
//                j++;
//            index = arr[i]* j;
//        }
//    }
//    int count = 0;
//    for (int i = 0; i < n; i++)
//        if (!nums[i])
//        {
//            if (!is_prime(i))
//                printf("%d\n",i);
//        }
//
//        printf("%d %d\n",count,mark);
//    return 0;
//}



//int countPrimes(int n) {
//    if (n <= 2)
//        return 0;
//    int mark = n - 2;
//    int* nums = (int*)calloc(n, sizeof(int));
//    int side = (int)(sqrt(n));
//    int i = 2;
//    int index = 0;
//    nums[0] = 1;
//    nums[1] = 1;
//    for (i = 2; i <= side; i++)
//    {
//        int j = i;
//        index = i * j;
//        while (index < n)
//        {
//            if (nums[index] == 0)
//            {
//                nums[index] = 1;
//                mark--;
//            }
//            j++;
//            index = i * j;
//        }
//    }
//    free(nums);
//    return mark;
//}