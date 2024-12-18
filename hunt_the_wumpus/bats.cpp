/***************************************
 * Program Name: bats.cpp
 * Author: Ivan Wong
 * Date: 11/26/23
 * Description: Function definitions for bats class
 * Inputs: NA
 * Outputs: NA
 ***************************************/

#include "bats.h"

#include <iostream>

using namespace std;

void Bats::encounter() {      //Prints encounter message
    cout << "--------------------------------\n"
         << "You entered a room full of bats!" << endl
         << "You now feel hazed and confused." << endl
         << "--------------------------------\n";
}

void Bats::percept() const {        //Prints percept message
    cout << "---------------------------\n"
         << "You hear wings flapping..." << endl
         << "---------------------------\n";
}

string Bats::print() const {        //Returns bat symbol
    return "B";
}