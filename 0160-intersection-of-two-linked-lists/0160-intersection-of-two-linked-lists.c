/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct ListNode ListNode;
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) 
{
    int lenA = 0;
    int lenB = 0;

    ListNode* pcurA = headA;
    ListNode* pcurB = headB;

    while (pcurA)
    {
        pcurA = pcurA->next;
        lenA++;
    }

    while (pcurB)
    {
        pcurB = pcurB->next;
        lenB++;
    }

    int del = abs(lenA - lenB);

    ListNode* more_list = headA;
    ListNode* less_list = headB;

    if (lenA < lenB)
    {
        more_list = headB;
        less_list = headA;
    }

    

    while (del--)
    {
        more_list = more_list->next;
    }

    while (less_list)
    {
        if (more_list == less_list)
        {
            return more_list;
        }
        more_list = more_list->next;
        less_list = less_list->next;
    }

    return NULL;
}