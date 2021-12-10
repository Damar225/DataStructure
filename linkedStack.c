#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct stacknode
{
    int entry;
    struct stacknode *next;
}StackNode;

typedef struct stack
{
    StackNode *top;
}Stack;

void main()
{
    Stack s;
    CreateStack(&s);
    push(8, &s);


    int x  = 20;

}

// create stack
void CreateStack(Stack *ps)
{
    ps->top = NULL;
}

// Push element
void Push(int e, Stack *ps)
{
    int *pn = (int*) malloc(sizeof(int));
    pn->entry = e;
    pn->next = ps->top;
    ps->top = pn;
}

// Pop element
void Pop(int *pe, Stack *ps)
{
    (*pe) = ps->top->entry;
    StackNode *pn = ps->top;
    ps->top = ps->top->next;
    free(pn);
}

// Stack Empty
int StackEmpty(Stack *ps)
{
    return ps->top == NULL;
}

// Stack Full
int StackFull(stack *ps)
{
    return 0;
}

// Clear Stack
void ClearStack(Stack *ps)
{
    StackNode *pn = ps->top;
    StackNode *qn = ps->top;
    while(pn->next != NULL){
        pn = pn->next;
        free(qn);
        qn = pn;
    }
    ps->top = NULL;
}

// Traverse Stack
void TraverseStack(Stack *ps, void (*pf)(int))
{
    StackNode *pn = ps->top;
    while(pn)
    {
        (*pf)(pn->entry);
        pn = pn->next;
    }
}

// Stack Size
int StackSize(Stack *ps)
{
    StackNode *pn = ps->top;
    int sum;
    for(sum = 0; pn; pn=pn->top)
        sum++;

    return sum;
}
