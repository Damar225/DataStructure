#include <stdlib.h>
#include <stdio.h>

typedef struct node
{
    int info;
    struct node *next;
}Node;

typedef struct linkedlist
{
    Node *start;
}LinkedList;

void CreateLinkedList(LinkedList*);

void main()
{
    LinkedList list;
    CreateLinkedList(&list);
    InsertAtStart(&list, 3);
    InsertAtStart(&list, 2);
    InsertAtStart(&list, 1);
    InsertAtEnd(&list, 4);
    InsertAtEnd(&list, 5);
    InsertAtEnd(&list, 6);
    InsertAfterPos(&list, 7, 4);
    PrintLinkedList(&list);

}

/*
--------------------------
-- General
--------------------------
*/


void CreateLinkedList(LinkedList *plist)
{
    plist->start = NULL;
}

void PrintLinkedList(LinkedList *plist)
{
    Node *ptr = plist->start;
    while(ptr !=NULL)
    {
        printf("%d --> ", ptr->info);
        ptr = ptr->next;
    }
}

/*
--------------------------
-- Insertion
--------------------------
*/

void InsertAtStart(LinkedList *list, int element)
{
    Node *pn = (Node*)malloc(sizeof(Node));
    pn->info = element;
    pn->next = list->start;
    list->start = pn;
}

void InsertAtEnd(LinkedList *plist, int element)
{
    Node *pn = (Node*)malloc(sizeof(Node));
    pn->info = element;
    pn->next = NULL;
    Node *ptr = plist->start;
    while(ptr->next !=NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = pn;
}

void InsertAfterPos(LinkedList *plist, int element, int value)
{
    Node *pn = (Node*)malloc(sizeof(Node));
    pn->info = element;
    Node *ptr = plist->start;

    while(ptr != NULL)
    {
        if(ptr->info == value)
        {
            pn->next = ptr->next;
            ptr->next = pn;
            return;
        }
        else
        {
            ptr = ptr->next;
        }
    }
}

void InsertBeforePos(LinkedList *plist, int element, int value)
{
    Node *pn = (Node*)malloc(sizeof(Node));
    pn->info = element;
    Node *ptr = plist->start;
    Node *prev = plist->start;

    while(ptr != NULL)
    {
        if(ptr->info == value)
        {
            pn->next = ptr;
            prev->next = pn;
            return;
        }
        else
        {
            prev = ptr;
            ptr = ptr->next;
        }
    }
}

