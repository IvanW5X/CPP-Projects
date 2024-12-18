/* Program name: prog.cpp
 * Author: Ivan Wong
 * Date: 11/12/23
 * Description: 
 * Input: 
 * Ouput: 
 */

#include "display.h"

using namespace std;

int main()
{
	cout << "\nWelcome to Coffee++" << endl;		//your main function lives here
	int choice = -1;
	Shop s;

	ifstream menuFile, shopFile;		//Declare ifstreams

	s.load_data(menuFile, shopFile);		//populate your Shop:

	while (choice != QUIT){
		choice = get_choice();
		perform_action(s, choice);
	}

	cout << "Bye!" << endl;

	return 0;
}
