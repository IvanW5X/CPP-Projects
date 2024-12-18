/***************************************************
* Project Title: To-do list
* Date (Started): 6/26/2024
* Date (Finished): 7/1/2024
* File Description: Header file for double 
*                   linked list
* Author: Ivan Wong
****************************************************/

#ifndef DLIST_H
#define DLIST_H

#include <iostream>
#include <string>
#include "node.h"

class DList {
protected:
    Node *head;
    int size;
public:
/***************************************************
 * Description:
 * Constructor function for DList class
 *
 * Assuming:
 * Node class/struct exists
 *
 * Output:
 * DList is initialized
 ***************************************************/
DList();


/***************************************************
 * Description:
 * Initializes a DList
 *
 * Assuming:
 * Node class/struct exists
 *
 * Output:
 * DList is initialized
 ***************************************************/
void initDlist();


/***************************************************
 * Description:
 * Adds a node to the end of a DList
 *
 * Assuming:
 * DList is initialized
 *
 * Output:
 * DList with new node at the end
 ***************************************************/
void addDlist(TYPE e);


/***************************************************
 * Description:
 * Removes a node from a DList
 *
 * Assuming:
 * DList is initialized
 *
 * Output:
 * DList with desired node removed
 ***************************************************/
void removeDlist(TYPE e);


/***************************************************
 * Description:
 * Frees all nodes from a DList
 *
 * Assuming:
 * DList is initialized
 *
 * Output:
 * DList with no more allocated memory
 ***************************************************/
void freeList();


/***************************************************
 * Description:
 * Destructor function for DList class
 *
 * Assuming:
 * DList is initialized
 *
 * Output:
 * DList with no more allocated memory
 ***************************************************/
~DList();
};

#endif