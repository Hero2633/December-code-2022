////////int* printNumbers(int n, int* returnSize) {
////////    // write code here
////////    int sum = 0;
////////    for (int i = 0; i < n; i++)
////////        sum = sum * 10 + 9;
////////    *returnSize = sum;
////////    int* ret = (int*)malloc(sizeof(int) * (*returnSize));
////////    for (int i = 0; i < *returnSize; i++)
////////        ret[i] = i + 1;
////////    return ret;
////////}
////////#include <stdio.h>
////////#include<stdbool.h>
////////bool is_leap(int year)
////////{
////////    return (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
////////}
////////int main() {
////////    int year = 0;
////////    int month = 0;
////////    int day = 0;
////////    scanf("%d%d%d", &year, &month, &day);
////////    int Day[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
////////    if (is_leap(year))
////////        Day[2]++;
////////    int SumDay = 0;
////////    for (int i = 0; i < month; i++)
////////        SumDay += Day[i];
////////    SumDay += day;
////////    printf("%d\n", SumDay);
////////    return 0;
////////}
////////#include <stdio.h>
////////
////////int main() {
////////    int m = 0;
////////    scanf("%d", &m);
////////    int n = (m - 1) * m / 2 + 1;
////////    int head = 2 * n - 1;
////////    for (int i = 0; i < m; i++)
////////    {
////////        printf("%d", head);
////////        if (i != m - 1)
////////            printf("+");
////////        head += 2;
////////    }
////////}
////////}
//////#include <stdio.h>
//////
//////int main() {
//////    int n = 0;
//////    scanf("%d", &n);
//////    int arr[n];
//////    int countP = 0;
//////    int countN = 0;
//////    int sumP = 0;
//////    for (int i = 0; i < n; i++)
//////    {
//////        scanf("%d", arr + i);
//////        if (arr[i] > 0)
//////        {
//////            countP++;
//////            sumP += arr[i];
//////        }
//////        else if (arr[i] < 0)
//////            countN++;
//////    }
//////    float val = 0.0f;
//////    if (countP)
//////        val = sumP * 1.0f / countP;
//////    printf("%d %.1f\n", countN, val);
//////    return 0;
//////}
//////int minNumberInRotateArray(int* rotateArray, int rotateArrayLen) {
//////    // write code here
//////    int left = 0;
//////    int right = rotateArrayLen - 1;
//////    int mid = 0;
//////    while (left < right)
//////    {
//////        mid = (right - left) / 2 + left;
//////        if (rotateArray[mid] > rotateArray[right])
//////            left = mid + 1;
//////        else if (rotateArray[mid] < rotateArray[right])
//////            right = mid;
//////        else
//////            right--;
//////    }
//////    return rotateArray[left];
//////}
//////int* findErrorNums(int* nums, int numsSize, int* returnSize) {
//////    int* ret = (int*)malloc(sizeof(int) * 2);
//////    *returnSize = 2;
//////    for (int i = 0; i < numsSize; i++)
//////    {
//////        if (nums[abs(nums[i]) - 1] > 0)
//////            nums[abs(nums[i]) - 1] *= -1;
//////        else
//////            ret[0] = abs(nums[i]);
//////    }
//////    for (int i = 0; i < numsSize; i++)
//////        if (nums[i] > 0)
//////        {
//////            ret[1] = i + 1;
//////            break;
//////        }
//////    return ret;
//////
//////}
////#pragma warning (disable:4996)
//////#include <stdio.h>
//////#include<string.h>
//////int main() {
//////    int n = 0;
//////    scanf("%d", &n);
//////    getchar();
//////    for (int i = 0; i < n; i++)
//////    {
//////        char arr[101];
//////        gets(arr);
//////        if (arr[0] >= '0' && arr[0] <= '9')
//////        {
//////            printf("NO\n");
//////            continue;
//////        }
//////        int len = strlen(arr);
//////        if (len < 8)
//////        {
//////            printf("NO\n");
//////            continue;
//////        }
//////        int flag1 = 0;
//////        int flag2 = 0;
//////        int flag3 = 0;
//////        int flag4 = 0;
//////        for (int j = 0; j < len; j++)
//////        {
//////            if (arr[j] >= '0' && arr[j] <= '9')
//////            {
//////                flag1 = 1;
//////                continue;
//////            }
//////            if (arr[j] >= 'a' && arr[j] <= 'z')
//////            {
//////                flag2 = 1;
//////                continue;
//////            }
//////            if (arr[j] >= 'A' && arr[j] <= 'Z')
//////            {
//////                flag3 = 1;
//////                continue;
//////            }
//////            flag4 = 1;
//////            break;
//////        }
//////        if (!flag4)
//////        {
//////            if ((flag1 && flag2) || (flag1 && flag3) || (flag2 && flag3))
//////                printf("YES\n");
//////        }
//////        else
//////            printf("NO\n");
//////    }
//////    return 0;
//////}
////int GetNumberOfK_Part(int* nums, int left, int right, int k)
////{
////    if (left > right)
////        return 0;
////    int mid = (right - left) / 2 + left;
////    if (nums[mid] == k && nums[mid] == nums[left] && nums[left] == nums[right])
////        return right - left + 1;
////    if (nums[mid] == k)
////        return 1 + GetNumberOfK_Part(nums, left, mid - 1, k) + GetNumberOfK_Part(nums, mid + 1, right, k);
////    else if (nums[mid] > k)
////    {
////        return GetNumberOfK_Part(nums, left, mid - 1, k);
////    }
////    else
////        return GetNumberOfK_Part(nums, mid + 1, right, k);
////}
////int GetNumberOfK(int* data, int dataLen, int k) {
////    // write code here
////    int ret = GetNumberOfK_Part(data, 0, dataLen - 1, k);
////    return ret;
////}
////int main()
////{
////	printf("%d\n",1<<31);
////	return 0;
////}
////int convertInteger(int A, int B) {
////    int key = A ^ B;
////    int len = sizeof(int) * 8;
////    int count = 0;
////    for (int i = 0; i < len; i++)
////    {
////        if (key & ((unsigned int)1 << i))
////            count++;
////    }
////    return count;
////}
//#include<stdio.h>
//#include<limits.h>
////int main()
////{
////	 int a= 1 << 31;
////	printf("%d\n",INT_MIN<<1);
////	return 0;
////}
////int dominantIndex(int* nums, int numsSize) {
////    if (numsSize == 1)
////        return 0;
////    int max = 0;
////    int SubMax = max;
////    int maxi = 0;
////    for (int i = 0; i < numsSize; i++)
////    {
////        if (nums[i] > max)
////        {
////            SubMax = max;
////            max = nums[i];
////            maxi = i;
////        }
////        else
////        {
////            if (nums[i] > SubMax)
////                SubMax = nums[i];
////        }
////    }
////    printf("%d %d\n", max, SubMax);
////    if (SubMax == 0 || max / SubMax >= 2)
////        return maxi;
////    return -1;
////}
//int cmp(const void* p1, const void* p2)
//{
//    return *(int*)p1 - *(int*)p2;
//}
//int Deduplication(int* nums, int len)
//{
//    int prev = 0;
//    int cur = 0;
//    while (cur < len)
//    {
//
//        if (nums[cur] != nums[prev])
//        {
//            prev++;
//            nums[prev] = nums[cur];
//        }
//        cur++;
//    }
//    return prev + 1;
//}
//int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
//    int (*cmp_int)(const void*, const void*) = cmp;
//    qsort(nums1, nums1Size, sizeof(int), cmp_int);
//    qsort(nums2, nums2Size, sizeof(int), cmp_int);
//    int l1 = 0;
//    int l2 = 0;
//    int len = nums1Size;
//    if (nums2Size < nums1Size)
//        len = nums2Size;
//    int* tmp = (int*)malloc(sizeof(int) * len);
//    int k = 0;
//    while (l1 < nums1Size && l2 < nums2Size)
//    {
//        if (nums1[l1] == nums2[l2])
//        {
//            tmp[k++] = nums1[l1];
//            l1++, l2++;
//        }
//        else if (nums1[l1] > nums2[l2])
//        {
//            l2++;
//        }
//        else
//            l1++;
//    }
//    if (k == 0)
//    {
//        free(tmp);
//        *returnSize = 0;
//        return NULL;
//    }
//    *returnSize = Deduplication(tmp, k);
//    return tmp;
//}