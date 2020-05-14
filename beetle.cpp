#include <iostream> 
using namespace std;
#include "beetle.h"

//Constructor for assigning default values for body parts and total number of moves
beetle::beetle(string playerName) {
  // TotalMoves is zero because the game has not started yet
  this->totalMoves = 0;

  // All body parts start at zero indicating the player has no beetle Parts
  this->head = 0;
  this->body = 0;
  this->wings = 0;
  this->legs = 0;
  this->antennas = 0;
  this->eyes = 0;
  this->valueOfRoll = 0;

  this->playerName = playerName;

  this->hasAllBodyParts = false;
}

bool beetle::checkIfPlayerHasAllParts(int body, int head, int wings, int legs,
                                      int antennas, int eyes) {

  // If player has a complete beetle than "hasAllBodyParts" is updated to true
  if (body == 1 && head == 1 && wings == 2 && wings == 2 && legs == 6 &&
      antennas == 2 && eyes == 2) {
    this->hasAllBodyParts = true;
  }
  return hasAllBodyParts;
}

// Starts the beetle game
void beetle::startGame(int roll) {
  valueOfRoll = roll;
  if (valueOfRoll == 6 && body == 0) {
    this->body++;
  }

  if (valueOfRoll == 5 && body == 1 && head == 0) {
    this->head++;
  }

  if (valueOfRoll == 4 && body == 1 && wings < 2) {
    this->wings++;
  }

  if (valueOfRoll == 3 && body == 1 && legs < 6) {
    this->legs++;
  }


  if (valueOfRoll == 2 && head == 1 && antennas < 2) {
    this->antennas++;
  }

  
  if (valueOfRoll == 1 && head == 1 && eyes < 2) {
    this->eyes++;
  }

  hasAllBodyParts =
      checkIfPlayerHasAllParts(this->body, this->head, this->wings, this->legs,
                               this->antennas, this->eyes);

  totalMoves++;
}


int beetle::getHead() { return this->head; }


int beetle::getBody() { return this->body; }


int beetle::getWings() { return this->wings; }


int beetle::getLegs() { return this->legs; }


int beetle::getAntennas() { return this->antennas; }


int beetle::getEyes() { return this->eyes; }


string beetle::getPlayerName() { return this->playerName; }


int beetle::getTotalMoves() { return this->totalMoves; }

bool beetle::getHasAllBodyParts() { return this->hasAllBodyParts; }
