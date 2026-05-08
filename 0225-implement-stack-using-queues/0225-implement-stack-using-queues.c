typedef int QDataType;

//定义节点结构
typedef struct QueueNode
{
	QDataType data;
	struct QueueNode* next;
}QueueNode;

//定义队列的结构
typedef struct Queue
{
	QueueNode* phead;//队列头节点
	QueueNode* ptail;//队列尾节点
	int size;//有效数据个数
}Queue;

//判断队列是否为空
bool QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->phead == NULL;
}

//初始化队列
void QueueInit(Queue* pq)
{
	assert(pq);
	pq->phead = pq->ptail = NULL;
	pq->size = 0;

	return;
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
		perror("malloc fail!");
		exit(1);
	}

	newnode->data = x;
	newnode->next = NULL;

	//判断是否是空队列
	if (QueueEmpty(pq))
	{
		pq->phead = pq->ptail = newnode;
	}
	else
	{
		pq->ptail->next = newnode;
		pq->ptail = pq->ptail->next;
	}
	pq->size++;

	return;
}

//队列头部删除元素
void QueuePop(Queue* pq)
{
	assert(!QueueEmpty(pq));

	//判断是否为唯一节点
	if (pq->phead == pq->ptail)
	{
		free(pq->phead);
		pq->phead = pq->ptail = NULL;
	}
	else
	{
		//记录新头节点
		QueueNode* next = pq->phead->next;

		free(pq->phead);
		pq->phead = next;
	}
	pq->size--;

	return;
}

//队列头部获取元素
QDataType QueueFront(Queue* pq)
{
	assert(!QueueEmpty(pq));

	return pq->phead->data;
}

//队列尾部获取元素
QDataType QueueBack(Queue* pq)
{
	assert(!QueueEmpty(pq));

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

	pq->phead = pq->ptail = NULL;
}

typedef struct
{
	Queue q1;
	Queue q2;
} MyStack;


MyStack* myStackCreate()
{
	MyStack* st = (MyStack*)malloc(sizeof(MyStack));

	QueueInit(&st->q1);
	QueueInit(&st->q2);

	return st;
}

void myStackPush(MyStack* obj, int x)
{
	Queue* NoEmp = &obj->q1;
	Queue* Emp = &obj->q2;

	if (QueueEmpty(NoEmp))
	{
		Emp = &obj->q1;
		NoEmp = &obj->q2;
	}

	QueuePush(NoEmp, x);

	return;
}

int myStackPop(MyStack* obj)
{
	Queue* NoEmp = &obj->q1;
	Queue* Emp = &obj->q2;

	if (QueueEmpty(NoEmp))
	{
		Emp = &obj->q1;
		NoEmp = &obj->q2;
	}

	while (QueueSize(NoEmp) > 1)
	{
		QueuePush(Emp, QueueFront(NoEmp));
		QueuePop(NoEmp);
	}
	int top = QueueFront(NoEmp);
	QueuePop(NoEmp);

	return top;
}

int myStackTop(MyStack* obj)
{
	Queue* NoEmp = &obj->q1;
	Queue* Emp = &obj->q2;

	if (QueueEmpty(NoEmp))
	{
		Emp = &obj->q1;
		NoEmp = &obj->q2;
	}

	int top = QueueBack(NoEmp);

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