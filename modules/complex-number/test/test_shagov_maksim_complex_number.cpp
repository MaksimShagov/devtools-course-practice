// Copyright 2021 Maksim Shagov

#include <gtest/gtest.h>

#include <tuple>
#include "include/complex_number.h"

TEST(Shagov_Maksim_ComplexNumberTEST, Constructor) {
    ComplexNumber number;
    ASSERT_EQ(number.getRe(), 0);
    ASSERT_EQ(number.getIm(), 0);
}

TEST(Shagov_Maksim_ComplexNumberTEST, Operator_equals) {
    ComplexNumber number(13.7, -11.2);
    ComplexNumber number1 = number;

    ASSERT_EQ(number.getRe(), number1.getRe());
    ASSERT_EQ(number.getIm(), number1.getIm());
}

TEST(Shagov_Maksim_ComplexNumberTEST, Addition_test) {
    ComplexNumber number(1.0, -1.0);
    ComplexNumber number1(-1.0, 1.0);

    ComplexNumber add_number = number1 + number;

    ASSERT_EQ(add_number.getRe(), 0.0);
    ASSERT_EQ(add_number.getIm(), 0.0);
}

TEST(Shagov_Maksim_ComplexNumberTEST, No_equal_test) {
    ComplexNumber number(1.0, -1.0);
    ComplexNumber number1(-131.2, 13.8);

    ASSERT_NE(number, number1);
}
