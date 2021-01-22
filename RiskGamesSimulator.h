/**
 *@author Karl Schreiner
 *Email:karl.f.schreiner@vanderbilt.edu
 *Last Changed: 1/22/2021
 * @brief Simulates outcomes between X attackers and Y defenders numSimulations
 *times and records the results in turnouts.
 */

#ifndef HACKATHON_RISKGAMESSIMULATOR_H
#define HACKATHON_RISKGAMESSIMULATOR_H

#include "RiskGame.h"
#include <fstream>

// allows for the sorting of possible outcomes by likelihood of occurrence
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
    /**
     * @brief Simulates numAttackers vs numDefenders numSimulations times and
     * records the results.
     * @param numAttackers
     * @param numDefenders
     * @param numSimulations
     */
    RiskGamesSimulator(uint32_t numAttackers, uint32_t numDefenders,
                       uint32_t numSimulations);
    /**
     * @return a vector of all possible outcomes sorted by likelihood of outcome
     */
    std::vector<node> getTurnouts();

    /**
     * @return The percent of the time that attackers win
     */
    double getAttackerPercent();

private:
    /**
     * runSimulation
     * @brief simulates battles of attackers and defenders numSimulation times.
     */
    void runSimulation();
    uint32_t attackers;
    uint32_t defenders;
    uint32_t attackerVictories;
    uint32_t defenderVictories;
    uint32_t numSimulations;
    double attackerPercent;
    /**
     * records all outcomes sorted by likelihood of occurence
     */
    std::vector<node> turnOuts;
};

#endif // HACKATHON_RISKGAMESSIMULATOR_H
