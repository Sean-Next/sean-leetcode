/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct ListNode ListNode;
struct ListNode* removeElements(struct ListNode* head, int val) 
{
    ListNode* newhead = (ListNode*)malloc(sizeof(ListNode));
    ListNode* newtail = newhead;
    newhead->next = NULL;

    ListNode* pcur = head;

    while (pcur)
    {
        if (pcur->val != val)
        {
            newtail->next = pcur;
            newtail = newtail->next;
        }
        pcur = pcur->next;
    }
    newtail->next = NULL;

    return newhead->next;
}