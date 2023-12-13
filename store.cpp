// ------------------------------------------------ store.cpp ---------------------------------------------------------
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
#include "store.h"
// ----------------------------------------- default constructor ------------------------------------------------------
// Default consturctor
// --------------------------------------------------------------------------------------------------------------------
store::store() {
}

// ---------------------------------------------- destructor ----------------------------------------------------------
// Destructor for memory management
// --------------------------------------------------------------------------------------------------------------------
store::~store() {
}
void notFound() {
  cout << "Invalid: Customer ID not found." << endl;
}

// -------------------------------------------- in data4commands ------------------------------------------------------
// Reads data4commands. From text file. Assumptions hold.
// ---------------------------------------------------------------------------------------------------------------------
void store::inData4Commands(string in) {
  ifstream myFile(in);
  if (!myFile.is_open()) {
    cerr << "File Not Found: " << in << endl;
    return;
  }

  string word;
  while (getline(myFile, word)) {
    stringstream ss(word);
    string temp, transaction, type, movieGenre, mName, director, actor;
    int ID, yearR, monthR;

    ss >> transaction;

    if (transaction == "I") {
      inv.printInventory();
    } else if (transaction == "H") {
      ss >> temp;
      istringstream(temp) >> ID;

      while (!customersIn.findItem(ID)) {
        notFound();
        if (!getline(myFile, word)) {
          myFile.close();
          return;
        }
        stringstream ss(word);
        ss >> transaction;
        if (transaction == "H") {
          ss >> temp;
          istringstream(temp) >> ID;
        } else {
          break;
        }
      }

      inv.printCustomerHistory(ID);
    } else if (transaction == "B" || transaction == "R") {
      ss >> temp;
      istringstream(temp) >> ID;

      while (!customersIn.findItem(ID)) {
        notFound();
        if (!getline(myFile, word)) {
          myFile.close();
          return;
        }
        stringstream ss(word);
        ss >> transaction;
        if (transaction == "B" || transaction == "R") {
          ss >> temp;
          istringstream(temp) >> ID;
        } else {
          break;
        }
      }

      ss >> type;
      if (type != "D") {
        cout << "Invalid: not existing type of media." << endl;
        continue;
      }

      ss >> movieGenre;

      if (movieGenre == "F") {
        ss.ignore(); // Ignore the space after movieGenre
        getline(ss, mName, ',');
        ss >> yearR;

        if (inv.manipulateComedy("F", " " + mName, yearR)) {
          string his = transaction + " " + movieGenre + " " + mName + " " + to_string(yearR);
          inv.addCustomerHistory(ID, his);

          if (transaction == "B") {
            inv.manipulateComedy("B", " " + mName, yearR);
          } else {
            inv.manipulateComedy("R", " " + mName, yearR);
          }
        }
      } else if (movieGenre == "D") {

        getline(ss, director, ',');
        getline(ss, mName, ',');

        if (inv.manipulateDrama("F", " " + director, mName)) {
          string his = transaction + " " + movieGenre + " " + mName + " " + director;
          inv.addCustomerHistory(ID, his);

          if (transaction == "B") {
            inv.manipulateDrama("B", " " + director, mName);
          } else {
            inv.manipulateDrama("R", " " + director, mName);
          }
        }
      } else if (movieGenre == "C") {
        ss >> monthR >> yearR >> actor;

        if (inv.manipulateClassics("F", monthR, yearR, actor)) {
          string his = transaction + " " + movieGenre + " " + to_string(monthR) + " " +
                       to_string(yearR) + " " + actor;
          inv.addCustomerHistory(ID, his);

          if (transaction == "B") {
            inv.manipulateClassics("B", monthR, yearR, actor);
          } else {
            inv.manipulateClassics("R", monthR, yearR, actor);
          }
        }
      } else {
        cout << "Invalid: Movie Genre not found." << endl;
      }
    } else {
      cout << "Invalid Command." << endl;
    }
  }

  myFile.close();
}

// -------------------------------------------- in data4customers ------------------------------------------------------
// Reads data4customers. From text file. Assumptions hold.
// ---------------------------------------------------------------------------------------------------------------------
void store::inData4Customers(string in) {
  ifstream myFile(in);
  if (!myFile.is_open()) {
    cerr << "File Not Opened!  " << in << endl;
    return;
  }

  while (!myFile.eof()) {
    string word;
    getline(myFile, word);
    if (word.empty()) {
      break;
    }

    stringstream parseLine(word);
    int ID;
    string firstName, lastName;

    parseLine >> ID;
    while (parseLine >> lastName >> firstName) {
      lastName += " " + firstName;
    }

    customer newCustomer = customer(firstName, lastName, ID);
  }

  myFile.close();
}

// -------------------------------------------- in data4movies ---------------------------------------------------------
// Reads data4movies. From text file. Assumptions hold.
// ---------------------------------------------------------------------------------------------------------------------
void store::inData4Movies(string in) {
  ifstream myFile(in);
  if (!myFile.is_open()) {
    cerr << "File Not Opened!  " << in << endl;
    return;
  }

  while (!myFile.eof()) {
    string word;
    getline(myFile, word);
    if (word.empty()) {
      break;
    }

    stringstream ss(word);
    int amount, yearR, monthR;
    string movieGenre, director, title, actor, FirstN, lastN, temp;
    

    // Read movie type
    getline(ss, movieGenre, ',');

    // Read amount
    getline(ss, temp, ',');
    istringstream(temp) >> amount;

    // Read director and title
    getline(ss, director, ',');
    getline(ss, title, ',');

    if (movieGenre == "C" || movieGenre == "c") {
      // Read major actor's first and last names
      getline(ss, FirstN, ' ');
      getline(ss, lastN, ' ');
      actor = FirstN + lastN;

      // Read release month and year
      getline(ss, temp, ' ');
      getline(ss, temp, ' ');
      istringstream(temp) >> monthR;

      getline(ss, temp, ' ');
      istringstream(temp) >> yearR;

      movie newMovie = movie("C", amount, director, title, actor, yearR, monthR);
      inv.addMovie(newMovie);

    } else if (movieGenre == "F" || movieGenre == "f" || movieGenre == "D" || movieGenre == "d") {
      // Read release year
      getline(ss, temp);
      istringstream(temp) >> yearR;

      if (movieGenre == "F" || movieGenre == "f") {
        movie newMovie = movie("F", amount, director, title, yearR);
        inv.addMovie(newMovie);
      } else if (movieGenre == "D" || movieGenre == "d") {
        movie newMovie = movie("D", amount, director, title, yearR);
        inv.addMovie(newMovie);
      }
    } else {
      cout << "Invalid Movie Genre." << endl;
    }
  }

  myFile.close();
}