#include <iostream> // for cin and cout
using namespace std;
#ifndef BEETLE_H
#define BEETLE_H

class beetle {

public:
  // Default Constructor that takes a string variable and a int variable
  beetle(string playerName);

  // Starts the game and adds limbs due to correct roll which in the end after
  // having all parts of the Beetle completed
  void startGame(int roll);

  // Checks if the players has completely the beetle Game
  bool checkIfPlayerHasAllParts(int body, int head, int wings, int legs,
                                int antennas, int eyes);

  // Mutators that increase the body parts of the beetle by one
  void gainBody() { this->body++; }
  void gainHead() { this->head++; }
  void gainWings() { this->wings++; }
  void gainLegs() { this->legs++; }
  void gainAnennas() { this->antennas++; }
  void gainEyes() { this->eyes++; }

  // Accessors to access the private variables
  string getPlayerName();

  int getTotalMoves();
  int getBody();
  int getHead();
  int getWings();
  int getLegs();
  int getAntennas();
  int getEyes();
  bool getHasAllBodyParts();

private:
  string playerName;

  int valueOfRoll;

  // Variables that are body parts of the beetle
  int body;
  int head;
  int wings;
  int legs;
  int antennas;
  int eyes;

  int totalMoves;

  bool hasAllBodyParts;
};

#endif
