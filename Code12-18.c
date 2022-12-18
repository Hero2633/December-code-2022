//
//void Swap(int* a, int* b)
//{
//    int tmp = *a;
//    *a = *b;
//    *b = tmp;
//}
//int cmp(const void* p1, const void* p2)
//{
//    return *(int*)p1 - *(int*)p2;
//}
//int cmp1(const void* p1, const void* p2)
//{
//    return *(int*)p2 - *(int*)p1;
//}
//void AdjustDown(int* nums, int top, int end, int (*cmp)(const void* p1, const void* p2))
//{
//    int parent = top;
//    int child = 2 * top + 1;
//    while (child < end)
//    {
//        if (child + 1 < end && (cmp(nums + child + 1, nums + child) < 0))
//            child++;
//        if (cmp(nums + parent, nums + child) <= 0)
//            break;
//        else
//        {
//            Swap(nums + child, nums + parent);
//            parent = child;
//            child = 2 * parent + 1;
//        }
//    }
//}
//int findKthLargest(int* nums, int numsSize, int k) {
//    for (int top = (k - 2) / 2; top >= 0; top--)
//    {
//        AdjustDown(nums, top, k, cmp);
//    }
//    for (int i = k; i < numsSize; i++)
//    {
//        if (nums[0] < nums[i])
//        {
//            Swap(nums, nums + i);
//            AdjustDown(nums, 0, k, cmp);
//        }
//    }
//    //AdjustDown(nums,0,k,cmp);
//    return nums[0];
//}
////int main()
////{
////    int arr[] = {3,2,3,1,2,4,5,5,6};
////    int len = sizeof(arr) / sizeof(int);
////    findKthLargest(arr,len,9);
////    return 0;
////}
//#include<string.h>
//#include<stdio.h>
//#include<stdlib.h>
////int* GetNext(char* p, int len)
////{
////    int* next = (int*)malloc(sizeof(int)*len);
////    next[0] = -1;
////    int j = 0;
////    int k = -1;
////    while (j < len - 1)
////    {
////        if (k == -1 || p[k] == p[j])
////        {
////            next[j + 1] = k + 1;
////            k += 1;
////            j++;
////        }
////        else
////        {
////            k = next[k];
////        }
////    }
////    return next;
////}
////int KMP(char* dest, char* sour)
////{
////    int len1 = strlen(dest);
////    int len2 = strlen(sour);
////    int i = 0;
////    int j = 0;
////    int* next = GetNext(sour,len2);
////    while (i < len1)
////    {
////        while (j==-1||i < len1 && j < len2 && dest[i] == sour[j])
////        {
////            i++;
////            j++;
////        }
////        if (j >= len2)
////        {
////            free(next);
////            return i - j;
////        }
////            j = next[j];
////    }
////    free(next);
////    return -1;
////}
////void test1()
////{
////    char ch1[] = {"abcabcdabcdef"};
////    char ch2[] = {"dab"};
////    int ret = KMP(ch1,ch2);
////    printf("%d\n",ret);
////}
////int main()
////{
////    test1();
////    return 0;
////}
//int PartSort(int* nums, int left, int right)
//{
//        int keyi = left;
//        int prev = left;
//        int cur = prev + 1;
//        while (cur <= right)
//        {
//            if (nums[cur] < nums[keyi] && ++prev != cur)
//            {
//                Swap(nums + prev, nums + cur);
//            }
//            cur++;
//        }
//        Swap(nums + keyi, nums + prev);
//        return prev;
//}
//
//
//void QuickSort(int* nums, int left, int right)
//{
//    if (left >= right)
//        return;
//    int mid=PartSort(nums,left,right);
//    QuickSort(nums,left,mid-1);
//    QuickSort(nums,mid+1,right);
//
//}
//void QuickSort1(int* nums, int left, int right)
//{
//    if (left >= right)
//        return;
//    int begin = left;
//    int end = right;
//    int key = nums[left];
//    int cur = left;
//    while (cur <= right)
//    {
//        if (nums[cur] == key)
//            ++cur;
//        else if (nums[cur] < key)
//        {
//            Swap(nums+left,nums+cur);
//            left++;
//            cur++;
//        }
//        else
//        {
//            Swap(nums+right,nums+cur);
//            right--;
//        }
//    }
//    QuickSort1(nums, begin, left - 1);
//    QuickSort1(nums,right+1,end);
//
//}
////void test1()
////{
////    int arr[] = { 9,8,5,5,5,5,5,5,5,5,7,6,5,4,3,2,1,0,10 };
////    int len = sizeof(arr) / sizeof(int);
////    QuickSort1(arr,0,len-1);
////    for (int i = 0; i < len; i++)
////        printf("%d ",arr[i]);
////}
////int main()
////{
////    test1();
////    return 0;
////}
//int Count(int* nums, int begin1, int end1,int begin2,int end2)
//{
//    int count = 0;
//    int l1 = begin1;
//    int l2 = begin2;
//    while (l1 <= end1 && l2 <= end2)
//    {
//        if (nums[l1] > nums[end2])
//        {
//            count += (end2 - begin2 + 1) * (end1 - l1 + 1);
//            break;
//        }
//        else
//        {
//            if (nums[l1] > nums[l2])
//            {
//                count++;
//                l2++;
//            }
//            else
//            {
//                l1++;
//            }
//        }
//    }
//    return count;
//}
//int Merge(int* nums, int left, int right, int* tmp)
//{
//    if (left >= right)
//        return 0;
//    int mid = (right - left) / 2 + left;
//    int begin1 = left, end1 = mid;
//    int begin2 = mid + 1, end2 = right;
//    int count = 0;
//    int L = Merge(nums, left, mid, tmp);
//    int R = Merge(nums, mid + 1, right, tmp);
//    int k = left;
//    while (l1 <= end1 && l2 <= end2)
//    {
//        if (nums[l1] <= nums[l2])
//        {
//            tmp[k++] = nums[l1];
//            l1++;
//        }
//        else
//        {
//            tmp[k++] = nums[l2++];
//        }
//    }
//    while (l1 <= end1)
//    {
//        tmp[k++] = nums[l1++];
//    }
//    while (l2 <= end2)
//    {
//        tmp[k++] = nums[l2++];
//    }
//    for (int i = left; i < (k - left); i++)
//    {
//        nums[i] = tmp[i];
//    }
//
//    return count + L + R;
//}
//
//int reversePairs(int* nums, int numsSize) {
//    int* tmp = (int*)malloc(sizeof(int) * numsSize);;
//    return Merge(nums, 0, numsSize - 1, tmp) - 1;
//}
//int main()
//{
//    int arr[] = { 7,5,6,4 };
//    reversePairs(arr,4);
//    return 0;
//}