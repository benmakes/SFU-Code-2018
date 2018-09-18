/**
 * @file lab2b.cpp
 * @author Martin Benjamin
 * @Date   25/05/2018
 * @version 1.0
 * @section A program to change 24 hour time to am pm that throws errors
 * if the input is invalid.
 */
// I declare that this assignment is my own work and that I have correctly
// acknowledged the work of others.  I acknowledged that I have read and
// following the Academic Honesty and Integrity related policies as
// outlined in the syllabus.
//
// _____ Benjamin Martin ____      _____July 25 2018______________
//
// ____ 301347720______

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class TimeFormatMistake
{
  public:
    TimeFormatMistake();
};

int main()
{
  //declare consts
  const int MINMINUTES = 0;
  const int MAXMINUTES = 59;
  const int MINHOURS = 0;
  const int MAXHOURS = 23;
  //declare variables
  string again = "y";
  string time24 = "\0";
  string hoursString = "\0";
  string minutesString = "\0";
  int hours = 0;
  int minutes = 0;
  char comma = ':';


  while (again == "y")
  {
    try
    {
    //prompt user to input the time
    cout << "Enter the time in 24 hour notation:" << endl;
    cin >> time24;
    //verify the input is valid
    if (!(isdigit(time24[0]) && isdigit(time24[1]) && isdigit(time24[3])
      && isdigit(time24[4]) && (time24[2] == comma) && (time24.length()==5))
      && !(isdigit(time24[0]) && isdigit(time24[2])
      && isdigit(time24[3]) && (time24[1] == comma) && (time24.length()==4)))
      {
        throw TimeFormatMistake();
      }

    //verify the time is between 00:00 and 23:59
    minutesString = "00";
    if (time24[1] == comma)
    {
      hoursString = "0";
      hoursString[0] = time24[0];
      minutesString[0] = time24[2];
      minutesString[1] = time24[3];
    }
    else
    {
      hoursString = "00";
      hoursString[0] = time24[0];
      hoursString[1] = time24[1];
      minutesString[0] = time24[3];
      minutesString[1] = time24[4];
    }
    //convert the hours and minutes to ints
    hours = stoi(hoursString);
    minutes = stoi(minutesString);

    //check the hour and time are invalid
    if(!(hours >= MINHOURS && hours <= MAXHOURS) ||
      !(minutes >= MINMINUTES && minutes <= MAXMINUTES))
    {
      throw TimeFormatMistake();
    }

    //output the 12 hour time
    cout << "That is the same as" << endl;
    if (hours == 0)
    {
      cout << "12";
    }
    else if (hours < 13)
    {
      cout << hours;
    }
    else
    {
      cout << hours -12;
    }
    cout << ":" << setw(2) << setfill('0') << minutes << " ";
    if (hours < 12 && hours != 0)
    {
      cout << "AM";
    }
    else
    {
      cout << "PM";
    }
    cout << endl;

    //check if they wish to continue
    cout << "Again?(y/n)" << endl;
    cin >> again;
    while (again != "y" && again != "n")
    {
      cout << "Haha but seriously, y or n. Again?(y/n)" << endl;
      cin >> again;
    }
    }//endtry
    catch(TimeFormatMistake)
    {
      cout << "There is no such time as " << time24 << endl;
      cout << "Try again:" << endl;
    }
  }


  return 0;
}

TimeFormatMistake::TimeFormatMistake()
{}
