/**
 * @file lab3b.cpp
 * @author Martin Benjamin
 * @Date   29/05/2018
 * @version 1.0
 * @section A program that uses classes to construct a car class,
 * accelerate the car, brake the car, and output the speed of the car
 */
// I declare that this assignment is my own work and that I have correctly
// acknowledged the work of others.  I acknowledged that I have read and
// following the Academic Honesty and Integrity related policies as
// outlined in the syllabus.
//
// _____ Benjamin Martin ____      _____May 29 2018______________
//
// ____ 301347720______

#include <iostream>
#include <string>
using namespace std;

class Car
{
public:
  //Car constructor. P is for passed variable names.
  Car(int yearModelP, string makeP);

  //accessor functions
  int getYearModel();
  string getMake();
  int getSpeed();

  //mutator functions
  void accelerate();//adds 5 to the speed
  void brake();//subtracts 5 from the speed

private:
  //member functions
  int yearModel; //year the car was made
  string make; //make of the car
  int speed; //speed the car is traveling at
};

int main()
{
  //declare variables
  int i = 0; //counter
  //create my car
  Car mycar(1988, "Momma Martin");
  //accelerate  my car 5 times and print the speed
  for (i=0;i<5;i++)
  {
    mycar.accelerate();
    cout << "The current speed of the car is " << mycar.getSpeed() << endl;
  }
  //brake my car 5 times and print the speed
  for (i=0;i<5;i++)
  {
    mycar.brake();
    cout << "The current speed of the car is " << mycar.getSpeed() << endl;
  }
  return 0;
}

//constructor function for car
Car::Car(int yearModelP, string makeP)
{
  yearModel = yearModelP;
  make = makeP;
  speed = 0;
}

//accessor functions for Car
int Car::getYearModel()
{
  return yearModel;
}
string Car::getMake()
{
  return make;
}
int Car::getSpeed()
{
  return speed;
}

//mutator functions
void Car::accelerate()
{
  speed = speed + 5;
}

void Car::brake()
{
  if (speed > 5)
  {
    speed = speed - 5;
  }
  else
  {
    speed = 0;
  }
}
