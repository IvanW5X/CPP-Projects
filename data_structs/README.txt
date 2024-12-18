This project is designed to practice and help understand data structures.
Using C++, we will see how storing data differs between different data structures
and examine the time/space complexity of each structure. The project will
help practice C++, memory management, problem solving, and overall programming.

We will be defining and implemting our own version of...
Dynamic Arrays,
Binary Search Trees,
Hashmaps and
Linked-Lists.

Once these structures are implemted, we will explore other data structures and
implement them into the program. The other data structres we will implement will be
Converting a...
1a. Dynamic Array -> Set
1b. Bynamic Array -> Deque
2a. Linked-List -> Queue
2b. Linked-List -> Stack
3a. Binary Search Tree -> AVL Tree
3b. Binary Search Tree -> Heap

Some requirements for the program is that...
There must be no runtime errors,
no segmentation faults,
no memory leaks,
you must be able to handle cases with invalid inputs
(either exit the program or produce an error message) and
all code must be commented neatly.
Also be sure to use good programming practices.

Solution/Implementations/Notes:
    Because this project is very abstract and there isn't a main goal
    (ie. We are not doing anything with the data structures, just implemting them),
    the solutions are very straight forward and explaining each and every structure wouldn't
    be neccessary, so I'll just explain how I implemted the "big" ones. We will really be going
    over adding and removing an element as well as any other majorly important functions.
    Dynamic Array:
    Creating the dyanmic array was pretty simple and was quick to implement. Adding an element
    required an O(1) time complexity as all I did was add the element at index "size" then incremented the size.
    Additionally, I did have to check whether or not there was enough space to add another element, so
    there's a double capacity function which creates a new array double the capacity of the original dyanmic array
    and copies over the data and frees the old array. Removing an element was as simple as overwriting the element
    to be removed by shifting all other element to the right of the unwanted element to the left one space in memory.
    Linked List:
    The linked list was also reletively easy to implement. Adding an element required O(1) time complexity because I
    decided to add every new element to the front of the list instead of the back. Removing an element was as simple as
    reconnecting the list accordingly and freeing the element to be removed.
    Binary Search Tree:
    The BST was completed, but I required outside help from previous assignments I completed or by searching through the web
    for answers and guides. For the BST, I had to create Tree Node functions that used the BST root node as a parameter to
    modify the tree. Adding a node was pretty simple as I used recursion to traverse the tree and place the new data.
    Removing from the tree proved to be a challenge, but here's what I did and my thought proccess going through it.
    First, we have to check whether or not the current node value needs to be deleted. If the value matches, we also have to
    check whether or not the node has a right child. If it does, we need to get the left most node value of the right child
    and copy it to the current node. This value will ensure that the tree is still in order. Next we will have to remove that
    left most node because it is now a duplicate/copy. If the current node does not have a right child, we get the left child,
    delete the current node, and return the left child as the current node.
    Notes:
    This project will be incomplete as it has taken too much time, repetition, and effort than I wanted. The AVL and Heap data
    structure implementations are the main reasons, so for the time being, this project will be marked as done, but it is incomplete.
    The code that has already been implemted will be commented neatly, but any missing chuncks of code will not be filled and I
    will be moving onto another project soon.
