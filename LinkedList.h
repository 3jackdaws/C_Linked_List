#pragma once
//*************************************************
// linked list definition
//
// This header files defines types and functions for a linked list used to
// store key-value pairs.
//
// Author: Philip Howard
// Date:   2015/12/30
//

// Opaque type for lists
typedef void *linked_list_t;

// Create and initialize a list.
// Return pointer to list. Return NULL on failure.
linked_list_t* Init_List();

// Delete a list are free all memory used by the list
// It is erroneous to use the list pointer after caling this routine.
// Return zero on success
int Delete_List(linked_list_t list);

// Insert an item at the beginning of the list
// Return zero on success
// Params:
//    list: list to add item to
//    key: pointer to key for item
//    data: pointer to data for item
int Insert_At_Beginning(linked_list_t list, int data);

// Insert an item at the end of the list
// Return zero on success
// Params:
//    list: list to add item to
//    key: pointer to key for item
//    data: pointer to data for item
int Insert_At_End(linked_list_t list, int data);

// Return true (non-zero) if the list is empty
//    list: list to examine
int Empty(linked_list_t list);

// Remove an item from the beginning of the list
// Return zero on success
// Params:
//    list: list to remove item from
//    key: pointer to location to store key of removed item
//         if key is NULL, key is not returned
//    data: pointer to location to store data of removed item
//          if data is NULL, data is not returned
int Remove_From_Beginning(linked_list_t list, int* data);

// Remove an item from the end of the list
// Return zero on success
// Params:
//    list: list to remove item from
//    key: pointer to location to store key of removed item
//         if key is NULL, key is not returned
//    data: pointer to location to store data of removed item
//          if data is NULL, data is not returned
int Remove_From_End(linked_list_t list, int* data);

int Count(linked_list_t);

void Print_List(linked_list_t list);

void Print_List_Backwards(linked_list_t list);
