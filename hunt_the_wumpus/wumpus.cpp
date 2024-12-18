/***************************************
 * Program Name: wumpus.cpp
 * Author: Ivan Wong
 * Date: 11/26/23
 * Description: Function definitions for wumpus class
 * Inputs: NA
 * Outputs: NA
 ***************************************/

#include "wumpus.h"

#include <iostream>

using namespace std;

//Wumpus Implementation

void Wumpus::encounter() {        //Prints encounter message
    cout << "---------------------------------------\n"
         << "You've entered the Wumpus' room... RIP" << endl
         << "---------------------------------------\n";
}

void Wumpus::percept() const {      //Prints percept message
    cout << "-----------------------------\n"
         << "You smell a terrible stench." << endl
         << "-----------------------------\n";
}

string Wumpus::print() const {      //Returns wumpus symbol
    return "W";
}