typedef struct 
{
    int* arr;
    int front;
    int rear;
    int capacity;
    
} MyCircularQueue;

bool myCircularQueueIsEmpty(MyCircularQueue* obj) 
{
    return obj->front == obj->rear;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) 
{
    return obj->front == (obj->rear + 1) % (obj->capacity + 1);
}

MyCircularQueue* myCircularQueueCreate(int k) 
{
    MyCircularQueue* Queue = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));

    Queue->arr = (int*)malloc(sizeof(int) * (k + 1));
    Queue->front = Queue->rear = 0;
    Queue->capacity = k;

    return Queue;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) 
{
    if (myCircularQueueIsFull(obj))
    {
        return false;
    }

    obj->arr[obj->rear++] = value;
    obj->rear = obj->rear % (obj->capacity + 1);

    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) 
{
    if (myCircularQueueIsEmpty(obj))
    {
        return false;
    }

    obj->front++;
    obj->front = obj->front % (obj->capacity + 1);

    return true;
}

int myCircularQueueFront(MyCircularQueue* obj) 
{
    if (myCircularQueueIsEmpty(obj))
    {
        return -1;
    }

    return obj->arr[obj->front];
}

int myCircularQueueRear(MyCircularQueue* obj) 
{
    if (myCircularQueueIsEmpty(obj))
    {
        return -1;
    }
    int prev = obj->rear - 1;
    prev = (prev + obj->capacity + 1) % (obj->capacity + 1);
    return obj->arr[prev];
}

void myCircularQueueFree(MyCircularQueue* obj) 
{
    free(obj->arr);
    free(obj);

    return;
}

/**
 * Your MyCircularQueue struct will be instantiated and called as such:
 * MyCircularQueue* obj = myCircularQueueCreate(k);
 * bool param_1 = myCircularQueueEnQueue(obj, value);
 
 * bool param_2 = myCircularQueueDeQueue(obj);
 
 * int param_3 = myCircularQueueFront(obj);
 
 * int param_4 = myCircularQueueRear(obj);
 
 * bool param_5 = myCircularQueueIsEmpty(obj);
 
 * bool param_6 = myCircularQueueIsFull(obj);
 
 * myCircularQueueFree(obj);
*/