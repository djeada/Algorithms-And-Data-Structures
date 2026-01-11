#include "add_string_numbers.h"
#include "gtest/gtest.h"

TEST(AddStringNumbersTest, AddSimpleIntegers) {
    EXPECT_EQ(addStrings("12345", "67890"), "80235");
}

TEST(AddStringNumbersTest, AddWithCarry) {
    EXPECT_EQ(addStrings("999", "1"), "1000");
}

TEST(AddStringNumbersTest, AddZero) {
    EXPECT_EQ(addStrings("123", "0"), "123");
    EXPECT_EQ(addStrings("0", "456"), "456");
}

TEST(AddStringNumbersTest, AddSingleDigits) {
    EXPECT_EQ(addStrings("5", "7"), "12");
}

TEST(AddStringNumbersTest, AddDifferentLengths) {
    EXPECT_EQ(addStrings("1", "999"), "1000");
    EXPECT_EQ(addStrings("12345", "5"), "12350");
}

TEST(AddStringNumbersTest, AddSimpleFloats) {
    EXPECT_EQ(addStrings("123.45", "678.90"), "802.35");
}

TEST(AddStringNumbersTest, AddFloatWithDifferentDecimalPlaces) {
    EXPECT_EQ(addStrings("1.5", "2.25"), "3.75");
    EXPECT_EQ(addStrings("10.123", "0.7"), "10.823");
}

TEST(AddStringNumbersTest, AddIntegerAndFloat) {
    EXPECT_EQ(addStrings("10", "0.5"), "10.5");
    EXPECT_EQ(addStrings("1.25", "3"), "4.25");
}

TEST(AddStringNumbersTest, AddFloatsWithCarry) {
    EXPECT_EQ(addStrings("0.99", "0.01"), "1.00");
    EXPECT_EQ(addStrings("9.99", "0.01"), "10.00");
}

TEST(AddIntegerStringsTest, SimpleAddition) {
    EXPECT_EQ(addIntegerStrings("123", "456"), "579");
}

TEST(AddIntegerStringsTest, AddWithCarry) {
    EXPECT_EQ(addIntegerStrings("999", "1"), "1000");
}

TEST(AddIntegerStringsTest, AddDifferentLengths) {
    EXPECT_EQ(addIntegerStrings("1", "99999"), "100000");
}
