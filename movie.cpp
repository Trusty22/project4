// ------------------------------------------------ movie.cpp ---------------------------------------------------------
// Jacob Pedersen, Mandeep Masoun | CSS343 B Au 23
// Creation Date: 11.27.2023
// Date of Last Modification: 12.11.2023
// --------------------------------------------------------------------------------------------------------------------
// Implementation file for movie.
// --------------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions.
// This is a genre of movie (three types for this movie rental store - comedy, drama, classics). Operations necessary
// include: borrow, return, inventory and history. Assumptions are formed on the basis defined already and also
// the fact that we are assuming the text files of movie store data (which include data4commands.txt and 
// data4movies.txt) are read in successfully and the data is formatted correctly. We will check for garbage inputs
// per the instructions and handle them with simple error messages. 
// --------------------------------------------------------------------------------------------------------------------
#include "movie.h"
using namespace std;

// ------------------------------------------------- constructor ------------------------------------------------------
// Prescribed movie constructor. Includes variations for movie type. 
// --------------------------------------------------------------------------------------------------------------------
movie::movie(string movie_Genre){
        while (!(movie_Genre == "D" || movie_Genre == "F" || movie_Genre == "C")){
            std::cout << "Type does not exist. Enter 'D', 'F', or 'C': ";
            std::cin >> movie_Genre;
        }
        if((movie_Genre == "D") || (movie_Genre == "F") || (movie_Genre == "C")){
        this->movie_Genre = movie_Genre;
    }
}

// ------------------------------ drama and comedy specific type constructor ------------------------------------------
// Prescribed movie constructor for drama and comedy types. Includes variations for movie type. 
// --------------------------------------------------------------------------------------------------------------------
movie::movie(string movie_Genre, int amount, string director, string title, int release_year){
    while(!(movie_Genre == "D" || movie_Genre == "F" || movie_Genre == "C")){
        std::cout << "Type does not exist. Enter 'D', 'F', or 'C': ";
        std::cin >> movie_Genre;
    }
    if((movie_Genre == "D") || (movie_Genre == "F")){ //two check 
    this->movie_Genre = movie_Genre;
    this->amount = amount;
    this->director = director;
    this->title = title;

    this->actor = actor;
    this->release_year = release_year;
    this->release_month = release_month;
  }
}

// ------------------------------------ classics specific type constructor --------------------------------------------
// Prescribed movie constructor for drama and comedy types. Includes variations for movie type. 
// --------------------------------------------------------------------------------------------------------------------
movie::movie(string movie_Genre, int amount, string director, string title, string major_actor, int release_month, 
int release_year){
    while (!(movie_Genre == "D" || movie_Genre == "F" || movie_Genre == "C")){
    std::cout << "Type does not exist. Enter 'D', 'F', or 'C': ";
    std::cin >> movie_Genre;
    }
    if ((movie_Genre == "C")){
    this->movie_Genre = movie_Genre; //two check 
    this->amount = amount;
    this->director = director;
    this->title = title;

    this->actor = actor;
    this->release_year = release_year;
    this->release_month = release_month; //extra check 
  }
}

// --------------------------------------------------- getStock -------------------------------------------------------
// Prescribed function for gettingand reading amount number per title (input string). 
// --------------------------------------------------------------------------------------------------------------------
int movie::getStock(string title){
    return amount;
}

// --------------------------------------------------- ostream --------------------------------------------------------
// Prescribed function for ostream. Follows o/p per instructions. 
// --------------------------------------------------------------------------------------------------------------------
ostream& operator<<(ostream &ostream, const movie &movie){
    if((movie.movie_Genre == "D") || (movie.movie_Genre == "F")){
    ostream << movie.movie_Genre << ", " << movie.amount << ", " << movie.director << ", " << movie.title << ", " 
    << movie.release_year;
  }
  if(movie.movie_Genre == "C"){
    ostream << movie.movie_Genre << ", " << movie.amount << ", " << movie.director << ", " << movie.title << ", " << 
    movie.actor << " " << movie.release_month << " " << movie.release_year;
  }
  return ostream; 
}

// -------------------------------------------------- destructor  -----------------------------------------------------
// Prescribed movie destructor. 
// --------------------------------------------------------------------------------------------------------------------
movie::~movie(){

}

