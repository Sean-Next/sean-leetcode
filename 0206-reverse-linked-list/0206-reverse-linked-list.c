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
    if (head == NULL)
    {
        return NULL;
    }

    ListNode* prev = NULL;
    ListNode* curr = head;
    ListNode* next = head->next;

    while (curr)
    {
        curr->next = prev;
        prev = curr;
        curr = next;
        if (next)
        next = next->next;
    }

    return prev;
}