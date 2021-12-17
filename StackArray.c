/*
    Accessing Mechanism:
    - CreateStack, Push, StackFull, Pop

*/

typedef struct stack
{
    int top;
    StackEntry entry[MAXSTACK];
}Stack;

void CreateStack(Stack *ps)
{
    ps->top = 0;
}

void Push(StackEntry e, Stack *ps)
{
    ps->entry[ps->top++] = e;
}

void Pop(StackEntry *pe, Stack *ps)
{
    ps->top--;
    *pe = ps->entry[ps->top];
}

void StackTop(StackEntry *pe, Stack *ps)
{
    *pe = ps->entry[ps->top -1];
}

int StackEmpty(Stack *ps)
{

    if(ps->top == 0)
        return 1;
    else
        return 0;
    // return !ps->top;
}

int StackSize(Stack *ps)
{
    return ps->top;
}

int StackFull(Stack *ps)
{
    if(ps->top == MAXSTACK)
        return 1;
    else
        return 0;
    // return ps->top >= MAXSTACK;
}

void ClearStack(Stack *ps)
{
    ps->top = 0;
}
