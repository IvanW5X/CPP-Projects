/***************************************
 * Program Name: stalactites.h
 * Author: Ivan Wong
 * Date: 11/26/23
 * Description: Function prototypes for stalactites class
 * Inputs: NA
 * Outputs: NA
 ***************************************/

#ifndef STALACTITES_H
#define STALACTITES_H 

#include "event.h"

using namespace std;

class Stalactites : public Event {
private:
public:

/**************************************************
 * Name: encounter()
 * Description: Does nothing
 * Parameters: NA
 * Pre-conditions: User has entered a room with stalactites
 * Post-conditions: NA
 **************************************************/
void encounter();


/**************************************************
 * Name: percept()
 * Description: Prints percept message for stalactites
 * Parameters: NA
 * Pre-conditions: User is close to a stalactite
 * Post-conditions: Stalactite percept message will be printed
 **************************************************/
void percept() const;


/**************************************************
 * Name: print()
 * Description: Returns symbol for stalactites
 * Parameters: NA
 * Pre-conditions: NA
 * Post-conditions: Stalactites symbol will be returned
 **************************************************/
string print() const;
};

#endif
