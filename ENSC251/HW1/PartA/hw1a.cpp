/**
 * @file hw1a.cpp
 * @author Martin Benjamin
 * @Date   30/05/2018
 * @version 1.0
 * @section A program that uses classes to play rock paper scissors vs the cpu
 *
 */
// I declare that this assignment is my own work and that I have correctly
// acknowledged the work of others.  I acknowledged that I have read and
// following the Academic Honesty and Integrity related policies as
// outlined in the syllabus.
//
// _____ Benjamin Martin ____      _____May 30 2018______________
//
// ____ 301347720______

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

//create rock paper scissors class
class Rps
{
public:
  //Rps constructor. Initializes all member variables to 0.
  Rps( );

  //accessor functions for member variables
  string getCpuWeapon();
  string getUserWeapon();
  string getWinner();

  //mutator functions
  void cpuChoice();//generate computer choice
  void userChoice();//prompt the user to select his choice
  void chooseWinner();//compare weapons to decide who won the game

  //output function to display the selections and the winner
  void output(ostream& outs);

private:
  //member variables
  int cpuWeapon; //1 is rock, 2 is paper, 3 is scissors.
  int userWeapon; //1 is rock, 2 is paper, 3 is scissors.
  int winner; //0 is tie, 1 is user, 2 is cpu.
};

int main()
{
  /****
  test driver program:
  To ensure a random number srand() must be set appropriately.
  To use this Rock Paper Scissors game, first construct an Rps class with no
  input. Then use the cpuChoice() function to create a random computer choice.
  Next ask for input with userChoice(). userChoice() will verify the input is
  acceptable, meaning the first non space input is a digit. chooseWinner()
  will determine the winner based on the user and cpu weapon selections.
  output(ostream& outs) takes an output stream as an input, and displays the
  results of the game to that stream
  ****/

  //testing creating the object and the accessor functions
  cout << "Test driving the program in 3... 2... 1..." << endl << endl;
  cout << "Setting the random seed to 0" << endl;
  srand(0);
  cout << "creating an Rps object test" << endl;
  Rps test;
  cout << "test.getCpuWeapon() and test.getUserWeapon() should confirm "<<
    "they have been correctly created." << endl;
  cout << "test.getWinner() should report noone has won." << endl << endl;
  cout << test.getCpuWeapon() << endl;
  cout << test.getUserWeapon() << endl;
  cout << test.getWinner() << endl << endl;

  //testing the cpuChoice, and userChoice functions
  cout << "Now testing test.cpuChoice() with a set seed." << endl;
  test.cpuChoice();
  cout << "displaying cpuWeapon has changed" << endl;
  cout << test.getCpuWeapon() << endl<< endl;

  cout << "Now testing test.userChoice() and input verification." << endl <<
    "Unacceptable input prompts for another attempt.\n";
  test.userChoice();
  cout << test.getUserWeapon() << endl << endl;

  //testing chooseWinner() function
  cout << "Now testing test.chooseWinner reports correctly" << endl;
  test.chooseWinner();
  cout << "The winner is reported as " << test.getWinner() << endl << endl;

  //testing output fucntion with cout
  cout << "Now testing test.output(cout) function displays correctly" << endl;
  test.output(cout);

  cout << "Test driving complete!" << endl;
  cout << "===============================================" << endl << endl;
  //Test drive program ends

  //Main program begins

  //set the random seed
  srand(time(0));

  //announce the game
  cout << "WELCOME TO THE ULTIMATE ARENA OF ROCK PAPER SCISSORS" << endl
    << "Hear the roar of of my people and tremble" << endl
    << "\"BLEEP BLOOP BLEEP... BLEEP BLEEP BLOOP...\"" << endl
    << "Now proceed, mortal, if ye not wish to live forever" << endl;

  //create the Rps game
  Rps game;

  //play the game until there is not a tie
  while ((game.getWinner() != "user") && (game.getWinner() != "cpu"))
  {
    //make cpu selection
    game.cpuChoice();
    //make user selection
    game.userChoice();
    //select the winner
    game.chooseWinner();
    //display the weapons and the outcome
    game.output(cout);
  }

  return 0;
}

//Constructor function for Rps class initializing all member variables to 0
Rps::Rps()
{
  cpuWeapon = 0;
  userWeapon = 0;
  winner = 0;
}

//accesor functions for member variables
string Rps::getCpuWeapon()
{
  if (cpuWeapon == 1)
  {
    return "rock";
  }
  else if (cpuWeapon == 2)
  {
    return "paper";
  }
  else if (cpuWeapon == 3)
  {
    return "scissors";
  }
  //for testing
  else if (cpuWeapon == 0)
  {
    return "cpuWeapon has been created properly";
  }
  else
  {
    cerr << "Error: The cpu weapon is not interpretable." << endl;
    return "Error: getCpuWeapon";
  }
}
string Rps::getUserWeapon()
{
  if (userWeapon == 1)
  {
    return "rock";
  }
  else if (userWeapon == 2)
  {
    return "paper";
  }
  else if (userWeapon == 3)
  {
    return "scissors";
  }
  //for testing
  else if (userWeapon == 0)
  {
    return "userWeapon has been created properly";
  }
  else
  {
    cerr << "Error: The user weapon is not interpretable." << endl;
    return "Error getUserWeapon";
  }
}
string Rps::getWinner()
{
  if (winner == 0)
  {
    return "noone";
  }
  else if (winner == 1)
  {
    return "user";
  }
  else if (winner == 2)
  {
    return "cpu";
  }
  else
  {
    cerr << "Error: The winner is not interpretable." << endl;
    return "Error getWinner";
  }
}

//mutator functions
//Rps::cpuChoice uses srand to determine one int 1-3 to determine
//the cpu's weapon. Please determine the srand in the main.
//1 for rock. 2 for paper. 3 for scissors.
void Rps::cpuChoice()
{
  cpuWeapon = (rand() % 3) + 1;
}

//Rps::userChoice prompts the user to input their choice from a menu by int.
//1 for rock. 2 for paper. 3 for scissors.
void Rps::userChoice()
{
  //declare variables
  int userWeaponEntry = 0; //inputed by userChoice
  bool breakflag = 0;
  //request input and verify
  while (breakflag == 0)
  {
    cout << "Please select your weapon. 1 is for rock. 2 is for paper." <<
    " 3 is for scissors" << endl;
    cin >> userWeaponEntry;
    cin.clear();
    cin.ignore(1000,'\n');
    //verify the entry is valid
    if (userWeaponEntry >= 1 && userWeaponEntry <= 3 )
    {
      userWeapon = userWeaponEntry;
      breakflag = 1;
    }
    if (breakflag == 1)
    {
      break;
    }
    else
    {
      cerr << "Sorry, the input you provided could not be understood. Try again."
        << endl;
    }
  }
}

//Rps::chooseWinner compares the weapons chosen by the cpu and the user
//and records the winner.
//0 is for a tie. 1 is user. 2 is cpu.
void Rps::chooseWinner()
{
  if (userWeapon == cpuWeapon)
  {
    winner = 0;
  }
  else if ((userWeapon==1 && cpuWeapon==3) ||
    (userWeapon==2 && cpuWeapon==1) || (userWeapon==3 && cpuWeapon==2))
  {
    winner = 1;
  }
  else if ((cpuWeapon==1 && userWeapon==3) ||
    (cpuWeapon==2 && userWeapon==1) || (cpuWeapon==3 && userWeapon==2))
  {
    winner = 2;
  }
  else
    cerr << "There was a problem with the winner selection" << endl;
}

void Rps::output(ostream& outs)
{
  outs << "You chose " << getUserWeapon() << endl;
  outs << "The cpu chose " << getCpuWeapon() << endl;
  outs << "The winner was " << getWinner() << endl;
}
