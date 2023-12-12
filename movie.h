#ifndef movie_h_
#define movie_h_
#include <iostream>
#include <string>

using namespace std;

class movie {
public:
  string movie_type;
  string title;
  string major_actor;
  string director;
  int stock;
  int release_year;
  int release_month;

  movie(string movie_type);                                                                                                    // constructor taking in string movie_type
  movie(string movie_type, int stock, string director, string title, int release_year);                                        // constructor for comedy AND drama types
  movie(string movie_type, int stock, string director, string title, string major_actor, int release_month, int release_year); // constructor for classics
  ~movie();
  int getStock(string title); // prescribed stock getter which takes in string title
private:
  friend std::ostream &operator<<(std::ostream &ostream, const movie &movie); //&movie object
};
#endif