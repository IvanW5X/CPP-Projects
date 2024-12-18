/***************************************************
* Project Title: Data Structures
* Date (Started): 7/17/2024
* Date (Finished): TBD
* File Description: Header file for hashmap data structure
* Author: Ivan Wong
****************************************************/

#ifndef HASHMAP_H
#define HASHMAP_H

#include "types.h"

class HashMap {
private:
    int size;
    HashNode **table;
    int capacity;
public:
/********************
 * HashMap Functions
 ********************/
HashMap();
int HASH(KEY_TYPE str) const;
void initHashMap(int capacity);
void insertMap(KEY_TYPE k, TYPE e);
void resizeMap();
TYPE* atMap(KEY_TYPE k) const;
bool containsKey(KEY_TYPE k) const;
void removeKey(KEY_TYPE k);
void clearMap();
void printMap() const;
~HashMap();

};

#endif