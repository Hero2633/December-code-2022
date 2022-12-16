//#include<stdio.h>
////struct ListNode
////{
////    struct ListNode* next;
////    int val;
////};
////struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
////    struct ListNode* dummyhead = (struct ListNode*)malloc(sizeof(struct ListNode));
////    if (dummyhead == NULL)
////        exit(-1);
////    dummyhead->next = NULL;
////    struct ListNode* cur = dummyhead;
////    int sum = 0;
////    int carry = 0;
////    while (l1 && l2)
////    {
////        struct ListNode* next1 = l1->next;
////        struct ListNode* next2 = l2->next;
////        struct ListNode* NewHead = (struct ListNode*)malloc(sizeof(struct ListNode));
////        if (!NewHead)
////            exit(-1);
////        sum = (l1->val + l2->val + carry) % 10;
////        carry = (l1->val + l2->val + carry) / 10;
////        NewHead->val = sum;
////        cur->next = NewHead;
////        cur = NewHead;
////        cur->next = NULL;
////        l1 = next1;
////        l2 = next2;
////    }
////    while (l1)
////    {
////        struct ListNode* next1 = l1->next;
////        struct ListNode* NewHead = (struct ListNode*)malloc(sizeof(struct ListNode));
////        if (!NewHead)
////            exit(-1);
////        sum = (l1->val + carry) % 10;
////        carry = (l1->val + carry) / 10;
////        NewHead->val = sum;
////        cur->next = NewHead;
////        cur = NewHead;
////        cur->next = NULL;
////        l1 = next1;
////    }
////    while (l2)
////    {
////        struct ListNode* next2 = l2->next;
////        struct ListNode* NewHead = (struct ListNode*)malloc(sizeof(struct ListNode));
////        if (!NewHead)
////            exit(-1);
////        sum = (l2->val + carry) % 10;
////        carry = (l2->val + carry) / 10;
////        NewHead->val = sum;
////        cur->next = NewHead;
////        cur = NewHead;
////        cur->next = NULL;
////        l2 = next2;
////    }
////    while (carry)
////    {
////        struct ListNode* NewHead = (struct ListNode*)malloc(sizeof(struct ListNode));
////        if (!NewHead)
////            exit(-1);
////        sum = (carry) % 10;
////        carry = (carry) / 10;
////        NewHead->val = sum;
////        cur->next = NewHead;
////        cur = NewHead;
////        cur->next = NULL;
////    }
////    struct ListNode* Head = dummyhead->next;
////    free(dummyhead);
////    return Head;
////}
//#include<stdlib.h>
//#include<limits.h>
//struct Node
//{
//	int index;
//	int* arr;
//	int len;
//};
//void Swap(struct Node* a, struct Node* b)
//{
//	struct Node tmp = *a;
//	*a = *b;
//	*b = tmp;
//}
//void AdjustDown(struct Node* Heap, int top, int end)
//{
//	int parent = top;
//	int child = 2*parent+1;
//	while (child < end)
//	{
//		if (child + 1 < end && Heap[child + 1].arr[Heap[child + 1].index] < Heap[child].arr[Heap[child].index])
//		{
//			child++;
//		}
//		if (Heap[child].arr[Heap[child].index] >= Heap[parent].arr[Heap[parent].index])
//			break;
//		else
//		{
//			Swap(Heap+child,Heap+parent);
//			parent = child;
//			child = 2 * parent + 1;
//		}
//	}
//}
//int* MulArrSort(int** nums, int Row, int* Col, int* returnSize)
//{
//	*returnSize = 0;
//	//����ϲ��������Ԫ�ظ���
//	for (int i = 0; i < Row; i++)
//	{
//		*returnSize += Col[i];
//	}
//	int* ret = (int*)malloc(sizeof(int) * (*returnSize));
//	if (!ret)
//		exit(EXIT_FAILURE);
//	//1��������ʼ������
//	struct Node* Heap = (struct Node*)malloc(sizeof(struct Node) * (Row));
//	if (!Heap)
//		exit(EXIT_FAILURE);
//	int size = 0;//��¼��Ч�������
//	for (int i = 0; i < Row; i++)
//	{
//		if (nums[i])
//		{
//			Heap[size].arr = nums[i];
//			Heap[size].index = 0;
//			Heap[size].len = Col[i];
//			size++;
//		}
//	}
//	int HeapSize = size;
//	//2������С��
//	for (int top = (HeapSize - 1 - 1) / 2; top >= 0; top--)
//	{
//		AdjustDown(Heap,top,HeapSize);
//	}
//	int k = 0;//��¼�ϲ�������±�
//	struct Node NextNode ={ 0 };
//	//3����ʼѡ��
//	while (HeapSize)
//	{
//		ret[k++] = Heap[0].arr[Heap[0].index];
//		NextNode = Heap[0];
//		NextNode.index++;
//		//4������С��
//		if (NextNode.index >= NextNode.len)//˵��ĳһ�����������Ѿ�ѡ���ˣ�С��Ԫ�ؼ�1�����¶Ѷ�Ԫ�أ��������½���
//		{
//			Swap(Heap+HeapSize-1,Heap);
//			HeapSize--;
//		}
//		else//����������һ�ε�λ��
//		{
//			Heap[0] = NextNode;//����������һ��λ��
//		}
//		AdjustDown(Heap,0,HeapSize);
//	}
//	free(Heap);
//	return ret;
//}
//void test1()
//{
//	int arr1[] = { 1,2,3,4,5 };
//	int arr2[] = { 6,7,8,9,10 };
//	int arr3[] = { 11,12,13,14,15,16 };
//	int arr4[] = { 17,18,19,20};
//	int* arr[] = { arr1,arr2,arr3,arr4 };
//	int RowLen = sizeof(arr) / sizeof(arr[0]);
//	int ColLen[10] = { 0 };
//	ColLen[0] = sizeof(arr1) / sizeof(arr1[0]);
//	ColLen[1] = sizeof(arr2) / sizeof(arr2[0]);
//	ColLen[2] = sizeof(arr3) / sizeof(arr3[0]);
//	ColLen[3] = sizeof(arr4) / sizeof(arr4[0]);
//	int size = 0;
//	int *ret=MulArrSort(arr,RowLen,ColLen,&size);
//	for (int i = 0; i < size; i++)
//		printf("%d ",ret[i]);
//
//}
//int main()
//{
//	test1();
//	return 0;
//}
////struct ListNode* BuyNode(int val)
////{
////	struct ListNode* Node = (struct ListNode*)malloc(sizeof(struct ListNode));
////	Node->val = val;
////	Node->next = NULL;
////	return Node;
////}
////void Swap(struct ListNode** a, struct ListNode** b)
////{
////	struct ListNode* tmp = *a;
////	*a = *b;
////	*b = tmp;
////}
////void AdjustDown(struct ListNode** lists, int top, int end)
////{
////	int parent = top;
////	int child = 2 * top + 1;
////	while (child < end)
////	{
////		if (child + 1 < end && lists[child + 1]->val < lists[child]->val)
////			child++;
////		if (lists[child]->val >= lists[parent]->val)
////			break;
////		else
////		{
////			Swap(lists + parent, lists + child);
////			parent = child;
////			child = 2 * parent + 1;
////		}
////	}
////}
////struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
////
////	//
////	struct ListNode** Heap = (struct ListNode**)malloc(sizeof(struct ListNode*) * listsSize);
////	int size = 0;
////	for (int i = 0; i < listsSize; i++)
////	{
////		if (lists[i])
////		{
////			Heap[size++] = lists[i];
////		}
////	}
////	int HeapSize = size;
////	for (int top = (HeapSize - 2) / 2; top >= 0; top--)
////	{
////		AdjustDown(Heap, top, HeapSize);
////	}
////	struct ListNode* dummyhead = (struct ListNode*)malloc(sizeof(struct ListNode));
////	dummyhead->next = NULL;
////	struct ListNode* cur = dummyhead;
////	while (HeapSize)
////	{
////		struct ListNode* next = Heap[0]->next;
////		struct ListNode* NewNode = BuyNode(Heap[0]->val);
////		cur->next = NewNode;
////		cur = NewNode;
////		if (next)
////		{
////			Heap[0] = next;
////		}
////		else
////		{
////			Swap(Heap, Heap + HeapSize - 1);
////			HeapSize--;
////		}
////		AdjustDown(Heap, 0, HeapSize);
////	}
////	struct ListNode* Head = dummyhead->next;
////	free(dummyhead);
////	return Head;
////}