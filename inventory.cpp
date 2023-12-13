// ------------------------------------------------ inventory.cpp -----------------------------------------------------
// Jacob Pedersen, Mandeep Masoun | CSS343 B Au 23
// Creation Date: 11.27.2023
// Date of Last Modification: 12.11.2023
// --------------------------------------------------------------------------------------------------------------------
// Implementation file for movie genre: classics.
// --------------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions.
// This is a genre of movie (three types for this movie rental store - comedy, drama, classics). Operations necessary
// include: borrow, return, inventory and history. Assumptions are formed on the basis defined already and also
// the fact that we are assuming the text files of movie store data (which include data4commands.txt and
// data4movies.txt) are read in successfully and the data is formatted correctly. We will check for garbage inputs
// per the instructions and handle them with simple error messages.
// --------------------------------------------------------------------------------------------------------------------
#include "inventory.h"

// -------------------------------------------- default constructor --------------------------------------------------
// standard default constructor
// --------------------------------------------------------------------------------------------------------------------
inventory::inventory() {
}

// ------------------------------------------------- destructor -------------------------------------------------------
// standard deconstructor
// --------------------------------------------------------------------------------------------------------------------
inventory::~inventory() {
}

// ---------------------------------------------- store customer history ----------------------------------------------
// Store customer history. Using vector pair, taking in 4 digit id number.
// --------------------------------------------------------------------------------------------------------------------
void inventory::addCustomerHistory(int id, string history) {
  customerHistory[id].second.push_back(history); // using vector pair to store
}

// ---------------------------------------------- print customer history ----------------------------------------------
// Print cust history. Stored in vector pair.
// --------------------------------------------------------------------------------------------------------------------
void inventory::printCustomerHistory(int id) {
  cout << " Customer ||" << id << " History " << endl; // REMOVED ----------

  int i = 0;
  while (i < customerHistory[id].second.size()) {
    cout << customerHistory[id].second[i] << endl;
    i++;
  }
}

// ---------------------------------------------- print inventory -----------------------------------------------------
// prints the inventory of movies for the rental store (this neglects current stock levels, and is a library overview).
// POSSIBLY ANNEX THIS for simplicity since inventory stock is more useful.
// --------------------------------------------------------------------------------------------------------------------
void inventory::printInventory() {
  int j = 0;
  while (j < comedy.size()) { // comedy
    cout << comedy[j] << endl;
    j++;
  }

  int k = 0;
  while (k < drama.size()) { // drama
    cout << drama[k] << endl;
    k++;
  }

  int i = 0;
  while (i < classics.size()) { // classics
    cout << classics[i] << endl;
    i++;
  }
}

// -------------------------------------- print current available inventory -------------------------------------------
// prints the current available inventory of movies for the rental store (this does NOT neglect current stock levels,
// and is a up to date library overview). CHECK: Formatting!
// --------------------------------------------------------------------------------------------------------------------
void inventory::printCurrentAvailableInventory() {
  int j = 0;
  while (j < comedy.size()) { // comedy
    cout << comedy[j] << " \tStock = " << comedy[j].stock << endl;
    j++;
  }

  int k = 0;
  while (k < drama.size()) { // drama
    cout << drama[k] << " \tStock = " << drama[k].stock << endl;
    k++;
  }

  int i = 0;
  while (i < classics.size()) { // classics
    cout << classics[i] << " \tStock = " << classics[i].stock << endl;
    i++;
  }
}

// --------------------------------------------------- add movie -----------------------------------------------------
// function def for adding a title to a genre. via vector.
// -------------------------------------------------------------------------------------------------------------------
void inventory::addMovie(movie movie) {
  while (movie.movie_Genre == "F") {
    comedy.push_back(movie);
    break;
  }
  while (movie.movie_Genre == "D") {
    drama.push_back(movie);
    break;
  }
  while (movie.movie_Genre == "C") {
    classics.push_back(movie);
    break;
  }
}

// ---------------------------------------------- manipulate comedy --------------------------------------------------
// action handling for comedy film type.
// -------------------------------------------------------------------------------------------------------------------
bool inventory::manipulateComedy(string action, string title, int year) {
  int i = 0;
  while (i < comedy.size()) {
    if (comedy[i].title == title && comedy[i].release_year == year) {
      if (action == "B") {
        if (comedy[i].stock - 1 < 0) {
          cout << "Error: Movie is Out of Stock." << endl;
          return false;
        } else {
          comedy[i].stock = comedy[i].stock - 1;
          return true;
        }
      } else if (action == "R") {
        comedy[i].stock = comedy[i].stock + 1;
        return true;
      } else if (action == "F") {
        return true;
      }
    }
    i++;
  }
  return true;
}

// ----------------------------------------------- manipulate drama --------------------------------------------------
// action handling for drama film type.
// -------------------------------------------------------------------------------------------------------------------
bool inventory::manipulateDrama(string action, string director, string title) {
  int i = 0;
  while (i < drama.size()) {
    if (drama[i].title == title && drama[i].director == director) {
      if (action == "B") {
        if (drama[i].stock - 1 < 0) {
          cout << "Error: Movie is Out of Stock." << endl;
          return false;
        } else {
          drama[i].stock = drama[i].stock - 1;
          return true;
        }
      } else if (action == "R") {
        drama[i].stock = drama[i].stock + 1;
        return true;
      } else if (action == "F") {
        return true;
      }
    }
    i++;
  }
  return false;
}

// --------------------------------------------- manipulate classics -------------------------------------------------
// action handling for classics film type.
// -------------------------------------------------------------------------------------------------------------------
bool inventory::manipulateClassics(string action, int month, int year, string actor) {
  int i = 0;
  while (i < classics.size()) {
    if (classics[i].release_month == month && classics[i].actor == actor &&
        classics[i].release_year == year) {
      if (action == "B") {
        if (classics[i].stock - 1 < 0) {
          cout << "Error: Movie is Out of Stock." << endl;
          return false;
        } else {
          classics[i].stock = classics[i].stock - 1;
          return true;
        }
      } else if (action == "R") {
        classics[i].stock = classics[i].stock + 1;
        return true;
      } else if (action == "F") {
        return true;
      }
    }
    i++;
  }
  return false;
}