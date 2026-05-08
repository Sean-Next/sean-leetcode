/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct ListNode ListNode;
struct ListNode* reverseList(struct ListNode* head) 
{
    ListNode* a = NULL;
    ListNode* b = head;
    

    while (b)
    {
        ListNode* c = b->next;

        b->next = a;
        a = b;
        b = c;
        if (c)
        c = c->next;
    }
    return a;
}