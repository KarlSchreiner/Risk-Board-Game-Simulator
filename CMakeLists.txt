cmake_minimum_required(VERSION 3.17)
project(hackathon)

set(CMAKE_CXX_STANDARD 14)

add_executable(Hackathon RiskGameSimulatorDriver.cpp RiskGame.cpp RiskGame.h RiskGamesSimulator.cpp RiskGamesSimulator.h )