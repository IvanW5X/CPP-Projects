/***************************************************
* Project Title: To-do list
* Date (Started): 6/26/2024
* Date (Finished): 7/1/2024
* File Description: Main/Driver file 
*                   for to-do list
* Author: Ivan Wong
****************************************************/

#include "todo.h"

int main() {
    ToDo toDoList;
    std::string fileName = "";
    std::string userOption = "";
    std::ifstream getFileInfo;

    //Intro text
    std::cout << "\n"
              << "--------------------------------------\n"
              << "Welcome, this is a to-do list program\n"
              << "--------------------------------------" << std::endl;

    //Get file from user
    fileName = toDoList.getFileName();

    //Invalid file, return with code 1
    if (fileName == "")
        return 1;

    //File successfully opened, initialize list
    toDoList.initToDoList(getFileInfo, fileName);

    //Keep user in program until they choose to exit
    while (userOption != QUIT) {
        toDoList.displayOptions();
        toDoList.handleOptions(userOption);
    }
    //Update txt file
    toDoList.updateToDoFile(fileName);

    std::cout << "\nExiting Program..." << std::endl;

    return 0;
}