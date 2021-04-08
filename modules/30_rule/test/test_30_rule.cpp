// Copyright 2021 Maksim Shagov

#include <gtest/gtest.h>

#include <tuple>
#include <vector>
#include "include/30_rule.h"

TEST(Maksim_Shagov_Cell_Auto, can_throw_ex_zero_size) {
    ASSERT_ANY_THROW(CellularAuto(0, 0));
}

TEST(Maksim_Shagov_Cell_Auto, can_throw_ex_zero_size_with_state) {
    vector<CellState> state;
    ASSERT_ANY_THROW(CellularAuto(0, 0, state));
}

TEST(Maksim_Shagov_Cell_Auto, can_create_cell_class) {
    ASSERT_NO_THROW(CellularAuto(1, 1));
}

TEST(Maksim_Shagov_Cell_Auto, can_create_cell_class_from_vector) {
    vector<CellState> state {dead, alive, dead};
    ASSERT_NO_THROW(CellularAuto(1, 1, state));
}

TEST(Maksim_Shagov_Cell_Auto, can_iterate_5_times) {
    vector<CellState> state {dead, alive, dead};
    CellularAuto automat(1, 3, state);
    ASSERT_NO_THROW(automat.iterate(5));
}

TEST(Maksim_Shagov_Cell_Auto, can_create_2_equal_auto) {
    vector<CellState> state {dead, dead, dead};
    CellularAuto automat(1, 3, state);
    CellularAuto automat2(1, 3, state);

    ASSERT_EQ(automat.get_state(), automat2.get_state());
}

TEST(Maksim_Shagov_Cell_Auto, can_use_001_rule) {
    vector<CellState> state {dead, dead, alive};
    CellularAuto automat(2, 3, state);
    automat.iterate(1);
    state = {dead, alive, dead};

    ASSERT_EQ(automat.get_state()[1], state);
}

TEST(Maksim_Shagov_Cell_Auto, can_use_010_rule) {
    vector<CellState> state {dead, alive, dead};
    CellularAuto automat(2, 3, state);
    automat.iterate(1);
    state = {dead, alive, dead};

    ASSERT_EQ(automat.get_state()[1], state);
}

TEST(Maksim_Shagov_Cell_Auto, can_use_011_rule) {
    vector<CellState> state {dead, alive, alive};
    CellularAuto automat(2, 3, state);
    automat.iterate(1);
    state = {dead, alive, dead};

    ASSERT_EQ(automat.get_state()[1], state);
}

TEST(Maksim_Shagov_Cell_Auto, can_use_100_rule) {
    vector<CellState> state {alive, dead, dead};
    CellularAuto automat(2, 3, state);
    automat.iterate(1);
    state = {dead, alive, dead};

    ASSERT_EQ(automat.get_state()[1], state);
}

TEST(Maksim_Shagov_Cell_Auto, can_use_111_rule) {
    vector<CellState> state {alive, alive, alive};
    CellularAuto automat(2, 3, state);
    automat.iterate(1);
    state = {dead, dead, dead};

    ASSERT_EQ(automat.get_state()[1], state);
}

TEST(Maksim_Shagov_Cell_Auto, classic_seq_for_rule_30) {
    vector<CellState> state {dead, dead, dead,
                             dead, alive, dead,
                             dead, dead, dead};
    CellularAuto automat(2, 9, state);
    automat.iterate(1);
    state[3] = alive;
    state[4] = alive;
    state[5] = alive;

    ASSERT_EQ(automat.get_state()[1], state);
}
