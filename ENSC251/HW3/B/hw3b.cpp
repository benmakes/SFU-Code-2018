/**
 * @file lab3b.cpp
 * @author Martin Benjamin
 * @Date   3/07/2018
 * @version 1.0
 */
// I declare that this assignment is my own work and that I have correctly
// acknowledged the work of others.  I acknowledged that I have read and
// following the Academic Honesty and Integrity related policies as
// outlined in the syllabus.
//
// _____ Benjamin Martin ____      _____July 3 2018______________
//
// ____ 301347720______

//HW3a A program that uses a class to hold a stack of chars of max size 5.
//It throws errors for stack overflow and stack empty
//credit to textbook for stack class example

#include <iostream>
#include <cstddef>
using namespace std;

//interface
class Stack
{
public:
  Stack(int size);
  //creates the array to the max size given
  Stack(const Stack& theObject);
  //copy constructor
  ~Stack();
  //destructor
  void push(char newC);
  //adds a character to the end of the stack if the stack is not full
  char pop();
  //returns the last char if the stack is not empty
private:
  int size;//max size of stack
  int used;//current amount of chars in the stack
  char* charStack;//point to a dynamic array that holds the stack
};
class StackOverflowException
{
public:
  StackOverflowException();
};
class StackEmptyException
{
public:
  StackEmptyException();
};

int main()
{
  //test driver program
  //declare variables
  int stackSize = 0;
  int finished = 0;
  char input = '\0';
  //make a stack
  cout << "Please enter the size of stack you wish to use in positive int form" << endl;
  cin >> stackSize;
  while (cin.fail() || stackSize <= 0)
  {
    cin.clear();
    cin.ignore(256,'\n');
    cout << "Error. Please enter a size of stack > 0. For example 3" << endl;
    cin >> stackSize;
  }
  Stack myStack(stackSize);

  //allow user to choose what to do with stack
  while(finished >= 0)
  {
    cout << "Enter 1 to push a char to the stack. Enter 2 to pop a char. Enter "
      << "a negative int to exit." << endl;
    cin >> finished;
    if (cin.fail())
    {
      cerr << "That is not the proper input format." << endl;
      cin.clear();
      cin.ignore(256,'\n');
      finished = 0;
    }
    if (finished == 1)
    {
      //add something to the stack
      cout << "Please enter a character to add to the stack" << endl;
      cin >> input;
      cin.clear();
      cin.ignore(256,'\n');
      myStack.push(input);
    }
    else if(finished == 2)
    {
      //remove something from the stack
      cout << myStack.pop() << endl << endl;
    }
  }
  return 0;
}

//implementation
//constructor
Stack::Stack(int maxSize)
{
  size = maxSize;
  used = 0;
  charStack = new char[size+1];
}
Stack::Stack(const Stack& theObject)
{
  int i = 0;
  size = theObject.size;
  used = theObject.used;
  charStack = new char(size+1);
  for (i = 0; i < size; i++ )
  {
    charStack[i] = theObject.charStack[i];
  }
}
//destructor
Stack::~Stack()
{
  delete [] charStack;
}
void Stack::push(char newC)
{
  try
  {
    if (used < size)
    {
      used++;
      charStack[used] = newC;
      cout << endl;
    }
    else
    {
      throw StackOverflowException();
    }
  }
  catch(StackOverflowException)
  {
    cerr << "You cannot add something to a full stack" << endl;
    cout << endl;
  }
}
char Stack::pop()
{
  try
  {
    if (used > 0)
    {
      char temp = '\0';
      temp = charStack[used];
      charStack[used] = '\0';
      used--;
      return temp;
    }
    else
    {
      throw StackEmptyException();
    }
  }
  catch(StackEmptyException)
  {
    cerr << "You cannot pop an empty stack" << endl;
    return ' ';
  }
}
StackEmptyException::StackEmptyException()
{
  //left intentionally blank
}
StackOverflowException::StackOverflowException()
{
  //left intentionally blank
}
