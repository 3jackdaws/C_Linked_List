//
//  main.c
//  LinkedList
//
//  Created by Ian Murphy on 1/28/16.
//  Copyright © 2016 Ian Murphy. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

int Print(int data)
{
    printf("%d  ", data);
    return 0;
}

int main(int argc, const char * argv[])
{
    linked_list_t list;
 
    printf("Init List\n");
    list = Init_List();
    
    printf("Insert numbers 0-9 at beginning\n");
    for (int i =0; i<10; i++)
    {
        Insert_At_Beginning(list, i);
    }
    Traverse(list, (void *)&Print);
    printf("\n");
    printf("Insert numbers 10-19 at end\n");
    for (int i =10; i<20; i++)
    {
        Insert_At_End(list, i);
    }
    int * mydata = malloc(sizeof(int));
    printf("Remove from beginning.\nValue removed: ");
    Remove_From_Beginning(list, mydata);
    printf("%d\n", *mydata);
    
    printf("Print list after removing beginning.\n");
    Traverse(list, (void *)&Print);
    printf("\n");
    
    printf("Remove from beginning twice more.\n");
    
    Remove_From_Beginning(list, mydata);
    Remove_From_Beginning(list, mydata);
    
    printf("Print list again.\n");
    Traverse(list, (void *)&Print);
    printf("\n");
    
    printf("Remove from end of list.\nValue removed: ");
    Remove_From_End(list, mydata);
    Print(*mydata);
    printf("Print list after removing end.\n");
    Traverse(list, (void *)&Print);
    printf("\n");
    printf("\nDeleting list.\n");
    free(mydata);
    mydata = NULL;
    Delete_List(list);
    
    printf("Reinit List\n");
    //free(list);
    list = Init_List();
    printf("Insert in order 10 random numbers.\n");
    for (int i = 0; i<20; i++)
    {
        int ran = rand()%100;
        printf("Inserting: %d\n", ran);
        Insert_In_Order(list, ran);
    }
    printf("Printing List:\n");
    Traverse(list, (void *)&Print);
    printf("\n");
    Delete_List(list);
    linked_list_t list2;
    Delete_List(list2);
    Init_List(list2);
    Delete_List(list2);
    
    
    return 0;
}
