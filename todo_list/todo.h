/***************************************************
* Project Title: To-do list
* Date (Started): 6/26/2024
* Date (Finished): 7/1/2024
* File Description: Header file for 
*                   todo list
* Author: Ivan Wong
 ***************************************************/

#ifndef TODO_H
#define TODO_H

#define QUIT "5"

#include <fstream>
#include "dlist.h"

class ToDo : public DList{
private:
public:
/***************************************************
 * Description:
 * Constructor function for the ToDo class
 *
 * Assuming:
 * N/A
 *
 * Output:
 * To-do list is initialized
 ***************************************************/
ToDo();


/***************************************************
 * Description:
 * Prints the inroduction to the terminal when the program
 * is loaded. Displays what the program is and it's options.
 *
 * Assuming:
 * User has not selected an option
 *
 * Output:
 * Options displayed
 ***************************************************/
void displayOptions() const;


/***************************************************
 * Description:
 * Get name of file and returns the name as a string
 *
 * Assuming:
 * File name has not been found/set yet
 *
 * Output:
 * File name OR empty string if file name not found
 ***************************************************/
std::string getFileName();


/***************************************************
 * Description:
 * Initializes to-do list, grabs data from txt file
 *
 * Assuming:
 * Valid txt file
 *
 * Output:
 * Double linked lists with tasks from previous session
 ***************************************************/
void initToDoList(std::ifstream &fileptr, std::string &fileName);


/***************************************************
 * Description:
 * Displays tasks from the to-do list
 *
 * Assuming:
 * To-do list has been initialized
 *
 * Output:
 * Tasks form list printed to terminal
 ***************************************************/
void displayTasks() const;


/***************************************************
 * Description:
 * Adds a task to the to-do list
 *
 * Assuming:
 * To-do list has been initialized
 *
 * Output:
 * New task added to end of list
 ***************************************************/
void addTask();


/***************************************************
 * Description:
 * Gets a task from a desired index
 *
 * Assuming:
 * Valid index is provided
 *
 * Output:
 * Task returned as a string
 ***************************************************/
TYPE getTaskFromIndex(int index);


/***************************************************
 * Description:
 * Removes a task from the to-do list
 *
 * Assuming:
 * To-do list has been initialized
 *
 * Output:
 * List returned with desired task removed
 ***************************************************/
void removeTask();


/***************************************************
 * Description:
 * Clears all tasks from the to-do list
 *
 * Assuming:
 * To-do list has been initialized
 *
 * Output:
 * Memory from to-do list is freed
 ***************************************************/
void clearToDoList();


/***************************************************
 * Description:
 * Takes in user input adn decides what to do with it
 *
 * Assuming:
 * To-do list has been initialized and txt file is valid
 *
 * Output:
 * Reroutes user to another function
 ***************************************************/
void handleOptions(std::string &userOption);


/***************************************************
 * Description:
 * Updates the txt file with current task data
 *
 * Assuming:
 * To-do list has been initialized
 *
 * Output:
 * Txt file opened is now updated with the current list
 ***************************************************/
void updateToDoFile(std::string &fileName);


/***************************************************
 * Description:
 * Destructor function for ToDo class
 *
 * Assuming:
 * N/A
 *
 * Output:
 * Frees any memory allocated to list
 ***************************************************/
~ToDo();
};

#endif