/**
 *@author Karl Schreiner
 *Email:karl.f.schreiner@vanderbilt.edu
 *Last Changed: 1/22/2021
 * @brief Simulates outcomes between X attackers and Y defenders numSimulations
 *times and records the results in turnouts.
 *
 */

#include "RiskGamesSimulator.h"
#include "iostream"

RiskGamesSimulator::RiskGamesSimulator(uint32_t numAttackers,
                                       uint32_t numDefenders,
                                       uint32_t numSimulations)
        : attackers(numAttackers), defenders(numDefenders), attackerVictories(0),
          defenderVictories(0), numSimulations(numSimulations) {
    runSimulation();
}

void RiskGamesSimulator::runSimulation() {
    for (int i = 0; i < numSimulations; ++i) {
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
    attackerPercent = double(attackerVictories) / numSimulations * 100;
    std::sort(turnOuts.begin(), turnOuts.end(), std::greater<node>());
    for (node &j : turnOuts) {
        j.num = (double)j.num / numSimulations * 100;
    }
}

std::vector<node> RiskGamesSimulator::getTurnouts() { return turnOuts; }

double RiskGamesSimulator::getAttackerPercent() { return attackerPercent; }
