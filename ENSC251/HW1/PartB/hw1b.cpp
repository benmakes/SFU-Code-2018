/**
 * @file hw1b.cpp
 * @author Martin Benjamin
 * @Date   30/05/2018
 * @version 1.0
 * @section A program that uses classes to rate movies. It can report
 * the average rating of the movie. It can also add a rating to the movie.
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
#include <string>
#include <iomanip>
using namespace std;

//create movie class
class Movie
{
public:
  //movie Constructor. P is for passed variables
  Movie(string movieNameP, string mpaaRatingP);

  //accessor functions
  string getMovieName();
  string getMpaaRating();

  //mutator functions. P is for passed variables
  void setMovieName(string movieNameP);
  void setMpaaRating(string mpaaRatingP);

  //function for adding a rating to a movie between 1-5. 1 = terrible.
  //2 = bad. 3 = OK. 4 = good. 5 = great.
  void addRating(int ratingP);

  //function for checking the average rating of the movie
  double getAverage();

private:
  string movieName;
  string mpaaRating;
  //Counters for the number of people that rated the movie this value
  int count1;
  int count2;
  int count3;
  int count4;
  int count5;
};

int main()
{
  /****
  test driver program:
  To use this program first create a Movie class object by passing the movie
  and the mpaa rating. Then use the addRating(5) function, with your rating.
  5 was used as an example. The function can take 1-5.
  ****/
  //testing creating the object and the accessor functions
  cout << "Test driving the program in 3... 2... 1..." << endl << endl;
  cout << "creating an Rps object test" << endl;
  Movie test("movietest","PG");
  cout << "test.getMovieName() and test.getMpaaRating() should return" <<
    "movietest and PG" << endl;
  cout << test.getMovieName() << " " << test.getMpaaRating() << endl;
  cout << "test.setMovieName(\"1\") and test.setMovieRating(\"2\") will change" <<
    " the values appropriately" << endl;
  cout << test.getMovieName() << " " << test.getMpaaRating() << endl;
  cout << "test.addRating(1) should be the rating for test.getAverage()" <<
    endl;
  test.addRating(1);
  cout << test.getAverage() << endl;
  cout << "Test driving complete!" << endl;
  cout << "===============================================" << endl << endl;
  //Test drive program ends

  //create deadpool Movie and rate it 5 times
  Movie deadpool("Deadpool","R");
  deadpool.addRating(1);
  deadpool.addRating(2);
  deadpool.addRating(2);
  deadpool.addRating(2);
  deadpool.addRating(2);

  //create stardust Movie and rate it 5 times
  Movie stardust("Stardust","PG");
  stardust.addRating(3);
  stardust.addRating(4);
  stardust.addRating(4);
  stardust.addRating(5);
  stardust.addRating(5);

  //output each movie name, mpaa rating and average rating
  cout << "For the Movie: " << deadpool.getMovieName() << endl;
  cout << "The MPAA rating is: " << deadpool.getMpaaRating() << endl;
  cout << fixed << setprecision(2) << deadpool.getAverage() << endl << endl;

  cout << "For the Movie: " << stardust.getMovieName() << endl;
  cout << "The MPAA rating is: " << stardust.getMpaaRating() << endl;
  cout << fixed << setprecision(2) << stardust.getAverage() << endl;

  return 0;
}

//Movie constructor. Takes input strings movieRatingP and mpaaStringP.
//Sets counts of people rating the movie that int to zero.
//P is for passed variables
Movie::Movie(string movieNameP, string mpaaRatingP)
{
  movieName = movieNameP;
  mpaaRating = mpaaRatingP;
  count1 = 0;
  count2 = 0;
  count3 = 0;
  count4 = 0;
  count5 = 0;
}

//accessor functions
string Movie::getMovieName()
{
  return movieName;
}
string Movie::getMpaaRating()
{
  return mpaaRating;
}

//mutator functions. P is for passed variables
void Movie::setMovieName(string movieNameP)
{
  movieName = movieNameP;
}
void Movie::setMpaaRating(string mpaaRatingP)
{
  mpaaRating = mpaaRatingP;
}

//function for adding a rating to a movie between 1-5. 1 = terrible.
//2 = bad. 3 = OK. 4 = good. 5 = great. It takes an int as input.
void Movie::addRating(int ratingP)
{
  if (ratingP >= 1 && ratingP <= 5)
  {
    if (ratingP == 1)
    {
      count1++;
    }
    else if (ratingP == 2)
    {
      count2++;
    }
    else if (ratingP == 3)
    {
      count3++;
    }
    else if (ratingP == 4)
    {
      count4++;
    }
    else if (ratingP == 5)
    {
      count5++;
    }
  }
  else
  {
    cerr << "The rating you added is not valid" << endl;
  }
}

//function for checking the average rating of the movie
double Movie::getAverage()
{
  //declare variables
  int sumCount = 0;
  int sumRatings = 0;
  double average = 0.0;

  //find the amount of ratings taken
  sumCount = count1 + count2 + count3 + count4 + count5;
  //find the total value of the ratings taken
  sumRatings = count1 * 1 + count2 * 2 + count3 * 3  + count4 * 4 + count5 * 5;
  //find the average rating. Convert to double to avoid truncation
  average = double(sumRatings)/double(sumCount);
  return average;
}
