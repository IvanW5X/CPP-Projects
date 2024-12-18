/***************************************
 * Program Name: game.h
 * Author: Ivan Wong
 * Date: 11/26/23
 * Description: Function prototypes for game class
 * Inputs: NA
 * Outputs: NA
 ***************************************/

#ifndef GAME_H
#define GAME_H 

#include <vector>
#include <iostream>
#include <string>
#include "room.h"

using namespace std;

//Game interface 
class Game {
private:
	vector<vector<Room>> grid;

	//other member variables:
	int length; 					//length of the board
	int width;  					//width of the board
	int num_arrows; 				//keep track of number of errors remaining
	bool debug_view;				//debug mode

	int startLen;
	int startWid;

	int advLen;
	int advWid;

	bool hasGold;
	int batMoves;

	bool gameOver;
public:

/**************************************************
 * Name: Game()
 * Description: Default constructor for Game class 
 * Parameters: NA
 * Pre-conditions: NA 
 * Post-conditions: Game will constructed to nothing/0
 **************************************************/
Game();


/**************************************************
 * Name: ~Game()
 * Description: Destructor for Game class
 * Parameters: NA
 * Pre-conditions: Game object exist 
 * Post-conditions: Game object will have it's dynamic memory freed
 **************************************************/
~Game();


/**************************************************
 * Name: clear_data()
 * Description: Resets data for a game
 * Parameters: NA
 * Pre-conditions: Game object exists 
 * Post-conditions: Game object will have same variables as
 * 					a defaultly constructed Game object
 **************************************************/
void clear_data();


/**************************************************
 * Name: print_intro
 * Description: Prints intro text
 * Parameters: NA
 * Pre-conditions: Game object exists 
 * Post-conditions: Intro text printed to screen
 **************************************************/
void print_intro() const;


/**************************************************
 * Name: get_len()
 * Description: Gets length of grid from user
 * Parameters: NA
 * Pre-conditions: Game object exists 
 * Post-conditions: Length of grid returned
 **************************************************/
int get_len();


/**************************************************
 * Name: get_wid()
 * Description: Gets width of grid from user
 * Parameters: NA
 * Pre-conditions: Game object exists 
 * Post-conditions: Width of grid returned
 **************************************************/
int get_wid();


/**************************************************
 * Name: get_mode()
 * Description: Gets mode from user
 * Parameters: NA
 * Pre-conditions: Game object exists 
 * Post-conditions: Gamemode returned
 **************************************************/
bool get_mode();


/**************************************************
 * Name: set_up()
 * Description: Sets up game from user input
 * Parameters: int - length of grid
 * 			   int - width of grid
 * Pre-conditions: User entered valid length, width, and mode
 * Post-conditions: Game will be created to user specifics
 **************************************************/
void set_up(int, int);


/**************************************************
 * Name: insert_event()
 * Description: Randomly places 1 event in a room
 * Parameters: Event* - event being placed
 * Pre-conditions: Grid created appropiately
 * Post-conditions: An event will be randomly placed in grid
 **************************************************/
void insert_event(Event *event);


/**************************************************
 * Name: place_adv()
 * Description: Randomly places the adv
 * Parameters: NA
 * Pre-conditions: Grid created appropiately 
 * Post-conditions: Adv will be randomly placed
 **************************************************/
void place_adv();


/**************************************************
 * Name: wumpus_encounter()
 * Description: Prints game over and sets gameOver bool to true
 * Parameters: NA
 * Pre-conditions: User entered room with Wumpus 
 * Post-conditions: gameOver will be true
 **************************************************/
void wumpus_encounter();


/**************************************************
 * Name: gold_encounter()
 * Description: Sets hasGold to true and deletes gold ptr
 * Parameters: int& - "x" coord of gold event
 * 			   int& - "y" coord of gold event
 * Pre-conditions: User entered room with gold
 * Post-conditions: hasGold set to true
 **************************************************/
void gold_encounter(int &advLen, int &advWid);


/**************************************************
 * Name: stalactite_encounter()
 * Description: 50/50 chance game ends
 * Parameters: NA
 * Pre-conditions: User entered room with stalactite 
 * Post-conditions: 50/50 chance game ends
 **************************************************/
void stalactite_encounter();


/**************************************************
 * Name: bat_encounter()
 * Description: Sets batMoves to 5
 * Parameters: NA
 * Pre-conditions: User entered room with bats 
 * Post-conditions: batMoves set to 5
 **************************************************/
void bat_encounter();


/**************************************************
 * Name: encounter_event()
 * Description: Checks if user encounters an event
 * Parameters: NA
 * Pre-conditions: User can move around 
 * Post-conditions: Runs proper encounter function
 **************************************************/
void encounter_event();


/**************************************************
 * Name: print_percept()
 * Description: Prints percept text when user is close to event
 * Parameters: NA
 * Pre-conditions: User is adjacent to an event 
 * Post-conditions: Percept message will be printed
 **************************************************/
void print_percept() const;


/**************************************************
 * Name: display_game()
 * Description: Displays grid and game details
 * Parameters: NA
 * Pre-conditions: Game details are valid 
 * Post-conditions: Game details are printed to screen
 **************************************************/
void display_game() const;


/**************************************************
 * Name: check_game_over()
 * Description: Check to see if game is over
 * Parameters: NA
 * Pre-conditions: Game is being played 
 * Post-conditions: True or false returned
 **************************************************/
bool check_game_over() const;


/**************************************************
 * Name: get_dir()
 * Description: Gets direction of arrow from user
 * Parameters: NA
 * Pre-conditions: User wants to fire an arrow 
 * Post-conditions: Arrow direction returned
 **************************************************/
char get_dir();


/**************************************************
 * Name: wumpus_move()
 * Description: 75% chance Wumpus moves to random room
 * Parameters: NA
 * Pre-conditions: User fired an arrow 
 * Post-conditions: Wumpus will move or not move
 **************************************************/
void wumpus_move();


/**************************************************
 * Name: fire_arrow_north()
 * Description: Fires an arrow North
 * Parameters: NA
 * Pre-conditions: User fired an arrow North 
 * Post-conditions: Arrow fired North
 **************************************************/
void fire_arrow_north();


/**************************************************
 * Name: fire_arrow_south()
 * Description: Fires an arrow South
 * Parameters: NA
 * Pre-conditions: User fired an arrow South 
 * Post-conditions: Arrow fired South
 **************************************************/
void fire_arrow_south();


/**************************************************
 * Name: fire_arrow_east()
 * Description: Fires an arrow East
 * Parameters: NA
 * Pre-conditions: User fired an arrow East 
 * Post-conditions: Arrow fired East
 **************************************************/
void fire_arrow_east();


/**************************************************
 * Name: fire_arrow_west()
 * Description: Fires an arrow West
 * Parameters: NA
 * Pre-conditions: User fired an arrow West 
 * Post-conditions: Arrow fired West
 **************************************************/
void fire_arrow_west();


/**************************************************
 * Name: fire_arrow()
 * Description: Fires arrow in a direction
 * Parameters: NA
 * Pre-conditions: An arrow is going to be fired 
 * Post-conditions: Arrow fired in a direction
 **************************************************/
void fire_arrow();


/**************************************************
 * Name: move_up()
 * Description: Moves adv 1 room up
 * Parameters: NA
 * Pre-conditions: User wants to move up 
 * Post-conditions: Adv moved 1 room up
 **************************************************/
void move_up();


/**************************************************
 * Name: move_down()
 * Description: Moves adv 1 room down
 * Parameters: NA
 * Pre-conditions: User wants to move down 
 * Post-conditions: Adv moved 1 room down
 **************************************************/
void move_down();


/**************************************************
 * Name: move_left()
 * Description: Moves adv 1 room left
 * Parameters: NA
 * Pre-conditions: User wants to move left 
 * Post-conditions: Adv moved 1 room left
 **************************************************/
void move_left();


/**************************************************
 * Name: move_right()
 * Description: Moves adv 1 room right
 * Parameters: NA
 * Pre-conditions: User wants to move right 
 * Post-conditions: Adv moved 1 room right
 **************************************************/
void move_right();


/**************************************************
 * Name: move()
 * Description: Gets direction of movement from user 
 * Parameters: char - W A S or D needed
 * Pre-conditions: Adv is on grid
 * Post-conditions: W A S or D returned
 **************************************************/
void move(char);


/**************************************************
 * Name: get_input()
 * Description: 
 * Parameters: 
 * Pre-conditions: 
 * Post-conditions: 
 **************************************************/
char get_input();


/**************************************************
 * Name: 
 * Description: 
 * Parameters: 
 * Pre-conditions: 
 * Post-conditions: 
 **************************************************/
void play_game(int, int, bool);


/**************************************************
 * Name: 
 * Description: 
 * Parameters: 
 * Pre-conditions: 
 * Post-conditions: 
 **************************************************/
string play_again();
};

#endif