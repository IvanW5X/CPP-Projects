/***************************************************
* Project Title: To-do list
* Date (Started): 6/26/2024
* Date (Finished): 7/1/2024
* File Description: Header file for a node
                    with next and prev pointer
* Author: Ivan Wong
****************************************************/

#ifndef NODE_H
#define NODE_H

#ifndef TYPE
#define TYPE std::string
#endif

class Node {
public:
    TYPE val;
    Node *next;
    Node *prev;
};

#endif