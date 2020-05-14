#include <iostream>
using namespace std;
#include "dice.h"
#include <cstdlib>
// Default Constructor for the Dice class with a int parameter
dice::dice(int seed) {
  // Sets the puesdo-random number to the given seed value
  srand(seed);

  this->face = 1;
}

int dice::getFace() const { return this->face; }

int dice::roll() {
    
  this->face = rand() % 6 + 1;

  return this->face;
}
