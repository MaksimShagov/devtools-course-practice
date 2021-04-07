// Copyright 2021 Maksim Shagov
#include "include/30-rule.h""

GameOfLife::GameOfLife(const unsigned int rows, const unsigned int cols) {
    this->rows = rows;
    this->cols = cols;
    initialize(rows, cols);
}

template<class T>
void resize(vector<vector<T>>& target, const unsigned int dx, const unsigned int dy) {
    target.resize(dx);
    for (unsigned int i = 0; i < dx; i++) {
        target[i].resize(dy);
    }
}

void GameOfLife::iterate(const unsigned int iterations) {
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
            }//end for r
            state[r + 1] = new_state;
        }//end for iteration
    }
}

    char state_to_char(const CellState state) {
        if (state == dead) {
            return ' ';
        }
        return '*';
    }

    void GameOfLife::print() const {
        for (unsigned int r = 0; r < state.size(); r++) {
            for (unsigned int c = 0; c < state[r].size(); c++) {
                std::cout << state_to_char(state[r][c]) << " ";
            }
            std::cout << std::endl;
        }
    }

    void GameOfLife::initialize(const unsigned int rows, const unsigned int cols) {
        state.resize(rows);
        for (unsigned int r = 0; r < rows; r++) {
            state[r].resize(cols);
            for (unsigned int c = 0; c < cols; c++) {
                state[r][c] = dead;
            }
        }

        state[0][cols/2] = alive;
    }

    CellState GameOfLife::rules(const int row, const int col) const
    {
        if (state[row][col - 1] == dead && state[row][col] == dead && state[row][col + 1] == alive) {
            return alive;
        } else
        if (state[row][col - 1] == dead && state[row][col] == alive && state[row][col + 1] == dead) {
            return alive;
        } else
        if (state[row][col - 1] == dead && state[row][col] == alive && state[row][col + 1] == alive) {
            return alive;
        }else
        if (state[row][col - 1] == alive && state[row][col] == dead && state[row][col + 1] == dead) {
            return alive;
        }
        return dead;
    }

