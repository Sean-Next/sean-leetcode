//栈的储存数据类型
typedef int STDataType;

typedef struct Stack
{
	STDataType* arr;//栈的地址
	int top;//指向栈顶位置---有效数据个数
	int capacity;//空间大小
}ST;

//判断栈是否为空
bool STEmpty(ST* ps)
{
	return ps->top == 0;
}

//初始化栈
void STInit(ST* ps)
{
	assert(ps);

	ps->arr = NULL;
	ps->top = ps->capacity = 0;

	return;
}

//销毁栈
void STDesTroy(ST* ps)
{
	assert(ps);

	//销毁
	free(ps->arr);
	//初始化
	ps->arr = NULL;
	ps->top = ps->capacity = 0;

	return;
}

//在栈的顶部放入元素
void STPush(ST* ps, STDataType x)
{
	assert(ps);

	if (ps->top == ps->capacity)
	{
		//2倍增容
		int newcapacity = (ps->capacity == 0) ? 4 : (2 * ps->capacity);

		STDataType* temp = (STDataType*)realloc(ps->arr, newcapacity * sizeof(STDataType));

		//判断申请是否成功
		if (temp == NULL)
		{
			perror("realloc");
			exit(1);
		}

		ps->arr = temp;
		ps->capacity = newcapacity;
	}

	//元素入栈
	ps->arr[ps->top++] = x;

	return;
}

//获取栈的顶部元素
STDataType STTop(ST* ps)
{
	assert(ps && !STEmpty(ps));

	return ps->arr[ps->top - 1];
}

//在栈的顶部删除元素
void STPop(ST* ps)
{
	assert(!STEmpty(ps));

	ps->top--;

	return;
}

//获取栈的有效元素个数
int STSize(ST* ps)
{
	return ps->top;
}


typedef struct 
{
    ST push;
    ST pop;
} MyQueue;


MyQueue* myQueueCreate() 
{
    MyQueue* qu = (MyQueue*)malloc(sizeof(MyQueue));

    STInit(&qu->push);
    STInit(&qu->pop);

    return qu;
}

void myQueuePush(MyQueue* obj, int x) 
{
    STPush(&obj->push, x);

    return;
}

int myQueuePop(MyQueue* obj) 
{
    if (STEmpty(&obj->pop))
    {
        while (!STEmpty(&obj->push))
        {
            STPush(&obj->pop, STTop(&obj->push));
            STPop(&obj->push);
        }
    }
    int top = STTop(&obj->pop);
    STPop(&obj->pop);

    return top;
}

int myQueuePeek(MyQueue* obj) 
{
    if (STEmpty(&obj->pop))
    {
        while (!STEmpty(&obj->push))
        {
            STPush(&obj->pop, STTop(&obj->push));
            STPop(&obj->push);
        }
    }
    int top = STTop(&obj->pop);

    return top;
}

bool myQueueEmpty(MyQueue* obj) 
{
    return STEmpty(&obj->push) && STEmpty(&obj->pop);
}

void myQueueFree(MyQueue* obj) 
{
    STDesTroy(&obj->push);
    STDesTroy(&obj->pop);

    free(obj);
    obj = NULL;

    return;
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);
 
 * int param_2 = myQueuePop(obj);
 
 * int param_3 = myQueuePeek(obj);
 
 * bool param_4 = myQueueEmpty(obj);
 
 * myQueueFree(obj);
*/