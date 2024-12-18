/***************************************************
* Project Title: To-do list
* Date (Started): 6/26/2024
* Date (Finished): 7/1/2024
* File Description: Function definitions for 
*                   double linked list
* Author: Ivan Wong
****************************************************/

#include "dlist.h"

DList::DList() {initDlist();}

void DList::initDlist() {
    this->head = nullptr;
    this->size = 0;

    return;
}

void DList::addDlist(TYPE e) {
    //Create new node and copy val
    Node *newNode = new Node;
    newNode->val = e;

    //Check if head is already null
    if (this->head == nullptr) {
        //Head is null, make new node the head
        this->head = newNode;
        this->head->next = nullptr;
        this->head->prev = nullptr;
        this->size++;

        return;
    }

    //Create temp node to traverse list
    Node *temp = this->head;

    //Traverse to end of list
    while (temp->next != nullptr)
        temp = temp->next;
    
    //Add new node to list, connect accordingly
    temp->next = newNode;
    newNode->prev = temp;
    newNode->next = nullptr;
    this->size++;

    return;
}

void DList::removeDlist(TYPE e) {
    //List is empty, return
    if (this->head == nullptr)
        return;
    
    //Create temp node to traverse list
    Node *temp = this->head;

    //Check if head is the node to be removed
    if (temp->val == e) {
        //Set new head as the next node in list
        this->head = temp->next;
        
        //Next head isn't null, set prev ptr to nullptr
        if (this->head != nullptr)
            this->head->prev = nullptr;
        
        //Free memory, dec size, return
        delete temp;
        this->size--;

        return;
    }
    //Traverse down list
    while (temp != nullptr) {
        //Check for matching
        if (temp->val == e) {
            //Reconnect list checking if the pointers exist
            if (temp->prev != nullptr)
                temp->prev->next = temp->next;

            if (temp->next != nullptr)
                temp->next->prev = temp->prev;

            //Free temp, dec size, return
            delete temp;
            this->size--;

            return;
        }
        else
            //Traverse down list
            temp = temp->next;
    }
    return;
}

void DList::freeList() {
    //Check if list has any memory to be freed
    if (this->head == nullptr)
        return;
    
    Node *cur = this->head;
    Node *prev = nullptr;

    while (cur != nullptr) {
        prev = cur;
        cur = cur->next;

        removeDlist(prev->val);
    }
    //Reset size to 0
    this->size = 0;

    return;
}

DList::~DList() {this->freeList();}