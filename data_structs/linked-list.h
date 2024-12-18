/***************************************************
* Project Title: Data Structures
* Date (Started): 7/17/2024
* Date (Finished): TBD
* File Description: Header file for linked lists and
*                   linked list based data structures
* Author: Ivan Wong
****************************************************/

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "types.h"

class LinkedList {
protected:
    ListNode *head;
    int size;
public:
/************************
 * Linked List Functions
 ************************/
LinkedList();
void initList();
void clearList();
void insertFront(TYPE e);
void insertBack(TYPE e);
~LinkedList();

/************************
 * Linked List Interface
 ************************/
void insertToList(TYPE e, bool flag);
void removeFromList(TYPE e);
bool inList(TYPE e) const;
int getSize() const;
void printList() const;

};

class Queue : public LinkedList {
private:
public:
/*********************************
 * Linked List -> Queue Functions
 *********************************/
Queue();
~Queue();

/******************
 * Queue Interface
 ******************/
void addQueue(TYPE e);
TYPE removeQueue();
TYPE front() const;
bool isEmpty() const;
int getQueueSize() const;
void clearQueue();
void printQueue() const;

};

class Stack : public LinkedList {
private:
public:
/*********************************
 * Linked List -> Stack Functions
 *********************************/
Stack();
~Stack();

/******************
 * Stack Interface
 ******************/
void pushStack(TYPE e);
TYPE popStack();
TYPE topStack() const;
bool isEmpty() const;
int getStackSize() const;
void clearStack();
void printStack() const;

};

#endif