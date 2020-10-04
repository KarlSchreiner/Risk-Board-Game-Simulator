//
// Created by Karl on 10/3/2020.
//

#ifndef HACKATHON_RISKGAMESSIMULATOR_H
#define HACKATHON_RISKGAMESSIMULATOR_H
#include "RiskGame.h"

struct node {
  node(short numAttacking, short numDefending)
      : attackers(numAttacking), defenders(numDefending), num(0){};
  bool operator<(const node &rhs) const {
    if (num < rhs.num) {
      return true;
    } else {
      return false;
    }
  }
  bool operator>(const node &rhs) const {
    if (num > rhs.num) {
      return true;
    } else {
      return false;
    }
  }
  short attackers;
  short defenders;
  double num;
};
class RiskGamesSimulator {
public:
  RiskGamesSimulator(uint32_t numAttackers, uint32_t numDefenders,
                     uint32_t numSimulations);
  std::vector<node> runSimulation();
  std::vector<node> getVector();
  double getPercent();
  void printOutcomes(uint32_t numLines);

private:
  uint32_t attackers;
  uint32_t defenders;
  uint32_t attackerVictories;
  uint32_t defenderVictories;
  uint32_t simulations;
  double percent;
  std::vector<node> turnOuts;
};

#endif // HACKATHON_RISKGAMESSIMULATOR_H
