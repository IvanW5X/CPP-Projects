This is a to-do list program where a user will be able to add and remove a task
to a to-do list. The list will also be saved when the user exits, so that when
the user returns to the program and runs it, the list from the previous
session will be used.

The user will have choices to...
print the list,
add a task the list,
remove a task from the list,
clear the list and
exit program.

Some additional requirements are that...
a txt file must be used to access the list (hint, use file pointers),
removing a task that doesn't exist must produce an error message,
attempting to remove a task while no tasks are in the list must produce an error message,
attempting to print the list when no tasks are in the list must provide a message stating
that there are no tasks to be completed,
makefile must be used,
code must be commented and formatted neatly and,
use good practice when coding your solutions.

Solution/Implementation:
    Representing to-do list:
    I decided to use a linked list for the to-do list and just so that I can further practice
    my programming/problem solving skills, I used a doubly linked list even though there is no
    need to use one.
    Saving data from to-do list:
    Saving data from previous sessions was relatively easy. I decided to use the fstream library
    and wrote to the file upon existing the program and initializing the list by opening the txt
    file.
    Implementations:
    Please refer to the .h and .cpp files. All functions and code is commented neatly for
    readability.