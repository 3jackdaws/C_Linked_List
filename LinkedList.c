

#include "LinkedList.h"
#define NULL (void *)0

typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
}Node;


typedef struct List
{
    Node* head;
    Node* tail;
    int  count;
}List;


linked_list_t* Init_List()
{
    int s = sizeof(List);
    return (linked_list_t *)calloc(1, sizeof(List));
}

int Delete_List(linked_list_t list)
{
    Node * travel =((List *)list)->head;
    while(travel->next)
    {
        travel = travel->next;
        free(travel->prev);
    }
    free(travel);
    free(list);
    return 0;
}

int Insert_At_Beginning(linked_list_t list, int data)
{
    if(((List *)list)->head == 0)
    {
        ((List *)list)->head = ((List *)list)->tail = calloc(1, sizeof(Node));
        ((List *)list)->head->data = data;
    }
    else
    {
        Node * pre_head = ((List *)list)->head;
        ((List *)list)->head = calloc(1, sizeof(Node));
        ((List *)list)->head->data = data;
        ((List *)list)->head->next = pre_head;
        pre_head->prev = ((List *)list)->head;
        ((List *)list)->count++;
    }
    return 0;
}

int Insert_At_End(linked_list_t list, int data)
{
    if(((List *)list)->head == 0)
    {
        ((List *)list)->head = ((List *)list)->tail = calloc(1, sizeof(Node));
        ((List *)list)->head->data = data;
    }
    else
    {
        Node * pre_tail = ((List *)list)->tail;
        ((List *)list)->tail = calloc(1, sizeof(Node));
        ((List *)list)->tail->data = data;
        ((List *)list)->tail->prev = pre_tail;
        pre_tail->next = ((List *)list)->tail;
        ((List *)list)->count++;
    }
    return 0;
}

int Empty(linked_list_t list)
{
    if(((List *)list)->count > 0)
        return 1;
    return 0;
}

int Remove_From_Beginning(linked_list_t list, int* data)
{
    if(((List *)list)->count > 0)
    {
        List * LinkedList = ((List *)list);
    
        *data = LinkedList->head->data;
        LinkedList->count--;
        if(LinkedList->count == 0)
        {
            LinkedList->head = NULL;
            LinkedList->tail = NULL;
        }
        else
        {
            LinkedList->head = LinkedList->head->next;
            LinkedList->head->prev = NULL;
        }
        free(LinkedList->head);
        return 0;
    }
    return -1;
    
}

int Remove_From_End(linked_list_t list, int* data)
{
    return 0;
}

int Count(linked_list_t list)
{
    return ((List*)list)->count;
}

void Print_List(linked_list_t list)
{
    Node * travel = ((List *)list)->head;
    while(travel->next != 0)
    {
        printf("%d\n",travel->data);
        travel = travel->next;
    }
    printf("%d\n",travel->data);
}

void Print_List_Backwards(linked_list_t list)
{
    Node * travel = ((List *)list)->tail;
    while(travel->prev != 0)
    {
        printf("%d\n",travel->data);
        travel = travel->prev;
    }
    printf("%d\n",travel->data);
}

int Traverse(linked_list_t list, void (*action)(int data))
{
    Node * travel = ((List *)list)->head;
    while(travel->next != 0)
    {
        (*action)(travel->data);
        travel = travel->next;
    }
    (*action)(travel->data);
    return 0;
}
