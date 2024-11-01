#include <iostream>
#include <sstream>
#define CATCH_CONFIG_MAIN
#include "..\..\catch.hpp"
#include "..\time\CTime.h"

SCENARIO("Creating an invalid CTime object")
{
	WHEN("CTime object is created with inputting negative hours")
	{
		THEN("We should get an exception")
		{
			CHECK_THROWS_WITH(CTime(-20, 20, 20), OUT_OF_RANGE_EXCEPTION_MESSAGE);
		}
	}

	WHEN("CTime object is created with inputting negative minutes")
	{
		THEN("Object adjusts its time, subtracting minutes")
		{
			CTime time(20, -20, 20);

			CHECK(time.GetHours() == 19);
			CHECK(time.GetMinutes() == 40);
			CHECK(time.GetSeconds() == 20);

			CHECK(time.GetTimestamp() == 70820);
		}
	}

	WHEN("CTime object is created with inputting too much negative minutes")
	{
		THEN("We should get an exception")
		{
			CHECK_THROWS_WITH(CTime(20, -2000000, 20), OUT_OF_RANGE_EXCEPTION_MESSAGE);
		}
	}

	WHEN("CTime object is created with inputting negative seconds")
	{
		THEN("Object adjusts its time, subtracting seconds")
		{
			CTime time(20, 20, -20);

			CHECK(time.GetHours() == 20);
			CHECK(time.GetMinutes() == 19);
			CHECK(time.GetSeconds() == 40);

			CHECK(time.GetTimestamp() == 73180);
		}
	}

	WHEN("CTime object is created with inputting too much negative seconds")
	{
		THEN("We should get an exception")
		{
			CHECK_THROWS_WITH(CTime(20, 20, -200000), OUT_OF_RANGE_EXCEPTION_MESSAGE);
		}
	}

	WHEN("CTime object is created with inputting too much hours")
	{
		THEN("We should get an exception")
		{
			CHECK_THROWS_WITH(CTime(200, 20, 20), OUT_OF_RANGE_EXCEPTION_MESSAGE);
		}
	}

	WHEN("CTime object is created with inputting too much minutes")
	{
		THEN("We should get an exception")
		{
			CHECK_THROWS_WITH(CTime(20, 20000, 20), OUT_OF_RANGE_EXCEPTION_MESSAGE);
		}
	}

	WHEN("CTime object is created with inputting a bit too much minutes")
	{
		THEN("Object adjusts its time, converting extra minutes")
		{
			CTime time(20, 200, 20);

			CHECK(time.GetHours() == 23);
			CHECK(time.GetMinutes() == 20);
			CHECK(time.GetSeconds() == 20);

			CHECK(time.GetTimestamp() == 84020);
		}
	}

	WHEN("CTime object is created with inputting too much seconds")
	{
		THEN("We should get an exception")
		{
			CHECK_THROWS_WITH(CTime(20, 20, 200000), OUT_OF_RANGE_EXCEPTION_MESSAGE);
		}
	}

	WHEN("CTime object is created with inputting a bit too much seconds")
	{
		THEN("Object adjusts its time, converting extra seconds")
		{
			CTime time(20, 20, 2000);

			CHECK(time.GetHours() == 20);
			CHECK(time.GetMinutes() == 53);
			CHECK(time.GetSeconds() == 20);

			CHECK(time.GetTimestamp() == 75200);
		}
	}

	WHEN("CTime object is created with inputting negative timestamp")
	{
		THEN("We should get an exception")
		{
			CHECK_THROWS_WITH(CTime(-74730), OUT_OF_RANGE_EXCEPTION_MESSAGE);
		}
	}

	WHEN("CTime object is created with inputting timestamp that is too big")
	{
		THEN("We should get an exception")
		{
			CHECK_THROWS_WITH(CTime(999999), OUT_OF_RANGE_EXCEPTION_MESSAGE);
		}
	}
}

SCENARIO("Creating a CTime object and testing its functions")
{
	WHEN("CTime object is created through inputting hours, minutes and seconds")
	{
		THEN("We can get its parameters")
		{
			CTime time(20, 45, 30);

			CHECK(time.GetHours() == 20);
			CHECK(time.GetMinutes() == 45);
			CHECK(time.GetSeconds() == 30);

			CHECK(time.GetTimestamp() == 74730);
		}
	}

	WHEN("CTime object is created through inputting seconds after midnight")
	{
		THEN("We can get its parameters")
		{
			CTime time(20, 45, 30);

			CHECK(time.GetHours() == 20);
			CHECK(time.GetMinutes() == 45);
			CHECK(time.GetSeconds() == 30);

			CHECK(time.GetTimestamp() == 74730);
		}
	}
}

SCENARIO("Creating a CTime object and testing its overloaded operators")
{
	//Postfix ++
	WHEN("Postfix ++ operator is applied")
	{
		THEN("The seconds will increase by 1")
		{
			CTime time(20, 45, 30);

			time++;

			CHECK(time.GetHours() == 20);
			CHECK(time.GetMinutes() == 45);
			CHECK(time.GetSeconds() == 31);

			CHECK(time.GetTimestamp() == 74731);
		}
	}

	WHEN("Postfix ++ operator is applied to a edge case CTime object")
	{
		THEN("The seconds will increase by 1, pushing the counter over the edge")
		{
			CTime time(23, 59, 59);

			time++;

			CHECK(time.GetHours() == 0);
			CHECK(time.GetMinutes() == 0);
			CHECK(time.GetSeconds() == 0);

			CHECK(time.GetTimestamp() == 0);
		}
	}

	//Postfix --
	WHEN("Postfix -- operator is applied")
	{
		THEN("The seconds will decrease by 1")
		{
			CTime time(20, 45, 30);

			time--;

			CHECK(time.GetHours() == 20);
			CHECK(time.GetMinutes() == 45);
			CHECK(time.GetSeconds() == 29);

			CHECK(time.GetTimestamp() == 74729);
		}
	}

	WHEN("Postfix -- operator is applied to a edge case CTime object")
	{
		THEN("The seconds will decrease by 1, pushing the counter over the edge")
		{
			CTime time(0, 0, 0);

			time--;

			CHECK(time.GetHours() == 23);
			CHECK(time.GetMinutes() == 59);
			CHECK(time.GetSeconds() == 59);

			CHECK(time.GetTimestamp() == 86399);
		}
	}

	//Prefix ++
	WHEN("Prefix ++ operator is applied")
	{
		THEN("The seconds will increase by 1")
		{
			CTime time(20, 45, 30);

			++time;

			CHECK(time.GetHours() == 20);
			CHECK(time.GetMinutes() == 45);
			CHECK(time.GetSeconds() == 31);

			CHECK(time.GetTimestamp() == 74731);
		}
	}

	WHEN("Prefix ++ operator is applied to a edge case CTime object")
	{
		THEN("The seconds will increase by 1, pushing the counter over the edge")
		{
			CTime time(23, 59, 59);

			++time;

			CHECK(time.GetHours() == 0);
			CHECK(time.GetMinutes() == 0);
			CHECK(time.GetSeconds() == 0);

			CHECK(time.GetTimestamp() == 0);
		}
	}

	//Postfix --
	WHEN("Prefix -- operator is applied")
	{
		THEN("The seconds will decrease by 1")
		{
			CTime time(20, 45, 30);

			--time;

			CHECK(time.GetHours() == 20);
			CHECK(time.GetMinutes() == 45);
			CHECK(time.GetSeconds() == 29);

			CHECK(time.GetTimestamp() == 74729);
		}
	}

	WHEN("Prefix -- operator is applied to a edge case CTime object")
	{
		THEN("The seconds will decrease by 1, pushing the counter over the edge")
		{
			CTime time(0, 0, 0);

			--time;

			CHECK(time.GetHours() == 23);
			CHECK(time.GetMinutes() == 59);
			CHECK(time.GetSeconds() == 59);

			CHECK(time.GetTimestamp() == 86399);
		}
	}

	//+
	WHEN("+ operator is applied")
	{
		THEN("Two CTime objects will add up")
		{
			CTime firstTime(20, 45, 30); //74730
			CTime secondTime(3, 10, 35); //11435

			CTime thirdTime = firstTime + secondTime;

			CHECK(thirdTime.GetHours() == 23);
			CHECK(thirdTime.GetMinutes() == 56);
			CHECK(thirdTime.GetSeconds() == 5);

			CHECK(thirdTime.GetTimestamp() == 86165);
		}
	}

	WHEN("+ operator is applied and the time goes over the edge")
	{
		THEN("Two CTime objects will add up and time will be recalculated to fit the 24-hour limit")
		{
			CTime firstTime(20, 45, 30); //74730
			CTime secondTime(13, 10, 35); //47435

			CTime thirdTime = firstTime + secondTime;

			CHECK(thirdTime.GetHours() == 9);
			CHECK(thirdTime.GetMinutes() == 56);
			CHECK(thirdTime.GetSeconds() == 5);

			CHECK(thirdTime.GetTimestamp() == 35765);
		}
	}

	//TASK CASE
	WHEN("+ operator is applied and the time goes over the edge")
	{
		THEN("Two CTime objects will add up and time will be recalculated to fit the 24-hour limit")
		{
			CTime firstTime(23, 59, 59); //86399
			CTime secondTime(0, 0, 3); //3

			CTime thirdTime = firstTime + secondTime;

			CHECK(thirdTime.GetHours() == 0);
			CHECK(thirdTime.GetMinutes() == 0);
			CHECK(thirdTime.GetSeconds() == 2);

			CHECK(thirdTime.GetTimestamp() == 2);
		}
	}

	//-
	WHEN("- operator is applied")
	{
		THEN("One object will be decreased from another")
		{
			CTime firstTime(20, 45, 30); //74730
			CTime secondTime(3, 10, 35); //11435

			CTime thirdTime = firstTime - secondTime;

			CHECK(thirdTime.GetHours() == 17);
			CHECK(thirdTime.GetMinutes() == 34);
			CHECK(thirdTime.GetSeconds() == 55);

			CHECK(thirdTime.GetTimestamp() == 63295);
		}
	}

	WHEN("- operator is applied and the time goes over the edge")
	{
		THEN("One object will be decreased from another and time will be recalculated to fit the 24-hour limit")
		{
			CTime firstTime(3, 10, 35); //11435
			CTime secondTime(20, 45, 30); //74730

			CTime thirdTime = firstTime - secondTime;

			CHECK(thirdTime.GetHours() == 6);
			CHECK(thirdTime.GetMinutes() == 25);
			CHECK(thirdTime.GetSeconds() == 5);

			CHECK(thirdTime.GetTimestamp() == 23105);
		}
	}

	//TASK CASE
	WHEN("- operator is applied and the time goes over the edge")
	{
		THEN("One object will be decreased from another and time will be recalculated to fit the 24-hour limit")
		{
			CTime firstTime(0, 0, 5); //5
			CTime secondTime(0, 0, 10); //10

			CTime thirdTime = firstTime - secondTime;

			CHECK(thirdTime.GetHours() == 23);
			CHECK(thirdTime.GetMinutes() == 59);
			CHECK(thirdTime.GetSeconds() == 55);

			CHECK(thirdTime.GetTimestamp() == 86395);
		}
	}

	//+=
	WHEN("+= operator is applied")
	{
		THEN("Two CTime objects will add up and the result will be written into the first one")
		{
			CTime firstTime(20, 45, 30); //74730
			CTime secondTime(3, 10, 35); //11435

			firstTime += secondTime;

			CHECK(firstTime.GetHours() == 23);
			CHECK(firstTime.GetMinutes() == 56);
			CHECK(firstTime.GetSeconds() == 5);

			CHECK(firstTime.GetTimestamp() == 86165);
		}
	}

	WHEN("+= operator is applied and the time goes over the edge")
	{
		THEN("Two CTime objects will add up and the result will be written into the first one while time is recalculated to fit the 24-hour limit")
		{
			CTime firstTime(20, 45, 30); //74730
			CTime secondTime(13, 10, 35); //47435

			firstTime += secondTime;

			CHECK(firstTime.GetHours() == 9);
			CHECK(firstTime.GetMinutes() == 56);
			CHECK(firstTime.GetSeconds() == 5);

			CHECK(firstTime.GetTimestamp() == 35765);
		}
	}

	//-
	WHEN("-= operator is applied")
	{
		THEN("One object will be decreased from another and the result will be written into the first one")
		{
			CTime firstTime(20, 45, 30); //74730
			CTime secondTime(3, 10, 35); //11435

			firstTime -= secondTime;

			CHECK(firstTime.GetHours() == 17);
			CHECK(firstTime.GetMinutes() == 34);
			CHECK(firstTime.GetSeconds() == 55);

			CHECK(firstTime.GetTimestamp() == 63295);
		}
	}

	WHEN("-= operator is applied and the time goes over the edge")
	{
		THEN("One object will be decreased from another and the result will be written into the first one while time is recalculated to fit the 24-hour limit")
		{
			CTime firstTime(3, 10, 35); //11435
			CTime secondTime(20, 45, 30); //74730

			firstTime -= secondTime;

			CHECK(firstTime.GetHours() == 6);
			CHECK(firstTime.GetMinutes() == 25);
			CHECK(firstTime.GetSeconds() == 5);

			CHECK(firstTime.GetTimestamp() == 23105);
		}
	}

	//*
	WHEN("* operator is applied to a CTime object")
	{
		THEN("CTime object will be multiplied by an integer")
		{
			CTime firstTime(3, 10, 35); //11435
			int number = 3;

			CTime secondTime = firstTime * number;

			CHECK(secondTime.GetHours() == 9);
			CHECK(secondTime.GetMinutes() == 31);
			CHECK(secondTime.GetSeconds() == 45);

			CHECK(secondTime.GetTimestamp() == 34305);
		}
	}

	WHEN("* operator is applied to a CTime object and the time goes over the edge")
	{
		THEN("CTime object will be multiplied by an integer and time will be recalculated to fit the 24-hour limit")
		{
			CTime firstTime(3, 10, 35); //11435
			int number = 10;

			CTime secondTime = firstTime * number;

			CHECK(secondTime.GetHours() == 7);
			CHECK(secondTime.GetMinutes() == 45);
			CHECK(secondTime.GetSeconds() == 50);

			CHECK(secondTime.GetTimestamp() == 27950);
		}
	}

	WHEN("* operator is applied to a CTime object and the time goes over the edge multiple times")
	{
		THEN("CTime object will be multiplied by an integer and time will be recalculated to fit the 24-hour limit")
		{
			CTime firstTime(20, 45, 30); //74730
			int number = 10;

			CTime secondTime = firstTime * number;

			CHECK(secondTime.GetHours() == 15);
			CHECK(secondTime.GetMinutes() == 35);
			CHECK(secondTime.GetSeconds() == 0);

			CHECK(secondTime.GetTimestamp() == 56100);
		}
	}

	WHEN("* operator is applied to a CTime object and the time goes over the edge (integer is negative)")
	{
		THEN("CTime object will be multiplied by an integer and time will be recalculated to fit the 24-hour limit")
		{
			CTime firstTime(3, 10, 35); //11435
			int number = -3;

			CTime secondTime = firstTime * number;

			CHECK(secondTime.GetHours() == 14);
			CHECK(secondTime.GetMinutes() == 28);
			CHECK(secondTime.GetSeconds() == 15);

			CHECK(secondTime.GetTimestamp() == 52095);
		}
	}

	WHEN("* operator is applied to a CTime object and the time goes over the negative edge multiple times")
	{
		THEN("CTime object will be multiplied by an integer and time will be recalculated to fit the 24-hour limit")
		{
			CTime firstTime(20, 45, 30); //74730
			int number = -10;

			CTime secondTime = firstTime * number;

			CHECK(secondTime.GetHours() == 8);
			CHECK(secondTime.GetMinutes() == 25);
			CHECK(secondTime.GetSeconds() == 0);

			CHECK(secondTime.GetTimestamp() == 30300);
		}
	}

	//* to an int
	WHEN("* operator is applied to an integer")
	{
		THEN("CTime object will be multiplied by an integer")
		{
			CTime firstTime(3, 10, 35); //11435
			int number = 3;

			CTime secondTime = number * firstTime;

			CHECK(secondTime.GetHours() == 9);
			CHECK(secondTime.GetMinutes() == 31);
			CHECK(secondTime.GetSeconds() == 45);

			CHECK(secondTime.GetTimestamp() == 34305);
		}
	}

	WHEN("* operator is applied to an integer and the time goes over the edge (integer is too big)")
	{
		THEN("CTime object will be multiplied by an integer and time will be recalculated to fit the 24-hour limit")
		{
			CTime firstTime(3, 10, 35); //11435
			int number = 10;

			CTime secondTime = number * firstTime;

			CHECK(secondTime.GetHours() == 7);
			CHECK(secondTime.GetMinutes() == 45);
			CHECK(secondTime.GetSeconds() == 50);

			CHECK(secondTime.GetTimestamp() == 27950);
		}
	}

	WHEN("* operator is applied to an integer and the time goes over the edge multiple times")
	{
		THEN("CTime object will be multiplied by an integer and time will be recalculated to fit the 24-hour limit")
		{
			CTime firstTime(20, 45, 30); //74730
			int number = 10;

			CTime secondTime = number * firstTime;

			CHECK(secondTime.GetHours() == 15);
			CHECK(secondTime.GetMinutes() == 35);
			CHECK(secondTime.GetSeconds() == 0);

			CHECK(secondTime.GetTimestamp() == 56100);
		}
	}

	WHEN("* operator is applied to an integer and the time goes over the edge (integer is negative)")
	{
		THEN("CTime object will be multiplied by an integer and time will be recalculated to fit the 24-hour limit")
		{
			CTime firstTime(3, 10, 35); //11435
			int number = -3;

			CTime secondTime = number * firstTime;

			CHECK(secondTime.GetHours() == 14);
			CHECK(secondTime.GetMinutes() == 28);
			CHECK(secondTime.GetSeconds() == 15);

			CHECK(secondTime.GetTimestamp() == 52095);
		}
	}

	WHEN("* operator is applied to an integer and the time goes over the negative edge multiple times")
	{
		THEN("CTime object will be multiplied by an integer and time will be recalculated to fit the 24-hour limit")
		{
			CTime firstTime(20, 45, 30); //74730
			int number = -10;

			CTime secondTime = number * firstTime;

			CHECK(secondTime.GetHours() == 8);
			CHECK(secondTime.GetMinutes() == 25);
			CHECK(secondTime.GetSeconds() == 0);

			CHECK(secondTime.GetTimestamp() == 30300);
		}
	}

	///
	WHEN("/ operator is applied with a CTime object as attribute")
	{
		THEN("One CTime object will be divided by another")
		{
			CTime firstTime(20, 45, 30); //74730
			CTime secondTime(3, 10, 35); //11435

			int result = firstTime / secondTime;

			CHECK(result == 6);

		}
	}

	WHEN("/ operator is applied with a CTime object as attribute and the second object's time is bigger")
	{
		THEN("One CTime object will be divided by another, the result will be 0")
		{
			CTime firstTime(3, 10, 35); //11435
			CTime secondTime(20, 45, 30); //74730

			int result = firstTime / secondTime;

			CHECK(result == 0);
		}
	}

	/// to an int
	WHEN("/ operator is applied with an integer as attribute")
	{
		THEN("One CTime object will be divided by another")
		{
			CTime firstTime(20, 45, 30); //74730
			int number = 3;

			CTime secondTime = firstTime / number;

			CHECK(secondTime.GetHours() == 6);
			CHECK(secondTime.GetMinutes() == 55);
			CHECK(secondTime.GetSeconds() == 10);

			CHECK(secondTime.GetTimestamp() == 24910);
		}
	}

	WHEN("/ operator is applied with an integer as attribute (integer is too big)")
	{
		THEN("One CTime object will be divided by another, the result will be 0")
		{
			CTime firstTime(20, 45, 30); //74730
			int number = 300000;

			CTime secondTime = firstTime / number;

			CHECK(secondTime.GetHours() == 0);
			CHECK(secondTime.GetMinutes() == 0);
			CHECK(secondTime.GetSeconds() == 0);

			CHECK(secondTime.GetTimestamp() == 0);
		}
	}

	WHEN("/ operator is applied with an integer as attribute (integer is negative)")
	{
		THEN("One CTime object will be divided by another, the result will be recalculated to fit the 24-hour limit")
		{
			CTime firstTime(20, 45, 30); //74730
			int number = -3;

			CTime secondTime = firstTime / number;

			CHECK(secondTime.GetHours() == 17);
			CHECK(secondTime.GetMinutes() == 4);
			CHECK(secondTime.GetSeconds() == 50);

			CHECK(secondTime.GetTimestamp() == 61490);
		}
	}

	WHEN("/ operator is applied with an integer as attribute (integer is zero)")
	{
		THEN("One CTime object will be divided by another, the result will be 0")
		{
			CTime firstTime(20, 45, 30); //74730
			int number = 0;

			CTime secondTime;

			CHECK_THROWS_WITH(secondTime = firstTime / number, DIVISION_BY_ZERO_EXCEPTION_MESSAGE);
		}
	}

	//*=
	WHEN("*= operator is applied")
	{
		THEN("CTime object will be multiplied by an integer")
		{
			CTime time(3, 10, 35); //11435
			int number = 3;

			time *= number;

			CHECK(time.GetHours() == 9);
			CHECK(time.GetMinutes() == 31);
			CHECK(time.GetSeconds() == 45);

			CHECK(time.GetTimestamp() == 34305);
		}
	}

	WHEN("*= operator is applied and the time goes over the edge")
	{
		THEN("CTime object will be multiplied by an integer and time will be recalculated to fit the 24-hour limit")
		{
			CTime time(3, 10, 35); //11435
			int number = 10;

			time *= number;

			CHECK(time.GetHours() == 7);
			CHECK(time.GetMinutes() == 45);
			CHECK(time.GetSeconds() == 50);

			CHECK(time.GetTimestamp() == 27950);
		}
	}

	WHEN("*= operator is applied to an integer and the time goes over the edge multiple times")
	{
		THEN("CTime object will be multiplied by an integer and time will be recalculated to fit the 24-hour limit")
		{
			CTime time(20, 45, 30); //74730
			int number = 10;

			time *= number;

			CHECK(time.GetHours() == 15);
			CHECK(time.GetMinutes() == 35);
			CHECK(time.GetSeconds() == 0);

			CHECK(time.GetTimestamp() == 56100);
		}
	}

	WHEN("*= operator is applied and the time goes over the edge (integer is negative)")
	{
		THEN("CTime object will be multiplied by an integer and time will be recalculated to fit the 24-hour limit")
		{
			CTime time(3, 10, 35); //11435
			int number = -3;

			time *= number;

			CHECK(time.GetHours() == 14);
			CHECK(time.GetMinutes() == 28);
			CHECK(time.GetSeconds() == 15);

			CHECK(time.GetTimestamp() == 52095);
		}
	}

	WHEN("* operator is applied to a CTime object and the time goes over the negative edge multiple times")
	{
		THEN("CTime object will be multiplied by an integer and time will be recalculated to fit the 24-hour limit")
		{
			CTime time(20, 45, 30); //74730
			int number = -10;

			time *= number;

			CHECK(time.GetHours() == 8);
			CHECK(time.GetMinutes() == 25);
			CHECK(time.GetSeconds() == 0);

			CHECK(time.GetTimestamp() == 30300);
		}
	}

	///=
	WHEN("/= operator is applied with an integer as attribute")
	{
		THEN("One CTime object will be divided by another")
		{
			CTime time(20, 45, 30); //74730
			int number = 3;

			time/= number;

			CHECK(time.GetHours() == 6);
			CHECK(time.GetMinutes() == 55);
			CHECK(time.GetSeconds() == 10);

			CHECK(time.GetTimestamp() == 24910);
		}
	}

	WHEN("/= operator is applied with an integer as attribute (integer is too big)")
	{
		THEN("One CTime object will be divided by another, the result will be 0")
		{
			CTime time(20, 45, 30); //74730
			int number = 300000;

			time /= number;

			CHECK(time.GetHours() == 0);
			CHECK(time.GetMinutes() == 0);
			CHECK(time.GetSeconds() == 0);

			CHECK(time.GetTimestamp() == 0);
		}
	}

	WHEN("/= operator is applied with an integer as attribute (integer is negative)")
	{
		THEN("One CTime object will be divided by another, the result will be 0")
		{
			CTime time(20, 45, 30); //74730
			int number = -3;

			time /= number;

			CHECK(time.GetHours() == 17);
			CHECK(time.GetMinutes() == 4);
			CHECK(time.GetSeconds() == 50);

			CHECK(time.GetTimestamp() == 61490);
		}
	}

	WHEN("/ operator is applied with an integer as attribute (integer is zero)")
	{
		THEN("One CTime object will be divided by another, the result will be 0")
		{
			CTime time(20, 45, 30); //74730
			int number = 0;

			CHECK_THROWS_WITH(time /= number, DIVISION_BY_ZERO_EXCEPTION_MESSAGE);
		}
	}

	//<<
	WHEN("<< operator is applied")
	{
		THEN("CTime object will be outputted into output")
		{
			CTime time(20, 45, 30); //74730
			std::ostringstream outStream;

			outStream << time;

			CHECK(outStream.str() == "20:45:30");
		}
	}

	//>>
	WHEN(">> operator is applied")
	{
		THEN("CTime object will be created based on input data")
		{
			CTime time;
			std::istringstream inStream("20:45:30"); //74730

			inStream >> time;

			CHECK(time.GetHours() == 20);
			CHECK(time.GetMinutes() == 45);
			CHECK(time.GetSeconds() == 30);

			CHECK(time.GetTimestamp() == 74730);
		}
	}

	WHEN(">> operator is applied and the time is invalid (hour number is too big)")
	{
		THEN("CTime object will be created based on input data")
		{
			CTime time;
			std::istringstream inStream("28:45:30");

			CHECK_THROWS_WITH(inStream >> time, OUT_OF_RANGE_EXCEPTION_MESSAGE);
		}
	}

	//Other variants of invalid declaration are basically following the first SCENARIO. Therefore i see no reason to duplicate them

	//==
	WHEN("== operator is applied to equal CTime objects")
	{
		THEN("Operator will return 'true'")
		{
			CTime firstTime(20, 45, 30); //74730
			CTime secondTime(20, 45, 30); //74730

			CHECK(firstTime == secondTime);

		}
	}

	WHEN("== operator is applied to unequal CTime objects")
	{
		THEN("Operator will return 'false'")
		{
			CTime firstTime(20, 45, 30); //74730
			CTime secondTime(3, 10, 35); //11435

			CHECK(!(firstTime == secondTime));

		}
	}

	//!=
	WHEN("!= operator is applied to unequal CTime objects")
	{
		THEN("Operator will return 'true'")
		{
			CTime firstTime(20, 45, 30); //74730
			CTime secondTime(3, 10, 35); //11435

			CHECK(firstTime != secondTime);

		}
	}

	WHEN("!= operator is applied to equal CTime objects")
	{
		THEN("Operator will return 'false'")
		{
			CTime firstTime(20, 45, 30); //74730
			CTime secondTime(20, 45, 30); //74730

			CHECK(!(firstTime != secondTime));

		}
	}

	//>
	WHEN("> operator is applied, first CTime object is bigger than the second")
	{
		THEN("Operator will return 'true'")
		{
			CTime firstTime(20, 45, 30); //74730
			CTime secondTime(3, 10, 35); //11435

			CHECK(firstTime > secondTime);

		}
	}

	WHEN("> operator is applied, both CTime objects are equal")
	{
		THEN("Operator will return 'false'")
		{
			CTime firstTime(3, 10, 35); //11435
			CTime secondTime(3, 10, 35); //11435

			CHECK(!(firstTime > secondTime));

		}
	}

	WHEN("> operator is applied, second CTime object is bigger than the first")
	{
		THEN("Operator will return 'false'")
		{
			CTime firstTime(3, 10, 35); //11435
			CTime secondTime(20, 45, 30); //74730

			CHECK(!(firstTime > secondTime));

		}
	}

	//<
	WHEN("< operator is applied, second CTime object is bigger than the first")
	{
		THEN("Operator will return 'true'")
		{
			CTime firstTime(3, 10, 35); //11435
			CTime secondTime(20, 45, 30); //74730

			CHECK(firstTime < secondTime);

		}
	}

	WHEN("< operator is applied, both CTime objects are equal")
	{
		THEN("Operator will return 'false'")
		{
			CTime firstTime(20, 45, 30); //74730
			CTime secondTime(20, 45, 30); //74730

			CHECK(!(firstTime < secondTime));

		}
	}

	WHEN("< operator is applied, first CTime object is bigger than the second")
	{
		THEN("Operator will return 'false'")
		{
			CTime firstTime(20, 45, 30); //74730
			CTime secondTime(3, 10, 35); //11435

			CHECK(!(firstTime < secondTime));

		}
	}

	//>=
	WHEN(">= operator is applied, first CTime object is bigger than the second")
	{
		THEN("Operator will return 'true'")
		{
			CTime firstTime(20, 45, 30); //74730
			CTime secondTime(3, 10, 35); //11435

			CHECK(firstTime >= secondTime);

		}
	}

	WHEN(">= operator is applied, both CTime objects are equal")
	{
		THEN("Operator will return 'true'")
		{
			CTime firstTime(20, 45, 30); //74730
			CTime secondTime(20, 45, 30); //74730

			CHECK(firstTime >= secondTime);

		}
	}

	WHEN(">= operator is applied, second CTime object is bigger than the first")
	{
		THEN("Operator will return 'false'")
		{
			CTime firstTime(3, 10, 35); //11435
			CTime secondTime(20, 45, 30); //74730

			CHECK(!(firstTime >= secondTime));

		}
	}

	//<=
	WHEN("<= operator is applied, second CTime object is bigger than the first")
	{
		THEN("Operator will return 'true'")
		{
			CTime firstTime(3, 10, 35); //11435
			CTime secondTime(20, 45, 30); //74730

			CHECK(firstTime <= secondTime);

		}
	}

	WHEN("<= operator is applied, both CTime objects are equal")
	{
		THEN("Operator will return 'true'")
		{
			CTime firstTime(3, 10, 35); //11435
			CTime secondTime(3, 10, 35); //11435

			CHECK(firstTime <= secondTime);

		}
	}

	WHEN("<= operator is applied, first CTime object is bigger than the second")
	{
		THEN("Operator will return 'false'")
		{
			CTime firstTime(20, 45, 30); //74730
			CTime secondTime(3, 10, 35); //11435

			CHECK(!(firstTime <= secondTime));

		}
	}
}
