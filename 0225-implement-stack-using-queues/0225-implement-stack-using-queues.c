//存储数据类型---int
typedef int QDataType;

//节点-结构体
typedef struct QueueNode
{
	QDataType data;
	struct QueueNode* next;
}QueueNode;

//队列-结构体
typedef struct Queue
{
	QueueNode* phead;//队列头节点
	QueueNode* ptail;//队列尾节点
	int size;//有效数据个数
}Queue;

//初始化队列
void QueueInit(Queue* pq)
{
	assert(pq);

	pq->phead = pq->ptail = NULL;
	pq->size = 0;

	return;
}

//打印队列所有元素
void QueuePrint(Queue* pq)
{
	assert(pq);

	QueueNode* pcur = pq->phead;

	//遍历打印
	while (pcur)
	{
		printf("%d->", pcur->data);
		pcur = pcur->next;
	}
	printf("NULL\n");

	return;
}

//判断队列是否为空
bool QueueEmpty(Queue* pq)
{
	assert(pq);

	//判断头节点是否为空
	return pq->phead == NULL;
}

//队列尾部放入元素
void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);

	//申请空间
	QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));

	//申请失败结束程序
	if (newnode == NULL)
	{
		perror("malloc fail !");
		exit(1);
	}

	//新节点初始化
	newnode->data = x;
	newnode->next = NULL;

	//判断是否是空队列
	if (QueueEmpty(pq))
	{
		//更改头节点和尾节点
		pq->phead = pq->ptail = newnode;
	}
	else
	{
		//连接新节点
		pq->ptail->next = newnode;

		//更改尾节点
		pq->ptail = pq->ptail->next;
	}

	//元素数量增加
	pq->size++;

	return;
}

//队列头部删除元素
void QueuePop(Queue* pq)
{
	assert(pq && !QueueEmpty(pq));

	//判断是否为唯一节点
	if (pq->phead == pq->ptail)
	{
		free(pq->phead);

		//头节点与尾节点置空
		pq->phead = pq->ptail = NULL;
	}
	else
	{
		//记录新头节点
		QueueNode* newphead = pq->phead->next;

		free(pq->phead);
		pq->phead = newphead;
	}

	//元素数量减少
	pq->size--;

	return;
}

//队列头部获取元素
QDataType QueueFront(Queue* pq)
{
	assert(pq && !QueueEmpty(pq));

	return pq->phead->data;
}

//队列尾部获取元素
QDataType QueueBack(Queue* pq)
{
	assert(pq && !QueueEmpty(pq));

	return pq->ptail->data;
}

//获取队列有效数据个数
int QueueSize(Queue* pq)
{
	assert(pq);

	return pq->size;
}

//销毁队列
void QueueDesTroy(Queue* pq)
{
	assert(pq);

	QueueNode* pcur = pq->phead;

	while (pcur)
	{
		//记录下一节点
		QueueNode* next = pcur->next;

		free(pcur);
		pcur = next;
	}

	//队列初始化
	pq->phead = pq->ptail = NULL;
	pq->size = 0;

	return;
}



typedef struct 
{
    Queue q1;
    Queue q2;
} MyStack;


MyStack* myStackCreate() 
{
    MyStack* st = (MyStack*)malloc(sizeof( MyStack));

    if (st == NULL)
    {
        exit(1);
    }

    QueueInit(&st->q1);
    QueueInit(&st->q2);

    return st;
}

void myStackPush(MyStack* obj, int x) 
{
    Queue* push = QueueEmpty(&obj->q1) ? &obj->q2 : &obj->q1;

    QueuePush(push, x);

    return;
    
}

int myStackPop(MyStack* obj) 
{
    Queue* pop = QueueEmpty(&obj->q1) ? &obj->q2 : &obj->q1;
    Queue* push = !QueueEmpty(&obj->q1) ? &obj->q2 : &obj->q1;

    while (pop->size > 1)
    {
        int front = QueueFront(pop);
        QueuePop(pop);
        QueuePush(push, front);
    }

    int top = QueueFront(pop);
    QueuePop(pop);

    return top;
}

int myStackTop(MyStack* obj) 
{
    Queue* pop = QueueEmpty(&obj->q1) ? &obj->q2 : &obj->q1;
    Queue* push = !QueueEmpty(&obj->q1) ? &obj->q2 : &obj->q1;

    while (pop->size > 1)
    {
        int front = QueueFront(pop);
        QueuePop(pop);
        QueuePush(push, front);
    }

    int top = QueueFront(pop);
    QueuePop(pop);
    QueuePush(push, top);

    return top;
}

bool myStackEmpty(MyStack* obj) 
{
    return QueueEmpty(&obj->q1) && QueueEmpty(&obj->q2);
}

void myStackFree(MyStack* obj) 
{
    QueueDesTroy(&obj->q1);
    QueueDesTroy(&obj->q2);

    free(obj);
    obj = NULL;

    return;
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);
 
 * int param_2 = myStackPop(obj);
 
 * int param_3 = myStackTop(obj);
 
 * bool param_4 = myStackEmpty(obj);
 
 * myStackFree(obj);
*/