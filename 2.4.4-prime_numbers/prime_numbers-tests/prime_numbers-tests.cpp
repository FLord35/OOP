#include <iostream>
#define CATCH_CONFIG_MAIN
#include "..\..\catch.hpp"
#include "..\prime_numbers\prime_generator.h"

SCENARIO("Testing our program")
{
	WHEN("Upper bound is less than 2")
	{
		THEN("Throw exception")
		{
			REQUIRE_THROWS_WITH(GeneratePrimeNumbersSet(1), NUMBER_TOO_LOW_MESSAGE);
		}		
	}

	WHEN("Upper bound is more than MAX_UPPER_BOUND")
	{
		THEN("Throw exception")
		{
			REQUIRE_THROWS_WITH(GeneratePrimeNumbersSet(MAX_UPPER_BOUND + 1), NUMBER_TOO_LARGE_MESSAGE);
		}
	}

	WHEN("Upper bound is equal to 2")
	{
		THEN("Set of primes will have 1 element")
		{
			REQUIRE(GeneratePrimeNumbersSet(2).size() == 1);
		}
	}

	WHEN("Upper bound is equal to 30")
	{
		THEN("Set of primes will have 10 elements")
		{
			std::set<int> expectedPrimes = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29 };

			REQUIRE(GeneratePrimeNumbersSet(30).size() == 10);
			REQUIRE(GeneratePrimeNumbersSet(30) == expectedPrimes);
		}
	}

	WHEN("Upper bound is equal to 100 000 000")
	{
		THEN("Set of primes will have 5761455 elements")
		{
			REQUIRE(GeneratePrimeNumbersSet(100000000).size() == 5761455);
		}
	}
}