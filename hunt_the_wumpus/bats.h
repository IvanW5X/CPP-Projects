/***************************************
 * Program Name: bats.h
 * Author: Ivan Wong
 * Date: 11/26/23
 * Description: Function prototypes for bats class
 * Inputs: NA
 * Outputs: NA
 ***************************************/

#ifndef BATS_H
#define BATS_H 

#include "event.h"

using namespace std;

//Bats Interface

class Bats : public Event {
private:
public:

/**************************************************
 * Name: encounter()
 * Description: Prints message for when user encounters a bat
 * Parameters: NA
 * Pre-conditions: User has entered same room as a bat
 * Post-conditions: Bat encounter message will be printed
 **************************************************/
void encounter();


/**************************************************
 * Name: percept()
 * Description: Prints percept message for when user is close to a bat
 * Parameters: NA
 * Pre-conditions: User is adjacent to a bat
 * Post-conditions: Bat percept message will be printed
 **************************************************/
void percept() const;


/**************************************************
 * Name: print()
 * Description: Returns symbol for bats
 * Parameters: NA
 * Pre-conditions: NA
 * Post-conditions: Bat symbol will be returned
 **************************************************/
string print() const;
};

#endif