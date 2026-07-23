/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef  struct ListNode ListNode;
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) 
{
    ListNode* guard = (ListNode*)malloc(sizeof(ListNode));
    ListNode* pcur = guard;

    ListNode* pcur1 = list1;
    ListNode* pcur2 = list2;

    while (pcur1 && pcur2)
    {
        if (pcur1->val <= pcur2->val)
        {
            pcur->next = pcur1;
            pcur1 = pcur1->next;
        }
        else
        {
            pcur->next = pcur2;
            pcur2 = pcur2->next;
        }
        pcur = pcur->next;
    }

    if (pcur1 == NULL)
    {
        pcur->next = pcur2;
    }
    else
    {
        pcur->next = pcur1;
    }

    return guard->next;
}