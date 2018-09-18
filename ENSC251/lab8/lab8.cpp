/**
 * @file lab8.cpp
 * @author Martin Benjamin
 * @Date   17/07/2018
 * @version 1.0
 * @section A program to read stock prices and return some statistics
 */
// I declare that this assignment is my own work and that I have correctly
// acknowledged the work of others.  I acknowledged that I have read and
// following the Academic Honesty and Integrity related policies as
// outlined in the syllabus.
//
// _____ Benjamin Martin ____      _____July 17 2018______________
//
// ____ 301347720______

//Lab8 A program that reads stock prices and returns some statistics
//from StockPrices.csv

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <map>
#include <set>
#include <functional>
#include <algorithm>
#include <cstdlib>
using namespace std;

//declare functions
double avgPriceThatYear(string thatYear,map<string,double> date_map, map<string,double>::const_iterator p);
double highPriceThatYear(string thatYear,map<string,double> date_map, map<string,double>::const_iterator p);
double lowPriceThatYear(string thatYear,map<string,double> date_map, map<string,double>::const_iterator p);
double avgPriceThatMonth(string thatMonth,map<string,double> date_map, map<string,double>::const_iterator p);


int main()
{
  //declare variables
  string nextYear = "";
  string nextMonth = "";
  string nextDay = "";
  string nextDate = "";
  double nextPrice = 0.0;
  string garbage = "";//for removing unwanted data
  ifstream ins;
  ofstream outs;

  // Declaring a function type that returns a bool for ordering in a set
  typedef function <bool (pair<string, double>, pair<string, double>)> Orderer;
  // Define the function to sort the pairs by price
  Orderer compFunctor = [](pair<string, double> element1, pair<string, double> element2)
  {
      return element1.second <= element2.second;
  };

  //make maps sorted by date, 1 set sorted by price
  map<string,double> date_map;
  //make necessary iterators
  map<string,double>::const_iterator p;
  set<pair<string,double>>::const_iterator p2;
  set<pair<string,double>>::const_reverse_iterator p2r;

  //open StockPrices.csv
  ins.open("StockPrices.csv");
  if (ins.fail())
  {
    cout << "Input file opening failed.\n";
    exit(1);
  }
  //Read in the data of StockPrices.csv to a map
  //Throw away the first line
  getline(ins,garbage, '\n');
  while(!ins.eof())
  {
    //Get the date
    getline(ins, nextMonth, '/');
    getline(ins, nextDay, '/');
    getline(ins, nextYear, ',');
    //make day and month two digits
    if (nextDay.length()==1)
    {
      nextDay = "0" + nextDay;
    }
    if (nextMonth.length()==1)
    {
      nextMonth = "0" + nextMonth;
    }
    nextDate = nextYear + nextMonth + nextDay;
    //throw away the opening price
    getline(ins,garbage, ',');
    //read in the high price
    ins >> nextPrice;
    //add the element to date_map with the date as the first,
    // and the high as second
    date_map[nextDate] = nextPrice;
    //throw away the rest of the line
    getline(ins,garbage,'\n');
  }
  ins.close();

  //call out the average price each year and month, and low of the year, and high of the year
  cout << "The Average Price in 2008 was " << setprecision(9) << avgPriceThatYear("2008",date_map,p) << endl;
  cout << "The Average Price in 2009 was " << avgPriceThatYear("2009",date_map,p) << endl;
  cout << "The Average Price in 2010 was " << avgPriceThatYear("2010",date_map,p) << endl;
  cout << "The Average Price in 2011 was " << avgPriceThatYear("2011",date_map,p) << endl;
  cout << "The Average Price in 2012 was " << avgPriceThatYear("2012",date_map,p) << endl;
  cout << "The Average Price in 2013 was " << avgPriceThatYear("2013",date_map,p) << endl;
  cout << "The Average Price in 2014 was " << avgPriceThatYear("2014",date_map,p) << endl;
  cout << "The Average Price in 2015 was " << avgPriceThatYear("2015",date_map,p) << endl;
  cout << "The Average Price in 2016 was " << avgPriceThatYear("2016",date_map,p) << endl;
  cout << "The Average Price in 2017 was " << avgPriceThatYear("2017",date_map,p) << endl;
  cout << "The Average Price in 2018 was " << avgPriceThatYear("2018",date_map,p) << endl;
  cout << endl;
  cout << "The Average Price in January is " << avgPriceThatMonth("01",date_map,p) << endl;
  cout << "The Average Price in February is " << avgPriceThatMonth("02",date_map,p) << endl;
  cout << "The Average Price in March is " << avgPriceThatMonth("03",date_map,p) << endl;
  cout << "The Average Price in April is " << avgPriceThatMonth("04",date_map,p) << endl;
  cout << "The Average Price in May is " << avgPriceThatMonth("05",date_map,p) << endl;
  cout << "The Average Price in June is " << avgPriceThatMonth("06",date_map,p) << endl;
  cout << "The Average Price in July is " << avgPriceThatMonth("07",date_map,p) << endl;
  cout << "The Average Price in August is " << avgPriceThatMonth("08",date_map,p) << endl;
  cout << "The Average Price in September is " << avgPriceThatMonth("09",date_map,p) << endl;
  cout << "The Average Price in October is " << avgPriceThatMonth("10",date_map,p) << endl;
  cout << "The Average Price in November is " << avgPriceThatMonth("11",date_map,p) << endl;
  cout << "The Average Price in December is " << avgPriceThatMonth("12",date_map,p) << endl;
  cout << endl;
  cout << "The Low Price in 2008 was " << lowPriceThatYear("2008",date_map,p) << endl;
  cout << "The Low Price in 2009 was " << lowPriceThatYear("2009",date_map,p) << endl;
  cout << "The Low Price in 2010 was " << lowPriceThatYear("2010",date_map,p) << endl;
  cout << "The Low Price in 2011 was " << lowPriceThatYear("2011",date_map,p) << endl;
  cout << "The Low Price in 2012 was " << lowPriceThatYear("2012",date_map,p) << endl;
  cout << "The Low Price in 2013 was " << lowPriceThatYear("2013",date_map,p) << endl;
  cout << "The Low Price in 2014 was " << lowPriceThatYear("2014",date_map,p) << endl;
  cout << "The Low Price in 2015 was " << lowPriceThatYear("2015",date_map,p) << endl;
  cout << "The Low Price in 2016 was " << lowPriceThatYear("2016",date_map,p) << endl;
  cout << "The Low Price in 2017 was " << lowPriceThatYear("2017",date_map,p) << endl;
  cout << "The Low Price in 2018 was " << lowPriceThatYear("2018",date_map,p) << endl;
  cout << endl;
  cout << "The High Price in 2008 was " << highPriceThatYear("2008",date_map,p) << endl;
  cout << "The High Price in 2009 was " << highPriceThatYear("2009",date_map,p) << endl;
  cout << "The High Price in 2010 was " << highPriceThatYear("2010",date_map,p) << endl;
  cout << "The High Price in 2011 was " << highPriceThatYear("2011",date_map,p) << endl;
  cout << "The High Price in 2012 was " << highPriceThatYear("2012",date_map,p) << endl;
  cout << "The High Price in 2013 was " << highPriceThatYear("2013",date_map,p) << endl;
  cout << "The High Price in 2014 was " << highPriceThatYear("2014",date_map,p) << endl;
  cout << "The High Price in 2015 was " << highPriceThatYear("2015",date_map,p) << endl;
  cout << "The High Price in 2016 was " << highPriceThatYear("2016",date_map,p) << endl;
  cout << "The High Price in 2017 was " << highPriceThatYear("2017",date_map,p) << endl;
  cout << "The High Price in 2018 was " << highPriceThatYear("2018",date_map,p) << endl;
  cout << endl;

  // make a set that will store the data of the map in pairs sorted by price low to high
  set<pair<string, double>, Orderer> price_set(date_map.begin(), date_map.end(), compFunctor);

  //print out to a new file the highs sorts from lowest to highest and highest to lowest
  outs.open("lowestToHighest");
  if (outs.fail( ))
  {
      cout << "Output file opening failed.\n";
      exit(1);
  }
  outs << "date(YYYYMMDD),price" << endl;
  // Iterate over the set and print out the values seperate by a comma

  for (p2 = price_set.begin(); p2 != price_set.end(); ++p2)
  {
    outs << setprecision(9) << p2->first << "," << p2->second << endl;
  }
  outs.close();
  //print to text from highest to lowest
  outs.open("highestToLowest");
  if (outs.fail( ))
  {
      cout << "Output file opening failed.\n";
      exit(1);
  }

  outs << "date(YYYYMMDD),price" << endl;
  // Iterate over the set and print out the values seperate by a comma

  for (p2r = price_set.rbegin(); p2r != price_set.rend(); p2r++)
  {
    outs << setprecision(9) << p2r->first << "," << p2r->second << endl;
  }

  outs.close();

  return 0;
}

double avgPriceThatYear(string thatYear,map<string,double> date_map, map<string,double>::const_iterator p)
{
  int count = 0;
  double yearSum = 0.0;
  double yearAvg = 0.0;
  for (p = date_map.begin(); p != date_map.end(); p++)
  {
    if (p->first[0]==thatYear[0] && p->first[1]==thatYear[1] && p->first[2]==thatYear[2] && p->first[3]==thatYear[3])
    {
      count++;
      yearSum = yearSum + p->second;
    }
  }
  yearAvg = yearSum/count;
  return yearAvg;
}
double highPriceThatYear(string thatYear,map<string,double> date_map, map<string,double>::const_iterator p)
{
  double high = 0.0;
  for (p = date_map.begin(); p != date_map.end(); p++)
  {
    if (p->first[0]==thatYear[0] && p->first[1]==thatYear[1] && p->first[2]==thatYear[2] && p->first[3]==thatYear[3])
    {
      if (p->second > high)
      {
        high = p->second;
      }
    }
  }
  return high;
}
double lowPriceThatYear(string thatYear,map<string,double> date_map, map<string,double>::const_iterator p)
{
  double low = 1000000.0;
  for (p = date_map.begin(); p != date_map.end(); p++)
  {
    if (p->first[0]==thatYear[0] && p->first[1]==thatYear[1] && p->first[2]==thatYear[2] && p->first[3]==thatYear[3])
    {
      if (p->second < low)
      {
        low = p->second;
      }
    }
  }
  return low;
}
double avgPriceThatMonth(string thatMonth,map<string,double> date_map, map<string,double>::const_iterator p)
{
  int count = 0;
  double monthSum = 0.0;
  double monthAvg = 0.0;
  for (p = date_map.begin(); p != date_map.end(); p++)
  {
    if (p->first[4]==thatMonth[0] && p->first[5]==thatMonth[1])
    {
      count++;
      monthSum = monthSum + p->second;
    }
  }
  monthAvg = monthSum/count;
  return monthAvg;
}
