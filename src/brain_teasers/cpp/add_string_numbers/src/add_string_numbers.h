#pragma once

#include <string>

/**
 * Adds two numbers represented as strings.
 * Handles both integers and floating-point numbers.
 * 
 * @param s1 First number as string
 * @param s2 Second number as string
 * @return Sum of the two numbers as string
 */
std::string addStrings(const std::string& s1, const std::string& s2);

/**
 * Adds two non-negative integers represented as strings.
 * 
 * @param s1 First non-negative integer as string
 * @param s2 Second non-negative integer as string
 * @return Sum of the two integers as string
 */
std::string addIntegerStrings(const std::string& s1, const std::string& s2);
