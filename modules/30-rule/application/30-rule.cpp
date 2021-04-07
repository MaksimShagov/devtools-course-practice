// Copyright 2021 Maksim Shagov
#include "include/30-rule.h"

int main() {

    GameOfLife game(10,10);
    game.print(); //print initial configuration
    game.iterate(10); //or iterate(10) or how many steps you want
    game.print(); //print configuration at the end

    return 0;
}