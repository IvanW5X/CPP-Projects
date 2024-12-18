/***************************************
 * Program Name: main.cpp
 * Author: Ivan Wong
 * Date: 11/26/23
 * Description: Program runs game of Hunt the Wumpus
 * Inputs: Moving, firing arrows, play again, dimensions of grid
 * Outputs: Hunt the Wumpus
 ***************************************/

#include <cstdlib>
#include <ctime>
#include "game.h"

using namespace std;

int main() {
	srand(time(NULL));		//Set the random seed
	
	Game g;
	string playAgain = "";

	g.print_intro();

	do {
		int len = g.get_len();			//Get length
		int wid = g.get_wid();			//Get width
		bool debug = g.get_mode();		//Get mode

		g.play_game(wid, len, debug);		//Play game
		playAgain = g.play_again();			//Get option to play again

		g.clear_data();					//Clear remaining data from previous game

	} while(playAgain == "y");				//User wants to play again

	return 0;
}