/***************************************
 * Program Name: stalactites.cpp
 * Author: Ivan Wong
 * Date: 11/26/23
 * Description: Function definitions for stalactites object
 * Inputs: NA
 * Outputs: NA
 ***************************************/

#include "stalactites.h"

#include <iostream>

using namespace std;

//Stalactites Implementation

void Stalactites::encounter() {}        //There is no stalactite encounter message

void Stalactites::percept() const {         //Prints percept message
    cout << "-------------------------\n"
         << "You hear water dripping." << endl
         << "-------------------------\n";
}

string Stalactites::print() const {         //Returns stalactites symbol
    return "S";
}