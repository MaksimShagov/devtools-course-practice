// Copyright 2021 Maksim Shagov

#include "include/30_rule.h"
#include <vector>

CellularAuto::CellularAuto(const unsigned int rows, const unsigned int cols) {
    if (rows == 0 || cols == 0) {
        throw "Sizes must bee > 0";
    }
    this->rows = rows;
    this->cols = cols;

    state.resize(rows);
    for (unsigned int r = 0; r < rows; r++) {
        state[r].resize(cols);
        for (unsigned int c = 0; c < cols; c++) {
            state[r][c] = dead;
        }
    }
}

CellularAuto::CellularAuto(const unsigned int rows, const unsigned int cols,
                           const vector<CellState>& states) {
    if (rows == 0 || cols == 0) {
        throw "Sizes must bee > 0";
    }
    this->rows = rows;
    this->cols = cols;

    state.resize(rows);
    for (unsigned int r = 0; r < rows; r++) {
        state[r].resize(cols);
        for (unsigned int c = 0; c < cols; c++) {
            state[r][c] = dead;
        }
    }

    state[0] = states;
}

template<class T>
void resize(vector<vector<T>>& target, const unsigned int dx,
             const unsigned int dy) {
    target.resize(dx);
    for (unsigned int i = 0; i < dx; i++) {
        target[i].resize(dy);
    }
}

vector<vector<CellState>> CellularAuto::get_state() {
    return state;
}

void CellularAuto::iterate(const unsigned int iterations) {
    unsigned int rows = state.size();
    unsigned int cells = 0;
    if (rows != 0) {
        cells = state[0].size();
    }

    vector<CellState> new_state(cols);

    for (unsigned int iteration = 0; iteration < iterations; iteration++) {
        for (unsigned int r = 0; r < rows - 1; r++) {
            for (unsigned int c = 1; c < cells - 1; c++) {
                new_state[c] = rules(r, c);
            }
            state[r + 1] = new_state;
        }
    }
}

CellState CellularAuto::rules(const int row, const int col) const {
    if (state[row][col - 1] == dead && state[row][col] == dead &&
     state[row][col + 1] == alive) {
        return alive;
    } else if (state[row][col - 1] == dead && state[row][col] == alive &&
     state[row][col + 1] == dead) {
        return alive;
    } else if (state[row][col - 1] == dead && state[row][col] == alive &&
     state[row][col + 1] == alive) {
        return alive;
    } else if (state[row][col - 1] == alive && state[row][col] == dead &&
     state[row][col + 1] == dead) {
        return alive;
    }
    return dead;
}
