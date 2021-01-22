/**
 *@author Karl Schreiner
 *Email:karl.f.schreiner@vanderbilt.edu
 *Last Changed: 1/22/2021
 * @brief Simulates one battle outcome between X attackers and Y defenders.
 */

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

    /**
     * Initializes the RiskGame for a specific match up ie x attackers vs y
     * defenders.
     * @param attackers The desired number of attackers to simulate
     * @param defenders The desired number of defenders to simulate
     */
    RiskGame(uint32_t attackers, uint32_t defenders);
    /**
     * @brief Simulates one outcome of attackers and defenders.
     * The object is spent after as numAttackers and numDefenders will be
     * changed to the final result of the battle.
     * @return returns a vector with the first value corresponding to the attacker
     * outcome and the second defender outcome.
     */
    std::vector<short> fullGameSimulation();

private:
    /**
     *
     * @param numDice to be rolled
     * @return a greater sorted dice roll vector of size numDice
     */
    std::vector<short> getDiceRoll(uint32_t numDice);
    void simulateOneRound();
};

#endif // HACKATHON_RISKGAME_H
