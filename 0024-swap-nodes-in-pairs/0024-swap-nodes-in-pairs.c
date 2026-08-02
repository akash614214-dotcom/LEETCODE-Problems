/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* h) {
    struct ListNode d;
    d.next = h;
    struct ListNode* p = &d;
    
    while (p->next && p->next->next) {
        struct ListNode* a = p->next;
        struct ListNode* b = a->next;
        
        p->next = b;
        a->next = b->next;
        b->next = a;
        
        p = a;
    }
    
    return d.next;
}