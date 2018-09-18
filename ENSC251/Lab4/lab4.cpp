/**
 * @file hw1a.cpp
 * @author Martin Benjamin
 * @Date   07/06/2018
 * @version 1.0
 * @section A program that uses classes to create ordered pairs
 * and uses overloaded operators
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
using namespace std;

class Pairs
{
public:
 Pairs( );
 //the order pair is initialized to (0,0)
 Pairs(int first);
 //the ordered pair is initialized to (first, 0)
 Pairs(int first, int second);
 //the orded pair is initiialized to (first,second)
 //other members and friends
 friend Pairs operator +(const Pairs& pair1, const Pairs& pair2);
 //Adds the ordered pairs as (a,b) + (c,d) and returns (a+c,b+d)
 //pair 1 and pair 2 must already be initialized
 friend Pairs operator -(const Pairs& pair1, const Pairs& pair2);
 //Adds the ordered pairs as (a,b) - (c,d) and returns (a-c,b-d)
 //pair 1 and pair 2 must already be initialized
 friend Pairs operator *(const Pairs& pair, const int multiplier);
 //multiplies an ordered pair (a,b) by the multiplier c
 //pair must already be initialized
 friend istream& operator >>(istream& ins, Pairs& second);
 //accepts input for an orded pair in the form (a,b)
 friend ostream& operator <<(ostream& outs, Pairs& second);
 //outputs an ordered pair (a,b)
private:
 int f;
 int s;
};

int main()
{
  //test the constructors
  cout << "Contructing a pair with no paramaters" << endl;
  Pairs mypair0;
  cout << mypair0 << endl;
  cout << "Constructing a pair with only 1 paramater, 1" << endl;
  Pairs mypair1(1);
  cout << mypair1 << endl;
  cout << "Constructing a pair with 2 paramaters, (1,-2)" << endl;
  Pairs mypair2(1,-2);
  cout << mypair2 << endl;

  //test the + - * operators
  cout << "Testing + operator with (1,0) + (1,-2)" << endl;
  Pairs exampleAdd = mypair1 + mypair2;
  cout << exampleAdd << endl;

  cout << "Testing - operator with (1,0) - (1,-2)" << endl;
  Pairs exampleSub = mypair1 - mypair2;
  cout << exampleSub << endl;

  cout << "Testing * operator with (1,-2) * 2" << endl;
  Pairs exampleMult = mypair2 * 2;
  cout << exampleMult << endl;

  //test the >> << operators
  cout << "Now input a pair in the form (a,b) with two ints" << endl;
  cin >> mypair0;
  cout << "You entered ";
  cout << mypair0 << endl;

  return 0;
}

//constructors for pairs
Pairs::Pairs()
{
  f = 0;
  s = 0;
}
Pairs::Pairs(int first)
{
  f = first;
  s = 0;
}
Pairs::Pairs(int first, int second)
{
  f = first;
  s = second;
}

//overload for << and >> operators
istream& operator >>(istream& ins, Pairs& second)
{
  bool breakflag = false; //for verifying input format
  char tempC = '\0'; //for reading brackets and comma
  while(breakflag == false)
  {
    //declare variables
    breakflag = true;
    tempC = '\0';

    //read the first character and confirm it is a (
    ins >> tempC;
    if (tempC != '(')
    {
      breakflag = false;
    }

    //read the first interger IF the previous input is valid
    if (breakflag == true)
    {
      {
        ins >> second.f;
      }
    }

    //read the , IF the previous input is valid
    if (breakflag == true)
    {
      ins >> tempC;
    }

    if (tempC != ',')
    {
      breakflag = false;
    }

    //read the second interger IF the previous input is valid
    if (breakflag == true)
    {
      ins >> second.s;
    }

    //read the ) IF the previous input is valid
    if (breakflag == true)
    {
      ins >> tempC;
    }
    if (tempC != ')')
    {
      breakflag = false;
    }

    //if everything is valid end the loop
    if (breakflag == true)
    {
      return ins;
      break;
    }

    //disregard previous input and offer another try
    ins.clear();
    ins.ignore(1000,'\n');
    cout << "That format was not supported, try again" << endl;
  }
}

ostream& operator <<(ostream& outs, Pairs& second)
{
  outs << '(';
  outs << second.f;
  outs << ',';
  outs << second.s;
  outs << ')';
  return outs;
}

//overload for + and - operators
//add the values of 2 pairs
Pairs operator +(const Pairs& pair1, const Pairs& pair2)
{
  Pairs temp;
  temp.f = pair1.f + pair2.f;
  temp.s = pair1.s + pair2.s;
  return temp;
}
//add the values
Pairs operator -(const Pairs& pair1, const Pairs& pair2)
{
  Pairs temp;
  temp.f = pair1.f - pair2.f;
  temp.s = pair1.s - pair2.s;
  return temp;
}

Pairs operator *(const Pairs& pair, const int multiplier)
{
  Pairs temp;
  temp.f = pair.f * multiplier;
  temp.s = pair.s * multiplier;
  return temp;
}
