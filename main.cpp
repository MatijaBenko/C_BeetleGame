/*************************************************************************
 *
 * Project_1: Beetle
 *
 * File Name:   main.cpp
 */

#include <iostream> // for cin and cout
using namespace std;
#include "beetle.h"
#include "dice.h"
#include <iomanip>
#include <vector>

int main() {
  // Winner is set to such high value so in the further code would be high than
  // the amount of turns value
  int seedVal, totalAmountOfPLayers, rollVal;
  int winner = 5000;

  // Intialize a PlaceHolder called Name
  string playerName;

  // Boolean varialbe when having a while loop to take in user input
  bool start = true;

  // Creates a blank list of object type Beetle
  vector<beetle> listOfPlayers;

  // A loop that asks the user to a value of int and will continue to loop until
  // the input is valid
  while (start) {
    cout << "Please Enter a Seed Value: " << endl;

    cin >> seedVal;

    if (cin.fail()) {
      cin.clear();
      cin.ignore(200, '\n');
      seedVal = 0;
    } else {
      start = false;
    }
  }

  //Initalizes the dice object
  dice dice(seedVal);
  //Resets the start boolean for the next while loop
  start = true;

  // A loop that asks the user to a value of int and will continue to loop until
  // the input is valid
  while (start) {

    cout << "Please Enter total number of players: " << endl;

    cin >> totalAmountOfPLayers;

    // Checks if Input is valid
    if (cin.fail()) {
      cin.clear();
      cin.ignore(200, '\n');
      totalAmountOfPLayers = 0;
    } else {
      start = false;
    }
  }

  // Loops to totalNumberOfPlayers and gets the input of string NAMES for each
  // beetle object
  for (int start = 0; start < totalAmountOfPLayers; start++) {

    cout << "Enter player " << start << " name: " << endl;

    cin >> playerName;

    // Initializes a beetle object with specific "playerName" and "seedVal"
    beetle player(playerName);

    // Adds object type Beetle to listOfPlayers vector
    listOfPlayers.push_back(player);
  }

  bool repeat = false;
  // A for Loop that starts and finish each player game
  while (!(repeat)) {
    // Loops through each player which simulates each Player taking a turn
    for (int eachPlayer = 0; eachPlayer < listOfPlayers.size(); eachPlayer++) {
      // rollVal saves the value of the dice when rolled
      rollVal = dice.roll();
      // Each Player starts the game with the given roll they done and build
      // there beetle
      listOfPlayers.at(eachPlayer).startGame(rollVal);
      // Checks if the player has all body parts
      if (listOfPlayers.at(eachPlayer).getHasAllBodyParts()) {
        repeat = true;
        // Prints of Winner
        cout << "SEED VALUE: " << seedVal << " PLAYER WINNER: "
             << listOfPlayers.at(eachPlayer).getPlayerName()
             << " TOTAL TURNS: " << listOfPlayers.at(eachPlayer).getTotalMoves()
             << endl;
      }
    }
  }
  return 0;
};
