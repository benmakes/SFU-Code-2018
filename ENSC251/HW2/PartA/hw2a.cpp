/**
 * @file hw2a.cpp
 * @author Martin Benjamin
 * @Date   12/06/2018
 * @version 1.0
 * @section A program that displays a histogram of a classes grades
 *
 */
// I declare that this assignment is my own work and that I have correctly
// acknowledged the work of others.  I acknowledged that I have read and
// following the Academic Honesty and Integrity related policies as
// outlined in the syllabus.
//
// _____ Benjamin Martin ____      _____June 12 2018______________
//
// ____ 301347720______


#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
using namespace std;

typedef int* intArrayPtr;

int main()
{
  //declare variables
  vector<int> v;
  vector<int> vRepeatIndex;
  vector<int> vNoRepeats;
  int next = 0;//user input
  int i = 0;//counter
  int j = 0;//counter
  int valuesCount = 0;
  intArrayPtr* histogram = NULL;

  //prompt for input until input is -1. Do not allow other negative numbers
  cout << "Enter a list of positive numbers.\n"
  << "Place -1 at the end.\n";
  cin >> next;
  while (cin.fail() || next < -1)
  {
    cin.clear();
    cin.ignore(1000,'\n');
    cerr << "that input was not valid. Please enter a positive int such as 1" << endl;
    cin >> next;
  }

  while (next != -1)
  {
    v.push_back(next);
    cin.clear();
    cin.ignore(1000,'\n');
    cin >> next;
    while (cin.fail() || next < -1)
    {
      cin.clear();
      cin.ignore(1000,'\n');
      cerr << "that input was not valid. Please enter a positive int such as 1" << endl;
      cin >> next;
    }
  }

  //sort the vector of inputs
  sort(v.begin(),v.end());

  //record the repeats
  for (i = 1; i < static_cast<int>(v.size()) ; i++)
  {
    if (v[i] == v[i-1])
    {
      vRepeatIndex.push_back(i);
    }
  }

  //create a no repeat vector by removing the elements at the repeated index
  vNoRepeats = v;

  if (vNoRepeats.size() != 0)
  {
    for (i = vRepeatIndex.size()-1; i > -1; i--)
    {
      vNoRepeats.erase(vNoRepeats.begin() + vRepeatIndex[i]);
    }
  }

  //assign the number of histogram values to a variable
  valuesCount = vNoRepeats.size();

  //make an array for values and an array for counts
  int values[valuesCount];
  int counts[valuesCount];

  for (i = 0; i < valuesCount; i++)
  {
    values[i] = 0;
    counts[i] = 0;
  }

  for (i = 0; i < static_cast<int>(vNoRepeats.size()); i++)
  {
    values[i] = vNoRepeats[i];
  }

  //add the sums
  for (i = 0; i < valuesCount; i++)
  {
    for (j = 0; static_cast<int>(j<v.size()); j++)
    {
      if (values[i] == v[j])
      {
        counts[i]++;
      }
    }
  }

  //create a dynamic array to hold the histogram
  histogram = new intArrayPtr[valuesCount];
  for (i=0; i<valuesCount;i++)
  {
    histogram[i] = new int[2];
    histogram[i][0] = values[i];
    histogram[i][1] = counts[i];
  }

  for (i=0; i<valuesCount;i++)
  {
    cout << "Number of " << histogram[i][0] <<"'s: " << histogram[i][1] << endl;
  }
  //clean up the histogram dynamic variable
  for (i=0; i<valuesCount; i++)
  {
   delete [] histogram[i];
  }
  delete [] histogram;

  return 0;
}
