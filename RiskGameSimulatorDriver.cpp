/**
 *@author Karl Schreiner
 *Email:karl.f.schreiner@vanderbilt.edu
 *Last Changed: 1/22/2021
 * @brief Creates a .csv document which has recorded all possible permutations
 *up to 25 attackers and defenders in the format Attackers, Defenders,
 *AttackerWinPercentage, then Outcomes. Outcomes is formatted as "numAttackers
 *numDefenders numberOfOccurrences". Simulates each permutation 1 million times to
 * insure statistical accuracy.
 */
#include "RiskGamesSimulator.h"
#include <iostream>

int main() {
    std::ofstream testfile;
    testfile.open("RiskRawData.csv");
    if (!testfile.is_open()) {
        std::cout << "file failed to open";
    }
    testfile << "Attackers,Defenders,AttackerWinPercentage,Outcomes\n";

    uint32_t sizeTable = 25; // max num of attackers and defenders
    for (int i = sizeTable; i >= 1; --i) {
        for (int j = sizeTable; j >= 1; --j) {
            RiskGamesSimulator simulation(i, j, 1000000);
            testfile << i << "," << j << "," << simulation.getAttackerPercent()
                     << ",";
            std::vector<node> turnOuts = simulation.getTurnouts();
            for (auto &turnOut : turnOuts) {
                testfile << turnOut.attackers << " " << turnOut.defenders << " "
                         << turnOut.num << " ";
            }

            testfile << "\n";
        }
    }

    testfile.close();
    return 0;
}
