//bool hasCycle(struct ListNode* head) {
//    struct ListNode* slow = head;
//    struct ListNode* fast = head;
//    while (fast && fast->next)
//    {
//        fast = fast->next->next;
//        slow = slow->next;
//        if (fast == slow)//˵���л�
//            return true;
//    }
//    return false;
//}
//struct ListNode* detectCycle(struct ListNode* head) {
//    struct ListNode* slow = head;
//    struct ListNode* fast = head;
//    while (fast && fast->next)
//    {
//        fast = fast->next->next;
//        slow = slow->next;
//        if (slow == fast)
//        {
//            struct ListNode* plist = head;
//            struct ListNode* meet = slow;
//            while (meet != plist)
//            {
//                meet = meet->next;
//                plist = plist->next;
//            }
//            return meet;
//        }
//    }
//    return NULL;
//}
//struct Node* copyRandomList(struct Node* head) {
//    //1������copy�ڵ�
//    struct Node* cur = head;
//    struct Node* next = NULL;
//    struct Node* copy = NULL;
//    while (cur)
//    {
//        copy = (struct Node*)malloc(sizeof(struct Node));
//        next = cur->next;
//        copy->val = cur->val;
//        cur->next = copy;
//        copy->next = next;
//        cur = next;
//    }
//    cur = head;
//    //2������random�ڵ�
//    while (cur)
//    {
//        copy = cur->next;
//        next = copy->next;
//        if (cur->random)
//        {
//            copy->random = cur->random->next;
//        }
//        else
//        {
//            copy->random = NULL;
//        }
//        cur = next;
//    }
//    cur = head;
//    //3���ָ��ͼ���
//    struct Node* copyHead = NULL;
//    struct Node* copyTail = NULL;
//    while (cur)
//    {
//        copy = cur->next;
//        next = copy->next;
//        if (!copyTail)
//        {
//            copyHead = copyTail = copy;
//            copyTail->next = NULL;
//        }
//        else
//        {
//            copyTail->next = copy;
//            copyTail = copy;
//            copyTail->next = NULL;
//        }
//        cur->next = next;
//        cur = next;
//    }
//    return copyHead;
//}