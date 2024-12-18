/***************************************
 * Program Name: gold.cpp
 * Author: Ivan Wong
 * Date: 11/26/23
 * Description: Function definitions for gold class
 * Inputs: NA
 * Outputs: NA
 ***************************************/

#include "gold.h"

#include <iostream>

using namespace std;

//Gold Implementation

void Gold::encounter() {        //Prints out encounter message
    if (this->encountered == false) {
        cout << "--------------------\n"
             << "You found the gold!" << endl
             << "--------------------\n";
        this->encountered = true;    //Gold is found
    }
}

void Gold::percept() const {          //Prints out percept message
    if (this->encountered == false) {
        cout << "--------------------------\n"
             << "You see a glimmer nearby." << endl
             << "--------------------------\n";
    }
}

string Gold::print() const {    //Returns gold symbol
    return "G";
}