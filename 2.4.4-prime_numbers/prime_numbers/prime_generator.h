#pragma once
#include <iostream>
#include <string>
#include <set>
#include <vector>

const std::string INVALID_ARGUMENTS_MESSAGE("Invalid arguments count");
const std::string USAGE_MESSAGE("Usage: prime_numbers.exe <upper bound>");

const int MAX_UPPER_BOUND = 100000000;

const std::string NUMBER_TOO_LOW_MESSAGE("Your upper boundary is too low, it should be greater than 1");
const std::string NUMBER_TOO_LARGE_MESSAGE("Your upper boundary is too large, it should be lower or equal to " + std::to_string(MAX_UPPER_BOUND));

const std::string QUANTITY_MESSAGE("Quantity: ");

void CheckUpperBound(int upperBound);

std::set<int> GeneratePrimeNumbersSet(int upperBound);

void OutputSet(std::set<int> set);