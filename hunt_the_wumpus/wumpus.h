/***************************************
 * Program Name: wumpus.h
 * Author: Ivan Wong
 * Date: 11/26/23
 * Description: Function prototypes for wumpus class
 * Inputs: NA
 * Outputs: Na
 ***************************************/

#ifndef WUMPUS_H
#define WUMPUS_H 

#include "event.h"

using namespace std;

//Wumpus Interface

class Wumpus : public Event {
private:
public:

/**************************************************
 * Name: encounter()
 * Description: Prints encounter message for wumpus class
 * Parameters: NA
 * Pre-conditions: User has entered a room with the wumpus
 * Post-conditions: Wumpus encounter message will be printed
 **************************************************/
void encounter();


/**************************************************
 * Name: percept()
 * Description: Prints percept message for wumpus class
 * Parameters: NA
 * Pre-conditions: User is close to the wumpus
 * Post-conditions: Wumpus percept message will be printed
 **************************************************/
void percept() const;


/**************************************************
 * Name: print()
 * Description: Returns the wumpus symbol
 * Parameters: NA
 * Pre-conditions: NA
 * Post-conditions: Wumpus symbol will be returned
 **************************************************/
string print() const;
};

#endif