// ------------------------------------------------ customer.cpp -----------------------------------------------------
// Jacob Pedersen, Mandeep Masoun | CSS343 B Au 23
// Creation Date: 11.27.2023
// Date of Last Modification: 12.11.2023
// --------------------------------------------------------------------------------------------------------------------
// Implementation file for cusotmer. 
// --------------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions.
// This is a genre of movie (three types for this movie rental store - comedy, drama, classics). Operations necessary
// include: borrow, return, inventory and history. Assumptions are formed on the basis defined already and also
// the fact that we are assuming the text files of movie store data (which include data4commands.txt and 
// data4movies.txt) are read in successfully and the data is formatted correctly. We will check for garbage inputs
// per the instructions and handle them with simple error messages. 
// --------------------------------------------------------------------------------------------------------------------
#include "customer.h"

// ------------------------------------------ default constructor -----------------------------------------------------
// Prescribed default constructor. New format by me upon reccomendation from QSC. 
// --------------------------------------------------------------------------------------------------------------------
customer::customer() : firstName(""), lastName(""), id(0) {}

// ------------------------------------------ default constructor -----------------------------------------------------
// Prescribed default constructor taking in attributes per the instructions. New format by me upon reccomendation 
// from QSC. 
// --------------------------------------------------------------------------------------------------------------------
customer::customer(string firstName, string lastName, int id) : firstName(firstName), lastName(lastName), id(id) {}

// --------------------------------------------- deconstructor -------------------------------------------------------
// prescribed deconstructor 
// -------------------------------------------------------------------------------------------------------------------
customer::~customer(){

}

// ------------------------------------------- first name getter ------------------------------------------------------
// getter function for first name. POSSIBLY: more specific getters needed (e.g. just first name or just last name 
// perhaps - will circle back.)
// --------------------------------------------------------------------------------------------------------------------
string customer::getFirstName(){
    return firstName;
}

// ------------------------------------------- last name getter ------------------------------------------------------
// getter function for first name. POSSIBLY: more specific getters needed (e.g. just first name or just last name 
// perhaps - will circle back.)
// --------------------------------------------------------------------------------------------------------------------
string customer::getLastName(){
    return lastName;
}

// -------------------------------------------- customer History ------------------------------------------------------
// Shows the history for a customer.
// --------------------------------------------------------------------------------------------------------------------
void customer::customerHistory(){
    int i = 0;
    while (i < history.size()){
        cout << history[i] << endl;
        i++;
    }
    if (history.size() == 0){
        cout << "Error: No available history." << endl;
    }
}

// ------------------------------------------------- add movie -------------------------------------------------------
// Utilizing vector, add movie by title to a customers history. 
// --------------------------------------------------------------------------------------------------------------------
void customer::addMovie(string newMovie) {
    history.emplace_back(newMovie);
}

// ------------------------------------------------- add movie -------------------------------------------------------
// printing to the format per the instructions. id number (4 digit), last name, first name. 
// --------------------------------------------------------------------------------------------------------------------
ostream& operator<<(ostream &output, customer &customer) {
    return output << customer.getID() << " " << customer.getLastName() << " " << customer.getFirstName();
}