// ------------------------------------------------- customer.h ------------------------------------------------------
// Jacob Pedersen, Mandeep Masoun | CSS343 B Au 23
// Creation Date: 11.27.2023
// Date of Last Modification: 12.11.2023
// --------------------------------------------------------------------------------------------------------------------
// Header file for cusotmer. Customer creates and manages customers for movie rentals. The customer attributes 
// include: 4-digit ID number, last name, first name. All of these data are separated by one whitespace per
// the instructions in the assignment pdf. An example: 1111 Mouse Mickey
// --------------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions.
// This header and implementation file for a customer in the program is read in from data4customers.txt. We are 
// assuming that the data is formatted correctly in data4customers.txt (input as the example shows above). Included 
// is a print function and also customer history. 
// --------------------------------------------------------------------------------------------------------------------
#ifndef customer_h_
#define customer_h_
using namespace std;
#include <iostream>
#include <string>
#include <vector>

class customer{
public:
    customer();
    customer(string first_name, string last_name, int id);
    ~customer();
    void customerHistory(); //revelas customer history
    void addMovie(string newMovie);
    string getFullName();
    string getFirstName();
    string getLastName();
    int getID();
    vector<string> cusHis;

    friend std::ostream& operator<<(std::ostream &output, const customer &customer); //ostream
private:
    int id;
    string firstName;
    string lastName;

    
};
#endif