/***************************************
 * Program Name: room.cpp
 * Author: Ivan Wong
 * Date: 11/26/23
 * Description: Function definitions for room class
 * Inputs: NA
 * Outputs: NA
 ***************************************/

#include "room.h"

using namespace std;

//Room Implementation

Room::Room() {      //Default constructor for room class
    hasAdventurer = false;
    event = nullptr;
}

void Room::set_event(Event* newEvent) {     //Setter for event ptr
    if (this->event != nullptr) {
        delete this->event;             //Delete pointer event if there's already on there
    }
    this->event = newEvent;             //Set event ptr to new event ptr
}

Event* Room::get_event() const {        //Getter for event ptr
    return this->event;
}

void Room::set_adventurer(bool hasAdv) {    //Setter for adv bool
    this->hasAdventurer = hasAdv;
}

bool Room::get_adventurer() const {         //Getter for adv bool
    return this->hasAdventurer;
}