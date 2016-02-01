//
//  main.c
//  LinkedList
//
//  Created by Ian Murphy on 1/28/16.
//  Copyright © 2016 Ian Murphy. All rights reserved.
//

#include <stdio.h>
#include "LinkedList.h"

int Print(int data)
{
    printf("%d\n", data);
    return 0;
}

int main(int argc, const char * argv[])
{
    linked_list_t list;
    list = Init_List();
    
    
    for (int i =0; i<10; i++)
    {
        Insert_At_Beginning(list, i);
    }
    int * mydata = malloc(sizeof(int));
    Remove_From_Beginning(list, mydata);
    Traverse(list, &Print);

    
    
    return 0;
}
