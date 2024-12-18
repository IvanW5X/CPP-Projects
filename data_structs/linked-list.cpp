/***************************************************
* Project Title: Data Structures
* Date (Started): 7/17/2024
* Date (Finished): TBD
* File Description: Function definitions for linked lists
*                   and linked list based data structures
* Author: Ivan Wong
****************************************************/

#include "linked-list.h"

/************************
 * Linked List Function Definitions
 ************************/
LinkedList::LinkedList() {this->initList();}

void LinkedList::initList() {
    this->head = nullptr;
    this->size = 0;
}

void LinkedList::clearList() {
    if (this->head == nullptr)
        return;

    //Create nodes to traverse list
    ListNode *cur = this->head;
    ListNode *prev = nullptr;

    while (cur != nullptr) {
        //Assign nodes accordingly
        prev = cur;
        cur = cur->next;

        //Free prev node data
        this->removeFromList(prev->val);
    }
    return;
}

void LinkedList::insertFront(TYPE e) {
    //Create new node and copy value
    ListNode *newNode = new ListNode;
    newNode->val = e;

    //Check if list empty
    if (this->head == nullptr) {
        //Empty, assign new node to be head
        this->head = newNode;
        newNode->next = nullptr;
    }
    else {
        //Not empty, connect node to list and make new node the head
        newNode->next = this->head;
        this->head = newNode;
    }
    //Increment size
    this->size++;

    return;
}

void LinkedList::insertBack(TYPE e) {
    //If list if empty, insert to front
    if (this->head == nullptr) {
        this->insertFront(e);
        return;
    }
    //Create temp node for traversal
    ListNode *temp = this->head;

    //Create new node and copy value
    ListNode *newNode = new ListNode;
    newNode->val = e;
    newNode->next = nullptr;

    //Go to last node
    while (temp->next != nullptr)
        temp = temp->next;

    //Connect new node to end of list
    temp->next = newNode;

    //Increment size
    this->size++;
    
    return;
}

void LinkedList::insertToList(TYPE e, bool flag) {
    //If true, insert to front
    if (flag == true)
        this->insertFront(e);
    
    //If false, insert to back
    else
        this->insertBack(e);
}

void LinkedList::removeFromList(TYPE e) {
    //Check if list is empty, if so return
    if (this->head == nullptr) {
        std::cout << "\nLIST IS EMPTY\n";
        return;
    }
    if (this->head->val == e) {
        //Save next node
        ListNode *temp = this->head->next;

        //Delete head
        delete this->head;

        //Temp becomes new head and dec size
        this->head = temp;
        this->size--;

        return;
    }
    //Create temp nodes for traversal
    ListNode *cur = this->head;
    ListNode *prev = nullptr;

    while (cur != nullptr) {
        prev = cur;
        cur = cur->next;

        //Value found, delete and return
        if (cur->val == e) {
            prev->next = cur->next;
            delete cur;
            this->size--;

            return;
        }
    }
    return;
}

bool LinkedList::inList(TYPE e) const{
    //Check if data exists, if not return
    if (this->head == nullptr) {
        std::cout << "\nLIST IS EMPTY\n";
        return false;
    }
    ListNode *temp = this->head;

    //Traverse down list
    while (temp->next != nullptr) {
        //Found, return true
        if (temp->val == e)
            return true;

        temp = temp->next;
    }
    //Not found, return false
    return false;
}

int LinkedList::getSize() const{
    //Data does not exist, return 0
    if (this->head == nullptr)
        return 0;

    ListNode *temp = this->head;
    int counter = 0;

    //Traverse down list
    while (temp != nullptr) {
        //Node exists, inc counter and continue
        counter++;
        temp = temp->next;
    }
    return counter;
}

void LinkedList::printList() const {
    //Check if data exists, if not return
    if (this->head == nullptr)
        return;

    ListNode *temp = this->head;

    //Start from head, print value and traverse
    while (temp != nullptr) {
        std::cout << temp->val << " ";
        temp = temp->next;
    }

    std::cout << std::endl;

    return;
}

LinkedList::~LinkedList() {this->clearList();}

/*****************************
 * Queue Function Definitions
 *****************************/
Queue::Queue() {this->initList();}

void Queue::addQueue(TYPE e) {
    this->insertBack(e);

    return;
}

TYPE Queue::removeQueue() {
    if (this->head == nullptr) {
        //Data does not exist, throw error and abort
        throw std::out_of_range("\nERROR, DATA NOT FOUND\n");
    }
    ListNode *temp = this->head;
    TYPE data = temp->val;

    this->removeFromList(temp->val);

    return data;
}

TYPE Queue::front() const {
    if (this->head == nullptr)
        //Data does not exist, throw error and abort
        throw std::out_of_range("\nERROR, DATA NOT FOUND\n");

    return this->head->val;
}

bool Queue::isEmpty() const {
    return this->size == 0;
}

int Queue::getQueueSize() const {
    return this->getSize();
}

void Queue::clearQueue() {
    this->clearList();

    return;
}

void Queue::printQueue() const {
    this->printList();

    return;
}

Queue::~Queue() {this->clearQueue();}

/*****************************
 * Stack Function Definitions
 *****************************/
Stack::Stack() {this->initList();}

void Stack::pushStack(TYPE e) {
    this->insertFront(e);

    return;
}

TYPE Stack::popStack() {
    if (this->head == nullptr)
        //Data does not exist, throw error and abort
        throw std::out_of_range("\nERROR, DATA NOT FOUND\n");

    ListNode *temp = this->head;
    TYPE data = temp->val;

    this->removeFromList(temp->val);

    return data;
}

TYPE Stack::topStack() const {
    if (this->head == nullptr)
        //Data does not exist, throw error and abort
        throw std::out_of_range("\nERROR, DATA NOT FOUND\n");
    
    return this->head->val;
}

bool Stack::isEmpty() const {
    return this->size == 0;
}

int Stack::getStackSize() const {
    return this->getSize();
}

void Stack::clearStack() {this->clearList();}

void Stack::printStack() const {
    this->printList();

    return;
}

Stack::~Stack() {this->clearStack();}