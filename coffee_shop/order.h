/* Program name: order.h
 * Author: Ivan Wong
 * Date: 11/12/23
 * Description: Header file for order class
 * Input: Function prototypes
 * Ouput: NA
 */

#ifndef ORDER_H
#define ORDER_H 

#include <string>
#include "menu.h"

using namespace std;

class Order
{
private:
	int id;
	string coffee_name;
	char coffee_size;
	int quantity;

public:
	//need to include accessor functions and mutator functions for private member when appropriate
    //need to include constructors and destructors where appropriate
    //need to use 'const' when appropriate

/**************************************************
 * Name: Order()
 * Description: Default constructor for order object
 * Parameters: NA
 * Pre-conditions: Order has been declared, but not initialized
 * Post-conditions: Order object will be initialized to nothing
 **************************************************/
Order();


/**************************************************
 * Name: get_size()
 * Description: Gets size of drink from user
 * Parameters: NA
 * Pre-conditions: NA
 * Post-conditions: Size of drink will be returned
 **************************************************/
char get_size();


/**************************************************
 * Name: get_quantity()
 * Description: Gets quantity from user
 * Parameters: NA
 * Pre-conditions: NA
 * Post-conditions: Quantity will be returned
 **************************************************/
int get_quantity();


/**************************************************
 * Name: fil_order()
 * Description: Fills an order object with data
 * Parameters: int - ID of order object
 * 			   string - Coffee name of order object
 * 			   char - size of order object
 * 			   int - quantity of order object
 * Pre-conditions: ID, coffee name, size, and quantity are valid
 * Post-conditions: Order object will be filled correctly
 **************************************************/
Order fill_order(int newId, string newCoffeeName, char newSize, int newQuantity);


/**************************************************
 * Name: print_order() const
 * Description: Prints one order to the screen
 * Parameters: NA
 * Pre-conditions: Order object os filled correctly
 * Post-conditions: NA
 **************************************************/
void print_order() const;


/**************************************************
 * Name: write_order() const
 * Description: Writes orders to order txt file
 * Parameters: ofstream& - writes into file
 * Pre-conditions: There is at least one order
 * Post-conditions: Order txt file will be written into
 **************************************************/
void write_order(ofstream& orderFile) const;
};
#endif