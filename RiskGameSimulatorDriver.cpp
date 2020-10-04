//
// Created by Karl on 10/3/2020.
//
#include "RiskGamesSimulator.h"
#include <iostream>
int main() {
  std::cout << "Hello Gamer, input number of attackers. ";
  uint32_t numAttackers;
  std::cin >> numAttackers;
  std::cout << "Now enter number of defenders. ";
  uint32_t numDefenders;
  std::cin >> numDefenders;

  RiskGamesSimulator simulation(numAttackers, numDefenders, 10000);
  std::cout << "Attackers have a " << simulation.getPercent()
            << "% chance of winning.\n";
  std::cout << "The most likely outcomes are: \n";
  simulation.printOutcomes(10);

  return 0;
};
#include "RiskGameSimulatorDriver.h"
