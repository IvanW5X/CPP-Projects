/***************************************
 * Program Name: game.cpp
 * Author: Ivan Wong
 * Date: 11/26/23
 * Description: Function definitions for game class
 * Inputs: NA
 * Outputs: NA
 ***************************************/

#include "game.h"
#include "gold.h"
#include "stalactites.h"
#include "bats.h"
#include "wumpus.h"

#include <iostream>
#include <string>

using namespace std;

//Game Implementation

Game::Game() {		//Game constructor
	this->length = 0;
	this->width = 0;
	this->num_arrows = 0;
	this->debug_view = false;

	this->startLen = 0;
	this->startWid = 0;

	this->advLen = 0;
	this->advWid = 0;

	this->hasGold = false;
	this->batMoves = 0;

	this->gameOver = false;
}

Game::~Game() {		//Game deconstructor
	for (int i = 0; i < this->length; i++) {
		for (int j = 0; j < this->width; j++) {
			if (grid.at(i).at(j).get_event() != nullptr) {		//Check for event in room
				grid.at(i).at(j).set_event(nullptr);			//Set event to NULL
			}
		}
	}
}

void Game::clear_data() {		//Clears data
	for (int i = 0; i < this->length; i++) {
		for (int j = 0; j < this->width; j++) {
			if (grid.at(i).at(j).get_event() != nullptr) {		//Check for event in room
				grid.at(i).at(j).set_event(nullptr);			//Set event to NULL
			}
			if (grid.at(i).at(j).get_adventurer() == true) {	//Check for adv in room
				grid.at(i).at(j).set_adventurer(false);			//Set adv to false
			}
		}
	}
	this->gameOver = false;			//Set used game vars to false/0
	this->hasGold = false;

	this->batMoves = 0;
}

void Game::print_intro() const {
	cout << "\n--------------------------------------------------------\n"		//Intro text
		 << "Welcome to Hunt The Wumpus!\n"
		 << "You are the adventurer and it is up to you to collect the gold and return\n"
		 << "to the starting room OR you can fire an arrow at the Wumpus to kill him.\n"
		 << "Good Luck and Have Fun!\n"
		 << "Tip: Watch out for the bats and stalactites!\n"
		 << "--------------------------------------------------------\n\n";
}

int Game::get_len() {		//Get length of game grid
	int len = 0;

	do {
		cout << "How many rooms would you like?\n"		//Ask user for length
			 << "Enter 4-50: ";
		cin >> len;

		if (len < 4 || len > 50) {		//Length cannot be less than 4 or more than 50
			cout << "\nINVALID INPUT, TRY AGAIN\n\n";		//Error message
		}

	} while(len < 4 || len > 50);		//Keep user in loop until valid input

	return len;
}

int Game::get_wid() {		//Get width of game grid
	int wid = 0;

	do {
		cout << "\nHow many caves would you like?\n"		//Ask user for width
			 << "Enter 4-50: ";
		cin >> wid;

		if (wid < 4 || wid > 50) {		//Width cannot be less than 4 or more than 50
			cout << "\nINVALID INPUT, TRY AGAIN\n\n";		//Error message
		}

	} while(wid < 4 || wid > 50);		//Keep user in loop until valid input

	return wid;
}

bool Game::get_mode() {		//Get mode of game
	bool debug = true;
	string choice = "";

	do {
		cout << "\nWould you like to play in debug mode (CHEAT MODE)?\n"		//Ask user if they want to play in debug mode
			 << "Enter Yes (y) or No (n): ";
		cin >> choice;

		if (choice == "y") {		//User wants to play in debug mode
			debug = true;
		}
		else if (choice == "n") {		//User does not want to play in debug mode
			debug = false;
		}
		else {
			cout << "\nINVALID INPUT, TRY AGAIN\n\n";		//Handles invalid input
		}

	} while(choice != "y" && choice != "n");		//Keep user in loop until valid input

	return debug;
}

void Game::set_up(int l, int w) {		//Set up the game
	this->length = l;
	this->width = w;

	this->num_arrows = 3; 	//Start with 3 arrows

	this->grid.resize(l);

	for (int i = 0; i < l; i++) {		// Create the game board: 2D vector of Room objects
		this->grid.at(i).resize(w);
	}

	this->insert_event(new Wumpus);
	this->insert_event(new Gold);

	this->insert_event(new Bats);		// Randomly insert events (2 bats, 2 stalactites, 1 wumpus, 1 gold)
	this->insert_event(new Bats);		// and adventurer into the board

	this->insert_event(new Stalactites);
	this->insert_event(new Stalactites);

	this->place_adv();
}

void Game::insert_event(Event *e) {
	int lenIdx = 0;
	int widIdx = 0;

	do {
		lenIdx = rand() % grid.size();			//Random cave
		widIdx = rand() % (grid.at(0).size());		//Random room

	} while(grid.at(lenIdx).at(widIdx).get_event() != nullptr &&		//Check if room already has an event
			grid.at(lenIdx).at(widIdx).get_adventurer() == false);		//Check if room has adventurer

	this->grid.at(lenIdx).at(widIdx).set_event(e);		//Place event in random room
}

void Game::place_adv() {
	int advLenIdx = 0;
	int advWidIdx = 0;
	bool placeAdv = false;		//Track the adv

	do {
		advLenIdx = rand() % grid.size();			//Random cave
		advWidIdx = rand() % (grid.at(0).size());	//Random room

		if (grid.at(advLenIdx).at(advWidIdx).get_event() == nullptr &&			//Check for room w/o event
			grid.at(advLenIdx).at(advWidIdx).get_adventurer() == false) {		//Check for existing adventurer
				grid.at(advLenIdx).at(advWidIdx).set_adventurer(true);			//Place adv in random room
				placeAdv = true;												//Set to adv tracker to true
		}
	} while(placeAdv == false);			//Keep looping until adv is placed

	this->startLen = advLenIdx;		//Save starting room len
	this->startWid = advWidIdx;		//Save starting room wid
	
	this->advLen = advLenIdx;		//Save adv length index for future moves
	this->advWid = advWidIdx;		//Save adv width index for future moves
}

void Game::wumpus_encounter() {		//User enters room with Wumpus
	cout << endl
		 << "----------\n"
		 << "GAME OVER" << endl		//Game over message
		 << "----------\n";
	this->gameOver = true;			//Set killed to true
}

void Game::gold_encounter(int &advLen, int &advWid) {		//User encounters gold
	this->hasGold = true;			//Set hasGold to true
	grid.at(advLen).at(advWid).set_event(nullptr);		//Set room with gold event to NULL
}

void Game::stalactite_encounter() {		//User enters room with stalactites
	int randNum = rand() % 2;		//50% chance

	if (randNum == 1) {
		cout << "-------------------------\n"
			 << "A stalctite fell on you!\n"		//User is killed
			 << "GAME OVER" << endl
			 << "-------------------------\n";
		this->gameOver = true;			//Set gameOver to true
	}
	else {			//Stalactite does not kill user
		return;
	}
}

void Game::bat_encounter() {	//User encounters bats
	this->batMoves = 5;			//Next 5 moves will be reversed
}

//Function is over 15 lines due to formatting and 
//length of text rather than use of semicolons
void Game::encounter_event() {
	if (grid.at(advLen).at(advWid).get_event() != nullptr &&
		grid.at(advLen).at(advWid).get_event()->print() == "W") {		//User encounters Wumpus
			grid.at(advLen).at(advWid).get_event()->encounter();
			wumpus_encounter();
		}
	if (grid.at(advLen).at(advWid).get_event() != nullptr &&
		grid.at(advLen).at(advWid).get_event()->print() == "G") {		//User encounters gold
			grid.at(advLen).at(advWid).get_event()->encounter();
			gold_encounter(advLen, advWid);
		}
	if (grid.at(advLen).at(advWid).get_event() != nullptr &&
		grid.at(advLen).at(advWid).get_event()->print() == "S") {		//User encounters stalactites
			grid.at(advLen).at(advWid).get_event()->encounter();
			stalactite_encounter();
		}
	if (grid.at(advLen).at(advWid).get_event() != nullptr &&
		grid.at(advLen).at(advWid).get_event()->print() == "B") {		//User encounters bats
			grid.at(advLen).at(advWid).get_event()->encounter();
			bat_encounter();
		}
}

void Game::print_percept() const {		//Prints percept messages for each event
	cout << endl;

	if (advLen - 1 >= 0) {															//Check for top bound
		if (grid.at(this->advLen - 1).at(this->advWid).get_event() != nullptr) {	//Event above adv
			grid.at(this->advLen - 1).at(this->advWid).get_event()->percept();
		}
	}
	if (advLen + 1 < grid.size()) {													//Check for bottom bound
		if (grid.at(this->advLen + 1).at(this->advWid).get_event() != nullptr) {	//Event below adv
			grid.at(this->advLen + 1).at(this->advWid).get_event()->percept();
		}
	}
	if (advWid - 1 >= 0) {															//Check for left bound
		if (grid.at(this->advLen).at(this->advWid - 1).get_event() != nullptr) {	//Event left of adv
			grid.at(this->advLen).at(this->advWid - 1).get_event()->percept();
		}
	}
	if (advWid + 1 < grid.at(0).size()) {											//Check for right bound
		if (grid.at(this->advLen).at(this->advWid + 1).get_event() != nullptr) {	//Event right of adv
			grid.at(this->advLen).at(this->advWid + 1).get_event()->percept();
		}
	}
}

//Function is over 15 lines, but it completes one task and has a lot of "formatting" lines
void Game::display_game() const {
	cout << "\n----------------------\n"
		 << "Arrows remaining: " << this->num_arrows << endl		//Display number of arrows
		 << "----------------------\n";
	
	string line = "";

	for (int i = 0; i < this->width; i++)
		line += "-----";

	for (int i = 0; i < this->length; i++) {
		cout << line << endl;

		for (int j = 0; j < this->width; j++) {
			if (debug_view == true && (i == startLen && j == startWid) 	//Display escape rope if user is not in the starting room
				&& (grid.at(i).at(j).get_adventurer() == false)) {
					cout << "R";
			}
			else if (grid.at(i).at(j).get_adventurer() == false &&		//No adventurer in room
				grid.at(i).at(j).get_event() == nullptr) {			//No event in room
				cout << " ";
			}
			else if (grid.at(i).at(j).get_adventurer() == true) {		//Adventurer in room
				cout << "*";
			}
			else {
				if (debug_view == true && grid.at(i).at(j).get_event() != nullptr) {		//Event in room and debug mode on
					cout << grid.at(i).at(j).get_event()->print();							//Print out event symbol
				}
				else {
					cout << " ";		//There is an event, but debug mode is false
				}
			}
			cout << "  ||";
		}
		cout << endl;
	}
	cout << line << endl;
}

bool Game::check_game_over() const {		//Check for win
	if (this->gameOver == true) {		//If user won, return true
		return true;
	}
	if (this->hasGold == true && 
		this->advLen == this->startLen && this->advWid == this->startWid) {		//User escaped with gold

		cout << endl
		 << "---------------------------\n"
		 << "You escaped with the gold!\n"
		 << "---------------------------\n";
		return true;
	}
	else {
		return false;				//Game is not over, return false
	}
}

void Game::move_up() {		//Moves adv North
	if (batMoves > 0 ) {	//Check for batMoves
		if (advLen < grid.size() - 1) {		//Check for bottom of grid
			grid.at(advLen).at(advWid).set_adventurer(false);		//Remove adv from previous room
			advLen++;												//Increment advLen
			grid.at(advLen).at(advWid).set_adventurer(true);		//Add adv to new room
			batMoves--;
		}
	}
	else if (advLen > 0) {		//Check for top of grid
		grid.at(advLen).at(advWid).set_adventurer(false);		//Remove adv from previous room
		advLen--;												//Decrement advLen
		grid.at(advLen).at(advWid).set_adventurer(true);		//Add adv to new room
	}
}

void Game::move_down() {		//Moves adv South
	if (batMoves > 0) {
		if (advLen > 0) {		//Check for top of grid
			grid.at(advLen).at(advWid).set_adventurer(false);		//Remove adv from previous room
			advLen--;												//Decrement advLen
			grid.at(advLen).at(advWid).set_adventurer(true);		//Add adv to new room
			batMoves--;
		}
	}
	else if (advLen < grid.size() - 1) {		//Check for bottom of grid
		grid.at(advLen).at(advWid).set_adventurer(false);		//Remove adv from previous room
		advLen++;												//Increment advLen
		grid.at(advLen).at(advWid).set_adventurer(true);		//Add adv to new room
	}
}

void Game::move_left() {	//Moves adv West
	if (batMoves > 0) {
		if (advWid < grid.at(0).size() - 1) {		//Check for right of grid
			grid.at(advLen).at(advWid).set_adventurer(false);		//Remove adv from previous room
			advWid++;												//Increment advWid
			grid.at(advLen).at(advWid).set_adventurer(true);		//Add adv to new room
			batMoves--;
		}
	}
	else if (advWid > 0) {		//Check for left of grid
		grid.at(advLen).at(advWid).set_adventurer(false);		//Remove adv from previous room
		advWid--;												//Decrement advWid
		grid.at(advLen).at(advWid).set_adventurer(true);		//Add adv to new room
	}
}

void Game::move_right() {	//Moves adv East
	if (batMoves > 0) {
		if (advWid > 0) {		//Check for left of grid
			grid.at(advLen).at(advWid).set_adventurer(false);		//Remove adv from previous room
			advWid--;												//Decrement advWid
			grid.at(advLen).at(advWid).set_adventurer(true);		//Add adv to new room
			batMoves--;
		}
	}
	else if (advWid < grid.at(0).size() - 1) {		//Check for right of grid
		grid.at(advLen).at(advWid).set_adventurer(false);		//Remove adv from previous room
		advWid++;												//Increment advWid
		grid.at(advLen).at(advWid).set_adventurer(true);		//Add adv to new room
	}
}

char Game::get_dir() {		//Get direction of arrow
	char dir;

	do {
		cout << "\nFire an arrow...." << endl
			 << "W-up" << endl
			 << "A-left" << endl
			 << "S-down" << endl
			 << "D-right" << endl

			 << "Enter direction: ";		//Ask user for direction
		cin >> dir;
		cin.ignore(256, '\n');

		if (dir != 'w' && dir != 'a' && dir != 's' && dir != 'd') {		//Handles invalid inputs
			cout << "\nINVALID INPUT, TRY AGAIN\n\n";
		}

	} while(dir != 'w' && dir != 'a' && dir != 's' && dir != 'd');		//Keep user oin loop until valid input

	return dir;
}

//Function is over 15 lines due to formatting, but it completes 1 task
void Game::wumpus_move() {				//Moves Wumpus to a random room
	int moveChance = rand() % 4;
	Event *oldWumpus = nullptr;		//Track Wumpus

	if (moveChance != 0) {				//75% chance Wumpus moves
		for (int i = 0; i < grid.size(); i++) {
			for (int j = 0; j < (grid.at(0).size()); j++) {
				if (grid.at(i).at(j).get_event() != nullptr &&				//Check for event
					grid.at(i).at(j).get_event()->print() == "W") {			//Check for Wumpus
						oldWumpus = grid.at(i).at(j).get_event();			//Copy Wumpus pointer
						grid.at(i).at(j).set_event(nullptr);				//Remove Wumpus from room
						break;
				}
			}
			if (oldWumpus != nullptr) {		//Wumpus is found, break out of loops
					break;
			}
		}
		int randLen = 0, randWid = 0;

		do {
			randLen = rand() % grid.size();
			randWid = rand() % (grid.at(0).size());
		} while(grid.at(randLen).at(randWid).get_event() != nullptr);		//Finds a random room w/o an event

		grid.at(randLen).at(randWid).set_event(new Wumpus);			//Put new Wumpus in random room
		cout << "\n------------------------------\n"
			 << "The Wumpus heard your arrow...\n"
			 << "------------------------------\n";
	}
	else {
		cout << "\n---------------------------------\n"
			 << "The Wumpus didn't hear your shot.\n"		//25% chance Wumpus is not woken up
			 << "---------------------------------\n";
	}
}

void Game::fire_arrow_north() {		//Fires arrow north
	cout << "\n---------------------------\n" 
		 << "You fired an arrow North.\n"
		 << "---------------------------\n";

	for (int i = 1; i < 4; i ++) {			//Arrow fired a max of 3 rooms up
		if (advLen - i >= 0) {
			if (grid.at(advLen - i).at(advWid).get_event() != nullptr) {
				if (grid.at(advLen - i).at(advWid).get_event()->print() == "W") {		//Check for Wumpus
					cout << "\n------------------------------\n"
						 << "You pierced the Wumpus' heart!\n"
						 << "------------------------------\n";
					this->gameOver = true;									//Wumpus hit, game over
					return;
				}
			}
		}
	}
	wumpus_move();		//Wumpus not hit
}

void Game::fire_arrow_south() {		//Fires arrow south
	cout << "\n-------------------------\n" 
		 << "You fired an arrow South.\n"
		 << "-------------------------\n";

	for (int i = 1; i < 4; i ++) {			//Arrow fired a max of 3 rooms down
		if (advLen + i < grid.at(0).size()) {
			if (grid.at(advLen + i).at(advWid).get_event() != nullptr) {
				if (grid.at(advLen + i).at(advWid).get_event()->print() == "W") {		//Check for Wumpus
					cout << "\n------------------------------\n"
						 << "You pierced the Wumpus' heart!\n"
						 << "------------------------------\n";
					this->gameOver = true;									//Wumpus hit, game over
					return;
				}
			}
		}
	}
	wumpus_move();		//Wumpus not hit
}

void Game::fire_arrow_east() {		//Fires arrow east
	cout << "\n------------------------\n" 
		 << "You fired an arrow East.\n"
		 << "------------------------\n";

	for (int i = 1; i < 4; i ++) {			//Arrow fired a max of 3 rooms to the right
		if (advWid + i < grid.at(0).size()) {
			if (grid.at(advLen).at(advWid + i).get_event() != nullptr) {
				if (grid.at(advLen).at(advWid + i).get_event()->print() == "W") {		//Check for Wumpus
					cout << "\n------------------------------\n"
						 << "You pierced the Wumpus' heart!\n"
						 << "------------------------------\n";
					this->gameOver = true;									//Wumpus hit, game over
					return;
				}
			}
		}
	}
	wumpus_move();		//Wumpus not hit
}

void Game::fire_arrow_west() {		//Fires arrow west
	cout << "\n------------------------\n" 
		 << "You fired an arrow West.\n"
		 << "------------------------\n";

	for (int i = 1; i < 4; i ++) {			//Arrow fired a max of 3 rooms to the left
		if (advWid - i >= 0) {
			if (grid.at(advLen).at(advWid - i).get_event() != nullptr) {
				if (grid.at(advLen).at(advWid - i).get_event()->print() == "W") {		//Check for Wumpus
					cout << "------------------------------\n"
						 << "You pierced the Wumpus' heart!\n"
						 << "------------------------------\n";
					this->gameOver = true;									//Wumpus hit, game over
					return;
				}
			}
		}
	}
	wumpus_move();		//Wumpus not hit
}

void Game::fire_arrow() {		//User fires an arrow
	if (this->num_arrows == 0) {						//User has no more arrows
		cout << "-----------------------------\n"
			 << "You have no remaining arrows.\n"
			 << "-----------------------------\n\n";
	}
	else {												//User has arrows
		char dir = get_dir();		//Get direction of arrow

		switch(dir) {			//Fires arrow in user direction
			case 'w':
				fire_arrow_north();
				break;
			case 's':
				fire_arrow_south();
				break;
			case 'd':
				fire_arrow_east();
				break;
			case 'a':
				fire_arrow_west();
				break;
		}
	this->num_arrows--;
	}
}

void Game::move(char c) {		// Handle player's action: move or fire an arrow
	if (c == 'f'){
		fire_arrow();
		return;
	}
	switch(c){
		case 'w':
			move_up();
			break;
		case 'a':
			move_left();
			break;
		case 's':
			move_down();
			break;
		case 'd':
			move_right();
			break;
	}
}

char Game::get_input() {		//Get action, move direction or firing an arror
	char c;

	do {
		cout << endl << "Player move..." << endl << endl	//Ask user to move
			 << "W-up" << endl
			 << "A-left" << endl
			 << "S-down" << endl
			 << "D-right" << endl
			 << "f-fire an arrow" << endl

			 << "Enter input: ";
		cin >> c;
		cin.ignore(256, '\n');
		cout << endl;

		if (c != 'w' && c != 'a' && c != 's' && c != 'd' && c != 'f') {		//Handles invalid inputs
			cout << "\nINVALID INPUT, TRY AGAIN\n\n";
		}

	} while(c != 'w' && c != 'a' && c != 's' && c != 'd' && c != 'f');		//Keep user in loop until valid input

	return c;
}

void Game::play_game(int w, int l, bool d) {

	set_up(w, l);					//Set up board
	this->debug_view = d;				//Get debug mode

	char input, arrow_input;
	
	while (check_game_over() == false) {
		display_game();			//Print game board

		print_percept();			//Print percepts

		input = get_input();		//Get move direction

		move(input);				//Move adv

		encounter_event();		//Encounter events
	}
}

string Game::play_again() {
	string playAgain;

	do {
		cout << "\nWould you like to play again?\n"
		 	 << "Enter Yes (y) or No (n): ";
		cin >> playAgain;
		cout << endl;

		if (playAgain != "y" && playAgain != "n") {
			cout << "\nINVALID INPUT, TRY AGAIN\n\n";
		}

	} while(playAgain != "y" && playAgain != "n");

	return playAgain;
}