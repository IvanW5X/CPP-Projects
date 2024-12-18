/***************************************
 * Program Name: event.h
 * Author: Ivan Wong
 * Date: 11/26/23
 * Description: Function prototypes for event class
 * Inputs: NA
 * Outputs: NA
 ***************************************/

#ifndef EVENT_H
#define EVENT_H 

#include <string>

using namespace std;

//Event Interface
//Note: this must be an abstract class!

class Event {
protected:
public:

/**************************************************
 * Name: encounter()
 * Description: Prints out message for when user encounters an event
 * Parameters: NA
 * Pre-conditions: User has entered the same room as an event
 * Post-conditions: Encounter message will be printed
 **************************************************/
virtual void encounter() = 0;


/**************************************************
 * Name: percept()
 * Description: Prints out message for when user is close to an event
 * Parameters: NA
 * Pre-conditions: User is adjacent to an event
 * Post-conditions: Percept message will be printed
 **************************************************/
virtual void percept() const = 0;


/**************************************************
 * Name: print()
 * Description: Returns the symbol for an event
 * Parameters: NA
 * Pre-conditions: A room has an event
 * Post-conditions: The symbol for the event will be returned
 **************************************************/
virtual string print() const = 0;
};

#endif