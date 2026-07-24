//存储数据类型---int
typedef char STDataType;

//栈-结构体
typedef struct Stack
{
	STDataType* arr;//栈地址
	int top;//有效数据个数---栈顶位置
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

//打印栈的所有元素
void STPrint(ST* ps)
{
	assert(ps);

	//遍历打印
	for (int i = 0; i < ps->top; i++)
	{
		printf("%d ", ps->arr[i]);
	}
	printf("\n");

	return;
}

//判断栈是否为空
bool STEmpty(ST* ps)
{
	assert(ps);

	return ps->top == 0;
}

//在栈的顶部放入元素
void STPush(ST* ps, STDataType x)
{
	assert(ps);

	//空间不足，申请空间
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

	//返回数组尾部元素
	return ps->arr[ps->top - 1];
}

//在栈的顶部删除元素
void STPop(ST* ps)
{
	assert(ps && !STEmpty(ps));

	ps->top--;

	return;
}

//获取栈的有效元素个数
int STSize(ST* ps)
{
	assert(ps);

	return ps->top;
}

//销毁栈
void STDesTroy(ST* ps)
{
	assert(ps);

	//销毁
	free(ps->arr);
	ps->arr = NULL;
	ps->top = ps->capacity = 0;

	return;
}


bool isValid(char* s) 
{
    ST st;
    STInit(&st);

    while (*s)
    {
        if (*s == '(' || *s == '[' || *s == '{')
        {
            STPush(&st, *s);
            s++;
        }
        else
        {
            if (STEmpty(&st))
            {
                return false;
            }
            else
            {
                char top = STTop(&st);

                if (top == '(' && *s == ')' || top == '[' && *s == ']' || top == '{' && *s == '}')
                {   
                    STPop(&st);
                    s++;
                }
                else
                {
                    return false;
                }
            
            }
        }

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