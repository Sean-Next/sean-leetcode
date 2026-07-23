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
    ListNode* guard = (ListNode*)malloc(sizeof(ListNode));
    ListNode* newtail = guard;
    ListNode* pcur = head;

    while (pcur != NULL)
    {
        if (pcur->val != val)
        {
            newtail->next = pcur;
            newtail = newtail->next;
        }
        pcur = pcur->next;
    }

    newtail->next = NULL;
    return guard->next;
}