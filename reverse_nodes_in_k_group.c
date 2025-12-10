struct ListNode* reverseList(struct ListNode* head, int k) {
    struct ListNode* prev = NULL;
    struct ListNode* current = head;
    
    for (int i = 0; i < k; i++) {
        struct ListNode* next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    
    return prev;
}

struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    struct ListNode* check = head;
    for (int i = 0; i < k; i++) {
        if (check == NULL) return head;
        check = check->next;
    }
    
    struct ListNode* newHead = reverseList(head, k);
    head->next = reverseKGroup(check, k);
    
    return newHead;
}
