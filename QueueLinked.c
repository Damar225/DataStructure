typedef struct queuenode
{
    QueueEntry entry;
    struct queuenode *next;
} QueueNode;

typedef struct queue
{
    QueueNode *front;
    QueueNode *rear;
    int size;
} Queue;

void main()
{

}

void CreateQueue(Queue *pq)
{
    pq->front = NULL;
    pq->rear = NULL;
    pq->size = 0;
}

void Append(QueueEntry e, Queue *pq)
{
    QueueNode *pn = (QueueNode*) malloc(sizeof(QueueNode));
    pn->entry = e;
    pn->next = NULL;

    if(!pq->rear)
        pq->front = pn;
    else
        pq->rear->next = pn;

    pq->rear = pn;
    pq->size++;
}

void Serve(QueueEntry *pe, Queue *pq)
{
    QueueNode *pn = pq->front;
    pq->front = pq->front->next;
    *pe = pn->entry;
    if(!pq->front)
        pq->rear = NULL;

    free(pn);
    pq->size--;
}

int QueueEmpty(Queue *pq)
{
    return !pq->front;
}

int QueueFull(Queue *pq)
{
    return 0;
}

int QueueSize(Queue *pq)
{
    return pq->size;
}

void ClearQueue(Queue *pq)
{
    while(pq->front)
    {
        pq->rear = pq->front->next;
        free(pq->front);
        pq->front = pq->rear;
    }
    pq->size = 0;
}

void TraverseQueue(Queue *pq, void (*pf)(QueueEntry))
{
    for(QueueNode *pn = pq->front;pn; pn=pn->next)
        (*pf)(pn->entry);
}
