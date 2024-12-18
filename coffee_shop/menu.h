/* Program name: menu.h
 * Author: Ivan Wong
 * Date: 11/12/23
 * Description: Header file for menu class
 * Input: Function prototypes
 * Ouput: NA
 */

#ifndef MENU_H
#define MENU_H 

#include "coffee.h"

using namespace std;

class Menu {
private:
    int num_coffee;
    Coffee* coffee_arr;
public:
    //need to include accessor functions and mutator functions for private member when appropriate
    //need to include constructors, copy constructors, assignment operator overload,
    //and destructors where appropriate
    //need to use 'const' when appropriate

/**************************************************
 * Name: Menu()
 * Description: Default constructor for a menu
 * Parameters: NA
 * Pre-conditions: Shop is declared somewhere
 * Post-conditions: Menu will be created an populated with nothing
 **************************************************/
Menu();


/**************************************************
 * Name: operator=()
 * Description: Assignment operator overload function for a menu
 * Parameters: Menu& - Menu object that gets copied
 * Pre-conditions: A menu is populated
 * Post-conditions: Menu will be deep copied
 **************************************************/
void operator=(const Menu& otherMenu);


/**************************************************
 * Name: Menu()
 * Description: Copy constructor for a menu
 * Parameters: Menu& - Menu object that gets copied
 * Pre-conditions: A menu is populated
 * Post-conditions: Menu will be deep copied
 **************************************************/
Menu(const Menu& otherMenu);


/**************************************************
 * Name: ~Menu()
 * Description: Menu deconstructor
 * Parameters: NA
 * Pre-conditions: A menu has been dynamically created
 * Post-conditions: Menu will be deleted from heap
 **************************************************/
~Menu();


/**************************************************
 * Name: search_coffee_by_name() const
 * Description: Gets coffee name from user and finds it to print
 *              to screen
 * Parameters: NA
 * Pre-conditions: Coffee array is populated
 * Post-conditions: Desired coffee info will be printed
 **************************************************/
void search_coffee_by_name() const;


/**************************************************
 * Name: search_coffee_by_price() const
 * Description: Gets budget from user and finds coffees within
 *              the budget and prints info to screen
 * Parameters: float - budget that user enters
 * Pre-conditions: Coffee array is populated
 * Post-conditions: All coffee withing the budget will be printed
 *                  to screen
 **************************************************/
void search_coffee_by_price(float budget) const;


/**************************************************
 * Name: update_menu_file() const
 * Description: Writes coffee into the menu text file
 * Parameters: Coffee* - data from coffee array
 *             int& - number of coffees
 * Pre-conditions: Menu txt file exists and menu is filled
 * Post-conditions: Menu txt file will be correctly written into
 **************************************************/
void update_menu_file(Coffee* coffee_arr, int& num_coffee) const;


/**************************************************
 * Name: add_to_menu()
 * Description: Adds a coffee to the coffee array
 * Parameters: Coffee& - coffee object that needs to be added
 * Pre-conditions: Coffee array already exists and is full
 * Post-conditions: New coffee will be added to coffee array
 **************************************************/
void add_to_menu(Coffee& coffee_to_add); //add a coffee object into the Menu


/**************************************************
 * Name: get_remove_coffee_index()
 * Description: Gets the index of coffee user wants to remove
 * Parameters: NA
 * Pre-conditions: Coffee array is populated
 * Post-conditions: Coffee index is returned
 **************************************************/
int get_remove_coffee_index();


/**************************************************
 * Name: remove_from_menu()
 * Description: Removes the coffee from coffee array
 * Parameters: int - index of coffee array to be removed
 * Pre-conditions: User entered a valid name/index
 * Post-conditions: Desired coffee is removed from the coffee array
 **************************************************/
void remove_from_menu(int index_of_coffee_on_menu); //remove a coffee object from the Menu


// feel free to add more member functions

/**************************************************
 * Name: populate_menu()
 * Description: Populates menu variables from the text files given
 * Parameters: ifstream - reads data from shop info file
 * Pre-conditions: There is a function to populate one coffee,
 *                 the files needed are valid for the ifstream
 * Post-conditions: Menu will variables will be populated
 **************************************************/
void populate_menu(ifstream &menuFile);


/**************************************************
 * Name: print_menu() const
 * Description: Prints the array of coffee
 * Parameters: NA
 * Pre-conditions: Coffee array is populated correctly
 * Post-conditions: Menu will be printed to screen
 **************************************************/
void print_menu() const;


/**************************************************
 * Name: print_coffee_name() const
 * Description: Prints the coffee names
 * Parameters: NA
 * Pre-conditions: Coffee array is populated
 * Post-conditions: Coffee names are printed to screen
 **************************************************/
void print_coffee_name() const;


/**************************************************
 * Name: get_coffee_name()
 * Description: Gets coffee name from user
 * Parameters: int - takes the index from user and matches 
 *                   it with the coffee name
 * Pre-conditions: Coffee array is populated
 * Post-conditions: Coffee name is returned
 **************************************************/
string get_coffee_name(int coffeeIndex);


/**************************************************
 * Name: print_coffee_cost() const
 * Description: Prints prices of one coffee
 * Parameters: string - coffee name needed to find prices
 * Pre-conditions: Coffee array is populated
 * Post-conditions: Prices of specific coffee is printed
 **************************************************/
void print_coffee_cost(string coffeeName) const;


/**************************************************
 * Name: calculate_cost()
 * Description: Calculates cost for an order
 * Parameters: string - coffee name needed to match/check
 *             char - size needed to find cost
 *             int - quantity needed to find cost
 * Pre-conditions: Valid coffee name is used
 * Post-conditions: A total cost is correctly determined and returned
 **************************************************/
float calculate_cost(string coffeeName, char size, int quantity);
};

#endif