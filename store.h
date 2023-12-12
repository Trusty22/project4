
// ------------------------------------------------ store.h ------------------------------------------------------
// Jacob Pedersen, Mandeep Masoun | CSS343 B Au 23
// Creation Date: 11.27.2023
// Date of Last Modification: 12.11.2023
// --------------------------------------------------------------------------------------------------------------------
// Implementation file for storing.
// --------------------------------------------------------------------------------------------------------------------

#ifndef STORE_H_
#define STORE_H_

#include "inventory.h"

using namespace std;

class store {
private:

Inventory inv;

public:
  store();
  ~store();
};
#endif