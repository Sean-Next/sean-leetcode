//栈的储存数据类型
typedef char STDataType;

typedef struct Stack
{
	STDataType* arr;//栈的地址
	int top;//指向栈顶位置---有效数据个数
	int capacity;//空间大小
}ST;

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

	if (ps != NULL)
	{
		free(ps->arr);
	}

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

//判断栈是否为空
bool STEmpty(ST* ps)
{
	return ps->top == 0;
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

bool isValid(char* s) 
{
    ST st;
    STInit(&st);

    char* p = s;

    while (*p)
    {
        if (*p == '(' || *p == '[' || *p == '{')
        {
            STPush(&st, *p);
        }
        else
        {
            if (STEmpty(&st))
            {
                return false;
            }
            
            int top = STTop(&st);

            if ((*p == ')' && top == '(') || (*p == ']' && top == '[') || (*p == '}' && top == '{'))
            {
                STPop(&st);
            }
            else
            {
                return false;
            }
        }
        p++;
    }

    if (STEmpty(&st))
    {
        return true;
    }
    else
    {
        return false;
    }
}