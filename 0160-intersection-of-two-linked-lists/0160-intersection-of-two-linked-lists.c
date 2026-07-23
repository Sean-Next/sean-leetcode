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
    int sizeA = 0;
    int sizeB = 0;

    ListNode* pcurA = headA;
    ListNode* pcurB = headB;

    while (pcurA)
    {
        pcurA = pcurA->next;
        sizeA++;
    }
    while (pcurB)
    {
        pcurB = pcurB->next;
        sizeB++;
    }

    int diff = abs(sizeA - sizeB);

    ListNode* LongList = headA;
    ListNode* shortList = headB;

    if (sizeA < sizeB)
    {
        LongList = headB;
        shortList = headA;
    }

    while (diff--)
    {
        LongList = LongList->next;
    }

    while (LongList)
    {
        if (LongList == shortList)
        {
            return LongList;
        }
        LongList = LongList->next;
        shortList = shortList->next;
    }

    return NULL;
}