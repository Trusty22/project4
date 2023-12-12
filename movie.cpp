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
movie::movie(string movie_type){
        while (!(movie_type == "D" || movie_type == "F" || movie_type == "C")) {
            std::cout << "Type does not exist. Enter 'D', 'F', or 'C': ";
            std::cin >> movie_type;
        }
        if ((movie_type == "D") || (movie_type == "F") || (movie_type == "C")){
        this->movie_type = movie_type;
    }
}

// ------------------------------ drama and comedy specific type constructor ------------------------------------------
// Prescribed movie constructor for drama and comedy types. Includes variations for movie type. 
// --------------------------------------------------------------------------------------------------------------------
movie::movie(string movie_type, int stock, string director, string title, int release_year){
    while (!(movie_type == "D" || movie_type == "F" || movie_type == "C")){
        std::cout << "Type does not exist. Enter 'D', 'F', or 'C': ";
        std::cin >> movie_type;
    }
    if ((movie_type == "D") || (movie_type == "F")){
    this->movie_type = movie_type;
    this->stock = stock;
    this->director = director;
    this->title = title;
    this->major_actor = major_actor;
    this->release_year = release_year;
    this->release_month = release_month;
  }
}

// ------------------------------------ classics specific type constructor --------------------------------------------
// Prescribed movie constructor for drama and comedy types. Includes variations for movie type. 
// --------------------------------------------------------------------------------------------------------------------
movie::movie(string movie_type, int stock, string director, string title, string major_actor, int release_month, 
int release_year){
    while (!(movie_type == "D" || movie_type == "F" || movie_type == "C")){
    std::cout << "Type does not exist. Enter 'D', 'F', or 'C': ";
    std::cin >> movie_type;
    }
    if ((movie_type == "C")){
    this->movie_type = movie_type;
    this->stock = stock;
    this->director = director;
    this->title = title;
    this->major_actor = major_actor;
    this->release_year = release_year;
    this->release_month = release_month;
  }
}

// --------------------------------------------------- getStock -------------------------------------------------------
// Prescribed function for gettingand reading stock number per title (input string). 
// --------------------------------------------------------------------------------------------------------------------
int movie::getStock(string title){
    return stock;
}

// --------------------------------------------------- ostream --------------------------------------------------------
// Prescribed function for ostream. Follows o/p per instructions. 
// --------------------------------------------------------------------------------------------------------------------
ostream& operator<<(ostream &ostream, const movie &movie) {
    if((movie.movie_type == "D") || (movie.movie_type == "F")) {
    ostream << movie.movie_type << ", " << movie.stock << ", " << movie.director << ", " << movie.title << ", " 
    << movie.release_year;
  }
  if (movie.movie_type == "C") {
    ostream << movie.movie_type << ", " << movie.stock << ", " << movie.director << ", " << movie.title << ", " << 
    movie.major_actor << " " << movie.release_month << " " << movie.release_year;
  }
  return ostream; 
}

// -------------------------------------------------- destructor  -----------------------------------------------------
// Prescribed movie destructor. 
// --------------------------------------------------------------------------------------------------------------------
movie::~movie(){

}

