/***************************************************
* Project Title: Data Structures
* Date (Started): 7/17/2024
* Date (Finished): TBD
* File Description: Header file for dynamic arrays and
*                   dynamic array based data structures
* Author: Ivan Wong
****************************************************/

#ifndef DYN_ARRAY_H
#define DYN_ARRAY_H

#include "types.h"

class DynArray {
protected:
    int size;
    int capacity;
    TYPE *data;
public:
/**************************
 * Dynamic Array Functions
 **************************/
DynArray();
void initArray(int capacity);
void doubleArray();
void removeAtIndex(int index);
~DynArray();

/**************************
 * Dynamic Array Interface
 **************************/
void insertToArray(TYPE e);
void removeFromArray(TYPE e);
void clearArray();
bool inArray(TYPE e) const;
void printArray() const;

};

class Set : public DynArray{
private:
public:
/*********************************
 * Dynamic Array -> Set Functions
 *********************************/
Set();
void dynArrToSet();
~Set();

/****************
 * Set Interface
 ****************/
void insertToSet(TYPE e);
void removeFromSet(TYPE e);
bool inSet(TYPE e) const;
void printSet() const;

};

class Deque : public DynArray{
private:
    int front;
    int back;
public:
/***********************************
 * Dynamic Array -> Deque Functions
 ***********************************/
Deque();
void dynArrToDeque();
void doubleDeque();
void clearDeque();
~Deque();

/******************
 * Deque Interface
 ******************/
TYPE frontEle();
TYPE backEle();
void pushFront(TYPE e);
void popFront();
void pushBack(TYPE e);
void popBack();
void printDeque() const;

};

#endif