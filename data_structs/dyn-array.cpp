/***************************************************
* Project Title: Data Structures
* Date (Started): 7/17/2024
* Date (Finished): TBD
* File Description: Function definitions for dynamic
*                   arrays and dynamic array based
*                   data structures
* Author: Ivan Wong
****************************************************/

#include "dyn-array.h"

/**************************************
 * Dynamic Array Functions Definitions
 **************************************/
DynArray::DynArray() {
    //Set data ptr to null and init array
    this->data = nullptr;
    this->initArray(ARRAY_CAP);
}

void DynArray::initArray(int capacity) {
    //Check if array already initialized
    if (this->data != nullptr) {
        std::cerr << "\nERROR, ARRAY ALREADY INITIALIZED\n";
        return;
    }
    //Create space for data on heap
    this->data = new TYPE[capacity];

    //Set size and capacity
    this->size = 0;
    this->capacity = capacity;

    return;
}

void DynArray::doubleArray() {
    //Check if data exists, if not return
    if (this->data == nullptr) {
        std::cerr << "\nERROR, ARRAY DOES NOT EXIST";
        return;
    }
    //Create more space for data
    TYPE *newdata = new TYPE[this->capacity * 2];

    //Copy data into new array
    for (int i = 0; i < this->size; i++)
        newdata[i] = this->data[i];

    //Delete old data
    delete [] this->data;

    //Point to new data and set capacity
    this->data = newdata;
    this->capacity = this->capacity * 2;

    return;
}

void DynArray::removeAtIndex(int index) {
    //Check if data exists, if not return
    if (this->data == nullptr || this->size <= 0) {
        std::cerr << "\nERROR, ARRAY DOES NOT EXIST\n";
        return;    
    }
    //Checking for valid index
    if (index < 0 || index > this->size - 1) {
        std::cerr << "\nERROR, INDEX OUT OF RANGE\n";
        return;
    }
    //Overide data at index, shift all other data left
    for (int i = index; i < this->size - 1; i++) {
        this->data[i] = this->data[i + 1];
    }
    //Decrement size
    this->size--;

    return;
}

void DynArray::insertToArray(TYPE e) {
    //Check if data exists, if not return
    if (this->data == nullptr) {
        std::cerr << "\nERROR, NOT ENOUGH MEMORY\n";
        return;    
    }
    //Check if more space is needed
    if (this->size >= this->capacity)
        this->doubleArray();
    
    //Add data
    this->data[size] = e;

    //Increment size
    this->size++;

    return;
}

void DynArray::removeFromArray(TYPE e) {
    //Check if data exists, if not return
    if (this->data == nullptr || this->size <= 0) {
        std::cerr << "\nERROR, ARRAY DOES NOT EXIST\n";
        return;    
    }
    //Look for data to remove
    for (int i = 0; i < this->size; i++) {
        //Found data
        if (this->data[i] == e) {
            //Remove data
            this->removeAtIndex(i);

            return;
        }
    }
    return;
}

void DynArray::clearArray() {
    //Check if data exists
    if (this->data != nullptr) {
        //Free memory
        delete [] this->data;

        //Set data to nullptr
        this->data = nullptr;

        //Reset size
        this->size = 0;

        return;
    }
}

bool DynArray::inArray(TYPE e) const {
    //Chekc if data exists, if not return false
    if (this->data == nullptr) {
        std::cerr << "\nERROR, ARRAY DOES NOT EXIST\n";
        return false;
    }
    //Look for data
    for (int i = 0; i < this->size; i++) {
        //Found, return true
        if (this->data[i] == e)
            return true;
    }
    //Not found, return false
    return false;
}

void DynArray::printArray() const {
    //Check if data exists, if not return
    if (this->data == nullptr) {
        std::cerr << "\nERROR, DATA DOES NOT EXIST\n";
        return;
    }
    //Print all data
    for (int i = 0; i < this->size; i++)
        std::cout << this->data[i] << " ";

    std::cout << std::endl;

    return;
}

DynArray::~DynArray() {this->clearArray();}

/***************************
 * Set Function Definitions
 ***************************/

Set::Set() {
    //If dynArray constructor fails, init array
    if (this->data == nullptr)
        this->initArray(ARRAY_CAP);

    this->dynArrToSet();
}

void Set::dynArrToSet() {
    //Check if data exists, if not return
    if (this->data == nullptr) {
        std::cerr << "\nERROR, DATA DOES NOT EXIST";
        return;
    }
    /*NOTE: Optimal solution is to use a hashmap to add unique values in a new array,
            but I'm going to refrain from using outside data structures/libraries */

    //Brute force method for removing dups
    for (int i = 0; i < this->size - 1; i++) {
        for (int j = i + 1; j < this->size; j++) {
            if (this->data[i] == this->data[j]) {
                this->removeAtIndex(j);

                //Adjusting for elements shifting
                j--;
            }
        }
    }
    return;
}

void Set::insertToSet(TYPE e) {
    //Check if data exists, if not return
    if (this->data == nullptr) {
        std::cerr << "\nERROR, NOT ENOUGH MEMORY\n";
        return;
    }
    //Check if value is in set
    if (!this->inArray(e))
        //Not in set, add value
        this->insertToArray(e);
    else
        std::cout << "\nCANNOT ADD DATA\n";

    return;
}

void Set::removeFromSet(TYPE e) {
    //Check if data exists, if not return
    if (this->data == nullptr) {
        std::cerr << "\nERROR, DATA DOES NOT EXIST\n";
        return;
    }
    //Remove data
    this->removeFromArray(e);

    return;
}

bool Set::inSet(TYPE e) const {
    //Reuse dynArray function
    return this->inArray(e);
}

void Set::printSet() const {
    //Reuse dynArray function
    return this->printArray();
}

Set::~Set() {this->clearArray();}

/*****************************
 * Deque Function Definitions
 *****************************/

Deque::Deque() {
    //If dynArray constructor fails, init array
    if (this->data == nullptr)
        this->initArray(ARRAY_CAP);

    //Transform dynArr to deque
    this->dynArrToDeque();
}

void Deque::dynArrToDeque() {
    if (this->data == nullptr) {
        std::cerr << "\nERROR, DATA DOES NOT EXIST\n";
        return;
    }
    //Assuming that largest idx element is the back
    this->front = 0;
    this->back = 0;

    return;
}

void Deque::doubleDeque() {
    //Check if data exists, if not return
    if (this->data == nullptr) {
        std::cerr << "\nERROR, DATA DOES NOT EXIST\n";
        return;
    }
    //Create space for larger array
    TYPE *newData = new  TYPE[this->capacity * 2];

    //Copy data from old -> new array
    for (int i = 0; i < this->size; i++)
        newData[i] = this->data[(this->front + i) % (this->capacity)];

    //Free old data
    delete [] this->data;

    //Point to new data and set new capacity, front, back
    this->data = newData;
    this->capacity = this->capacity * 2;
    this->front = 0;
    this->back = (this->size + this->front) % (this->capacity);

    return;
}

void Deque::clearDeque() {
    //Reuse dynArray function
    if (this->data != nullptr)
        this->clearArray();

    return;    
}

TYPE Deque::frontEle() {
    //Check if front ele exists
    if (this->size > 0)
        return this->data[this->front];
    else
        //Data does not exist, throw error and abort
        throw std::out_of_range("\nERROR, DATA NOT FOUND\n");
}

TYPE Deque::backEle() {
    //Check if back ele exists
    if (this->size > 0)
        return this->data[this->back];
    else
        //Data does not exist, throw error and abort
        throw std::out_of_range("\nERROR, DATA NOT FOUND\n");
}

void Deque::pushFront(TYPE e) {
    //Check if data exists, if not return
    if (this->data == nullptr) {
        std::cout << "\nERROR, DATA DOES NOT EXISTS\n";
        return;
    }
    //Check if more space is needed
    if (this->size >= this->capacity)
        this->doubleDeque();

    //Calculate front index, insert data, increment size
    this->front = (this->front + this->capacity - 1) % (this->capacity);
    this->data[this->front] = e;
    this->size++;

    return;
}

void Deque::popFront() {
    //Check if data exists, if not return
    if (this->data == nullptr || this->size <= 0) {
        std::cout << "\nERROR, DATA DOES NOT EXISTS\n";
        return;
    }
    //Recalculate front index, removing access to ele, decrement size
    this->front = (this->front + this->capacity + 1) % (this->capacity);
    this->size--;
    
    return;
}

void Deque::pushBack(TYPE e) {
    //Check if data exists, if not return
    if (this->data == nullptr) {
        std::cout << "\nERROR, DATA DOES NOT EXISTS\n";
        return;
    }
    //Check if more space is needed
    if (this->size >= this->capacity)
        this->doubleDeque();

    //Calculate back index, insert data, increment size
    this->back = (this->size + this->front) % this->capacity;
    this->data[this->back] = e;
    this->size++;

    return;
}

void Deque::popBack() {
    //Check if data exists, if not return
    if (this->data == nullptr || this->size <= 0) {
        std::cout << "\nERROR, DATA DOES NOT EXISTS\n";
        return;
    }
    //Recalculate back index, removing access to ele, decremeent size
    this->back = (this->back - 1) % this->capacity;
    this->size--;

    return;
}

void Deque::printDeque() const {
    //Check if data exists, if not return
    if (this->data == nullptr) {
        std::cerr << "\nERROR, DATA DOES NOT EXISTS\n";
        return;
    }
    //Traverse down array
    for (int i = 0; i < this->size; i++)
        //Start from front index and go down array
        std::cout << this->data[(this->front + i) % (this->capacity)] << " ";
    
    std::cout << std::endl;

    return;
}

Deque::~Deque() {this->clearDeque();}