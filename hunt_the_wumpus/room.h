/***************************************
 * Program Name: room.h
 * Author: Ivan Wong
 * Date: 11/26/23
 * Description: Function prototypes for room class
 * Inputs: NA
 * Outputs: NA
 ***************************************/
#ifndef ROOM_H
#define ROOM_H 

#include "event.h"
#include <iostream>

using namespace std;

//Room Interface
//Note: Each room may be empty or has an event (bat, gold, stalactite, or wumpus);
//		Use event polymorphically

class Room {
private:
    bool hasAdventurer;
    Event *event;
public:

/**************************************************
 * Name: Room()
 * Description: Default constructor for Room class 
 * Parameters: NA
 * Pre-conditions: NA 
 * Post-conditions: Room will be constructed to nothing or NULL
 **************************************************/
Room();


/**************************************************
 * Name: set_event()
 * Description: Sets event in a room object
 * Parameters: Event* - new event pointer being set into room
 * Pre-conditions: Room object exists
 * Post-conditions: Room object will have an event pointer or NULL
 **************************************************/
void set_event(Event *newEvent);


/**************************************************
 * Name: get_event()
 * Description: Returns an event pointer
 * Parameters: NA
 * Pre-conditions: Room object exists
 * Post-conditions: An event pointer or NULL will returned
 **************************************************/
Event* get_event() const;


/**************************************************
 * Name: set_adventurer()
 * Description: Sets adventurer in a room
 * Parameters: bool - room has or doesn't have an adv.
 * Pre-conditions: Room object exists
 * Post-conditions: A room will have an adv
 **************************************************/
void set_adventurer(bool hasAdv);


/**************************************************
 * Name: get_adventurer()
 * Description: Returns room bool for an adventurer
 * Parameters: NA
 * Pre-conditions: Room object exists 
 * Post-conditions: Bool will return true or false
 **************************************************/
bool get_adventurer() const;
};

#endif