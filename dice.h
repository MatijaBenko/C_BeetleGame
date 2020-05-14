#include <iostream> // for cin and cout
using namespace std;
#ifndef DICE_H
#define DICE_H
#include <cstdlib>

class dice {
public:
  // Default Constructor for the Dice class that takes in a int and sets the
  // "srand()" value to it Also gives face a value of 1;
  dice(int seed);

  int getFace() const;

  // A member function that imitates rolling a die
  int roll();

private:
  // member variable that holds the number of faces of the die
  int face;
};

#endif
