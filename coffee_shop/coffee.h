/* Program name: coffee.h
 * Author: Ivan Wong
 * Date: 11/12/23
 * Description: Header file for coffee class
 * Input: Function prototypes for coffee class
 * Ouput: NA
 */

#ifndef COFFEE_H
#define COFFEE_H

#include <string>
#include <fstream>
#include <iostream>

using namespace std;

class Coffee {
private:
    string name;
    float small_cost;
    float medium_cost;
    float large_cost;
    
public:
    //need to include accessor functions and mutator functions for private member when appropriate
    //need to include constructors and destructors where appropriate
    //need to use 'const' when appropriate

/**************************************************
 * Name: Coffee()
 * Description: Default coffee constructor
 * Parameters: NA
 * Pre-conditions: Coffee object exist
 * Post-conditions: A coffee object will be created and empty
 **************************************************/
Coffee();


/**************************************************
 * Name: get_name() const
 * Description: Gets name of coffee
 * Parameters: NA
 * Pre-conditions: NA
 * Post-conditions: Returns the name of a coffee
 **************************************************/
string get_name() const;


/**************************************************
 * Name: get_small_cost() const
 * Description: Gets small cost of a coffee
 * Parameters: NA
 * Pre-conditions: NA
 * Post-conditions: Returns small cost of a coffee
 **************************************************/
float get_small_cost() const;


/**************************************************
 * Name: get_medium_cost() const
 * Description: Gets medium cost of a coffee
 * Parameters: NA
 * Pre-conditions: NA
 * Post-conditions: Returns medium cost of a coffee
 **************************************************/
float get_medium_cost() const;


/**************************************************
 * Name: get_large_cost() const
 * Description: Get large cost of a coffee
 * Parameters: NA
 * Pre-conditions: NA
 * Post-conditions: Returns large cost of a coffee
 **************************************************/
float get_large_cost() const;


/**************************************************
 * Name: populate_coffee()
 * Description: Populates one coffee object using data from a txt file
 * Parameters: ifstream - reads data and stores values into a coffee object
 * Pre-conditions: Menu text file exists and is written into correctly
 * Post-conditions: One coffee object will be filled
 **************************************************/
void populate_coffee(ifstream& coffeeFile);


/**************************************************
 * Name: print_coffee() const
 * Description: Prints info of one coffee
 * Parameters: NA
 * Pre-conditions: Coffee object is filled
 * Post-conditions: Coffee info will be printed to the screen
 **************************************************/
void print_coffee() const;


/**************************************************
 * Name: add_coffee_info()
 * Description: Asks user for new coffee info and returns the object
 * Parameters: NA
 * Pre-conditions: User wants new coffee
 * Post-conditions: New coffee object will be filled correctly
 **************************************************/
Coffee add_coffee_info();


/**************************************************
 * Name: print_coffee_name() const
 * Description: Prints coffee name
 * Parameters: NA
 * Pre-conditions: Coffee object has a name
 * Post-conditions: Coffee name will be printed to screen
 **************************************************/
void print_coffee_name() const;
};

#endif