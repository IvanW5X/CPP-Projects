/***************************************************
* Project Title: Data Structures
* Date (Started): 7/17/2024
* Date (Finished): TBD
* File Description: Header file for necessary nodes
*                   used for data structures
*                   
* Author: Ivan Wong
****************************************************/

#ifndef TYPES_H
#define TYPES_H

#ifndef TYPE
#define TYPE int
#endif

#ifndef KEY_TYPE
#define KEY_TYPE const char*
#endif

#ifndef ARRAY_CAP
#define ARRAY_CAP 2
#endif

#ifndef HASH_CAP
#define HASH_CAP 2
#endif

#include <iostream>
#include <cstring>

/***************
 * Node Classes
 ***************/
class ListNode {
public:
    TYPE val;
    ListNode *next;
};

class TreeNode {
public:
    TYPE val;
    TreeNode *left;
    TreeNode *right;
};

class HashNode {
public:
    TYPE val;
    KEY_TYPE key;
    HashNode *next;
};

#endif