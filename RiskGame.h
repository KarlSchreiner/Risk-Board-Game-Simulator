//
// Created by Karl on 10/3/2020.
//

#ifndef HACKATHON_RISKGAME_H
#define HACKATHON_RISKGAME_H
#include <bits/stdc++.h>
#include <cstdint>
#include <cstdlib>
#include <vector>

class RiskGame {
public:
  int numAttackers;
  int numDefenders;
  std::vector<short> attackerRoll;
  std::vector<short> defenderRoll;

  RiskGame(uint32_t attackers, uint32_t defenders);
  std::vector<short> getDiceRoll(uint32_t numDice);
  void simulateOneRound();
  std::vector<short> fullGameSimulation();

private:
};

#endif // HACKATHON_RISKGAME_H
