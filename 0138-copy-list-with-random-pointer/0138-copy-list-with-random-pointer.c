/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *next;
 *     struct Node *random;
 * };
 */

typedef struct Node Node;

Node* CreateNode(Node* node)
{
    Node* newnode = (Node*)malloc(sizeof(Node));

    if (newnode == NULL)
    {
        exit(1);
    }

    newnode->val = node->val;
    newnode->next = node->next;
    newnode->random = NULL;

    return newnode;
}

void CopyNode(Node* node)
{
    Node* copynode = node->next;

    if (node->random)
    {
        copynode->random = node->random->next;
    }
    else
    {
        copynode->random = NULL;
    }

    return;
}

void LinkNode(Node* node)
{
    Node* copynode = node->next;

    if (copynode->next)
    {
        copynode->next = copynode->next->next;
    }
    else
    {
       copynode->next = NULL;
    }

    return;
}


Node* copyRandomList(Node* head) 
{
    if (head == NULL)
    {
        return NULL;
    }

    Node* pcur1 = head;
    Node* pcur2 = head;
    Node* pcur3 = head;

    while (pcur1 != NULL)
    {
        Node* next = pcur1->next;
        pcur1->next = CreateNode(pcur1);
        pcur1 = next;
    }

    while (pcur2 != NULL)
    {
        CopyNode(pcur2);
        pcur2 = pcur2->next->next;
    }

    while (pcur3 != NULL)
    {
        Node* next = pcur3->next->next;
        LinkNode(pcur3);
        pcur3 = next;
    }

    return head->next;
}