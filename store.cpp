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
store::store(){

}

// ---------------------------------------------- destructor ----------------------------------------------------------
// Destructor for memory management
// --------------------------------------------------------------------------------------------------------------------
store::~store(){

}

// -------------------------------------------- in data4commands ------------------------------------------------------
// Reads data4commands. From text file. Assumptions hold.
// ---------------------------------------------------------------------------------------------------------------------
void store::inData4Commands(string in){
        ifstream myFile(in);
    if (!myFile.is_open()) {
        cerr << "Error opening file: " << in << endl;
        return;
    }

    string line;
    while (getline(myFile, line)) {
        stringstream ss(line);
        string temp;
        string commandType, mediaType, movieType, movieTitle, directorName, majorActor;
        int customerID, releaseYear, releaseMonth;

        ss >> commandType;

        if (commandType == "I") {
            inventory.printEntireInventory();
        } else if (commandType == "H") {
            ss >> temp;
            istringstream(temp) >> customerID;

            while (!customersList.findItem(customerID)) {
                cout << "ERROR: No customer with this ID found." << endl;
                if (!getline(myFile, line)) {
                    myFile.close();
                    return;
                }
                stringstream ss(line);
                ss >> commandType;
                if (commandType == "H") {
                    ss >> temp;
                    istringstream(temp) >> customerID;
                } else {
                    break;
                }
            }

            inventory.printCustomerHistory(customerID);
        } else if (commandType == "B" || commandType == "R") {
            ss >> temp;
            istringstream(temp) >> customerID;

            while (!customersList.findItem(customerID)) {
                cout << "ERROR: No customer with this ID found." << endl;
                if (!getline(myFile, line)) {
                    myFile.close();
                    return;
                }
                stringstream ss(line);
                ss >> commandType;
                if (commandType == "B" || commandType == "R") {
                    ss >> temp;
                    istringstream(temp) >> customerID;
                } else {
                    break;
                }
            }

            ss >> mediaType;
            if (mediaType != "D") {
                cout << "ERROR: Invalid Media Type." << endl;
                continue;
            }

            ss >> movieType;

            if (movieType == "F") {
                ss.ignore(); // Ignore the space after movieType
                getline(ss, movieTitle, ',');
                ss >> releaseYear;

                if (inventory.actionComedy("F", " " + movieTitle, releaseYear)) {
                    string history = commandType + " " + movieType + " " + movieTitle + " " + to_string(releaseYear);
                    inventory.storeCustomerHistory(customerID, history);

                    if (commandType == "B") {
                        inventory.actionComedy("B", " " + movieTitle, releaseYear);
                    } else {
                        inventory.actionComedy("R", " " + movieTitle, releaseYear);
                    }
                }
            } else if (movieType == "D") {
                getline(ss, directorName, ',');
                getline(ss, movieTitle, ',');

                if (inventory.actionDrama("F", " " + directorName, movieTitle)) {
                    string history = commandType + " " + movieType + " " + movieTitle + " " + directorName;
                    inventory.storeCustomerHistory(customerID, history);

                    if (commandType == "B") {
                        inventory.actionDrama("B", " " + directorName, movieTitle);
                    } else {
                        inventory.actionDrama("R", " " + directorName, movieTitle);
                    }
                }
            } else if (movieType == "C") {
                ss >> releaseMonth >> releaseYear >> majorActor;

                if (inventory.actionClassic("F", releaseMonth, releaseYear, majorActor)) {
                    string history = commandType + " " + movieType + " " + to_string(releaseMonth) + " " +
                                     to_string(releaseYear) + " " + majorActor;
                    inventory.storeCustomerHistory(customerID, history);

                    if (commandType == "B") {
                        inventory.actionClassic("B", releaseMonth, releaseYear, majorActor);
                    } else {
                        inventory.actionClassic("R", releaseMonth, releaseYear, majorActor);
                    }
                }
            } else {
                cout << "ERROR: Invalid movie type." << endl;
            }
        } else {
            cout << "ERROR: Invalid command type." << endl;
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
        cerr << "Error opening file: " << in << endl;
        return;
    }

    while (!myFile.eof()) {
        string line;
        getline(myFile, line);
        if (line.empty()) {
            break;
        }

        stringstream parseLine(line);
        int ID;
        string firstName, lastName;
        
        parseLine >> ID;
        while (parseLine >> lastName >> firstName) {
            lastName += " " + firstName;
        }

        customer newCustomer = customer(firstName, lastName, ID);
        addCustomer(ID, newCustomer);
    }

    myFile.close();
}

// -------------------------------------------- in data4movies ---------------------------------------------------------
// Reads data4movies. From text file. Assumptions hold.
// ---------------------------------------------------------------------------------------------------------------------
void store::inData4Movies(string in) {
    ifstream myFile(in);
    if (!myFile.is_open()) {
        cerr << "Error opening file: " << in << endl;
        return;
    }

    while (!myFile.eof()) {
        string line;
        getline(myFile, line);
        if (line.empty()) {
            break;
        }

        stringstream ss(line);
        string movieType, director, title, majorActor, majorActorFirstName, majorActorLastName, temp;
        int stock, releaseYear, releaseMonth;

        // Read movie type
        getline(ss, movieType, ',');

        // Read stock
        getline(ss, temp, ',');
        istringstream(temp) >> stock;

        // Read director and title
        getline(ss, director, ',');
        getline(ss, title, ',');

        if (movieType == "C" || movieType == "c") {
            // Read major actor's first and last names
            getline(ss, majorActorFirstName, ' ');
            getline(ss, majorActorLastName, ' ');
            majorActor = majorActorFirstName + majorActorLastName;

            // Read release month and year
            getline(ss, temp, ' ');
            getline(ss, temp, ' ');
            istringstream(temp) >> releaseMonth;

            getline(ss, temp, ' ');
            istringstream(temp) >> releaseYear;

            movie newMovie = movie("C", stock, director, title, majorActor, releaseYear, releaseMonth);
            inventory.addMovie(newMovie);
        } else if (movieType == "F" || movieType == "f" || movieType == "D" || movieType == "d") {
            // Read release year
            getline(ss, temp);
            istringstream(temp) >> releaseYear;

            if (movieType == "F" || movieType == "f") {
                movie newMovie = movie("F", stock, director, title, releaseYear);
                inventory.addMovie(newMovie);
            } else if (movieType == "D" || movieType == "d") {
                movie newMovie = movie("D", stock, director, title, releaseYear);
                inventory.addMovie(newMovie);
            }
        } else {
            cout << "Error: Invalid Movie Type." << endl;
        }
    }

    myFile.close();
}
