/***************************************
 * Program Name:
 * Author:
 * Date:
 * Description:
 * Inputs:
 * Outputs:
 ***************************************/

#ifndef GOLD_H
#define GOLD_H 

#include "event.h"

using namespace std;

//Gold Interface

class Gold : public Event{
private:
    bool encountered = false;
public:

/**************************************************
 * Name: encounter()
 * Description: Prints encounter message and returns true for encountered
 * Parameters: NA
 * Pre-conditions: User has entered room with gold
 * Post-conditions: Encounter message will be printed and
 *                  gold will be found
 **************************************************/
void encounter();


/**************************************************
 * Name: percept()
 * Description: Prints percept message for gold
 * Parameters: NA
 * Pre-conditions: NA
 * Post-conditions: Percept message will be printed
 **************************************************/
void percept() const;


/**************************************************
 * Name: print()
 * Description: Returns gold symbol
 * Parameters: NA
 * Pre-conditions: NA
 * Post-conditions: Gold symbol will be returned
 **************************************************/
string print() const;
};

#endif