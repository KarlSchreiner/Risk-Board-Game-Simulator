//
// Created by Karl on 10/3/2020.
//

#include "RiskGame.h"

RiskGame::RiskGame(uint32_t attackers, uint32_t defenders)
    : numAttackers(attackers), numDefenders(defenders) {}

std::vector<short> RiskGame::getDiceRoll(uint32_t numDice) {
  std::vector<short> diceRoll(numDice);
  for (short i = 0; i < numDice; ++i) {
    diceRoll[i] = rand() % 6 + 1;
  }
  std::sort(diceRoll.begin(), diceRoll.end(), std::greater<short>());

  return diceRoll;
}

void RiskGame::simulateOneRound() {

  if (numAttackers >= 3) {
    attackerRoll = getDiceRoll(3);
  } else if (numAttackers == 2) {
    attackerRoll = getDiceRoll(2);
  } else {
    attackerRoll = getDiceRoll(1);
  }

  if (numDefenders >= 2) {
    defenderRoll = getDiceRoll(2);
  } else {
    defenderRoll = getDiceRoll(1);
  }

  for (int i = 0; i < defenderRoll.size() && i < attackerRoll.size() &&
                  numAttackers != 0 && numAttackers != 0;
       ++i) {
    if (defenderRoll[i] >= attackerRoll[i]) {
      --numAttackers;
    } else {
      --numDefenders;
    }
  }
}

std::vector<short> RiskGame::fullGameSimulation() {
  while (numAttackers > 0 && numDefenders > 0) {
    simulateOneRound();
  }
  std::vector<short> result;
  result.push_back(numAttackers);
  result.push_back(numDefenders);
  return result;
}