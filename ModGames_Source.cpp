/**************************************************************************************************************************************************/
// Name of Program:  GAME MODULES
// Written by : Htet Phyo Wai
// Date : September 24, 2018
// Purpose:	to present to the user a menu of game options.  
//          The user selects the menu number of the game selected and proceeds to play the game.  
//          When the game is completed, the program asks the user if she/he wishes to play another game. 
//          The user can continue to play any of the games as long as they wish.
/**************************************************************************************************************************************************/

#include <iostream>
#include "Games.h"
#include "HiLo.h"
#include "Storytime.h"
#include "Hangman.h"

/*
#include <string>
#include <cstdlib>	
#include <time.h>
*/


using namespace std;

/*
void intro();
void menu();
void input(int &);
void validate(string &);
void closing(string &);


void HLgame();
void introg1();
int RANDOM_NUMBER();
void guess(int &, int&);
void closingHL(string &);


void storyG();
void introg2();
void userQuestion();
void storymenu();
void storyinput(int &);
void story1();
void story2();
void story3();
void story4();
void closingstoryG(string &);



void gameHangMan();
void introg3();
void LOAD_ANSWER(int, string &);
int COMPLETED_WORD(int, string);
void HmInput(string &);
void PRINT_HANGED_MAN(int &);
void IMAGE_ONE();
void IMAGE_TWO();
void IMAGE_THREE();
void IMAGE_FOUR();
void IMAGE_FIVE();
void IMAGE_SIX();
void IMAGE_SEVEN();
void IMAGE_EIGHT();
void IMAGE_NINE();
void IMAGE_TEN();
void IMAGE_ELEVEN();
void closingHangMan(string &); */

/**************************************************************************************************************************************************/

int main()
{


	intro();						 //Function Call : Introduction Message 




	int menuinput = 0;				 // Declaration Statements

	do
	{
		menu();							 //Function Call : MENU SELECTION 		

		input(menuinput);				 //Function Call : Input and Validation

	} while (menuinput != 0);


	cout << "Press any key to exit the Program:";
	cin >> menuinput;

	return 0;
}
//End of Main Function *****************************************************************************************************************************/

/*/Function Definition :
//Name of Function : Intro
//Precondition : None
//Operation : This function will display the introduction message.
//Postcondition : None

void intro()  //Function Header 
{

	cout << "Welcome to the Game Modules program!Follow the instructions to select and play the games provided. We hope you have some fun!" << endl << endl;

}
//End of Introduction Message Function *************************************************************************************************************


//Function Definition :
//Name of Function : Menu
//Precondition : None
//Operation : This function will display the menu choices.
//Postcondition : None

void menu()  //Function Header
{
	cout << " Game Menu : " << endl;
	cout << "1- Hi / Low Game " << endl;
	cout << "2- Storytime " << endl;
	cout << "3- HangMan Game " << endl;
	cout << "0- Exit the program " << endl;

}
//End of MENU Function ****************************************************************************************************************************

//Function Definition :
//Name of Function : Input
//Precondition : The function receives an integer values passed as call - by - value parameters
//Operation : This function will direct to the game selected by the user by the selection logic .
//Postcondition : The function returns the menuinput as an integer value to the calling function.


void input(int & minput)  //Function Header
{
	string closinginp;
	string validation;


	cout << "Please enter the number from the list of the game you wish to play, or enter 0 (zero) to exit the program:" << endl;

	// Input 
	cin >> minput;

	while (minput < 0 || minput>3)                                 //Loop Logic for Invalid Input
	{
		cout << "You have entered an invalid menu selection." << endl;
		cout << "Please enter the number from the list of the game you wish to play, or enter 0 (zero) to exit the program:" << endl;
		cin >> minput;
	}
	if (minput == 1)												//Selection Logic for User Input 
	{
		cout << "You have entered " << minput << " to play High/Low Game.  Is this the game you wish to play?  Enter y for yes";
		validate(validation);
		HLgame();
	}
	else if (minput == 2)
	{
		cout << "You have entered " << minput << " to play Storytime Game.  Is this the game you wish to play?  Enter y for yes";
		validate(validation);
		storyG();
	}
	else if (minput == 3)
	{
		cout << "You have entered " << minput << " to play Game 3.  Is this the game you wish to play?  Enter y for yes";
		validate(validation);
		gameHangMan();
	}
	else if (minput == 0)
	{
		closing(closinginp);
		return;

	}


}
//End of INPUT Function ***************************************************************************************************************************


//Function Definition :
//Name of Function : validate
//Precondition : The function receives a string values passed as call - by - reference parameters
//Operation : This function will determine to continue the game .
//Postcondition : The function returns the validation input as a string value to the calling function

void validate(string & validation) // Function Header 
{
	//Input Statement 

	cin >> validation;

	// Selection Logic

	if (validation == "y")
		cout << "You will now play the Game" << endl;

}
//End of Input Validation Function******************************************************************************************************************

//Function Definition :
//Name of Function : Closing
//Precondition : None
//Operation : This function will display the closing message .
//Postcondition : None

void closing(string & closinginput)  //Function Header

{
	// Output 

	cout << "You have entered 0 to exit the game.  Are you ready to exit?  Enter y for yes" << endl;

	cin >> closinginput;


	if (closinginput == "y")
		cout << "Thank you for playing the Game Modules set of games. We hope you will return and play another game soon." << endl << endl;


}
//End of Closing Function*****************************************************************************************************************************
//****************************************END OF MAIN MENU MODULES************************************************************************************/

/* 

//Function Definition :
//Name of Function : HLgame
//Precondition : The function receives two integer values passed as call - by - value parameters
//Operation : This function will call the random number and the user input until they match each other.
//Postcondition : The function returns to the menuinput by the calling function.


void HLgame()
{

	introg1();


	// Declaration Statements

	int RandomNumber = 0;

	int Guessinput = 0;

	guess(Guessinput, RandomNumber);				 //Function Call : Input and Validation




	return;

}
//End of High Low game Module ***********************************************************************************************************************

//Function Definition :
//Name of Function : Intro
//Precondition : None
//Operation : This function will display the introduction message.
//Postcondition : None

void introg1()              // function header
{

	cout << "Welcome to the Hi/Low Game.  In this game, the computer has thought of a number between 1 and 100 inclusively.  See how many guesses it takes you to guess the correct number." << endl << endl;

}
//End of Introduction Message Function **************************************************************************************************************


// Function Name:  RANDOM_NUMBER
// Purpose:  To generate a random number
// Precondition:  None.
// Postcondition:  A randomly generated number is returned to the calling function.
int RANDOM_NUMBER()      // function header
{
	int RandomNumber = 0;
	srand(time(NULL));			// Calls the function to generate the random number.
	RandomNumber = rand() % 100 + 3;	// 100 is the range of values to be chosen (1-100), incremented by 1.
	return RandomNumber;
}
//End of Random Number Module************************************************************************************************************************


//Function Definition :
//Name of Function : Input
//Precondition : The function receives two integer values passed as call - by - value parameters
//Operation : This function will direct to the game selected by the user by the selection logic .
//Postcondition : The function returns the guessinput and randomnumber integer value to the calling function.


void guess(int & guessinput, int & RandomNumber)    // function header
{
	string closinginp;


	RandomNumber = RANDOM_NUMBER();                 // Declaration Statement

	cout << "The computer has selected its number." << endl << endl;

	cout << "Guess the number, enter 0 to exit the game:" << endl;

	while ((guessinput != RandomNumber) || (guessinput != 0))   //Loop for Invalid Number
	{
		cin >> guessinput;


		{	if (guessinput == RandomNumber)                      //Selection Logic
		{
			cout << "Congratulations!  You have correctly guessed that " << RandomNumber << " is the correct number. You will now be returned to the main game menu, where you can select to replay this game or choose another game." << endl;
			return;
		}
		else if ((guessinput < RandomNumber) && (guessinput > 0))
			cout << "Your guess is too low.  Try again.";
		else if ((guessinput > RandomNumber) && (guessinput < 100))
			cout << "Your guess is too high.  Try again.";
		else if (guessinput == 0)
		{
			closingHL(closinginp);
			return;
		}
		else
			cout << "You have entered an invalid value outside the range of this game." << endl;
		}
	}

}
//End of Guessing Function ***********************************************************************************************************************


//Function Definition :
//Name of Function : Closing
//Precondition : None
//Operation : This function will display the closing message .
//Postcondition : None

void closingHL(string & closinginput)   // function header
{

	//Output Statement 

	cout << "You have entered 0.  Do you really want to end this game and return to the main menu?  Enter y for yes" << endl;

	cin >> closinginput;


	if (closinginput == "y")
		cout << "You will now be returned to the main game menu, where you can select to replay this game or choose another game." << endl;


}

//End of Closing Function ***********************************************************************************************************************
//****************************************END OF High-Low Game***********************************************************************************
*/

/*/Function Definition :
//Name of Function : storyG
//Precondition : The function receives an integer value passed as call - by - value parameters
//Operation : This function will display the menu selection and the user choose the story.
//Postcondition : The function returns to the menuinput by the calling function.


void storyG()           // Function Header
{
	introg2();


	userQuestion();         //Fucntion Call :

	cout << "Now that you have told the computer about yourself, select one of the following adventure stories to read: " << endl;

	storymenu();		   //Function Call : MEnu for Story Selection			 			


	int StoryInput = 0;

	storyinput(StoryInput);






	return;
}
//End of Storytime Module *********************************************************************************************************************


//Function Definition :
//Name of Function : Intro
//Precondition : None
//Operation : This function will display the introduction message.
//Postcondition : None

void introg2()              // function header
{

	cout << "Welcome to Storytime.  In this game, you will be asked several questions about yourself.  Then you can select the adventure story you wish to read." << endl << endl;

}
//End of Introduction Message Function ********************************************************************************************************


//Function Definition :
//Name of Function : userQuestion
//Precondition : None
//Operation : This function will ask for the user to answer some question and display.
//Postcondition : The function will pass the user input to the callign function

void userQuestion() //function header
{
	//Declaration Statement
	string name;
	int age;
	string pet;
	string petname;

	//Output and Input Statements 

	cout << "Please tell the computer about yourself by answering the following questions with one-word answers" << endl << endl;
	cout << "What is your name?" << endl;
	cin >> name;
	cout << "How old are you?" << endl;
	cin >> age;
	cout << "What is your favorite pet or animal?" << endl;
	cin >> pet;
	cout << "What is your pet's name?" << endl;
	cin >> petname;
	cout << "You have entered " << endl;
	cout << "   Name: " << name << endl;
	cout << "   Age: " << age << endl;
	cout << "   Pet: " << pet << endl;
	cout << "   Pet Name: " << petname << endl;

}
//End of User Question  Function *************************************************************************************************************

//Function Definition :
//Name of Function(s) : StoryMenu
//Precondition : None
//Operation : This function will display the story menu
//Postcondition : None

void storymenu()  //function header
{
	//Display the Menu 

	cout << " Story Menu : " << endl;
	cout << "1- Story 1 " << endl;
	cout << "2- Story 2 " << endl;
	cout << "3- Story 3 " << endl;
	cout << "3- Story 4 " << endl;
	cout << "0- Exit the game " << endl;

}
//End of Story Menu  Function *************************************************************************************************************

//Function Definition :
//Name of Function(s) : StoryInput
//Precondition : The function receives an integer values passed as call-by-value parameters
//Operation :This function will direct to the game selected by the user by the selection logic 
//Postcondition : The function returns the storyinput as an integer value to the calling function. 

void storyinput(int & sinput)  //function header
{
	string closinginp;


	cout << "Please enter the number from the list of the story you wish to read, or enter 0 (zero) to exit the program:" << endl;
	cin >> sinput;

	while (sinput < 0 || sinput>4)         //Logic for Invalid Input 
	{
		cout << "You have entered an invalid menu selection." << endl;
		cout << "Please enter the number from the list of the story you wish to read, or enter 0 (zero) to exit the program:" << endl;
		cin >> sinput;
	}
	if (sinput == 1)                       //Selection Logic for User choices of story
	{
		story1();
	}
	else if (sinput == 2)
	{
		story2();
	}
	else if (sinput == 3)
	{
		story3();
	}
	else if (sinput == 4)
	{
		story4();
	}
	else if (sinput == 0)
	{
		closingstoryG(closinginp);
		return;

	}

}
//End of Story selection Function **************************************************************************************************************


//Function Definition :
//Name of Function(s) : Story1
//Precondition : None
//Operation : This function will display the story based on the user selection.
//Postcondition : None
void story1() //function header
{
	//Output 

	cout << "Here is Story 1: INSPIRATION " << endl;
	cout << "    	He was bored. So bored. He was hungry for new challenges but he was the last of the great innovators - society's problems had all been solved. All seemingly unconnected disciplines had long since been found to be related in horrifically elusive and contrived ways and he had mastered them all. He lay back in the dark and tried to relax. He longed for the challenges of the past when his racing mind prevented him from sleeping. It was tortuous at the time, but he now looked back on those times enviously. Then it hit him. Since he couldn't be presented with a challenging problem any more, all he had to do was to create a problem of his own design; so complicated and with so many interrelated complex relationships that only he could untangle them and calculate the ultimate outcome. But where to start? Then it hit him. He opened his eyes in the dark and said, Let there be light.(Source:ShortStoryArchive/AdaptationOftheStoryByDavidKelly)" << endl;
	cout << "***TheEnd***" << endl << endl;

	cout << "You may now select another story to read, or exit the game." << endl << endl;
	storymenu();

	int StoryInput = 0;

	storyinput(StoryInput);
	return;
}
//End of Story 1 Function *********************************************************************************************************************


//Function Definition :
//Name of Function(s) : Story2
//Precondition : None
//Operation : This function will display the story based on the user selection.
//Postcondition : None
void story2()
{
	cout << "Here is Story 2: The Birthday Machine" << endl;
	cout << "    	Calvin and his pet tiger, Hobbs, went for a walk in the forrest.  It was the day before his birthday.  He was going to be 7 years old.  On the trail, they saw . . ." << endl;
	cout << "***TheEnd***" << endl << endl;


	cout << "You may now select another story to read, or exit the game." << endl << endl;
	storymenu();

	int StoryInput = 0;

	storyinput(StoryInput);
	return;
}
//End of Story 2 Function *********************************************************************************************************************


//Function Definition :
//Name of Function(s) : Story3
//Precondition : None
//Operation : This function will display the story based on the user selection.
//Postcondition : None
void story3()
{
	cout << "Here is Story 3: " << endl;
	cout << "    	Calvin and his pet tiger, Hobbs, went for a walk in the forrest.  It was the day before his birthday.  He was going to be 7 years old.  On the trail, they saw . . ." << endl;
	cout << "***TheEnd***" << endl << endl;

	cout << "You may now select another story to read, or exit the game." << endl << endl;
	storymenu();

	int StoryInput = 0;

	storyinput(StoryInput);
	return;
}
//End of Story 3 Function *********************************************************************************************************************


//Function Definition :
//Name of Function(s) : Story4
//Precondition : None
//Operation : This function will display the story based on the user selection.
//Postcondition : None

void story4()
{
	cout << "Here is Story 4: " << endl;
	cout << "    	Calvin and his pet tiger, Hobbs, went for a walk in the forrest.  It was the day before his birthday.  He was going to be 7 years old.  On the trail, they saw . . ." << endl;
	cout << "***TheEnd***" << endl << endl;


	cout << "You may now select another story to read, or exit the game." << endl << endl;
	storymenu();

	int StoryInput = 0;

	storyinput(StoryInput);
	return;
}
//End of Story 4 Function *********************************************************************************************************************


//Function Definition :
//Name of Function(s) : ClosingStory
//Precondition : None
//Operation : This function will display the closing message
//Postcondition : None

void closingstoryG(string & closinginput) //function headder
{
	//Output Statements

	cout << "You have entered 0.  Do you really want to end this game and return to the main menu?  Enter y for yes" << endl;

	cin >> closinginput;


	if (closinginput == "y")
		cout << "You will now be returned to the main game menu, where you can select to replay this game or choose another game." << endl;


}
//End of Closing Function ***********************************************************************************************************************
//****************************************END OF Storytime Game***********************************************************************************/

/*/Function Definition :
//Name of Function(s) : Hangman Game
//Precondition : None
//Operation : This function will allow user to play game 3
//Postcondition : None

void gameHangMan()              // function header
{

	introg3();


	// Declaration Statements  

	string word = "cat";       //The word to be guessed.  
	int size = word.length();  //The number of characters in the word.  
	string answer = "***";     //Displayed word to be filled in with correctly guessed characters.  
	string guess = "";         //The letter guessed at each turn.  
	int IncorrectGuesses = 0;     //The number of incorrect guesses used to draw stickman.  
	int GuessedCorrectly = 0;
	int CorrectGuessFlag = 0;
	string PreviousGuesses = "";  //The list of letters already guessed by the player.  
	int i = 1;
	int x = 0;

	LOAD_ANSWER(size, answer);

	HmInput(guess);

	while (guess != "0")
	{

		for (x = 0; x <= size; x++)                  //when the guess input is equal to one of the character in the hidden word
		{
			if (guess == word.substr(x, 1))
			{
				answer.replace(x, 1, guess);
				cout << "You have guessed a correct letter in the word!" << endl << endl;
				cout << answer << endl;             // display the correct guess and its position in the word
				CorrectGuessFlag = 1;
				GuessedCorrectly = COMPLETED_WORD(size, answer);
			}
		}

		if (IncorrectGuesses < 11)                 // display the hangman when the user guess incorrectly for less than 11 times.
		{
			if (CorrectGuessFlag == 0)
			{
				IncorrectGuesses = IncorrectGuesses + 1;
				PreviousGuesses = PreviousGuesses + guess;
				cout << "Your guess is incorrect!" << endl;
				PRINT_HANGED_MAN(i);
				cout << "Your previous guesses are " << PreviousGuesses << endl;
			}

		}
		else
		{
			cout << "You Lost!!! See you Next Time!" << endl;

			break;
		}

		HmInput(guess);                          // Prompt for user guess after each round 



		CorrectGuessFlag = 0;

		if (GuessedCorrectly == 1)
		{
			break;
		}





		string ClosingInput;


		if (guess == "0")
		{
			closingHangMan(ClosingInput);              // Calling function: Closing 

			return;
		}


	}
	cout << "The correct answer is " << word << endl;

	return;
}

//End of HangMan Function *********************************************************************************************************************


//Function Definition :
//Name of Function(s) : introg3
//Precondition : None
//Operation : This function will display the introduction message
//Postcondition : None

void introg3()              // function header
{

	cout << "Welcome to HangMan Game. In this game, the player will guess a word by selecting an alphabet, and the hangman will displayed each time the player guessed it wrong." << endl << endl;

}
//End of Introduction Message Function ********************************************************************************************************


//Function Definition :
//Name of Function(s) : Load_Answer
//Precondition : This function receive the size of the word to be guessed
//Operation : This function will pass the numbers of word to be guessed 
//Postcondition : This function return the size and answer variable as call-by-referecne values. 

void LOAD_ANSWER(int size, string & answer)
{

	int i = 0;

	cout << "Here is your first word.  There are " << size << " letters in this word."
		<< endl << endl;

	for (i = 0; i < size; i++)
	{
		answer.replace(i, 1, "*");
		cout << answer.substr(0, 1) << " ";
	}

	cout << endl << endl;
}
//End of Load_Answer Function *********************************************************************************************************************


//Function Definition :
//Name of Function(s) : HmInput
//Precondition : None
//Operation : This function ask user to input the guess word. 
//Postcondition : This function pass the user input to the calling module. 

void HmInput(string & hminput)
{
	cout << "Please enter a guess, or enter 0 to exit" << endl;
	cin >> hminput;

}
//End of Hm Input Function *********************************************************************************************************************


//Function Definition :
//Name of Function(s) : Print_Hanged_Man
//Precondition : None
//Operation : This function will display the HangMan images one after another after each round of incorret guess.
//Postcondition : None

void PRINT_HANGED_MAN(int & i)
{

	switch (i)
	{
	case 1:
		IMAGE_ONE(); i++;
		break;
	case 2:
		IMAGE_TWO(); i++;
		break;
	case 3:IMAGE_THREE(); i++;
		break;
	case 4:	IMAGE_FOUR(); i++;
		break;
	case 5:
		IMAGE_FIVE(); i++;
		break;

	case 6:
		IMAGE_SIX(); i++;
		break;

	case 7:
		IMAGE_SEVEN(); i++;
		break;

	case 8:
		IMAGE_EIGHT(); i++;
		break;

	case 9:
		IMAGE_NINE(); i++;
		break;

	case 10:
		IMAGE_TEN(); i++;
		break;

	case 11:
		IMAGE_ELEVEN(); i++;
		break;

	}
}
//End of Print HangMan Function *********************************************************************************************************************


//Function Definition :
//Name of Function(s) : IMAGE_ONE; IMAGE_TWO; ... ; IMAGE_ELEVEN
//Precondition : None
//Operation : This function will display the images of the hangman
//Postcondition : None

void IMAGE_ONE()
{
	cout << "    ***      " << endl;
	cout << "   *   *     " << endl;
	cout << "    ***      " << endl;

}
void IMAGE_TWO()
{
	cout << "    ***      " << endl;
	cout << "   *   *     " << endl;
	cout << "    ***      " << endl;
	cout << "     |       " << endl;
}
void IMAGE_THREE()
{
	cout << "    ***      " << endl;
	cout << "   *   *     " << endl;
	cout << "    ***      " << endl;
	cout << "     |       " << endl;
	cout << "     |       " << endl;

}
void IMAGE_FOUR()
{
	cout << "    ***      " << endl;
	cout << "   *   *     " << endl;
	cout << "    ***      " << endl;
	cout << "     |       " << endl;
	cout << "     |       " << endl;
	cout << "     |       " << endl;

}
void IMAGE_FIVE()
{
	cout << "    ***      " << endl;
	cout << "   *   *     " << endl;
	cout << "    ***      " << endl;
	cout << "    -|       " << endl;
	cout << "     |       " << endl;
	cout << "     |       " << endl;

}
void IMAGE_SIX()
{
	cout << "    ***      " << endl;
	cout << "   *   *     " << endl;
	cout << "    ***      " << endl;
	cout << "   --|       " << endl;
	cout << "     |       " << endl;
	cout << "     |       " << endl;

}
void IMAGE_SEVEN()
{
	cout << "    ***      " << endl;
	cout << "   *   *     " << endl;
	cout << "    ***      " << endl;
	cout << "   --|--      " << endl;
	cout << "     |       " << endl;
	cout << "     |       " << endl;
}
void IMAGE_EIGHT()
{
	cout << "    ***      " << endl;
	cout << "   *   *     " << endl;
	cout << "    ***      " << endl;
	cout << "   --|--     " << endl;
	cout << "     |       " << endl;
	cout << "     |       " << endl;
	cout << "    /        " << endl;

}
void IMAGE_NINE()
{
	cout << "    ***      " << endl;
	cout << "   *   *     " << endl;
	cout << "    ***      " << endl;
	cout << "   --|--     " << endl;
	cout << "     |       " << endl;
	cout << "     |       " << endl;
	cout << "    /        " << endl;
	cout << "   /         " << endl;

}
void IMAGE_TEN()
{
	cout << "    ***      " << endl;
	cout << "   *   *     " << endl;
	cout << "    ***      " << endl;
	cout << "   --|--     " << endl;
	cout << "     |      " << endl;
	cout << "     |_       " << endl;
	cout << "    /       " << endl;
	cout << "   /         " << endl;
}
void IMAGE_ELEVEN()
{
	cout << "    ***      " << endl;
	cout << "   *   *     " << endl;
	cout << "    ***      " << endl;
	cout << "   --|--     " << endl;
	cout << "     |       " << endl;
	cout << "     |_ _    " << endl;
	cout << "    /        " << endl;
	cout << "   /         " << endl;
}
//End of Image Modules *********************************************************************************************************************


//Function Definition :
//Name of Function(s) : Completed_Word
//Precondition : This function receive the size of the word to be guessed
//Operation : This function will pass the value of flag for each correct/incorrect guesses
//Postcondition : This function return the flag value as call-by-referecne values. 

int COMPLETED_WORD(int size, string answer)
{
	int x = 0;
	int flag = 1;

	for (x = 0; x <= size; x++)
	{
		if (answer.substr(x, 1) == "*")
		{
			flag = 0;
		}
	}
	if (flag == 1)
	{
		cout << endl << "You have guessed the correct word!  --  ";
	}
	return flag;

}
//End of Completed_Word Function *********************************************************************************************************************


//Function Definition :
//Name of Function(s) : ClosingHangMan
//Precondition : None
//Operation : This function will display the closing message
//Postcondition : None

void closingHangMan(string & closinginput)
{
	//Output Statements

	cout << "You have entered 0.  Do you really want to end this game and return to the main menu?  Enter y for yes" << endl;

	cin >> closinginput;


	if (closinginput == "y")
		cout << "You will now be returned to the main game menu, where you can select to replay this game or choose another game." << endl;


}
//End of Closing Function ***********************************************************************************************************************/
//****************************************END OF HangMan Game***********************************************************************************/




