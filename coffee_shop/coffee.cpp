/* Program name: coffee.cpp
 * Author: Ivan Wong
 * Date: 11/12/23
 * Description: 
 * Input: 
 * Ouput: 
 */

#include "coffee.h"

using namespace std;


//function defintions from coffee.h goes here

Coffee::Coffee() {      //Default constructor
    name = "";
    small_cost = 0;
    medium_cost = 0;
    large_cost = 0;
}

void Coffee::populate_coffee(ifstream &coffeeFile) {        //Get data of one coffee
    coffeeFile >> name
               >> small_cost
               >> medium_cost
               >> large_cost;
}

string Coffee::get_name() const {     //Get name of coffee
    return name;
}

float Coffee:: get_small_cost() const {     //Get small cost
    return small_cost;
}

float Coffee:: get_medium_cost() const {        //Get medium cost
    return medium_cost;
}

float Coffee:: get_large_cost() const {     //Get large cost
    return large_cost;
}

void Coffee::print_coffee() const {     //Print one coffee
    cout << name << endl
         << "   Small: $" << small_cost << endl
         << "   Medium: $" << medium_cost << endl
         << "   Large: $" << large_cost << endl << endl;
}

void Coffee::print_coffee_name() const {
    cout << name << endl;
}

//Function is under 15 lines if you dont include declarations
Coffee Coffee::add_coffee_info() {      //Gets info for new coffee
    Coffee coffee_to_add;
    string coffeeName = "";
    float newScost, newMcost, newLcost;

    cout << "\nEnter coffee name: ";        //Ask user for name
    cin >> coffeeName;

    cout << "Enter small price: ";      //Ask user for small price
    cin >> newScost;

    cout << "Enter medium price: ";     //Ask user for medium price
    cin >> newMcost;

    cout << "Enter large price: ";      //Ask user for large price
    cin >> newLcost;

    coffee_to_add.name = coffeeName;
    coffee_to_add.small_cost = newScost;    //Set coffee equal to user inputs
    coffee_to_add.medium_cost = newMcost;
    coffee_to_add.large_cost = newLcost;

    return coffee_to_add;
}