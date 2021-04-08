// Copyright 2021 Maksim Shagov
#include "include/30_rule.h"

int main() {
    CellularAuto game(10, 10);
    game.print();
    game.iterate(10);
    game.print();

    return 0;
}
