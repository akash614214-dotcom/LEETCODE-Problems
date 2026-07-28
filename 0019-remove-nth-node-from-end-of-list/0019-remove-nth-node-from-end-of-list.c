/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* h, int n) {
    struct ListNode d;
    d.next = h;

    struct ListNode *f = &d, *s = &d;

    while (n--)
        f = f->next;

    while (f->next) {
        f = f->next;
        s = s->next;
    }

    s->next = s->next->next;

    return d.next;
}