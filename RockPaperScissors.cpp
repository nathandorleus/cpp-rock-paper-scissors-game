// C++ program to play rock paper scissors
#include <iostream> // Allows the program to use input and output
#include <ctime> // Provides time() to help generate random computer choices
#include <cctype> // Provides tolower() to convert uppercase letters to lowercase
using namespace std;

char getUserChoice(); // Gets and validates the user's choice
char getComputerChoice(); // Generates the computer's choice
void showChoice(char choice); // Displays the full name of a choice
void chooseWinner(char player, char computer); // Determines the winner of the round

int main(){
	// Variables that store the player's and computer's choices
	char player;
	char computer;

	// Get the user's choice and display it
	player = getUserChoice();
	cout << "Your choice: ";
	showChoice(player);

	// Generate the computer's choice and display it
	computer = getComputerChoice();
	cout << "Computer's choice: ";
	showChoice(computer);

	// Compare both choices and display the result
	chooseWinner(player, computer);

	return 0;
}

// Gets the user's choice and checks that it is valid
char getUserChoice(){
	char player;
	
	// Repeat the prompt until the user enters a valid choice
	do{
		cout << "Choose one of the following\n";
		cout << "*************************\n";
		cout << "'r' or 'R' for rock\n";
		cout << "'p' or 'P' for paper\n";
		cout << "'s' or 'S' for scissors\n";
		cout << "*************************\n";

		cin >> player;

		// Convert the input to lowercase so uppercase letters also work
		player = tolower(static_cast<unsigned char>(player));

		if(player != 'r' && player != 'p' && player != 's'){
			cout << "Invalid input.\n";
		}
	}

	while(player != 'r' && player != 'p' && player != 's');

	// Return the valid choice
	return player;
}

// Randomly selects a choice for the computer
char getComputerChoice(){

	// Seed the random number generator using the current time
	srand(time(0));

	// Generate a random integer from 1 through 3
	int num = rand() % 3 + 1;

	switch(num){
		case 1:
			return 'r';
		case 2:
			return 'p';
		case 3:
			return 's';
	}

	return 0;
}

// Displays the full name of the selected choice
void showChoice(char choice){
	switch(choice){
		case 'r':
			cout << "Rock\n";
			break;
		case 'p':
			cout << "Paper\n";
			break;
		case 's':
			cout << "Scissors\n";
			break;
	}
}

void chooseWinner(char player, char computer){
	switch(player){
		case 'r': // The player chose rock
			if(computer == 'r'){
				cout << "It's a tie!\n";
			}
			else if(computer == 'p'){
				cout << "You lose!\n";
			}
			else{
				cout << "You win!\n";
			}
			break;
		case 'p': // The player chose paper
			if(computer == 'r'){
				cout << "You win!\n";
			}
			else if(computer == 'p'){
				cout << "It's a tie!\n";
			}
			else{
				cout << "You lose!\n";
			}
			break;
		case 's': // The player chose scissors
			if(computer == 'r'){
				cout << "You lose!\n";
			}
			else if(computer == 'p'){
				cout << "You win!\n";
			}
			else{
				cout << "It's a tie!\n";
			}
			break;
	}

	cout << "*************************\n";
}
