// ------------------------------------------------ inventory.h -------------------------------------------------------
// Jacob Pedersen, Mandeep Masoun | CSS343 B Au 23
// Creation Date: 11.27.2023
// Date of Last Modification: 12.11.2023
// --------------------------------------------------------------------------------------------------------------------
// header file for inventory class. 
// --------------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions.
// This is a class for managing operations of the store. This includes tracking of inventory stock, as well as incre-
// menting and decrementing stock counts for movies within genres (for borrow and return). 
// assuming that each item is uniquely identified by its complete set of sorting attributes. 
// --------------------------------------------------------------------------------------------------------------------
#ifndef inventory_h_
#define inventory_h_
using namespace std;
#include <iostream>
#include "movie.h"
#include <vector>
#include <string>
#include <map>

class inventory{
public:
    inventory(); //default 
    ~inventory(); //deconstructor
    void printInventory(); //prints I
    void printCurrentAvailableInventory(); //prints I with more information including stock and relevant info 
    void addMovie(movie addedMovie);
    bool manipulateComedy(string action, string title, int yearReleased); //comedy movies (‘F’) sorted by Title, then Year it released
    bool manipulateDrama(string action, string director, string title); //dramas (‘D’) are sorted by Director, then Title 
    bool manipulateClassics(string action, int month, int year, string majorActor); //classics (‘C’) are sorted by Release date, then Major actor
    void addCustomerHistory(int id, string customerHistory); //manual store customer history 
    void printCustomerHistory(int id);

private:
  map<int, vector<string>> customerHistory;
  vector<movie> comedy;
  vector<movie> drama;
  vector<movie> classics; 

};
#endif