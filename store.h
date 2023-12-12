
// ------------------------------------------------ store.h ------------------------------------------------------
// Jacob Pedersen, Mandeep Masoun | CSS343 B Au 23
// Creation Date: 11.27.2023
// Date of Last Modification: 12.11.2023
// --------------------------------------------------------------------------------------------------------------------
// Implementation file for storing.
// --------------------------------------------------------------------------------------------------------------------

#ifndef STORE_H
#define STORE_H

#include "customer.h"
#include "inventory.h"
#include "movie.h"
#include "string"
#include <fstream>
#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>

using namespace std;

class Store {
public:
  Store();
  ~Store();
  void loadMovies();
  void loadCustomers();
  void readCommandFile(string fileName);
  void readCustomersFile(string fileName);
  void readMovieFile(string fileName);
  bool addCustomer(int hashkey, customer customer);
  bool findCustomer(int ID);

private:
  Inventory inventory;
  //HashTable<int, Customer> customersList;
};
#endif