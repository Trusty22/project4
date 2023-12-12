// ------------------------------------------------ classics.h --------------------------------------------------------
// Jacob Pedersen, Mandeep Masoun | CSS343 B Au 23
// Creation Date: 11.27.2023
// Date of Last Modification: 12.11.2023
// --------------------------------------------------------------------------------------------------------------------
// Header file for movie genre: classics. 
// --------------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions.
// This is a genre of movie (three types for this movie rental store - comedy, drama, classics). Operations necessary
// include: borrow, return, inventory and history. Assumptions are formed on the basis defined already and also
// the fact that we are assuming the text files of movie store data (which include data4commands.txt and 
// data4movies.txt) are read in successfully and the data is formatted correctly. We will check for garbage inputs
// per the instructions and handle them with simple error messages. 
// --------------------------------------------------------------------------------------------------------------------

#ifndef CLASSICS_H_
#define CLASSICS_H_
#include "movie.h"
using namespace std;

class classics{
public:
    classics();
    ~classics();
};
#endif