/**
 * @file lab2b.cpp
 * @author Martin Benjamin
 * @Date   2/07/2018
 * @version 1.0
 * @section A program to change 24 hour time to am pm that throws errors
 * if the input is invalid.
 */
// I declare that this assignment is my own work and that I have correctly
// acknowledged the work of others.  I acknowledged that I have read and
// following the Academic Honesty and Integrity related policies as
// outlined in the syllabus.
//
// _____ Benjamin Martin ____      _____July 2 2018______________
//
// ____ 301347720______

//HW3a A program that makes derived class Truck from base class Vehicle

#include <iostream>
#include <string>
using namespace std;

class Person
{
public:
 Person();
 Person(string theName);
 Person(const Person& theObject);
 string getName() const;
 Person& operator = (const Person& rtSide);
 friend istream& operator >>(istream& inStream,
 Person& personObject);
 friend ostream& operator <<(ostream& outStream,
 const Person& personObject);
private:
 string name;
};


class Vehicle
{
public:
  //constructors
  Vehicle();
  Vehicle(string makeName);
  Vehicle(string makeName, int cylinderNum);
  Vehicle(string makeName, int cylinderNum, Person ownerName);
  Vehicle(const Vehicle& theObject);
  //accessors
  string getMake() const;
  int getCylinders() const;
  string getOwner() const;
  //mutators
  void setMake(string newMake);
  void setCylinders(int newCyl);
  void setOwner(Person newOwner); //requires the Person newOwner to exist
  //overloaded = operator
  Vehicle& operator = (const Vehicle& rtSide);

protected:
  string make;
  int cylinders;
  Person owner;
};


class Truck : public Vehicle
{
public:
  //constructors
  Truck();
  Truck(string makeName);
  Truck(string makeName, int cylinderNum);
  Truck(string makeName, int cylinderNum, Person ownerName);
  Truck(string makeName, int cylinderNum, Person ownerName, double loadVal);
  Truck(string makeName, int cylinderNum, Person ownerName, double loadVal,
    int tow);
  Truck(const Truck& theObject);
  //accessors
  double getLoad() const;
  int getTowing() const;
  //mutators
  void setLoad(double newLoad);
  void setTowing(int newTowing);
  //overloaded = operator
  Truck& operator = (const Truck& rtSide);

private:
  double load;
  int towing;
};


int main()
{
  //declare variables
  string name1 = "";
  string name2 = "";
  string v1Name = "";
  int v2Cyl = 0;
  string name3 = "";
  double loadD = 0.0;
  int towI = 0;
  //test driver program
  cout << "Welcome to the test driver program of every member function!" << endl;
  cout << "Please input in the form requested" << endl;
  cout << "Enter name 1 as a string" << endl;
  cin >> name1;
  cout << endl << "Making person1 Person object" << endl;
  Person person1(name1);
  cout << "Creating a wannabe Person object with no arguement" << endl;
  Person wannabe;
  cout << "Using cout << wannabe: " << endl << wannabe << endl;
  cout << "Using cin >> wannabe. Enter any name you like as a string" << endl;
  cin >> wannabe;
  cout << endl << "Using cout << wannabe.getName() " << endl;
  cout << wannabe.getName() << endl;
  cout << "wannabe really wants to be person1. Using wannabe = person1" << endl;
  wannabe = person1;
  cout << "Using cout << wannabe: " << endl << wannabe << endl << endl << endl;


  //Making vehicles
  cout << "Making vehicle V0 without any info" << endl;
  Vehicle V0;
  cout << "Please enter a manufacturer name as a string" << endl;
  cin >> v1Name;
  Vehicle V1(v1Name);
  cout << "Please enter an integer for number of cylinders for V2" << endl;
  cin >> v2Cyl;
  Vehicle V2(v1Name,v2Cyl);
  cout << "Who wants to own V3? Please enter a name as a string" << endl;
  cin >> name3;
  Person v3owner;
  v3owner = name3;
  Vehicle V3(v1Name,v2Cyl,v3owner);
  cout << "Outputing the 4 vehicles info using accessors" << endl;
  cout << "V: manufacturer - cylinders - owner" << endl;
  cout << "V0: " << V0.getMake() << " - " << V0.getCylinders() << " - " <<  V0.getOwner() <<endl;
  cout << "V1: " << V1.getMake() << " - " << V1.getCylinders() << " - " << V1.getOwner() << endl;
  cout << "V2: " << V2.getMake() << " - " << V2.getCylinders() << " - " << V2.getOwner() << endl;
  cout << "V3: " << V3.getMake() << " - " << V3.getCylinders() << " - " << V3.getOwner() << endl;
  cout << endl << "Please input a new make to set for v0 as a string" << endl;
  cin >> v1Name;
  V0.setMake(v1Name);
  cout << "Please set a new number of cylinders for v1 in int format" << endl;
  cin >> v2Cyl;
  V1.setCylinders(v2Cyl);
  cout << "Please enter a new owner for v2 as a string" << endl;
  cin >> name3;
  Person v2owner(name3);
  V2.setOwner(v2owner);
  cout << "V: manufacturer - cylinders - owner" << endl;
  cout << "V0: " << V0.getMake() << " - " << V0.getCylinders() << " - " <<  V0.getOwner() <<endl;
  cout << "V1: " << V1.getMake() << " - " << V1.getCylinders() << " - " << V1.getOwner() << endl;
  cout << "V2: " << V2.getMake() << " - " << V2.getCylinders() << " - " << V2.getOwner() << endl;
  cout << "V3: " << V3.getMake() << " - " << V3.getCylinders() << " - " << V3.getOwner() << endl;
  cout << "Now assigning V3 = V0" << endl;
  V3 = V0;
  cout << "V3: " << V3.getMake() << " - " << V3.getCylinders() << " - " << V3.getOwner() << endl;
  cout << endl << "Please enter a new make as a string for V3. It won't change V0" << endl;
  cin >> v1Name;
  V3.setMake(v1Name);
  cout << "V0: " << V0.getMake() << " - " << V0.getCylinders() << " - " <<  V0.getOwner() <<endl;
  cout << "V3: " << V3.getMake() << " - " << V3.getCylinders() << " - " << V3.getOwner() << endl;
  cout << endl << endl;

  //Making trucks
  cout << "Making trucks now. Make? Inputted as a string" << endl;
  cin >> v1Name;
  cout << "Cylinders in int format?" << endl;
  cin >> v2Cyl;
  cout << "Owner as a string?" << endl;
  cin >> name3;
  Person truckOwner(name3);
  cout << "Making a truck without load or tow" << endl;
  Truck T0(v1Name, v2Cyl, truckOwner);
  cout << "Truck 0: " << T0.getMake() << " - " << T0.getCylinders() << " - "
    << T0.getOwner() << " - " << T0.getLoad() << " - " << T0.getTowing() << endl;
  cout << endl << "Choose a load double" << endl;
  cin >> loadD;
  cout << "Making a truck with load" << endl;
  Truck T1(v1Name, v2Cyl, truckOwner, loadD);
  cout << "Truck 1: " << T1.getMake() << " - " << T1.getCylinders() << " - "
    << T1.getOwner() << " - " << T1.getLoad() << " - " << T1.getTowing() << endl;
  cout << endl << "Choose a tow int" << endl;
  cin >> towI;
  cout << "Making a truck with load and tow" << endl;
  Truck T2(v1Name, v2Cyl, truckOwner, loadD, towI);
  cout << "Truck 2: " << T2.getMake() << " - " << T2.getCylinders() << " - "
    << T2.getOwner() << " - " << T2.getLoad() << " - " << T2.getTowing() << endl;
  cout << endl << "Let us change truck 0s load and tow. Please enter a Load in double"
    << " format?" << endl;
  cin >> loadD;
  cout << "Please enter a Tow in int format?" << endl;
  cin >> towI;
  T0.setLoad(loadD);
  T0.setTowing(towI);
  cout << "Truck 0: " << T0.getMake() << " - " << T0.getCylinders() << " - "
    << T0.getOwner() << " - " << T0.getLoad() << " - " << T0.getTowing() << endl;
  cout << "Let us set Truck 1 = Truck 0" << endl;
  T1 = T0;
  cout << "Truck 1: " << T1.getMake() << " - " << T1.getCylinders() << " - "
    << T1.getOwner() << " - " << T1.getLoad() << " - " << T1.getTowing() << endl;
  cout << endl << "Please enter a load for Truck 1 in double format. It won't change T0"
    << endl;
  cin >> loadD;
  T1.setLoad(loadD);
  cout << "Truck 0: " << T0.getMake() << " - " << T0.getCylinders() << " - "
    << T0.getOwner() << " - " << T0.getLoad() << " - " << T0.getTowing() << endl;
  cout << "Truck 1: " << T1.getMake() << " - " << T1.getCylinders() << " - "
    << T1.getOwner() << " - " << T1.getLoad() << " - " << T1.getTowing() << endl;

  cout << endl << "Thank you for sticking through this!! You win the truck of your choice!"
    << endl;
  return 0;
}

//Person class constructors
Person::Person()
{
  name = "Name not given";
}
Person::Person(string firstName)
{
  name = firstName;
}
//copy constructor
Person::Person(const Person& theObject)
{
  name = theObject.name;
}
//accessor function
string Person::getName() const
{
  return name;
}
//Person class overloaded operators
istream& operator >>(istream& inStream, Person& personObject)
{
  string nameInput;
  inStream >> nameInput;
  personObject.name = nameInput;
  return inStream;
}
ostream& operator <<(ostream& outStream, const Person& personObject)
{
  outStream << personObject.name;
  return outStream;
}

Person& Person::operator =(const Person &rtSide)
{
  name = rtSide.name;
  return *this;
}

//Vehicle class constructors
Vehicle::Vehicle()
{
  Person unspecifiedOwner;
  make = "Not specefied";
  cylinders = 0;
  owner = unspecifiedOwner;
}
Vehicle::Vehicle(string makeName)
{
  Person unspecifiedOwner;
  make = makeName;
  cylinders = 0;
  owner = unspecifiedOwner;
}
Vehicle::Vehicle(string makeName, int cylinderNum)
{
  Person unspecifiedOwner;
  make = makeName;
  cylinders = cylinderNum;
  owner = unspecifiedOwner;
}
Vehicle::Vehicle(string makeName, int cylinderNum, Person ownerName)
{
  make = makeName;
  cylinders = cylinderNum;
  owner = ownerName;
}
Vehicle::Vehicle(const Vehicle& theObject)
{
  make = theObject.make;
  cylinders = theObject.cylinders;
  owner = theObject.owner;
}

//Vehicle accessor functions
string Vehicle::getMake() const
{
  return make;
}
int Vehicle::getCylinders() const
{
  return cylinders;
}
string Vehicle::getOwner() const
{
  return owner.getName();
}
//Vehicle mutator functions
void Vehicle::setMake(string newMake)
{
  make = newMake;
}
void Vehicle::setCylinders(int newCyl)
{
  cylinders = newCyl;
}
void Vehicle::setOwner(Person newOwner)
{
  //check to see if owner exists already?
  owner = newOwner;
}
Vehicle& Vehicle::operator =(const Vehicle &rtSide)
{
  make = rtSide.make;
  cylinders = rtSide.cylinders;
  owner = rtSide.owner;
  return *this;
}

//Truck constructors
Truck::Truck() : Vehicle(), load(0.0), towing(0)
{
  //left intentionally blank
}
Truck::Truck(string makeName) : Vehicle(makeName), load(0.0), towing(0)
{
  //left intentionally blank
}
Truck::Truck(string makeName, int cylinderNum) : Vehicle(makeName, cylinderNum),
  load(0.0), towing(0)
{
  //left intentionally blank
}
Truck::Truck(string makeName, int cylinderNum, Person ownerName)
  : Vehicle(makeName, cylinderNum, ownerName), load(0.0), towing(0)
{
  //left intentionally blank
}
Truck::Truck(string makeName, int cylinderNum, Person ownerName, double loadVal)
  : Vehicle(makeName, cylinderNum, ownerName), load(loadVal), towing(0)
{
  //left intentionally blank
}
Truck::Truck(string makeName, int cylinderNum, Person ownerName, double loadVal,
  int tow) : Vehicle(makeName, cylinderNum, ownerName), load(loadVal), towing(tow)
{
  //left intentionally blank
}
Truck::Truck(const Truck& theObject)
{
  make = theObject.make;
  cylinders = theObject.cylinders;
  owner = theObject.owner;
  load = theObject.load;
  towing = theObject.towing;
}
//Truck accessors
double Truck::getLoad() const
{
  return load;
}
int Truck::getTowing() const
{
  return towing;
}

//Truck mutators
void Truck::setLoad(double newLoad)
{
  load = newLoad;
}
void Truck::setTowing(int newTowing)
{
  towing = newTowing;
}
Truck& Truck::operator = (const Truck& rtSide)
{
  make = rtSide.make;
  cylinders = rtSide.cylinders;
  owner = rtSide.owner;
  load = rtSide.load;
  towing = rtSide.towing;
  return *this;
}
