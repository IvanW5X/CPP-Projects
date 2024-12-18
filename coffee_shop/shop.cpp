/* Program name: shop.cpp
 * Author: Ivan Wong
 * Date: 11/12/23
 * Description: Function definitions for shop class
 * Input: All user input for shop class
 * Ouput: Shop object
 */

#include "shop.h"

using namespace std;

//function defintions from shop.h goes here


Shop::Shop() {		//Default constructor
	phone = "";		//Set all variables to 0 or NULL
	address = "";
	revenue = 0;
	order_arr = nullptr;
	num_orders = 0;
	//cout << "\nShop default constructor\n";
}

Shop::Shop(const Shop& otherShop) {		//Copy constructor for shop
	this->phone = otherShop.phone;
	this->address = otherShop.address;	//Takes the phone, address, revenue
	this->revenue = otherShop.revenue;

	this->num_orders = otherShop.num_orders;
	this->order_arr = new Order[this->num_orders];		//Create new array with same size as other shop

	for (int i = 0; i < this->num_orders; i++) {		//Copy orders
		this->order_arr[i] = otherShop.order_arr[i];
	}
	this->m = otherShop.m;		//Copy menu
	//cout << "\nShop CC\n";		//Verifying it works, uncomment to check
}

Shop& Shop::operator=(const Shop& otherShop) {		//Assignment operator overload for shop
	this->phone = otherShop.phone;
	this->address = otherShop.address;		//Takes the phone, address, revenue
	this->revenue = otherShop.revenue;

	if (this == &otherShop) {		//If same shop, return the shop
		return *this;
	}
	if (this->order_arr != nullptr) {		//If this arder array already exists, delete it
		delete [] this->order_arr;
	}
	this->num_orders = otherShop.num_orders;
	this->order_arr = new Order[this->num_orders];		//Create new array with same size as other shop

	for (int i = 0; i < this->num_orders; i++) {		//Copy orders
		this->order_arr[i] = otherShop.order_arr[i];
	}
	this->m = otherShop.m;		//Copy menu
	//cout << "\nShop AOO\n";

	return *this;		//Return the copied shop
}

Shop::~Shop() {		//Deconstructor
	if (this->order_arr != nullptr) {		//Check if order_arr is pointing to nothing already
		delete [] this->order_arr;		//Delete order array
		this->order_arr = nullptr;		//Set pointer to NULL
	}
	//cout << "\nShop Deconstructor\n";
}


void Shop::load_data(ifstream &menuFile, ifstream &shopFile) {		//Get data from files
	menuFile.open("menu.txt");		//Opening files
	shopFile.open("shop_info.txt");

	shopFile >> phone;		//Get phone number
	shopFile.ignore();		//Take new line character
	getline(shopFile, address);		//Get address
	revenue = 0;			//Init. revenue to 0
	num_orders = 0;			//Init. num_orders to 0

	m.populate_menu(menuFile);		//Get menu/coffee array

	menuFile.close();		//Closing files
	shopFile.close();

	return;
}

void Shop::view_shop_detail() {		//Print shop info
	cout << "\nAddress: " << address << endl;		//Print address
	cout << "Phone: " << phone << endl;				//Print phone number
	cout << "The shop revenue is: $" << revenue << endl;		//Print shop revenue
	
	m.print_menu();		//Print menu
	
	cout << "Order info:" << endl;
	if (num_orders == 0) {			//No orders yet
		cout << "No orders have been placed\n";
	}
	else {
		for (int i = 0; i < num_orders; i++) {		//Print orders if there are any
			order_arr[i].print_order();
		}
	}
	return;
}

void Shop::add_to_menu(){		//Adds coffee to menu
	Coffee coffee_to_add;		//Create coffee object
	m.add_to_menu(coffee_to_add);		//Call add_to_menu function passing in coffee_to_add
	cout << "\nAdded to menu!\n";

	return;
}

void Shop::remove_from_menu(){		//Removes coffee from menu
	int coffeeIndex;
	m.remove_from_menu(coffeeIndex);
	cout << "\nSuccessfully removed from menu\n";

	return;
}


void Shop::search_by_name() {		//Search coffee by name	
	m.search_coffee_by_name();

	return;
}

void Shop::search_by_price(){		//Search coffee by price
	float budget;
	m.search_coffee_by_price(budget);

	return;
}

bool Shop::confirm_order() {		//Confirmation function
	char choice;
	do {
		cout << "Confirm order, Yes(y)  No(n): ";		//Ask user to confirm order
		cin >> choice;

		if (choice != 'y' && choice != 'n') {		//Handles invalid inputs
			cout << "\nInvalid Input, Try Again\n\n";
		}
		else if (choice == 'y') {		//Confirms order
			choice = true;
			cout << "\nOrder confirmed\n";
			return choice;
		}
		else if (choice == 'n') {		//Cancel order
			cout << "\nOrder cancelled\n";
			choice = false;
			return choice;
		}
	} while (true);		//Keep user in loop until valid input entered
}

void Shop::add_to_order_arr(Order& order_to_add) {		//Adds an order to order array

	Order* new_order_arr = new Order[num_orders + 1];		//Create new order array with size +1

	for (int i = 0; i < num_orders; i++) {		//Copy old data into new data
		new_order_arr[i] = order_arr[i];
	}
	delete [] order_arr;			//Delete old array
	
	order_arr = new_order_arr;		//Set pointer to new array
	
	order_arr[num_orders] = order_to_add;		//Last index gets new order
	num_orders++;		//Increment number of orders
}

void Shop::write_orders(ofstream& orderFile) const {		//Writes into order file
	orderFile.open("orders.txt");			//Open order txt file

	orderFile << num_orders << endl;		//Write the number of orders

	for (int i = 0; i < num_orders; i++) {		//Loops for how many orders there are
		order_arr[i].write_order(orderFile);	//Writes one order
	}
}

void Shop::place_order() {		//Places an order and stores it in order array
	int coffeeIndex = 0;
	Order order_to_add;			//Declare order object
	ofstream orderFile;			//Declare ofstream
	int newOrderId = 0;

	string coffeeName = m.get_coffee_name(coffeeIndex);		//Get coffee name from user
	m.print_coffee_cost(coffeeName);		//Print out prices for coffee

	char size = order_to_add.get_size();		//Get size from user
	int quantity = order_to_add.get_quantity();		//Get quantity from user

	float totalCost = m.calculate_cost(coffeeName, size, quantity);			//Calculate total cost

	bool confirmOrder = confirm_order();		//Ask user to confirm order

	if (confirmOrder == true) {		//Order confirmed
		
		newOrderId = num_orders + 1;		//Gets the id number

		order_to_add = order_to_add.fill_order(newOrderId, coffeeName, size, quantity);		//Fill order object
		add_to_order_arr(order_to_add);					//Add order to order array

		cout << "Your order has been placed. Your order number is " << newOrderId << ".\n";
		write_orders(orderFile);		//Write orders into order file

		revenue += totalCost;		//Add total cost to revenue
	}
	else {		//Order not confirmed
		return;
	}
}

Shop Shop::clone_shop() {		//Create deep copies of shop
	Shop cloned_shop;		//Declare shop

	cloned_shop = *this; // test AOO        

    Shop cloned_shop2 = *this; // test CC 

    cout << "Shop cloned successfully!" << endl; 

    return cloned_shop;
}