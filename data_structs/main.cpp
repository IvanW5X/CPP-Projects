/***************************************************
* Project Title: Data Structures
* Date (Started): 7/17/2024
* Date (Finished): TBD
* File Description: Driver file for testing user
*                   created data structures
* Author: Ivan Wong
****************************************************/

#include "bst.h"
#include "dyn-array.h"
#include "linked-list.h"
#include "hashmap.h"

void dynArrayTests(DynArray& myDynArray);
void setTests(Set& mySet);
void dequeTests(Deque& myDeque);

void linkedListTest(LinkedList& myList);
void queueTests(Queue& myQueue);
void stackTests(Stack& myStack);

void BSTTests(BST& myBST);
void AVLTests(AVLTree& myAVL);
//void heapTests(Heap& myHeap);

void hashMapTests(HashMap& myHashMap);

void pause() {
        std::cout << "\nPress <enter> to continue...\n";
        std::cin.clear();
        std::cin.ignore(256, '\n');
}

int main(int argc, char **argv) {
    std::cout << "\n"
              << "--------------------------------------------------------------------\n"
              << "Welcome, this is a program that tests data structures created by me\n"
              << "--------------------------------------------------------------------" << std::endl;
    pause();

    std::cout << "TESTING DYNAMIC ARRAYS\n";
    pause();
    DynArray myDynArray;
    dynArrayTests(myDynArray);

    std::cout << "\nTESTING SETS AS A DYNAMIC ARRAY\n";
    pause();
    Set mySet;
    setTests(mySet);

    std::cout << "\nTESTING DEQUES AS A DYNAMIC ARRAY\n";
    pause();
    Deque myDeque;
    dequeTests(myDeque);

    std::cout << "\nTESTING LINKED LISTS\n";
    pause();
    LinkedList myList;
    linkedListTest(myList);

    std::cout << "\nTESTING QUEUES AS A LINKED LIST\n";
    pause();
    Queue myQueue;
    queueTests(myQueue);

    std::cout << "\nTESTING STACKS AS A LINKED LIST\n";
    pause();
    Stack myStack;
    stackTests(myStack);

    std::cout << "\nTESTING BINARY SEARCH TREES\n";
    pause();
    BST myBST;
    BSTTests(myBST);
/*
    std::cout << "\nTESTING AVL TREES\n";
    pause();
    AVLTree myAVL;
    AVLTests(myAVL);
*/
    //Testing Heap

    //pause();


    std::cout << "\nTESTING HASHMAPS\n";
    pause();

    HashMap myHashMap;
    hashMapTests(myHashMap);

    std::cout << "\nEXITING PROGRAM...\n" << std::endl;

    return 0;
}

void dynArrayTests(DynArray& myDynArray) {
    myDynArray.insertToArray(1);
    myDynArray.insertToArray(2);
    myDynArray.insertToArray(3);
    myDynArray.insertToArray(4);
    myDynArray.insertToArray(5);

    std::cout << "Expected: 1 2 3 4 5\n"
              << "Actual:   ";
    myDynArray.printArray();

    myDynArray.removeFromArray(1);
    myDynArray.removeFromArray(5);
    myDynArray.removeFromArray(3);

    std::cout << "Expected: 2 4\n"
              << "Actual:   ";
    myDynArray.printArray();

    std::cout << "Expected: False True\n"
              << "Actual:   ";
    if (!myDynArray.inArray(1))
        std::cout << "False ";
    else
        std::cout << "\nERROR\n";

    if (myDynArray.inArray(2))
        std::cout << "True" << std::endl;
    else
        std::cout << "\nERROR\n";
}

void setTests(Set& mySet) {
    mySet.insertToArray(1);
    mySet.insertToArray(2);
    mySet.insertToArray(2);
    mySet.insertToArray(1);
    mySet.insertToArray(3);

    std::cout << "Expected: 1 2 2 1 3\n"
              << "Actual:   ";
    mySet.printArray();
    std::cout << "Converting...\n\n";
    mySet.dynArrToSet();

    std::cout << "Expected: 1 2 3\n"
              << "Actual:   ";
    mySet.printSet();

    std::cout << "Expected: \nCANNOT ADD DATA\n"
              << "Actual:   ";
    mySet.insertToSet(1);

    mySet.removeFromSet(3);
    mySet.insertToSet(5);
    std::cout << "Expected: 1 2 5\n"
              << "Actual:   ";
    mySet.printSet();
}

void dequeTests(Deque& myDeque) {
    myDeque.pushFront(1);
    myDeque.pushFront(2);
    myDeque.pushFront(3);
    myDeque.pushBack(4);
    myDeque.pushBack(5);
    myDeque.pushBack(6);

    std::cout << "Expected: 3 2 1 4 5 6\n"
              << "Actual:   ";
    myDeque.printDeque();

    myDeque.popBack();
    myDeque.popFront();

    std::cout << "Expected: 2 1 4 5\n"
              << "Actual:   ";
    myDeque.printDeque();

    std::cout << "Expected: 2 5\n"
              << "Actual:   "
              << myDeque.frontEle() << " "
              << myDeque.backEle() << "\n";
}

void linkedListTest(LinkedList& myList) {
    myList.insertToList(1, true);
    myList.insertToList(2, true);
    myList.insertToList(3, false);
    myList.insertToList(4, false);

    std::cout << "Expected: 2 1 3 4\n"
              << "Actual:   ";
    myList.printList();

    myList.insertToList(5, true);
    myList.removeFromList(5);
    myList.removeFromList(4);

    std::cout << "Expected: 2 1 3\n"
              << "Actual:   ";
    myList.printList();

    std::cout << "Expected: True False 3\n"
              << "Actual:   ";
    if (myList.inList(1))
        std::cout << "True ";
    else
        std::cout << "\nERROR\n";
    if (!myList.inList(90))
        std::cout << "False ";
    else
        std::cout << "\nERROR\n";
    std::cout << myList.getSize() << std::endl;
}

void queueTests(Queue& myQueue) {
    myQueue.addQueue(1);
    myQueue.addQueue(2);
    myQueue.addQueue(3);
    myQueue.addQueue(4);

    std::cout << "Expected: 1 2 3 4\n"
              << "Actual:   ";
    myQueue.printQueue();

    myQueue.removeQueue();
    myQueue.removeQueue();
    myQueue.addQueue(5);
    myQueue.addQueue(6);
    myQueue.addQueue(7);

    std::cout << "Expected: 3 4 5 6 7\n"
              << "Actual:   ";
    myQueue.printQueue();

    std::cout << "Expected: 5 False 3\n"
              << "Actual:   "
              << myQueue.getQueueSize();
    if (!myQueue.isEmpty())
        std::cout << " False ";
    else
        std::cout << "\nERROR\n";
    
    std::cout << myQueue.front() << std::endl;
}

void stackTests(Stack& myStack) {
    myStack.pushStack(1);
    myStack.pushStack(2);
    myStack.pushStack(3);
    myStack.pushStack(4);
    myStack.pushStack(5);

    std::cout << "Expected: 5 4 3 2 1\n"
              << "Actual:   ";
    myStack.printStack();

    myStack.popStack();
    myStack.popStack();

    std::cout << "Expected: 3 2 1\n"
              << "Actual:   ";
    myStack.printStack();

    std::cout << "Expected: False 3\n"
              << "Actual:   ";
    if (!myStack.isEmpty())
        std::cout << "False ";
    else
        std::cout << "\nERROR\n";
    
    std::cout << myStack.topStack() << std::endl;
}

void BSTTests(BST& myBST) {
    myBST.addBst(10);
    myBST.addBst(2);
    myBST.addBst(5);
    myBST.addBst(6);
    myBST.addBst(15);

    std::cout << "Expected: 3 2 5 6 10 15 \n"
              << "Actual:   ";
    std::cout << myBST.heightTree() << " ";
    myBST.inOrderPrintTree();

    std::cout << "Expected: False True\n"
              << "Actual:   ";
    if (!myBST.containsBst(100))
        std::cout << "False ";
    else
        std::cout << "\nERROR\n";
    if (myBST.containsBst(2))
        std::cout << "True\n";
    else
        std::cout << "\nERROR\n";

    myBST.removeBst(2);
    myBST.removeBst(15);
    myBST.removeBst(6);

    std::cout << "Expected: 1 5 10\n"
              << "Actual:   ";
    std::cout << myBST.heightTree() << " ";
    myBST.inOrderPrintTree();
}

void AVLTests(AVLTree& myAVL) {

}

//void heapTests(Heap& myHeap) {}

void hashMapTests(HashMap& myHashMap) {
    myHashMap.insertMap("A", 1);
    myHashMap.insertMap("B", 2);
    myHashMap.insertMap("C", 3);
    myHashMap.insertMap("D", 4);
    myHashMap.insertMap("E", 5);

    std::cout << "Expected: A:1 B:2 C:3 D:4 E:5\n"
              << "Actual:   ";
    myHashMap.printMap();

    myHashMap.removeKey("A");
    myHashMap.removeKey("C");
    myHashMap.removeKey("E");
    std::cout << "Expected: B:2 D:4\n"
              << "Actual:   ";
    myHashMap.printMap();

    myHashMap.insertMap("B", 10);
    myHashMap.removeKey("D");

    std::cout << "Expected: KEY DOES NOT EXIST\n"
              << "          B:10\n"
              << "Actual:   ";
    myHashMap.removeKey("ERROR TEST");
    std::cout << "          ";
    myHashMap.printMap();
}