// Copyright 2021 Maksim Shagov

#ifndef MODULES_30_RULE_INCLUDE_30_RULE_H_
#define MODULES_30_RULE_INCLUDE_30_RULE_H_

#include <vector>
#include <iostream>
using std::vector;

enum CellState { //replacing your char* with CellState
    dead, alive
};

class GameOfLife {

public:

    GameOfLife(const unsigned int rows, const unsigned int cols);
    virtual ~GameOfLife() {}; //can omit the virtual if no subclasses are guaranteed

    void iterate(const unsigned int iterations); //can do several steps at once, one step at a time is the assumed default
    void print() const;

private:
    vector<vector<CellState>> state;
    unsigned int cols = 0;
    unsigned int rows = 0;

    void initialize(const unsigned int rows, const unsigned int cols); //does the randomization
    CellState rules(const int row, const int col) const;
};

#endif  // MODULES_30_RULE_INCLUDE_30_RULE_H_