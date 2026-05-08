/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct ListNode ListNode;
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) 
{
    ListNode* newhead = (ListNode*)malloc(sizeof(ListNode));
    ListNode* newtail = newhead;
    newhead->next = NULL;

    ListNode* pcur1 = list1;
    ListNode* pcur2 = list2;

    while (pcur1 && pcur2)
    {
        if (pcur1->val <= pcur2->val)
        {
            newtail->next = pcur1;
            pcur1 = pcur1->next;
        }
        else
        {
            newtail->next = pcur2;
            pcur2 = pcur2->next;
        }
        newtail = newtail->next;
    }

    if (pcur1)
    {
        newtail->next = pcur1;
    }
    else
    {
        newtail->next = pcur2;
    }

    return newhead->next;
}