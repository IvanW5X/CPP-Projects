/* Program name: order.cpp
 * Author: Ivan Wong
 * Date: 11/12/23
 * Description: Function definitions for order class
 * Input: All user input for order options
 * Ouput: Order object
 */

#include "order.h"

using namespace std;


//function defintions from order.h goes here


Order::Order() {        //Default constructor
    id = 0;         //Init. all variables to 0 or NULL
    coffee_name = "";
    coffee_size = '\0';
    quantity = 0;
}

char Order::get_size() {        //Get size from user
    char size1 = '\0';
    cout << "\nSmall (s)  Medium(m)  Large(l)\n\n";

    do {
        cout << "Which size would you like?\n"      //Ask user for size
             << "Enter size: ";
        cin >> size1;

        if (size1 != 's' && size1 != 'm' && size1 != 'l') {     //Handles invalid inputs
            cout << "\nInvalid Input, Try Again\n\n";
        }
        else {
            return size1;       //Return valid size
        }
    } while (true);     //Keep user in loop until valid input entered
}

int Order::get_quantity() {     //Get quantity from user
    int amount = 0;
    
    do {
        cout << "Enter quantity: ";     //Ask user for quantity
        cin >> amount;

        if (amount < 0) {       //Input needs to be a positive number
            cout << "\nEnter a positive number\n\n";
        }
    } while (amount < 0);       //Keep user in loop until valid input entered

    return amount;
}

Order Order::fill_order(int newId, string newCoffeeName, char newSize, int newQuantity) {   //Fills one order
    Order newOrder;

    newOrder.id = newId;
    newOrder.coffee_name = newCoffeeName;
    newOrder.coffee_size = newSize;
    newOrder.quantity = newQuantity;

    return newOrder;        //Returns filled order
}

void Order::print_order() const {       //Prints info of one order
    cout << id << " "
         << coffee_name << " "
         << coffee_size << " "
         << quantity << endl;
}

void Order::write_order(ofstream& orderFile) const {    //Writes into of one order
    orderFile << id << " "
              << coffee_name << " "
              << coffee_size << " "
              << quantity << endl;
}