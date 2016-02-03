

#include "LinkedList.h"

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
    return (linked_list_t *)calloc(1, sizeof(List));
}

int Delete_List(linked_list_t list)
{
    if(list != NULL && ((List *)list)->count > 0)
    {
        List * LinkedList = ((List *)list);
        Node * travel = LinkedList->head;
        while(travel->next)
        {
            travel = travel->next;
            free(travel->prev);
        }
        if(travel != NULL)
            free(travel);
    }
    free(list);
    list = NULL;
    
    return 0;
}

int Insert_At_Beginning(linked_list_t list, int data)
{
    List * LinkedList = ((List*)list);
    if(LinkedList->head == 0)
    {
        LinkedList->head = LinkedList->tail = calloc(1, sizeof(Node));
        LinkedList->head->data = data;
    }
    else
    {
        Node * pre_head = ((List *)list)->head;
        LinkedList->head = calloc(1, sizeof(Node));
        LinkedList->head->data = data;
        LinkedList->head->next = pre_head;
        pre_head->prev = ((List *)list)->head;
        
    }
    LinkedList->count++;
    return 0;
}

int Insert_At_End(linked_list_t list, int data)
{
    
    List * LinkedList = ((List*)list);
    if(LinkedList->head == 0)
    {
        LinkedList->head = LinkedList->tail = calloc(1, sizeof(Node));
        LinkedList->head->data = data;
    }
    else
    {
        Node * pre_tail = LinkedList->tail;
        LinkedList->tail = calloc(1, sizeof(Node));
        LinkedList->tail->data = data;
        LinkedList->tail->prev = pre_tail;
        pre_tail->next = LinkedList->tail;
        
    }
    LinkedList->count++;
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
            free(LinkedList->head);
            LinkedList->head = NULL;
            LinkedList->tail = NULL;
        }
        else
        {
            Node * hold = LinkedList->head;
            LinkedList->head = LinkedList->head->next;
            LinkedList->head->prev = NULL;
            free(hold);
        }
        
        return 0;
    }
    return -1;
    
}

int Remove_From_End(linked_list_t list, int* data)
{
    if(((List *)list)->count > 0)
    {
        List * LinkedList = ((List *)list);
        *data = LinkedList->tail->data;
        LinkedList->count--;
        if(LinkedList->count == 0)
        {
            free(LinkedList->head);
            LinkedList->head = NULL;
            LinkedList->tail = NULL;
        }
        else
        {
            Node * hold = LinkedList->tail;
            LinkedList->tail = LinkedList->tail->prev;
            LinkedList->tail->next = NULL;
            free(hold);
        }
        
        return 0;
    }
    return -1;
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

int Insert_In_Order(linked_list_t list, int data)
{
    List * LinkedList = (List *)list;
    
    Node * travel = LinkedList->head;
    while (travel != NULL && travel->data < data)
    {
        travel = travel->next;
    }
    if(travel)
    {
        if(travel == LinkedList->head)
        {
            Insert_At_Beginning(list, data);
            LinkedList->count--;
        }
        else if(travel == LinkedList->tail)
        {
            Node * nn = calloc(1, sizeof(Node));
            nn->data = data;
            nn->next = LinkedList->tail;
            nn->prev = LinkedList->tail->prev;
            LinkedList->tail->prev->next = nn;
            LinkedList->tail->prev = nn;
        }
        else
        {
            Node * nn = calloc(1, sizeof(Node));
            nn->data = data;
            nn->prev = travel->prev;
            nn->next = travel;
            travel->prev->next = nn;
            travel->prev = nn;
        }
        
    }
    else
    {
        Insert_At_End(list, data);
        LinkedList->count--;
    }
    LinkedList->count++;
    return 0;
}
