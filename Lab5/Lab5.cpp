/*
-----------------------------------
Aiden Trimble
C++ Fall 2020
Due: November 2nd, 2020
Lab 5 Number Guessing Game
To Create A Number Guessing Game
-----------------------------------
*/


#include <stdlib.h> //Library used for the random number generator
#include <time.h> //Library used that contains time and date function declarations
#include <iostream> //Library used for basic functions
#include <string> //Library used for the string function

using namespace std;

void gameresult(int& gamewins, int& gamelosses, int& guesses); 
/*
Preconditions: The random number, amount of guesses, and guess need to go through and the input needs to be valid.
Postconditions: The gamewins or gamelosses will go up by one depending if the player guessed correctly or not.
*/
bool again(int& ranNumber);
/*
Preconditions: The number of guesses, gamewins and gamelosses need to go through the function.
Postconditions: Function allows player to input 1 or 2 if they want to play again.
*/
void againquestion(int& ranNumber);
/*
Preconditions: Needs to go into the again function without errors.
Postconditions: Function outputs the random question if the player chooses to play again.
*/
void winMsg(int guesses);
/*
Preconditions: Function needs to continue with no errors.
Postconditions: Will output the randome win message if the player wins.
*/
void loseMsg(int guesses, int& ranNumber);
/*
Preconditions: Function needs to continue with no errors.
Postconditions: Will output the randome lose message if the player loses.
*/
void loop(int& guesses, int& ranNumber);
/*
Preconditions: Main loop that needs the guess, number of guesses, and random number without errors.
Postconditions: Determines whether or not the input is valid and runs the win or lose functions.
*/
void guessNumber(int);
/*
Preconditions: Function needs number of guesses without errors.
Postconditions:Function is ran through the main loop to count up the guess number the player is on.
*/

int guesses; //Gives guesses a number value

int main() //Main function definition
{
	int gamewins = 0;
	int gamelosses = 0;
	//Declaration for the game wins and losses

	bool playagain = true;
	string lines = "---------------------------------------------------------------------------------";
	//String dashes for convenience
	cout << lines << "\n\t      Welcome to the Random Number guessing Game!" << endl;
	cout << "\n\t\t   The Number is between 0 and 100!" << endl;
	cout << "\n\tYou Have 20 guesses to Guess the Random Number and Win!\n" << endl;
	cout << " Please Only Input Numbers, The Game Will End If You Input Letters Or Characters\n" << lines << endl;
	//Outputs the introduction of the game and explains the basic rules of how to play

	do
	{
		srand(unsigned int(time(NULL)));
		int ranNumber = rand() % 101;
		//This generates the random number between 0 and 100

		loop(guesses, ranNumber);
		//Plays the loop function

		gameresult(gamewins, gamelosses, guesses);
		//Plays the game result function
	

		if (again(ranNumber))
		{
			playagain = true;
		}
		else
		{
			playagain = false;
		}
		//Checks the value of the again function
		cout << endl;
	}
	//Checks to see if the playagain is true or false and repeats if it is true and ends if it is false
	while (playagain);
} 


void loop(int& guesses, int& ranNumber)
//Function that contains the main structure
{
	
int guess; //Gives guess an integer value
	
	for (guesses = 1; guesses <= 20; guesses++)
	{

		cout << "Type in your "; 
		guessNumber(guesses);
		cout << " guess:\n\n";
		//Output that tells the player to put in their next guess

		cin >> guess;
		//Allows the player to input the guess
		cout << endl;
		if (!cin)
		//Outputs the invalid message if the value was anything other than a number
		{
			cout << "Invalid Input, Only Guess Numbers Please" << endl;
			break;
		}
		if (guess < 0)
		//Outputs a message if the inputted number is less than 0
		{
			cout << "\nThe Number You Entered is Out of Bounds, Guess Between 0 and 100" << endl;
			continue;
		}
		if (guess > 100)
		//Outputs a message if the inputted number is greater than 100
		{
			cout << "\nThe Number You Entered is Out of Bounds, Guess Between 0 and 100" << endl;
			continue;
		}
		if (guess == ranNumber)
		//Sees if the inputted number is equal to the random number
		{
			guesses = 999;
			//Sets the guesses to 999 for reference used later if the player guesses correctly
			winMsg(guesses);
			break;
		}
		else
		//Outputs the function loseMsg if the guess is wrong
		{
			loseMsg(guesses, ranNumber);
			
		}
		
	}
}

void gameresult(int& gamewins, int& gamelosses, int& guesses)
//Function that outputs whether the player lost or won
{
	if (guesses == 999)
	//Checks to see if the guesses was set to 999 and if so it adds a win
	{
		gamewins++;
		
	}
	else
	//Checks to see if it wasn't and results to adding a loss
	{
		gamelosses++;

	}
	cout << "Games Won: " << gamewins << endl << "Games Lost: " << gamelosses << endl << endl;
	//Outputs the number of game wins and game losses
}

void guessNumber(int guesses)
//Creates the guess number the player is on
{
	switch (guesses)
	{
	case 1: cout << "1st";
		break;
	case 2: cout << "2nd";
		break;
	case 3: cout << "3rd";
		break;
	case 4:case 5:case 6:case 7:case 8:case 9:case 10:case 11:case 12:case 13:
	case 14:case 15:case 16:case 17:case 18:case 19:case 20: cout << guesses << "th";
		break;
	default: cout << "Next";
	}
}


bool again(int& ranNumber)
//Outputs the random play again question and allows the player to select yes or no
{
	int yn;
	againquestion(ranNumber);
	cout << "Input 1 for Yes or 2 for No\n" << endl;
	cin >> yn;

		if (yn == 1)
		//Plays the loop again if the player inputs 1
		{
			cout << endl;
			return 1;
		}
		if (yn == 2)
		//Ends the program if the player inputs 2 and outputs a thank you message
		{
		
			cout << "\nThank You For Playing!" << endl;
			return 0;
			
		}
		else
		//Ends program if player inputs anything else
		{
			cout << "I Will Take That As A No" << endl;
			return 0;
		}
	
}


void winMsg(int guesses)
//Function that outputs a random winning message when the player guesses correctly
{
	if (guesses == 999)
	//plays this part only if it was set to 999 from guessing correctly
	{
		srand(unsigned int(time(NULL)));
		int ranwinmsg = rand() % 11;
		//Creates the random number to choose the winning statement
		switch (ranwinmsg)
		{
		case 1: cout << "Congrats! You won!" << endl;
			break;
		case 2: cout << "Woo Hoo! You Win... Bragging Rights!" << endl;
			break;
		case 3: cout << "Congratulations! You Guessed Correctly!" << endl;
			break;
		case 4: cout << "Wow! That Was A Lucky Guess!" << endl;
			break;
		case 5: cout << "Good Job! You Won!" << endl;
			break;
		case 6: cout << "Jack Pot! You Guessed Right!" << endl;
			break;
		case 7: cout << "The Odds Were Against You, Tenno, But You Did It" << endl;
			break;
		case 8: cout << "Nice! That Was Right" << endl;
			break;
		case 9: cout << "Wow You Actually Got That? Good Job!" << endl;
			break;
		case 10: cout << "Add That To Your Collection Of Achievements Because You Just Won!" << endl;
			break;
		default: cout << "You Win!" << endl;
		}
		//Outputs the winning statement

	}
	
}

void loseMsg(int guesses, int& ranNumber)
//Function that outputs a random losing message when the player guesses incorrectly
{
	srand(unsigned int(time(NULL)));
	int ranlossmsg = rand() % 11;
	//Creates the random number to choose the losing statement
	switch (ranlossmsg)
	{
	case 1: cout << "The Number You Guessed Was Wrong" << endl;
		break;
	case 2: cout << "Try Again" << endl;
		break;
	case 3: cout << "Maybe Next Time" << endl;
		break;
	case 4: cout << "Wrong, Good Guess Though" << endl;
		break;
	case 5: cout << "Not Even Close, Try Again" << endl;
		break;
	case 6: cout << "You're Not Going To Win If You Guess Like That" << endl;
		break;
	case 7: cout << "Nope, Give It Another Shot" << endl;
		break;
	case 8: cout << "Incorrect, Guess Again" << endl;
		break;
	case 9: cout << "That Wasn't It" << endl;
		break;
	case 10: cout << "Try Something Else" << endl;
		break;
	default: cout << "Your Guess Was Incorrect" << endl;
	}
	//Outputs the losing statement
		
}

void againquestion(int& ranNumber)
//Function that outputs a random message asking the player if they want to play again
{

	srand(unsigned int(time(NULL)));
	int againquestion = rand() % 11;
	//Creates the random number to choose random question
	switch (againquestion)
	{
	case 1: cout << "Would You Like To Play Again?" << endl;
		break;
	case 2: cout << "You Got Another Round In Ya?" << endl;
		break;
	case 3: cout << "One More Game?" << endl;
		break;
	case 4: cout << "Are You Up For It Again?" << endl;
		break;
	case 5: cout << "That Was Fun, Wasn't It? Play Again?" << endl;
		break;
	case 6: cout << "You Got Nothing Else To Do, Play Again?" << endl;
		break;
	case 7: cout << "Don't Take A Break, Play Again?" << endl;
		break;
	case 8: cout << "I Dare You To Play Again, Accept The Challenge?" << endl;
		break;
	case 9: cout << "I Know You Can Do It, Play Again?" << endl;
		break;
	case 10: cout << "I Know You Want To Play Again Soooo Play Again?" << endl;
		break;
	default: cout << "Play Again?" << endl;
	}
	//Outpus the random question
}

