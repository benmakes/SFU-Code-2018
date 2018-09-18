/**
 * @file lab3a.cpp
 * @author Martin Benjamin
 * @Date   29/05/2018
 * @version 1.0
 * @section A program that uses classes to construct a patient class,
 * 3 procedure classes then displays the data to the user.
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
#include <iomanip>
using namespace std;

class Patient
{
public:
  //patient constructor. P is for passed in variable names.
  Patient(string firstNameP, string middleNameP, string lastNameP,
    string addressP, string cityP, string stateP, string zipCodeP,
    string phoneNumberP, string emergencyNameP, string emergencyPhoneP);

  //accessor functions
  string getFirstName();
  string getMiddleName();
  string getLastName();
  string getAddress();
  string getCity();
  string getState();
  string getZipCode();
  string getPhoneNumber();
  string getEmergencyName();
  string getEmergencyPhone();

  //mutator functions
  void setFirstName(string firstNameP);
  void setMiddleName(string middleNameP);
  void setLastName(string lastNameP);
  void setAddress(string addressP);
  void setCity(string cityP);
  void setState(string stateP);
  void setZipCode(string zipCodeP);
  void setPhoneNumber(string phoneNumberP);
  void setEmergencyName(string emergencyNameP);
  void setEmergencyPhone(string emergencyPhoneP);

  //output functions
  void output(ostream& outs);

private:
  //member variables
  string firstName;
  string middleName;
  string lastName;
  string address;
  string city;
  string state;
  string zipCode;
  string phoneNumber;
  string emergencyName;
  string emergencyPhone;
};

class Procedure
{
public:
  //Procedure constructor
  Procedure(string procedureNameP, string procedureDateP,
     string practitionerNameP, float ProcedureChargesP);

  //accessor function
  string getProcedureName();
  string getProcedureDate();
  string getPractitionerName();
  float getProcedureCharges();

  //mutator functions
  void setProcedureName(string procedureNameP);
  void setProcedureDate(string procedureDateP);
  void setPractitionerName(string practitionerNameP);
  void setProcedureCharges(float procedureChargesP);

  //output function
  void output(ostream& outs);

private:
  //member variables
  string procedureName;
  string procedureDate;
  string practitionerName;
  float procedureCharges;
};

int main()
{
  //declare variables
  float totalCost = 0.0;

  //create patient1 variable of class Patient
  Patient patient1("Ben", "P", "Martin", "111ave", "Vancouver", "BC",
   "v1v1v1", "6045555555", "Kirin", "6044444444");

  //create 3 procedureCharges
  Procedure procedure1("Physical exam", "Aug 29th 2018", "Dr. Irvine", 250.00);
  Procedure procedure2("X-ray", "Aug 29th 2018", "Dr. Jamison", 500.00);
  Procedure procedure3("Blood test", "Aug 29th 2018", "Dr. Smith", 200.00);

  //display the patitent data and all 3 of the procedure data
  patient1.output(cout);
  procedure1.output(cout);
  procedure2.output(cout);
  procedure3.output(cout);

  //calculate total cost of 3 procedures
  totalCost = procedure1.getProcedureCharges() + procedure2.getProcedureCharges() +
   procedure3.getProcedureCharges();

  cout << fixed << setprecision(2) << showpoint <<
    "The total cost of all three procedures is $" << totalCost << endl;

  return 0;
}

//Contstructor for patients
Patient::Patient(string firstNameP, string middleNameP, string lastNameP,
  string addressP, string cityP, string stateP, string zipCodeP,
  string phoneNumberP, string emergencyNameP, string emergencyPhoneP)
{
  firstName = firstNameP;
  middleName = middleNameP;
  lastName = lastNameP;
  address = addressP;
  city = cityP;
  state = stateP;
  zipCode = zipCodeP;
  phoneNumber = phoneNumberP;
  emergencyName = emergencyNameP;
  emergencyPhone = emergencyPhoneP;
}

//Patient accessor functions
string Patient::getFirstName()
{
    return firstName;
}
string Patient::getMiddleName()
{
    return middleName;
}
string Patient::getLastName()
{
    return lastName;
}
string Patient::getAddress()
{
    return address;
}
string Patient::getCity()
{
    return city;
}
string Patient::getState()
{
    return state;
}
string Patient::getZipCode()
{
    return zipCode;
}
string Patient::getPhoneNumber()
{
    return phoneNumber;
}
string Patient::getEmergencyName()
{
    return emergencyName;
}
string Patient::getEmergencyPhone()
{
    return emergencyPhone;
}

//Patient mutator functions
void Patient::setFirstName(string firstNameP)
{
  firstName = firstNameP;
}
void Patient::setMiddleName(string middleNameP)
{
  middleName = middleNameP;
}
void Patient::setLastName(string lastNameP)
{
  lastName = lastNameP;
}
void Patient::setAddress(string addressP)
{
  address = addressP;
}
void Patient::setCity(string cityP)
{
  city = cityP;
}
void Patient::setState(string stateP)
{
  state = stateP;
}
void Patient::setZipCode(string zipCodeP)
{
  zipCode = zipCodeP;
}
void Patient::setPhoneNumber(string phoneNumberP)
{
  phoneNumber = phoneNumberP;
}
void Patient::setEmergencyName(string emergencyNameP)
{
  emergencyName = emergencyNameP;
}
void Patient::setEmergencyPhone(string emergencyPhoneP)
{
  emergencyPhone = emergencyPhoneP;
}

void Patient::output(ostream& outs)
{
  //display patient data
  outs << "Full Name: " << firstName << " " << middleName << " " <<
    lastName << endl;
  outs << "Address: " << address << ", " << city << ", " << ", " <<
    state << ", " << zipCode << endl;
  outs << "Phone Number: " << phoneNumber << endl;
  outs << "Emergency Contact info: " << emergencyName << " " <<
    emergencyPhone << endl << endl;
}

//Procedure Constructor
Procedure::Procedure(string procedureNameP, string procedureDateP,
   string practitionerNameP, float procedureChargesP)
{
  procedureName = procedureNameP;
  procedureDate = procedureDateP;
  practitionerName = practitionerNameP;
  procedureCharges = procedureChargesP;
}

//Procedure accessor functions
string Procedure::getProcedureName()
{
  return procedureName;
}
string Procedure::getProcedureDate()
{
  return procedureDate;
}
string Procedure::getPractitionerName()
{
  return practitionerName;
}
float Procedure::getProcedureCharges()
{
  return procedureCharges;
}

//Procedure mutator functions
void Procedure::setProcedureName(string procedureNameP)
{
  procedureName = procedureNameP;
}
void Procedure::setProcedureDate(string procedureDateP)
{
  procedureDate = procedureDateP;
}
void Procedure::setPractitionerName(string practitionerNameP)
{
  practitionerName = practitionerNameP;
}
void Procedure::setProcedureCharges(float procedureChargesP)
{
  procedureCharges = procedureChargesP;
}

//Procedure output function
void Procedure::output(ostream& outs)
{
  //display procedure data
  outs.setf(ios::fixed);
  outs.setf(ios::showpoint);
  outs.precision(2);
  outs << "Procedure Name: " << procedureName << endl;
  outs << "Procedure Date: " << procedureDate << endl;
  outs << "Practitioner's Name: " << practitionerName << endl;
  outs << "ProcedureCharges $" << procedureCharges << endl << endl;
}
