#include "inventory.h"

using namespace std;

Inventory::Inventory() {}
Inventory::~Inventory() {}

void Inventory::addMovie(movie movie) {

  if (movie.movie_type == "C") {
    classics.push_back(movie);
  } else if (movie.movie_type == "F") {
    comedies.push_back(movie);
  } else if (movie.movie_type == "D") {
    dramas.push_back(movie);
  }
}

//----------------------------------------------------------------------------
// printEntireInventory()
// printEntireInventory(): Prints out the total inventory for the store
void Inventory::printEntireInventory() {
  for (int j = 0; j < comedies.size(); j++) {
    cout << comedies[j] << endl;
  }
  for (int k = 0; k < dramas.size(); k++) {
    cout << dramas[k] << endl;
  }
  for (int i = 0; i < classics.size(); i++) {
    cout << classics[i] << endl;
  }
}

//----------------------------------------------------------------------------
// printWorkingInventory()
// printWorkingInventory(): Prints out the working inventory for the store
void Inventory::printWorkingInventory() {
  for (int j = 0; j < comedies.size(); j++) {
    cout << comedies[j] << " \tStock = " << comedies[j].stock << endl;
  }
  for (int k = 0; k < dramas.size(); k++) {
    cout << dramas[k] << " \tStock = " << dramas[k].stock << endl;
  }
  for (int i = 0; i < classics.size(); i++) {
    cout << classics[i] << " \tStock = " << classics[i].stock << endl;
  }
}

//----------------------------------------------------------------------------
// actionComedy()
// actionComedy(): Borrows, returns, and searches for comedy movies
bool Inventory::actionComedy(string action, string title, int year) {
  for (int i = 0; i < comedies.size(); i++) {
    if (comedies[i].title == title && comedies[i].release_year == year) {
      if (action == "B") {
        if (comedies[i].stock - 1 < 0) {
          cout << "Error: Movie is Out of Stock." << endl;
          return false;
        } else {
          comedies[i].stock = comedies[i].stock - 1;
          return true;
        }
      } else if (action == "R") {
        comedies[i].stock = comedies[i].stock + 1;
        return true;
      } else if (action == "F") {
        return true;
      }
    }
  }
  return true;
}

//----------------------------------------------------------------------------
// actionDrama()
// actionDrama(): Borrows, returns, and searches for drama movies
bool Inventory::actionDrama(string action, string director, string title) {
  bool helper = false;
  for (int i = 0; i < dramas.size(); i++) {
    if (dramas[i].title == title && dramas[i].director == director) {
      if (action == "B") {
        if (dramas[i].stock - 1 < 0) {
          cout << "Error: Movie is Out of Stock." << endl;
          return false;
        } else {
          dramas[i].stock = dramas[i].stock - 1;
          return true;
        }
      } else if (action == "R") {
        dramas[i].stock = dramas[i].stock + 1;
        return true;
      } else if (action == "F") {
        return true;
      }
    }
  }
  return false;
}

//----------------------------------------------------------------------------
// actionClassic()
// actionClassic(): Borrows, returns, and searches for classic movies
bool Inventory::actionClassic(string action, int month, int year, string majorActor) {
  for (int i = 0; i < classics.size(); i++) {
    if (classics[i].release_month == month && classics[i].major_actor == majorActor && classics[i].release_year == year) {
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
  }
  return false;
}

//----------------------------------------------------------------------------
// storeCustomerHistory()
// storeCustomerHistory(): Stores the individual customer history
void Inventory::storeCustomerHistory(int id, string history) {
  cusData[id].push_back(history);
}

//----------------------------------------------------------------------------
// printCustomerHistory()
// printCustomerHistory(): Prints out individual customer history
void Inventory::printCustomerHistory(int id) {
  cout << "--------- Customer " << id << " History ----------" << endl;
  for (int i = 0; i < cusData[id].size(); i++) {
    cout << cusData[id][i] << endl;
  }
}
