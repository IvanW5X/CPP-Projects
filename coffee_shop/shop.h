/* Program name: shop.h
 * Author: Ivan Wong
 * Date: 11/12/23
 * Description: Header file for shop class
 * Input: Function prototypes for shop class
 * Ouput: NA
 */

#ifndef SHOP_H
#define SHOP_H

#include "menu.h"
#include "order.h"

using namespace std;

class Shop {
private:
    Menu m;
    string phone;
    string address; 
    float revenue;      //shop revenue
    Order *order_arr;   //order array
    int num_orders;     //number or orders
public:
    //need to include accessor functions and mutator functions for private member when appropriate
    //need to include constructors and destructors where appropriate
    //need to use 'const' when appropriate

/**************************************************
 * Name: Shop()
 * Description: Default constructor for shop object
 * Parameters: NA
 * Pre-conditions: Shop has been declared
 * Post-conditions: Shop will be init. to NULL or nothing
 **************************************************/
Shop();


/**************************************************
 * Name: Shop()
 * Description: Copy constructor for shop object
 * Parameters: Shop& - shop object you get info from
 * Pre-conditions: A shop object is already declared and init.
 * Post-conditions: A shop object will be deep copied
 **************************************************/
Shop(const Shop& otherShop);


/**************************************************
 * Name: operator=()
 * Description: Assignment operator overload for shop object
 * Parameters: Shop& - shop object you get info from
 * Pre-conditions: A shop object has already been declared and init.
 * Post-conditions: A shop object will be deep copied
 **************************************************/
Shop& operator=(const Shop& otherShop);


/**************************************************
 * Name: ~Shop()
 * Description: Deconstructor for shop object
 * Parameters: NA
 * Pre-conditions: A shop object has already been declared
 * Post-conditions: Shop object will be deleted correctly
 **************************************************/
~Shop();


/**************************************************
 * Name: load_data()
 * Description: Reads from files to correctly populate coffee, menu, etc.
 * Parameters: ifstream& - reads data for menu class
 *             ifstream& - reads data for shop info
 * Pre-conditions: Menu and shop info file exist and are correctly filled
 * Post-conditions: Menu and shop info will be populated
 **************************************************/
void load_data(ifstream &menuFile, ifstream &shopInfo);


/**************************************************
 * Name: view_shop_data()
 * Description: Prints shop info, menu, and orders to screen
 * Parameters: NA
 * Pre-conditions: Shop info, menu, and orders are populated
 * Post-conditions: Shop info, menu, and orders are printed to screen
 **************************************************/
void view_shop_detail();


/**************************************************
 * Name: add_to_menu()
 * Description: Adds coffee object to menu
 * Parameters: NA
 * Pre-conditions: New coffee is filled correctly
 * Post-conditions: Coffee array will be updated with new coffee
 **************************************************/
void add_to_menu();


/**************************************************
 * Name: remove_from_menu()
 * Description: Removes coffee from coffee array
 * Parameters: NA
 * Pre-conditions: Coffee array is filled correctly
 * Post-conditions: Desired coffee is removed from coffee array
 **************************************************/
void remove_from_menu();


/**************************************************
 * Name: search_by_name()
 * Description: Prints info of desired coffee
 * Parameters: NA
 * Pre-conditions: Coffee array is filled correctly
 * Post-conditions: Desired coffee is printed to screen
 **************************************************/
void search_by_name();


/**************************************************
 * Name: search_by_price()
 * Description: Prints all coffee within budget
 * Parameters: NA
 * Pre-conditions: Coffee array is filled correctly
 * Post-conditions: All coffee within budget is printed to screen
 **************************************************/
void search_by_price();


/**************************************************
 * Name: confirm_order()
 * Description: Asks user to confirm order placed
 * Parameters: NA
 * Pre-conditions: User entered in a valid order
 * Post-conditions: Order will be discarded ot placed depending on user
 **************************************************/
bool confirm_order();


/**************************************************
 * Name: add_to_order_arr()
 * Description: Adds order to order array
 * Parameters: Order& - order that needs to be added
 * Pre-conditions: Order object os filled correctly
 * Post-conditions: New order will be addded to order array
 **************************************************/
void add_to_order_arr(Order& order_to_add);


/**************************************************
 * Name: write_orders()
 * Description: Write all order info to order txt file
 * Parameters: ofstream& - writes into the order txt file
 * Pre-conditions: Order array is filled correctly
 * Post-conditions: All order info is written into order txt file
 **************************************************/
void write_orders(ofstream& orderFile) const;


/**************************************************
 * Name: place_order()
 * Description: Asks user to place an order and stores the order,
 *              calculates the revenue,
 *              writes order to order txt file
 * Parameters: NA
 * Pre-conditions: Coffee array is filled correctly
 * Post-conditions: Order is stored into order array,
 *                  revenue is correctly calculated,
 *                  order info is written into order txt file
 **************************************************/
void place_order();


/**************************************************
 * Name: clone_shop()
 * Description: Creates deep copies of an existing shop and
 *              a declared shop
 * Parameters: NA
 * Pre-conditions: A shop is populated
 * Post-conditions: AOO and CC functions create deep copies of the shop
 **************************************************/
Shop clone_shop();
};

#endif
