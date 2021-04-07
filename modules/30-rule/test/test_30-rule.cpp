// Copyright 2021 Maksim Shagov

#include <gtest/gtest.h>

#include <tuple>
#include "30-rule.h"

TEST(Default, Constructor) {
    
    ASSERT_EQ(1, 0);
}

typedef testing::TestWithParam<std::tuple<double, double> > Parametrized;
TEST_P(Parametrized, Constructor) {
    double real = std::get<0>(GetParam());
    double imag = std::get<1>(GetParam());
    ASSERT_EQ(1, real);
    ASSERT_EQ(1, imag);
}

INSTANTIATE_TEST_CASE_P(/**/, Parametrized, testing::Combine(
  testing::Values(1.0, 2.0),
  testing::Values(3.0, 4.0)
));
