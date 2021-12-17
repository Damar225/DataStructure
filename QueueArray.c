typedef struct queue
{
    int front;
    int rear;
    int size;
    QueueEntry entry[MAXQUEUE];
}Queue;

void main()
{

}

void CreateQueue(Queue *pq)
{
    pq->front = 0;
    pq->rear = -1;
    pq->size = 0;
}

void Append(QueueEntry e, Queue *pq)
{
    if(pq->rear == MAXQUEUE-1)
        pq->rear = 0;
    else
        pq->rear++;
    // pq->rear = (pq->rear + 1) % MAXQUEUE;

    pq->entry[pq->rear] = e;
    pq->size++;
}

void Serve(QueueEntry *pe, Queue *pq)
{
    *pe = pq->entry[pq->front];
    if(pq->front == MAXQUEUE-1)
        pq->front = 0;
    else
        pq->front++;
    pq->size--;
}

int QueueEmpty(Queue *pq)
{
    return !pq->size;
}

int QueueFull(Queue *pq)
{
    if(pq->size == MAXQUEUE)
        return 1;
    else
        return 0;
}

int QueueSize(Queue *pq)
{
    return pq->size;
}


void ClearQueue(Queue *pq)
{
    pq->front = 0;
    pq->rear = -1;
    pq->size = 0;
}

void TraverseQueue(Queue *pq, void (*pf)(QueueEntry))
{
    int pos, s;
    for(pos = pq->front, s = 0;s < pq->size;s++)
    {
        (*pf)(pq->entry[pos]);
        pos = (pos+1) % MAXQUEUE;
    }
}
