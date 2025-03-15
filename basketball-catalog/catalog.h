/* Program name: catalog.h
 * Author: Ivan Wong
 * Date: 10/29/23
 * Description: This file contains all of the function 
 *              declarations for the basketball catalog program
 * Input: Function declarations
 * Ouput: NA
 */

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//a struct to hold info of a team
struct Team {
  string name;        //name of the team
  string owner;       //owner of the team
  int market_value;   //market value of the team
  int num_player;     //number of players in the team
  struct Player *p;   //an array that holds all players
  float total_ppg;    //total points per game
};

//a struct to hold info of a player
struct Player {
  string name;      //name of the player
  int age;          //age of the player
  string nation;    //nationality of the player
  float ppg;        //points per game of the player
  float fg;         //field goal percentage
};


/**************************************************
 * Name: create_teams()
 * Description: This function will dynamically allocate
 *              an array of teams (of the requested size)
 * Parameters: int - size of the array
 * Pre-conditions: none
 * Post-conditions: a Team array of requested size is created and return
 ***********************************************/
Team* create_teams(int);


/**************************************************
 * Name: populate_team_data()
 * Description: This function will fill a single team struct 
 *              with information that is read in from the file
 * Parameters:  Team* - pointer to the Team array
 *              int - index of the Team in the array to be filled 
 *              ifstream& - input file to get information from
 * Pre-conditions: Team array has been allocated; 
 *                 provided index is less than the array size
 * Post-conditions: a Team at provided index is populated
 ***********************************************/
void populate_team_data(Team*, int, ifstream&); 


/**************************************************
 * Name: create_players()
 * Description: This function will dynamically allocate
 *              an array of players (of the requested size)
 * Parameters: int - size of the array
 * Pre-conditions: none
 * Post-conditions: a Player array of requested size is created and return
 ***********************************************/
Player* create_players(int);


/**************************************************
 * Name: populate_player_data()
 * Description: This function will fill a single player struct 
 *              with information that is read in from the file
 * Parameters:  Player* - pointer to the Player array
 *              int - index of the Player in the array to be filled 
 *              ifstream& - input file to get information from
 * Pre-conditions: Player array has been allocated; 
 *                 provided index is less than the array size
 * Post-conditions: a Player at provided index is populated
 ***********************************************/
void populate_player_data(Player*, int, ifstream&); 


/**************************************************
 * Name: delete_info()
 * Description: This function will  delete all the memory that was 
 *              dynamically allocated and set the pointers to null
 * Parameters: Team* - the Team array
 *             int - size of team array
 * Pre-conditions: the provided Team array hasn't been freed yet
 * Post-conditions: the Team array, with all Players inside, is freed
 ***********************************************/
void delete_info(Team*, int);


/***************************************************
 * Name: fileName()
 * Description: This function will take user input for the file name
 * Parameters: NA
 * Pre-conditions: User has not entered the file name
 * Post-conditions: User will have entered a valid file name
 ***************************************************/
string fileName();


/***************************************************
 * Name: main_options()
 * Description: Gets the user input for the four main options
 * Parameters: NA
 * Pre-conditions: Team file name has been correctly opened
 * Post-conditions: The user will have entered a number 1-4
 ****************************************************/
string main_options();


/*****************************************************
 * Name: populate_all_teams()
 * Description: This function populates all teams from the team file
 * Parameters: Team* - pointer to the team struct
 *             ifstream& - Input file to get data from
 *             int - Size of team array
 * Pre-conditions: Team array has been created, but not filled with proper data
 * Post-conditions: Team and player arrays will have been created and filled with proper data
 ****************************************************/
void populate_all_teams(Team*, ifstream&, int);


/******************************************************
 * Name: run_main_menu()
 * Description: Runs the main_options function and runs other functions based
 *              on what the user enters
 * Parameters: string& - user choice of what info the user wants
 *             string& - user choice of how the user wants info printed
 * Pre-conditions: Team file was successfully opened
 * Post-conditions: User will have entered a number 1-3 
 *******************************************************/
void run_main_menu(Team*, string, string, int);


/*******************************************************
 * Name: display_info_choice()
 * Description: This function will get the choice of how the user wants
 *              their info printed
 * Parameters: NA
 * Pre-conditions: User has all of the info they requested
 * Post-conditions: User choice will either be 1 or 2
 *********************************************************/
string display_info_choice();


/********************************************************
 * Name: main_option1()
 * Description: This function handles how the user wants to display team info
 * Parameters: Team* - grabs info from a Team struct
 *             string - grabs info of how the user wants to display data
 * Pre-conditions: All structs have been filled and user entered 1
 * Post-conditions: NA
 ********************************************************/
void main_option1(Team*, string);


/********************************************************
 * Name: print_team_by_name()
 * Description: This function prints a teams name, owner, and all of the players 
 *              and their attributes
 * Parameters: Team*- grabs data from a team struct
 *             int - team index
 * Pre-conditions: User entered a valid team name
 * Post-conditions: Team info will be printed on the screen
 ********************************************************/
void print_team_by_name(Team*, int);


/********************************************************
 * Name: main_option1a()
 * Description: This function appends team info to a file the user wants
 * Parameters: Team* - grabs data from a team struct
 *             int - team index
 * Pre-conditions: User entered a valid team name and a file name
 * Post-conditions: Team info will be appended onto the requested file
 ********************************************************/
void main_option1a(Team*, int);


/********************************************************
 * Name: get_team_name() 
 * Description: This function gets the team name from the user
 * Parameters: NA
 * Pre-conditions: NA
 * Post-conditiond: A valid team name will be stored
 ********************************************************/
int get_team_name();


/********************************************************
 * Name: main_option2()
 * Description: Handles user input for displaying top scorer to screen or file
 * Parameters: Team* - Grabs info from team array
 *             string - info choice from user
 *             int - size of the team array
 * Pre-conditions: User wants the top scorer
 * Post-conditions: User will be able to display top scorer of each team
 ********************************************************/
void main_option2(Team*, string, int);


/********************************************************
 * Name: print_top_scorers()
 * Description: Prints top scorers to screen/terminal
 * Parameters: Team* - grabs info from team array
 *             int - size of team array
 * Pre-conditions: Top scorers of each team are stored and user wants to 
 *                 print them to screen
 * Post-conditions: Top scorers of each team will be printed to the screen
 ********************************************************/
void print_top_scorers(Team*, int);


/********************************************************
 * Name: get_nationality()
 * Description: Gets the nationality by the user and stores the answer
 * Parameters: NA
 * Pre-conditions: User wants to search for players by nationality
 * Post-conditions: Nationality is valid and stored
 ********************************************************/
string get_nationality();


/********************************************************
 * Name: main_option2a()
 * Description: Prints top scorer of each team to a file
 * Parameters: Team* - grabs info from team array
 *             int - size of team array
 * Pre-conditions: User wants to print top scorer to a file
 * Post-conditions: Requested file will be appended with top scorer of each team
 ********************************************************/
void main_option2a(Team*, int);


/********************************************************
 * Name: print_player_nationality()
 * Description: Prints players by nationality
 * Parameters: Team* - grabs info from team array
 *             int - size of team array
 * Pre-conditions: User entered valid nationality and wants to print players to screen
 * Post-conditions: Players with matching nationality will be printed to screen
 ********************************************************/
void print_player_nationality(Team*, int);


/********************************************************
 * Name: main_option3()
 * Description: Handles where the user wants player of the same nationality to be displayed
 * Parameters: Team* - grabs info from team array
 *             string - info choice from the user
 *             int - size of team array
 * Pre-conditions: User entered a valid nationality
 * Post-conditions: Player with matching nationality will be printed to screen or a file
 ********************************************************/
void main_option3(Team*, string, int);


/********************************************************
 * Name: main_option3a()
 * Description: Prints player by nationality to a file
 * Parameters: Team* - grabs info from team array
 *             int - size of team array
 * Pre-conditions: User wants to print player by nationality to a file
 * Post-conditions: Players with matching nationality will be printed to requested file
 ********************************************************/
void main_option3a(Team*, int);