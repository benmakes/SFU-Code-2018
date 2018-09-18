/**
 * @file lab2b.cpp
 * @author Martin Benjamin
 * @Date   22/05/2018
 * @version 1.0
 * @section A program to take the input of 2 names as strings and output 2 names in pig latin
 */
// I declare that this assignment is my own work and that I have correctly
// acknowledged the work of others.  I acknowledged that I have read and
// following the Academic Honesty and Integrity related policies as
// outlined in the syllabus.
//
// _____ Benjamin Martin ____      _____May 22 2018______________
//
// ____ 301347720______

#include <iostream>
#include <string>
using namespace std;

void piglatin(string lastName, string firstName, string &pigLatFN, string &pigLatLN, string &pigLatName);

int main ()
{
    //declaring variables
    string firstName = ""; //user inputed first name
    string lastName = ""; //user inputed last name
    string pigLatFN = ""; //program generated pig latin first name
	string pigLatLN = ""; //program generated pig latin last name
	string pigLatName = ""; //program generated full pig latin name
	bool breakflag = false; //test to see if the strings entered are digits
	int lenFirstName = 0; //length of the first name string for error testing
	int lenLastName = 0; //length of the last name string for error testing
	int i = 0; //counter variable

    //request user input their names and test the input is entered correctly
	while(breakflag == false)
	{
		cout << "Please enter your first name" << endl;
		cin >> firstName;
    cin.ignore(1000,'\n');
		cout << "Please enter your last name" << endl;
		cin >> lastName;
    cin.ignore(1000,'\n');
		lenFirstName = firstName.length();
		lenLastName = lastName.length();

		breakflag = true;
		for (i=0;i<lenFirstName;i++)
		{
			if (isalpha(firstName[i])==false)
				breakflag = false;
		}
		for (i=0;i<lenLastName;i++)
		{
			if (isalpha(lastName[i])==false)
				breakflag = false;
		}
		if (breakflag == true)
		{
			break;
		}
		else
		{
			cerr << "Sorry, that name isn't all letters. Try again." << endl;
		}
	}

    piglatin(lastName, firstName, pigLatFN, pigLatLN, pigLatName);
	return 0;
}

/**
 * @brief piglatin takes the input of a first and last name and returns the outputs to the console the name in piglatin with the first letters capitalized
 *
 * @param lastName is a predefined string
 * @param firstName is a predefined string
 * @param pigLatFN is an empty string to be modified
 * @param pigLatLN is an empty string to be modified
 * @param pigLatName is an empty string to be modified
 * @return void
 *
 */

void piglatin(string lastName, string firstName, string &pigLatFN, string &pigLatLN, string &pigLatName)
{
    //declare variables
    int lenFirstName = 0; //length of first name
    int lenLastName = 0; //length of last name
	int i = 0; //counter
	char temp = ' '; //place holder for a swap

    //assign the length of each name to the appropriate variable
    lenFirstName = firstName.length();
    lenLastName = lastName.length();

    //change firstname and lastname to all lower case
	for (i=0;i<lenFirstName;i++)
	{
		firstName[i] = tolower(firstName[i]);
	}

	for (i=0;i<lenLastName;i++)
	{
		lastName[i] = tolower(lastName[i]);
	}

	//copy the strings to new strings to become pig latin
	pigLatFN = firstName;
	pigLatLN = lastName;

	/*if the first letter is a consonant move it to the end and add ay to it.
	If the first letter is a vowel add way to the end. */
	if (pigLatFN[0] == 'a' || pigLatFN[0] == 'e' || pigLatFN[0] == 'i' || pigLatFN[0] == 'o' || pigLatFN[0] == 'u' )
	{
		pigLatFN = pigLatFN + "way";
	}
	else
	{
		temp = pigLatFN[0];
		for (i=0;i<lenFirstName-1;i++)
		{
			pigLatFN[i] = pigLatFN[i+1];
		}
		pigLatFN[lenFirstName-1] = temp;
		pigLatFN = pigLatFN + "ay";
	}

	if (pigLatLN[0] == 'a' || pigLatLN[0] == 'e' || pigLatLN[0] == 'i' || pigLatLN[0] == 'o' || pigLatLN[0] == 'u' )
	{
		pigLatLN = pigLatLN + "way";
	}
	else
	{
		temp = pigLatLN[0];
		for (i=0;i<lenLastName-1;i++)
		{
			pigLatLN[i] = pigLatLN[i+1];
		}
		pigLatLN[lenLastName-1] = temp;
		pigLatLN = pigLatLN + "ay";
	}

	//captilize the first letters of both names
	pigLatFN[0] = toupper(pigLatFN[0]);
	pigLatLN[0] = toupper(pigLatLN[0]);

	//combine the names into a new string
	pigLatName = pigLatFN + " " + pigLatLN;

	//output the users piglatin name
	cout << "Your name in piglatin is " << pigLatName << endl;
	return;
}
