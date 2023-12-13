#include "customer.h"
#include "inventory.h"
#include "movie.h"
#include "store.h"
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;
// g++ main.cpp classics.cpp comedy.cpp drama.cpp customer.cpp inventory.cpp movie.cpp store.cpp classics.h comedy.h drama.h customer.h inventory.h movie.h store.h hash.h && ./a.out
int main() {
  store store;
  store.inData4Movies("data4movies.txt");
  store.inData4Customers("data4customers.txt");
  store.inData4Commands("data4commands.txt");
}
