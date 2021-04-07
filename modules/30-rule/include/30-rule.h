// Copyright 2021 Maksim Shagov

#ifndef MODULES_30_RULE_INCLUDE_30_RULE_H_
#define MODULES_30_RULE_INCLUDE_30_RULE_H_

#include <vector>
#include <iostream>
using std::vector;

enum CellState { //replacing your char* with CellState
    dead, alive
};

class CellularAuto {

public:

    CellularAuto(const unsigned int rows, const unsigned int cols);
    virtual ~CellularAuto() {};

    void iterate(const unsigned int iterations);
    void print() const;

private:
    vector<vector<CellState>> state;
    unsigned int cols = 0;
    unsigned int rows = 0;

    void initialize(const unsigned int rows, const unsigned int cols);
    void initialize(const unsigned int rows, const unsigned int cols, vector<CellState> init);
    CellState rules(const int row, const int col) const;
};

#endif  // MODULES_30_RULE_INCLUDE_30_RULE_H_