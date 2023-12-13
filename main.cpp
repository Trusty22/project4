#include "customer.h"
#include "inventory.h"
#include "movie.h"
#include "store.h"
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

int main() {
  store store;

  store.inData4Movies("data4movies.txt");

  store.inData4Customers("data4customers.txt");

  store.inData4Commands("data4commands.txt");
}
