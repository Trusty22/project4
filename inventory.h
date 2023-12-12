// ------------------------------------------------ inventory.h --------------------------------------------------------
// Jacob Pedersen, Mandeep Masoun | CSS343 B Au 23
// Creation Date: 11.27.2023
// Date of Last Modification: 12.11.2023
// ---------------------------------------------------------------------------------------------------------------------

#ifndef inventory_h_
#define inventory_h_
#include "movie.h"
#include <vector>
using namespace std;

class Inventory {
private:
  vector<movie> comedies;

  vector<movie> classics;

  vector<movie> dramas;

public:
  Inventory();
  ~Inventory();
};
#endif