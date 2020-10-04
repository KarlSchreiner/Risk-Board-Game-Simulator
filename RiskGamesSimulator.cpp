//
// Created by Karl on 10/3/2020.
//

#include "RiskGamesSimulator.h"
#include "iostream"
RiskGamesSimulator::RiskGamesSimulator(uint32_t numAttackers,
                                       uint32_t numDefenders,
                                       uint32_t numSimulations)
    : attackers(numAttackers), defenders(numDefenders), attackerVictories(0),
      defenderVictories(0), simulations(numSimulations) {
  runSimulation();
}
std::vector<node> RiskGamesSimulator::runSimulation() {
  for (int i = 0; i < simulations; ++i) {
    RiskGame gameObject(attackers, defenders);
    std::vector<short> result = gameObject.fullGameSimulation();
    if (result[0] == 0) {
      ++defenderVictories;
    } else {
      ++attackerVictories;
    }
    bool nodeExisted = false;
    for (node &j : turnOuts) {
      if (result[0] == j.attackers && result[1] == j.defenders) {
        ++j.num;
        nodeExisted = true;
      }
    }
    if (!nodeExisted) {
      turnOuts.emplace_back(result[0], result[1]);
    }
  }
  percent = double(attackerVictories) / simulations * 100;
  std::sort(turnOuts.begin(), turnOuts.end(), std::greater<node>());
  for (node &j : turnOuts) {
    j.num = (double)j.num / simulations * 100;
  }
  return turnOuts;
}
std::vector<node> RiskGamesSimulator::getVector() { return turnOuts; }
void RiskGamesSimulator::printOutcomes(uint32_t numLines) {
  for (int i = 0; i < numLines && i < turnOuts.size(); ++i) {
    std::cout << turnOuts[i].attackers << " attackers and "
              << turnOuts[i].defenders << " defenders has a " << turnOuts[i].num
              << "% chance of occurring! \n";
  }
}
double RiskGamesSimulator::getPercent() { return percent; }
