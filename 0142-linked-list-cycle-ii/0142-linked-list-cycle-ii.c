/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct ListNode ListNode;
struct ListNode *detectCycle(struct ListNode *head) 
{
    ListNode* slow = head;
    ListNode* fast = head;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            ListNode* pcur = head;

            while (fast != pcur)
            {
                fast = fast->next;
                pcur = pcur->next;
            }

            return fast;
        }
    }

    return NULL;
}