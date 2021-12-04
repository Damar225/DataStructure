typedef struct stack
{
    int top;
    StackEntry entry[MAXSTACK];
}Stack;

void CreatStack(Stack *ps)
{
    ps->top = 0;
}

void Push(StackEntry e, Stack *ps)
{
    ps->entry[ps->top++] = e;
}

void main()
{

}
