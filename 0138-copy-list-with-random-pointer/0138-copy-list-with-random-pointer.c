
typedef struct Node Node;

void copynode(Node* head)
{
    Node* pcur = head;

    while (pcur)
    {
        Node* newnode = (Node*)malloc(sizeof(Node));

        newnode->val = pcur->val;
        newnode->next = pcur->next;
        newnode->random = pcur->random;

        pcur->next = newnode;
        pcur = newnode->next;
    }

    return;
}

void copyrandom(Node* head)
{
    Node* pcur = head;
   
    while (pcur)
    {
        if (pcur->next->random)
        {
            pcur->next->random = pcur->next->random->next;
        }
        pcur = pcur->next->next;
    }

    return;
}

Node* creatnewnode(Node* head)
{
    Node* pcur = head;

    Node* newhead = (Node*)malloc(sizeof(Node));
    Node* newtail = newhead;
    newhead->next = NULL;

    while (pcur)
    {
        newtail->next = pcur->next;
        newtail = newtail->next;
        pcur = pcur->next->next;
    }

    return newhead->next;
}


struct Node* copyRandomList(struct Node* head)
{
    copynode(head);

    copyrandom(head);

    return creatnewnode(head);
}