//
//  main.c
//  LinkedList
//
//  Created by Ian Murphy on 1/28/16.
//  Copyright © 2016 Ian Murphy. All rights reserved.
//

#include <stdio.h>
#include "LinkedList.h"

int main(int argc, const char * argv[])
{
    linked_list_t list;
    list = Init_List();
    
    
    for (int i =0; i<10; i++)
    {
        Insert_At_Beginning(list, i);
    }
    
    Print_List(list);
    Print_List_Backwards(list);

    
    
    return 0;
}
