// ------------------------------------------------ inventory.h --------------------------------------------------------
// Jacob Pedersen, Mandeep Masoun | CSS343 B Au 23
// Creation Date: 11.27.2023
// Date of Last Modification: 12.11.2023
// ---------------------------------------------------------------------------------------------------------------------

#ifndef inventory_h_
#define inventory_h_

#include "movie.h"
#include <iostream>
#include <map>
#include <string>
#include <vector>


using namespace std;

class Inventory {
private:
  map<int, vector<string>> cusData;

  vector<movie> comedies;

  vector<movie> classics;

  vector<movie> dramas;
  

public:
  Inventory();
  ~Inventory();

  void addMovie(movie movie);   // adds movie to specific vector
  void printEntireInventory();  // prints out the entire movie inventory
  void printWorkingInventory(); // prints out entire movie inventory with stock specifically highlighted

  bool actionComedy(string action, string title, int year);                  // borrows, returns, and searches for comedies
  bool actionDrama(string action, string director, string title);            // borrows, returns, and searches for dramas
  bool actionClassic(string action, int month, int year, string majorActor); // borrows, returns, and searches for classics

  void storeCustomerHistory(int id, string history); // stores a specific customer's history
  void printCustomerHistory(int id);                 // prints a specific customer's history
};
#endif