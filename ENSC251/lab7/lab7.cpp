/**
 * @file lab7.cpp
 * @author Martin Benjamin
 * @Date   9/07/2018
 * @version 1.0
 * @section A program to change 24 hour time to am pm that throws errors
 * if the input is invalid.
 */
// I declare that this assignment is my own work and that I have correctly
// acknowledged the work of others.  I acknowledged that I have read and
// following the Academic Honesty and Integrity related policies as
// outlined in the syllabus.
//
// _____ Benjamin Martin ____      _____July 9 2018______________
//
// ____ 301347720______

//HW3a A program that

#include <iostream>
#include <string>
#include <cstddef>
#include <vector>
#include <algorithm>
using namespace std;

class Book
{
public:
  Book(string nextTitle, string nextAuthor, string nextDate);
  string getAuthor();
  string getDate();
  string getTitle();
  friend bool operator <(const Book& book1, const Book& book2);
  friend ostream& operator <<(ostream& outs, Book& the_book);
private:
  string author;
  string date;
  string title;
};

int main()
{
//declare variables
string nextAuthor = "";
string nextTitle = "";
string nextDate = "";
string nextName = "";
int choice = 0;
Book *nextEntry = NULL;
int i = 0;
vector<Book> bookDB;
vector<Book>::iterator p;

//request option
while(choice != 3)
{
  while (choice != 1 && choice != 2 && choice != 3)
  {
    cout << "Select from the following choices:" << endl << "1. Add new book" <<
      endl << "2. Print listing sorted by author" << endl << "3. Quit" << endl;
    cin >> choice;
    cin.clear();
    cin.ignore(256,'\n');
  }
  if (choice == 1)
  {
  //make a new book
  cout << "Enter author" << endl;
  getline(cin,nextAuthor);
  cout << "Enter title" << endl;
  getline(cin,nextTitle);
  cout << "Enter date" << endl;
  getline(cin,nextDate);
  cout << endl;
  //need unique name make it dynamic?
  nextEntry = new Book(nextTitle, nextAuthor, nextDate);
  bookDB.push_back(*nextEntry);
  delete nextEntry;
  choice = 0;
  }
  //print listing sorted by author
  if (choice == 2)
  {
    sort(bookDB.begin(),bookDB.end());
    cout << "The books entered so far, sorted alphabetically by author are:" << endl;

    for (p = bookDB.begin(); p != bookDB.end(); ++p)
    {
      cout << *p;
    }
    cout << endl;
    choice = 0;
  }
}
return 0;
}

//class functions
Book::Book(string nextTitle, string nextAuthor, string nextDate)
{
  author = nextAuthor;
  title = nextTitle;
  date = nextDate;
}
string Book::getAuthor()
{
  return author;
}
string Book::getDate()
{
  return date;
}
string Book::getTitle()
{
  return title;
}
ostream& operator <<(ostream& outs, Book& the_book)
{
  outs << "\t" << the_book.author << ". " << the_book.title << ". " << the_book.date
    << "." << endl;
  return outs;
}
bool operator <(const Book& book1, const Book& book2)
{
 return (book1.author < book2.author);
}
