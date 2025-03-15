/*******************************************
 * Program name: catalog.cpp
 * Author: Ivan Wong
 * Date: 10/29/23
 * Description: This file contains all of the function 
 *              definitions for the basketball catalog program
 * Input: All inputs from the user and the team info file
 * Ouput: NA
 ********************************************/

#include <iostream>
#include "catalog.h"
#include <fstream>
#include <string>

using namespace std;

//function definitions go here

Team* create_teams(int size) {
    Team* teamArr = new Team[size];     //Create and return dynamic team array
    return teamArr;
}

Player* create_players(int size) {
    Player* playerArr = new Player[size];       //Create and return dynamic player array
    return playerArr;
}

void populate_team_data(Team* teamArr, int teamIndex, ifstream& my_ifstream) {      //Fills a team struct with file data
    my_ifstream >> teamArr[teamIndex].name;
    my_ifstream >> teamArr[teamIndex].owner;
    my_ifstream >> teamArr[teamIndex].market_value;
    my_ifstream >> teamArr[teamIndex].num_player;
}

void populate_player_data(Player* playerArr, int playerIndex, ifstream& my_ifstream) {      //Fills a player struct with file data
    my_ifstream >> playerArr[playerIndex].name;
    my_ifstream >> playerArr[playerIndex].age;
    my_ifstream >> playerArr[playerIndex].nation;
    my_ifstream >> playerArr[playerIndex].ppg;
    my_ifstream >> playerArr[playerIndex].fg;
}

void delete_info(Team* teamArr, int teamSize) {      //This deletes memory on heap
    for (int i = 0; i < teamSize; i++) {        //Run for all teams
        delete [] teamArr[i].p;         //Delete player arrays
        teamArr[i].p = nullptr;         //Set player poitner to NULL
    }
    delete [] teamArr;      //Delete team array
    teamArr = nullptr;      //Set team pointer to NULL
}

string fileName() {             //Gets team file name from the user
    string fileName = "";
    ifstream openFileTest;

    cout << "\nEnter the team info file name: ";
    cin >> fileName;                        //User needs to enter file name

    openFileTest.open(fileName);        //Opening the user file name

    if (openFileTest.fail()) {
        cout << "NO file found\nExiting Program\n";     //Failed to open file, return empty string
        return "";
    }
    else {
        cout << "\nSuccessfully opened " << fileName << "\n";
        openFileTest.close();
        return fileName;                //File is found, file name is stored
    }
}

string main_options() {             //Gets user input for main option
    string option = "0";
    do {
        cout << "\nWhich option would you like to choose?\n"      //Prints out the options for the user
             << "1. Search team by name\n" 
             << "2. Display top scorer of each team\n"
             << "3. Search players by nationality\n" 
             << "4. Quit\n"
             << "Your choice: ";
        cin >> option;              //Take in user option

        if (option != "1" && option != "2" && 
            option != "3" && option != "4") {           //Message prints if user enters invalid input
            
            cout << "\nINVALID INPUT, TRY AGAIN\n";
        }
    }while (option != "1" && option != "2" &&
            option != "3" && option != "4");        //Keeps looping until user enters a valid input

    return option;
}

void populate_all_teams(Team* teamArr, ifstream& my_ifstream, int teamSize) {        //Populate all teams
    for (int i = 0; i < teamSize; i++) {
        populate_team_data(teamArr, i, my_ifstream);        //Populate one team
        teamArr[i].p = create_players(teamArr[i].num_player);      //Create dynamic array based on number of players

        for (int j = 0; j < teamArr[i].num_player; j++) {   
            populate_player_data(teamArr[i].p, j, my_ifstream);        //Populate players
        }
    }
}

void print_team_by_name(Team* teamArr, int teamIndex) {     //Function if for search by team name, print to screen
    cout << endl 
         << teamArr[teamIndex].name << ", "             //Print out team name and owner
         << teamArr[teamIndex].owner << endl;
    
    for (int i = 0; i < teamArr[teamIndex].num_player; i++) {       //Print out all the player and player info
        cout << teamArr[teamIndex].p[i].name << ", "
             << teamArr[teamIndex].p[i].age << ", "
             << teamArr[teamIndex].p[i].nation << ", "
             << teamArr[teamIndex].p[i].ppg << ", "
             << teamArr[teamIndex].p[i].fg << endl;
    }
}

int get_team_name() {       //Function gets the team name from a user
    string teamName;
    int teamIndex = -1;

    do {
        cout << "Enter team name: ";        //Ask for user input
        cin >> teamName;

        if (teamName == "Thunder_Strikers") {       //Set team name to proper team index
            teamIndex = 0;
        }
        else if (teamName == "Phoenix_Flames") {    //Set team name to proper team index
            teamIndex = 1;
        }
        else if (teamName == "Blizzard_Bears") {    //Set team name to proper team index
            teamIndex = 2;
        }
        else if (teamName == "Galaxy_Guardians") {  //Set team name to proper team index
            teamIndex = 3;
        }
        else {
            cout << "\nTeam Does Not Exist, Try again\n";   //Invalid input message
        }
    } while (teamIndex != 0 && teamIndex != 1 &&
            teamIndex != 2 && teamIndex != 3);      //Loop if user input is not a team name
                                                    //Function is "16" lines, but the while condition is split into 2 for readability
    return teamIndex;
}

void main_option1a(Team* teamArr, int teamIndex) {      //This function appends info of a team and its players to a file
    ofstream my_ofstream;
    string fileName;

    cout << "Enter a filename: ";       //Ask user for file name
    cin >> fileName;

    my_ofstream.open(fileName, ios::app);       //Open file and get ready to append it

    my_ofstream << teamArr[teamIndex].name << ", ";     //Print team name and owner
    my_ofstream << teamArr[teamIndex].owner << endl;

    for (int i = 0; i < teamArr[teamIndex].num_player; i++) {       //For loop prints out player info of each team
        my_ofstream << teamArr[teamIndex].p[i].name << ", ";
        my_ofstream << teamArr[teamIndex].p[i].age << ", ";
        my_ofstream << teamArr[teamIndex].p[i].nation << ", ";
        my_ofstream << teamArr[teamIndex].p[i].ppg << ", ";
        my_ofstream << teamArr[teamIndex].p[i].fg << endl;
    }
    cout << "\nAppended to " << fileName << endl;
}

void main_option1(Team* teamArr, string infoChoice) {         //Function handles info when user wants to display team info
    string teamName;
    infoChoice = display_info_choice();         //Get display info choice
    int teamIndex = -1;

    if (infoChoice == "1") {            //Print to terminal
        teamIndex = get_team_name();
        print_team_by_name(teamArr, teamIndex);
    }
    else if (infoChoice == "2") {       // Append to a file
        teamIndex = get_team_name();
        main_option1a(teamArr, teamIndex);
    }
    else {
        cout << "\nINVALID INPUT, DIRECTING BACK TO MAIN MENU\n";       //Invalid input message
    }
}

void print_top_scorers(Team* teamArr, int teamSize) {         //Function finds the top scorer of each team and prints it
    cout << endl;

    for (int i = 0; i < teamSize; i++) {       //Runs for each team
        string playerName = "";
        float ppg = 0;

        for (int j = 0; j < teamArr[i].num_player; j++) {       //Runs for each player
            if (teamArr[i].p[j].ppg > ppg) {            //Checking for the highest ppg of each team
                ppg = teamArr[i].p[j].ppg;              //Highest ppg stored in ppg
                playerName = teamArr[i].p[j].name;      //Name of highest ppg player stored in playerName
            }
        }
    cout << teamArr[i].name << ": " 
         << playerName << ", " 
         << ppg << endl;       //Print out team, player, and ppg
    }
}

void main_option2a(Team* teamArr, int teamSize) {
    ofstream my_ofstream;
    string fileName;

    cout << "Enter a filename: ";       //Ask user for file name
    cin >> fileName;

    my_ofstream.open(fileName, ios::app);       //Open file and get ready to append it

    for (int i = 0; i < teamSize; i++) {       //Runs for each team
        string playerName = "";
        float ppg = 0;

        for (int j = 0; j < teamArr[i].num_player; j++) {       //Runs for each player
            if (teamArr[i].p[j].ppg > ppg) {            //Checking for the highest ppg of each team
                ppg = teamArr[i].p[j].ppg;              //Highest ppg stored in ppg
                playerName = teamArr[i].p[j].name;      //Name of highest ppg player stored in playerName
            }
        }
    my_ofstream << teamArr[i].name << ", " 
                << playerName << ", " 
                << ppg << endl;       //Print out team, player, and ppg
    }
    cout << "\nAppended to " << fileName << endl;
}

void main_option2(Team* teamArr, string infoChoice, int teamSize) {     //Function handles print to screen or file for displaying top scorer
    infoChoice = display_info_choice();         //Get info choice from user

    if (infoChoice == "1") {
        print_top_scorers(teamArr, teamSize);       //Print to screen
    }
    else if (infoChoice == "2") {
        main_option2a(teamArr, teamSize);           //Append to a file
    }
    else {
        cout << "\nINVALID INPUT, DIRECTING BACK TO MAIN MENU\n";       //Invalid input message
    }
}

//Function is over 15 lines due to formating and readability rather than use of semi-colons
string get_nationality() {     //Function gets nationality from the user
    string nationality;

    do {
        cout << "Enter player nationality: ";       //Asks user for nation
        cin >> nationality;

        if (nationality != "USA" && nationality != "Canada" &&
            nationality != "Australia" && nationality != "Spain" &&
            nationality != "France" && nationality != "Brazil" &&
            nationality != "England" && nationality != "Argentina" &&
            nationality != "Russia" && nationality != "Portugal" &&
            nationality != "Sweden" && nationality != "Mexico") {
            
            cout << "\nINVALID INPUT, TRY AGAIN\n\n";           //Invalid input message
        }
    } while (nationality != "USA" && nationality != "Canada" &&         //Handles the invalid inputs and keeps user in loop
             nationality != "Australia" && nationality != "Spain" &&
             nationality != "France" && nationality != "Brazil" &&
             nationality != "England" && nationality != "Argentina" &&
             nationality != "Russia" && nationality != "Portugal" &&
             nationality != "Sweden" && nationality != "Mexico");
    
    return nationality;
}

void print_player_nationality(Team* teamArr, int teamSize) {        //Function prints players by nationality
    string nationality = get_nationality();         //Get nationality from user

    cout << endl;

    for (int i = 0; i < teamSize; i++) {                    //Runs for each team
        for (int j = 0; j < teamArr[i].num_player; j++) {               //Runs for each player
            if (teamArr[i].p[j].nation == nationality) {                //Checking for nationality match
                cout << teamArr[i].p[j].name << ", " 
                     << teamArr[i].p[j].age << endl;    //Printing out player name and age
            }
        }
    }
}

void main_option3a(Team* teamArr, int teamSize) {       //Function appends player info to a file, info based on nationality
    ofstream my_ofstream;
    string fileName;

    string nationality = get_nationality();         //Getting nationality from user

    cout <<"Enter a file name: ";       //Getting file name from user
    cin >> fileName;

    my_ofstream.open(fileName, ios::app);       //Getting ready to append file from user

    for (int i = 0; i < teamSize; i++) {            //Runs for each team
        for (int j = 0; j < teamArr[i].num_player; j++) {           //Runs for each player
            if (teamArr[i].p[j].nation == nationality) {            //Checking for nationality match
                my_ofstream << teamArr[i].p[j].name << ", " 
                            << teamArr[i].p[j].age << endl;     //Outputing player name and age into file
            }
        }
    }
    cout << "\nAppended to " << fileName << endl;
}

void main_option3(Team* teamArr, string infoChoice, int teamSize) {
    infoChoice = display_info_choice();         //Get info choice from user

    if (infoChoice == "1") {
        print_player_nationality(teamArr, teamSize);        //Print to screen
    }
    else if (infoChoice == "2") {
        main_option3a(teamArr, teamSize);
    }
    else {
        cout << "\nINVALID INPUT, DIRECTING BACK TO MAIN MENU\n";       //Invalid input message
    }
}

void run_main_menu(Team* teamArr, string mainOption, string infoChoice, int teamSize) {     //Handles user input 1-3 for mainOption
    if (mainOption == "1") {
        main_option1(teamArr, infoChoice);         //Search team by name
	}
	else if (mainOption == "2") {
        main_option2(teamArr, infoChoice, teamSize);         //Display top scorer of each team
	}
	else if (mainOption == "3") {
        main_option3(teamArr, infoChoice, teamSize);          //Search player by nationality
	}
}

string display_info_choice() {      //Takes user input of where they want info diplayed
    string choice = "0";
    do {
        cout << "\nHow would you like to display the information?\n"
             << "1. Print to screen\n"
             << "2. Print to file\n"
             << "Your choice: ";
        cin >> choice;              //Takes in choice

        if (choice != "1" && choice != "2") {
            cout << "\nINVALID INPUT, TRY AGAIN\n";
        }
    } while (choice != "1" && choice != "2");       //Handles invalid inputs
    return choice;
}