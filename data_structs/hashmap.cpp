/***************************************************
* Project Title: Data Structures
* Date (Started): 7/17/2024
* Date (Finished): TBD
* File Description: Function definitions for hashmap
*                   data structure
* Author: Ivan Wong
****************************************************/

#include "hashmap.h"

/*******************************
 * HashMap Function Definitions
 *******************************/
HashMap::HashMap() {
    this->table = nullptr;
    this->initHashMap(HASH_CAP);
}

int HashMap::HASH(KEY_TYPE str) const {
    int hashNum = 0;

    //Use ASCII value of string and iterator to obtain hash index
    for (int i = 0; str[i] != '\0'; i++) {
        hashNum += str[i];
        hashNum += i;
    }
    return hashNum;
}

void HashMap::initHashMap(int capacity) {
    //Check if data exists, if not return
    if (this->table != nullptr) {
        std::cout << "\nERROR, HASHMAP ALREADY INITIALIZED\n";
        return;
    }
    //Create array of hash node ptrs
    this->table = new HashNode*[capacity];

    //Init each ptr to nullptr
    for (int i = 0; i < capacity; i++)
        this->table[i] = nullptr;

    //Set size and capacity
    this->capacity = capacity;
    this->size = 0;

    return;
}

void HashMap::insertMap(KEY_TYPE k, TYPE e) {
    //Check if data exists, if not return
    if (this->table == nullptr) {
        std::cout << "\nERROR, DATA DOES NOT EXIST\n";
        return;
    }
    //Check if key already exists
    if (containsKey(k)) {
        //Get value
        TYPE *temp = this->atMap(k);
        
        //Update value
        *temp = e;

        return;
    }
    //If table is same size as cap, resize
    if (this->size == this->capacity)
        this->resizeMap();

    //Create new node and set key/value
    HashNode *newNode = new HashNode;
    newNode->key = k;
    newNode->val = e;

    //Get index, connect new node
    int idx = abs(this->HASH(k)) % this->capacity;
    newNode->next = this->table[idx];

    //Set new node as "head"
    this->table[idx] = newNode;
    this->size++;

    return;
}

void HashMap::resizeMap() {
    //Check if data exists, if not return nullptr
    if (this->table == nullptr) {
        std::cout << "\nERROR, DATA DOES NOT EXIST\n";
        return;
    }
    //Create new table with double the capacity
    HashNode **newTable = new HashNode*[this->capacity * 2];

    //Used for traversal of nodes
    HashNode *temp = nullptr;
    HashNode *tempNext = nullptr;
    int idx = 0;

    //Assign new table [] to nullptr
    for (int i = 0; i < this->capacity * 2; i++)
        newTable[i] = nullptr;

    //Go through table length
    for (int i = 0; i < this->capacity; i++) {
        temp = this->table[i];

        //Go through each list in table
        while (temp != nullptr) {
            //Find new idx for node
            idx = abs(this->HASH(temp->key)) % (this->capacity * 2);

            //Save next node
            tempNext = temp->next;

            //Connect old node to new table
            temp->next = newTable[idx];

            //Assign node to new table
            newTable[idx] = temp;

            //Move on to next node
            temp = tempNext;
        }
    }
    //Delete old table, assign new table and capacity
    delete [] this->table;
    this->table = newTable;
    this->capacity *= 2;

    return;
}   

TYPE* HashMap::atMap(KEY_TYPE k) const {
    //Check if data exists, if not return nullptr
    if (this->table == nullptr) {
        std::cout << "\nERROR, DATA DOES NOT EXIST\n";
        return nullptr;
    }
    //Get hash index
    int idx = abs(this->HASH(k)) % this->capacity;

    //Temp node to traverse ptrs
    HashNode *temp = this->table[idx];

    while (temp != nullptr) {
        //Check for matching key
        if (temp->key == k)
            //Found, return address
            return &temp->val;
        
        temp = temp->next;
    }
    //Not found, return nullptr
    return nullptr;
}

bool HashMap::containsKey(KEY_TYPE k) const {
    //Check if data exists, if not return
    if (this->table == nullptr) {
        std::cout << "\nERROR, DATA DOES NOT EXIST\n";
        return false;
    }
    //Check if key exists, if not return false, otherwise return true
    if (this->atMap(k) == nullptr)
        return false;
    else
        return true;
}

void HashMap::removeKey(KEY_TYPE k) {
    //Check if data exists, if not return
    if (this->table == nullptr) {
        std::cout << "\nERROR, DATA DOES NOT EXIST\n";
        return;
    }
    //Get index using HASH
    int idx = abs(this->HASH(k)) % this->capacity;
    HashNode *temp = this->table[idx];

    //No node at the index, return
    if (temp == nullptr) {
        std::cout << "KEY DOES NOT EXIST\n";
        return;
    }
    //Case for first node is the key, delete, dec size, return
    if (temp->key == k) {
        this->table[idx] = this->table[idx]->next;
        delete temp;
        this->size--;

        return;
    }
    HashNode *prev = nullptr;

    //Case for multiple nodes in list
    while (temp != nullptr) {
        prev = temp;

        //Go to second node
        temp = temp->next;

        //Key found
        if (temp->key == k) {
            //Reconnect list
            prev->next = temp->next;

            //Delete node with key, dec size, returb
            delete temp;
            this->size--;

            return;
        }
    }
    //Key not found, return
    std::cout << "KEY DOES NOT EXIST\n";

    return;
}

void HashMap::clearMap() {
    //Check if data exists, if not return
    if (this->table == nullptr) {
        std::cout << "\nERROR, DATA DOES NOT EXIST\n";
        return;
    }
    //Traverse table []
    for (int i = 0; i < this->capacity; i++) {
        HashNode *cur = this->table[i];
        HashNode *prev = nullptr;

        //Traverse list in each table
        while (cur != nullptr) {
            //Delete the prev node and move on
            prev = cur;
            cur = cur->next;
            delete prev;
        }
    }
    //Reset size
    this->size = 0;

    return;
}

void HashMap::printMap() const {
    //Check if data exists, if not return
    if (this->table == nullptr) {
        std::cout << "\nERROR, DATA DOES NOT EXIST\n";
        return;
    }
    //Go through table []
    for (int i = 0; i < this->capacity; i++) {
        HashNode *temp = this->table[i];

        //Go through each list in table
        while (temp != nullptr) {
            //Print key and value
            std::cout << temp->key << ":" << temp->val << " ";

            //Move onto next node
            temp = temp->next;
        }
    }
    std::cout << std::endl;

    return;
}

HashMap::~HashMap() {this->clearMap(); delete [] this->table;}