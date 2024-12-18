/* Program name: menu.cpp
 * Author: Ivan Wong
 * Date: 11/12/23
 * Description: The function definitions for the menu class
 * Input: All user input for menu options
 * Ouput: Menu object
 */

#include "menu.h"

using namespace std;

//function defintions from menu.h goes here


Menu::Menu() {		//Default constructor
	int num_coffee = 0;
	coffee_arr = nullptr;
	//cout << "\nMenu default constructor\n";
}

void Menu::operator=(const Menu& otherMenu) {		//Assignment operator overload
	if (this == &otherMenu) {		//Same menu, return
		return;
	}
	if (this != nullptr) {		//Delete copy coffee array if it already exists
		delete [] coffee_arr;
	}

	this->num_coffee = otherMenu.num_coffee;		//Copy number of coffee	
	this->coffee_arr = new Coffee[num_coffee];		//Create new array with same size

	for (int i = 0; i < num_coffee; i++) {
		this->coffee_arr[i] = otherMenu.coffee_arr[i];		//Copy coffee from original array to new array
	}
	//cout << "\nMenu AOO\n";		//Message verifies that it works, uncomment to check
}

Menu::Menu(const Menu& otherMenu)		//Copy construcor
			: num_coffee(otherMenu.num_coffee),		//Copy number of coffee
			  coffee_arr(new Coffee[num_coffee]) {	//Create new array with same size
	for (int i = 0; i < num_coffee; i++) {
		this->coffee_arr[i] = otherMenu.coffee_arr[i];		//Copy coffee into menu
	}
	//cout << "\nMenu CC\n";
}

Menu::~Menu() {		//Destructor for coffee array within menu
	if (this->coffee_arr != nullptr) {		//Check if coffee_arr is pointing to nothing already
		delete [] this->coffee_arr;		//Delete coffee array
		this->coffee_arr = nullptr;		//Set pointer to NULL
	}
	//cout << "\nMenu destructor\n";
}

void Menu::search_coffee_by_name() const{		//Search coffee by name
	string name = "";
	do {
		cout << "Enter coffee name: ";		//Ask user for coffee name
		cin >> name;

		for (int i = 0; i < num_coffee; i++) {		//Checking for coffee
			if (coffee_arr[i].get_name() == name) {
				cout << "\nResults: \n"
					 << "1. " << coffee_arr[i].get_name() << endl			//Print coffee info
					 << "   Small: $" << coffee_arr[i].get_small_cost() << endl
    				 << "   Medium: $" << coffee_arr[i].get_medium_cost() << endl
    				 << "   Large: $" << coffee_arr[i].get_large_cost() << endl;

				return;		//Leave function
			}
		}
		cout << "Sorry, we don't have the product at the moment :(\n"	//Coffee does not exist, error message
			 << "\nPlease try again\n\n";
	} while (true);		//Keep looping until valid coffee name is entered
}

//Function is 15 lines if you don't count the float declaration
void Menu::search_coffee_by_price(float budget) const{
	float lowestCost = 100;		//Getting lowest cost of coffee
	
	cout << "Enter maximum budget: ";		//Asking user for budget
	cin >> budget;
	cout << "\nResults: ";

	for (int i = 0; i < num_coffee; i++) {		//Runs for amount of coffees in menu
		if (budget >= coffee_arr[i].get_small_cost()) {			//Checking if small coffee cost fits budget
			cout << endl << i + 1 << ". " << coffee_arr[i].get_name() << endl;		//Prints coffee name and small price
			cout << "   Small: $" << coffee_arr[i].get_small_cost() << endl;
		}
		if (lowestCost > coffee_arr[i].get_small_cost()) {		//Stores the lowest price
			lowestCost = coffee_arr[i].get_small_cost();
		}
		if (budget >= coffee_arr[i].get_medium_cost()) {		//Checking for medium cost
			cout << "   Medium: $" << coffee_arr[i].get_medium_cost() << endl;		//Print medium cost
		}
		if (budget >= coffee_arr[i].get_large_cost()) {			//Checing for large cost
			cout << "   Large: $" << coffee_arr[i].get_large_cost() << endl;		//Print large cost
		}
	}
	if (budget < lowestCost) {		//Checking budget to lowest coffee cost
		cout << "\nSorry, we don't have a coffee that fits your budget :(\n";		//No coffee fits the budget
	}
}

void Menu::add_to_menu(Coffee& coffee_to_add){		//Adds coffee to coffee array
	Coffee* new_coffee_arr = new Coffee[num_coffee + 1];	//Create new coffee array with size + 1

	for (int i = 0; i < num_coffee; i++) {		//Copy old array data into new array
		new_coffee_arr[i] = coffee_arr[i];
	}
	delete [] coffee_arr;		//Delete old array

	coffee_arr = new_coffee_arr;		//Set old pointer to point to new array
	coffee_to_add = coffee_to_add.add_coffee_info();	//New coffee gets data from user input
	new_coffee_arr[num_coffee] = coffee_to_add;		//Add new coffee to last index of array
	num_coffee++;		//Increment amount of coffees by 1

	update_menu_file(coffee_arr, num_coffee);		//Update menu txt file

	return;
} 

int Menu::get_remove_coffee_index() {		//Gets index of desired coffee user wants to remove
	int index_of_coffee_on_menu;

	for (int i = 0; i < num_coffee; i++) {
		cout << i + 1 << ". " << coffee_arr[i].get_name() << endl;		//Prints the items
	}
	do {
		cout << "\nWhich coffee would you like to remove?\n"		//Ask user for which coffee they want to remove
			 << "Enter " << num_coffee + (1 - num_coffee) << "-"<< num_coffee << ": ";
		cin >> index_of_coffee_on_menu;

		if (index_of_coffee_on_menu <= num_coffee && index_of_coffee_on_menu > 0) {		//User entered valid int, return the int
			return index_of_coffee_on_menu;
		}
		else {
			cout << "\nInvalid Input, Try Again\n";		//Error message
		}
	} while (true);		//Keeps user in loop
}

void Menu::remove_from_menu(int index_of_coffee_on_menu) {		//Removes coffee from menu
	index_of_coffee_on_menu = get_remove_coffee_index();		//Get index of coffee

	Coffee* new_coffee_arr = new Coffee[num_coffee - 1];		//Create new array with size - 1

	for (int i = index_of_coffee_on_menu - 1; i < num_coffee - 1; i++) {	//Shift elements of array to the left 1
		coffee_arr[i] = coffee_arr[i + 1];
	}

	for (int i = 0; i < num_coffee - 1; i++) {		//Copy old data to new array
		new_coffee_arr[i] = coffee_arr[i];
	}

	delete [] coffee_arr;		//Delete old array
	num_coffee--;		//Decrement amount of coffee
	coffee_arr = new_coffee_arr;	//Set pointer to new array

	update_menu_file(coffee_arr, num_coffee);		//Update menu txt file
}

void Menu::populate_menu(ifstream &menuFile) {		//Populate coffee shop menu
	menuFile >> num_coffee;						//Get size of menu
	coffee_arr = new Coffee[num_coffee];		//Create dyn. array with proper size of menu

	for (int i = 0; i < num_coffee; i++) {
		coffee_arr[i].populate_coffee(menuFile);		//Populate menu with coffee
	}
}

void Menu::print_menu() const {		//Print menu
	cout << "\nHere is our menu:\n";
	for (int i = 0; i < num_coffee; i++) {		//Runs for each coffee in the menu
		cout << i + 1 << ". ";
		coffee_arr[i].print_coffee();		//Prints one coffee
	}
}

void Menu::update_menu_file(Coffee* coffee_arr, int& num_coffee) const{		//Rewrites menu txt file
	ofstream outFile;
	
	outFile.open("menu.txt");		//Open menu.txt

	outFile << num_coffee << endl;		//Print number of coffees

	for (int i = 0; i < num_coffee; i++) {		//Runs for number of coffees
		outFile << coffee_arr[i].get_name() << " "		//Prints coffee info
				<< coffee_arr[i].get_small_cost() << " "
				<< coffee_arr[i].get_medium_cost() << " "
				<< coffee_arr[i].get_large_cost() << endl;
	}
	outFile.close();		//Close menu.txt
}

void Menu::print_coffee_name() const {		//Prints all coffee name
	cout << endl;
	for (int i = 0; i < num_coffee; i++) {		//Runs for number of coffee
		cout << i + 1 << ". ";
		coffee_arr[i].print_coffee_name();		//Print coffee name
	}
}

string Menu::get_coffee_name(int coffeeIndex) {		//Gets user input for coffee name
	string coffeeName = "";

	print_coffee_name();		//Prints all coffee name

	do {
		cout << "\nWhich coffee would you like?\n"		//Ask user for coffee index
			 << "Enter " << num_coffee + (1 - num_coffee) << "-"<< num_coffee << ": ";
		cin >> coffeeIndex;

		if (coffeeIndex >= 1 && coffeeIndex <= num_coffee) {		//If valid, convert index into coffee name and return it
			coffeeName = coffee_arr[coffeeIndex - 1].get_name();
			return coffeeName;
		}
		else {
			cout << "\nInvalid Input, Try Again\n";		//Not a valid input
		}
	} while (true);		//Keeps user in loop until valid input entered
}

void Menu::print_coffee_cost(string coffeeName) const {		//Print prices of one coffee
	cout << endl << coffeeName << endl;
	
	for (int i = 0; i < num_coffee; i++) {		//Check for coffee name
		if (coffeeName == coffee_arr[i].get_name()) {		//Matching coffee name
			cout << "   Small: $" << coffee_arr[i].get_small_cost() << endl		//Print prices of coffee
				 << "   Medium: $" << coffee_arr[i].get_medium_cost() << endl
				 << "   Large: $" << coffee_arr[i].get_large_cost() << endl;
		}
	}
}

float Menu::calculate_cost(string coffeeName, char size, int quantity) {		//Calculates cost
	float totalCost;
	float oneCoffee;

	for (int i = 0; i < num_coffee; i++) {		//Checking for coffee name
		if (coffeeName == coffee_arr[i].get_name()) {
			if (size == 's') {
				oneCoffee = coffee_arr[i].get_small_cost();		//Small cost of coffee
			}
			else if (size == 'm') {
				oneCoffee = coffee_arr[i].get_medium_cost();	//Medium cost of coffee
			}
			else if (size == 'l') {
				oneCoffee = coffee_arr[i].get_large_cost();		//Large cost of coffee
			}
		}
	}
	totalCost = oneCoffee * quantity;	//Calculate total cost
	cout << "\nYour total cost is $" << totalCost << endl;

	return totalCost;
}