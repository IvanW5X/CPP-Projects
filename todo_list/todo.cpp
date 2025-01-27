/***************************************************
* Project Title: To-do list
* Date (Started): 6/26/2024
* Date (Finished): 7/1/2024
* File Description: Function definitions 
*                   for todo list
* Author: Ivan Wong
 ***************************************************/

#include "todo.h"

ToDo::ToDo() {this->initDlist();}

void ToDo::displayOptions() const {
    //Print options to terminal
    std::cout << "\n\033[34mSelect an Option\033[0m\n"      // Blue
         << "  1. Add a task\n"
         << "  2. Remove a task\n"
         << "  3. Display tasks\n"
         << "  4. Clear to-do list\n"
         << "  5. Exit program" << std::endl;

    return;
}

std::string ToDo::getFileName() {
    std::string fileName = "";
    std::ifstream openFile;

    //Ask user for file name
    std::cout << "\nEnter File Name: ";
    std::cin  >> fileName;

    //Open file name
    openFile.open(fileName);

    //Failed to open file
    if (openFile.fail()) {
        std::cerr << "\nFile Not Found, Exiting..." << std::endl;

        //Return empty string
        return "";
    }
    std::cout << "\nOpening " << fileName << std::endl;

    //Close file
    openFile.close();

    //Return file name as a string
    return fileName;
}

void ToDo::initToDoList(std::ifstream &fileptr, std::string &fileName) {
    std::string task = "";
    int size = 0;
    
    //Open file
    fileptr.open(fileName);
    
    //Get size of list from file
    fileptr >> size;

    //Get new line buffer
    getline(fileptr, task);

    //Get data from file and add to to-do list
    if (size > 0) {
        for (int i = 0; i < size; i++) {
            getline(fileptr, task);
            this->addDlist(task);
        }
    }
    //Close file
    fileptr.close();

    return;
}

void ToDo::displayTasks() const{
    int i = 1;

    //No tasks in list
    if (this->head == nullptr) {
        std::cout << "\nThere are No Tasks in the To-Do List" << std::endl;

        return;
    }
    Node *temp = this->head;

    std::cout << "\nList of Tasks:\n";

    //Traverse down list
    while (temp != nullptr) {
        //Print values of list
        std::cout << "  " << i << ". " << temp->val << std::endl;
        temp = temp->next;
        i++;
    }
    return;
}

void ToDo::addTask() {
    std::string task = "";

    //Ask user for task
    std::cout << "\nAdd Your Task: ";

    //Ignore buffer
    std::cin.ignore();

    //Get task from user
    getline(std::cin, task);

    //Add task to list
    this->addDlist(task);

    std::cout << "Successfully Added task" << std:: endl;

    return;
}

TYPE ToDo::getTaskFromIndex(int index) {
    Node *temp = this->head;

    //Get node with desired index
    for (int i = 0; i < index - 1; i++)
        temp = temp->next;
    
    //Return node value
    return temp->val;
}

void ToDo::removeTask() {
    //Display tasks
    this->displayTasks();

    //No tasks in list, return
    if (this->size < 1 || this->head == nullptr)
        return;

    std::string index = "";
    std::string task = "";

    while (true) {
        //Error handling
        try {
            //Ask user for task index
            std::cout << "\nWhich Task Would You Like to Remove?";
            std::cout << "\nEnter Index: ";
            std::cin >> index;

            //Check for valid index range
            if (stoi(index) < 1 || stoi(index) > this->size)
                //Not in range, throw out_of_range error
                throw std::out_of_range("Index out of range");

            //Get task from index
            task = this->getTaskFromIndex(stoi(index));

            //Remove task from list
            this->removeDlist(task);

            std::cout << "Successfully Removed Task" << std::endl;

            return;
        }
        //Error handling for invalid strings
        catch (const std::invalid_argument &e) {
            std::cerr << "\nInvalid Input, Enter a number 1-" << this->size << std::endl;
        }
        //Error hanlding for invalid index
        catch (const std::out_of_range &e) {
            std::cerr << "\nInvalid Input, Enter a number 1-" << this->size << std::endl;
        }
    }
    return;
}

void ToDo::clearToDoList() {
    //Check for any items in list
    if (this->head != nullptr) {
        this->freeList();

        std::cout << "Successfully Cleared To-Do List" << std::endl;
    }
    else
        std::cout << "\nThere are No Tasks in the To-Do List" << std::endl;;

    return;
}

void ToDo::handleOptions(std::string &userOption) {
    //Get option from user
    std::cout << "\nYour Choice: ";
    std::cin >> userOption;

    //Error handling
    try {
        //Switch case used to handle options, stoi() used to convert string -> int
        switch (stoi(userOption)) {
            case 1:
                this->addTask();
                break;
            case 2:
                this->removeTask();
                break;
            case 3:
                this->displayTasks();
                break;
            case 4:
                this->clearToDoList();
                break;
            case 5:
                return;
                break;
        }
    }
    //Catch all other invalid inputs
    catch (const std::invalid_argument &e) {
        //Print error message
        std::cout << "\nInvalid Input, Enter a Number 1-" << this->size << std::endl;
    }
    return;
}

void ToDo::updateToDoFile(std::string &fileName) {
    std::ofstream updateFileInfo;
    Node *temp = this->head;

    //Open file in output mode
    updateFileInfo.open(fileName, std::ios::out);

    //Failed to open file, return
    if (updateFileInfo.fail())
        return;

    //Write size to file
    updateFileInfo << this->size << std::endl;

    //Traverse list
    while (temp != nullptr) {
        //Write tasks to file
        updateFileInfo << temp->val << std::endl;
        temp = temp->next;
    }
    //Close file
    updateFileInfo.close();

    return;
}

ToDo::~ToDo() {this->freeList();}