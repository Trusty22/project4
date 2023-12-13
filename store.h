// ------------------------------------------------- store.h ----------------------------------------------------------
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
#ifndef store_h_
#define store_h_
using namespace std;
#include "customer.h"
#include "movie.h"
#include "inventory.h" //implement 
#include "hash.h" //unsure
#include "string"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <unordered_map>

class store{
public:
    store(); //default constructor
    ~store(); //destructor
    void inData4Commands(string in); //for reading in the data4commands txt file 
    void inData4Customers(string in); //for reading in the data4customers txt file 
    void inData4Movies(string in); //for reading in the data4movies txt file 
private:
    HashTable<int, customer> customersIn; //Update: HashTable
    inventory inv;
    

};
#endif
