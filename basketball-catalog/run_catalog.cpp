/* Program name: run_catalog.cpp
 * Author: Ivan Wong
 * Date: 10/29/23
 * Description: This file contains all of the function 
 * 				definitions for the basketball catalog program
 * Input: Function definitions
 * Ouput: Sorted information of data from a basketball league file
 */

#include <iostream>
#include "catalog.h"
#include <fstream>
#include <string>

using namespace std;

int main() {
	ifstream my_ifstream;			//Variable declarations, all iniitialized to 0 if possible
	int teamSize = 0;
	int teamIndex = 0;
	int playerIndex = 0;
	string mainOption = "0";
	string infoChoice = "0";

	string teamFile = fileName();		//Get file name from user

	my_ifstream.open(teamFile);		//Open user input file name

	if (teamFile == "") {		//Failed to open file, program termination
		return 1;			//Exit with exit code 1
	}
	my_ifstream >> teamSize;			//Take size of team array from file
	
	Team* teamArr = create_teams(teamSize);				//Create the dynamic team array
	populate_all_teams(teamArr, my_ifstream, teamSize);			//Populate all team arrays

	do {
		mainOption = main_options();
		
		if (mainOption == "4") {		//Exiting program, user choice
			cout << "\nExiting Program\n\n";

			delete_info(teamArr, teamSize);		//Free memory by deleting dynamic arrays
			return 0;						//Exit program
		}
		run_main_menu(teamArr, mainOption, infoChoice, teamSize);		//Main options menu function
	} while (mainOption != "4");		//Stay in program as long as user doesn't quit
}