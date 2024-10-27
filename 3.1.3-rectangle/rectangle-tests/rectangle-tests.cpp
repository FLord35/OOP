#include <iostream>
#define CATCH_CONFIG_MAIN
#include "..\..\catch.hpp"
#include "..\rectangle\CRectangle.h"

SCENARIO("Creating a rectangle and testing its functions")
{
	WHEN("Rectangle is created and initialised")
	{
		THEN("We can get its parameters")
		{
			CRectangle rectangle(1, 2, 3, 4);

			CHECK(rectangle.GetLeft() == 1);
			CHECK(rectangle.GetTop() == 2);
			CHECK(rectangle.GetWidth() == 3);
			CHECK(rectangle.GetHeight() == 4);

			CHECK(rectangle.GetRight() == 4);
			CHECK(rectangle.GetBottom() == 6);

			CHECK(rectangle.GetArea() == 12);
			CHECK(rectangle.GetPerimeter() == 14);
		}

		THEN("We can manually set parameters except area and perimeter")
		{
			CRectangle rectangle(1, 2, 3, 4);

			rectangle.SetLeft(10);
			CHECK(rectangle.GetLeft() == 10);

			rectangle.SetTop(8);
			CHECK(rectangle.GetTop() == 8);

			rectangle.SetWidth(12);
			CHECK(rectangle.GetWidth() == 12);

			rectangle.SetHeight(14);
			CHECK(rectangle.GetHeight() == 14);

			rectangle.SetRight(20);
			CHECK(rectangle.GetRight() == 20);

			rectangle.SetBottom(18);
			CHECK(rectangle.GetBottom() == 18);
		}

		THEN("Various parameters will be set to '0' if changed below '0' and some parameters will be recalculated to fit that")
		{
			CRectangle rectangle(1, 2, 3, 4);

			rectangle.SetRight(0);
			CHECK(rectangle.GetWidth() == 0);
			CHECK(rectangle.GetRight() == 1);

			rectangle.SetBottom(1);
			CHECK(rectangle.GetHeight() == 0);
			CHECK(rectangle.GetBottom() == 2);

			rectangle.SetWidth(-10);
			CHECK(rectangle.GetWidth() == 0);

			rectangle.SetHeight(-20);
			CHECK(rectangle.GetHeight() == 0);
		}

		THEN("Right and bottom coordinates are recalculated correctly when width and height are changed")
		{
			CRectangle rectangle(1, 2, 3, 4);

			rectangle.SetWidth(20);
			CHECK(rectangle.GetRight() == 21);

			rectangle.SetHeight(14);
			CHECK(rectangle.GetBottom() == 16);
		}

		THEN("Width and height are recalculated correctly when right and bottom coordinates are changed")
		{
			CRectangle rectangle(1, 2, 3, 4);

			rectangle.SetRight(20);
			CHECK(rectangle.GetWidth() == 19);

			rectangle.SetBottom(10);
			CHECK(rectangle.GetHeight() == 8);
		}

		THEN("Area and perimeter are dynamically recalculated every time the changes are made to the rectangle")
		{
			CRectangle rectangle(1, 2, 3, 4);

			CHECK(rectangle.GetArea() == 12);
			CHECK(rectangle.GetPerimeter() == 14);

			rectangle.SetRight(10);

			CHECK(rectangle.GetArea() == 36);
			CHECK(rectangle.GetPerimeter() == 26);

			rectangle.SetBottom(7);

			CHECK(rectangle.GetArea() == 45);
			CHECK(rectangle.GetPerimeter() == 28);
		}

		THEN("We can move it across some vector with height and width intact")
		{
			CRectangle rectangle(1, 2, 3, 4);

			rectangle.Move(-2, -4);

			CHECK(rectangle.GetLeft() == -2);
			CHECK(rectangle.GetTop() == -8);
			CHECK(rectangle.GetRight() == 1);
			CHECK(rectangle.GetBottom() == -4);
		}

		THEN("We can scale its width and height by some numbers")
		{
			CRectangle rectangle(1, 2, 3, 4);

			rectangle.Scale(2, 3);

			CHECK(rectangle.GetWidth() == 6);
			CHECK(rectangle.GetHeight() == 12);
		}
	}
}

SCENARIO("Creating two rectangles and testing intersection function")
{
	WHEN("Two rectangles are created and initialised with no intersection at all")
	{
		THEN("We can check if the intersection is present, the intersection rectangle will have null properties aside from left and top")
		{
			CRectangle firstRectangle(1, 2, 3, 4);
			CRectangle secondRectangle(20, 22, 3, 4);

			firstRectangle.Intersect(secondRectangle);

			CHECK(firstRectangle.GetLeft() == 1);
			CHECK(firstRectangle.GetTop() == 2);
			CHECK(firstRectangle.GetWidth() == 0);
			CHECK(firstRectangle.GetHeight() == 0);
		}
	}

	WHEN("Two rectangles are created and initialised with the one same corner")
	{
		THEN("We can check if the intersection is present, the intersection rectangle will have null properties aside from left and top")
		{
			CRectangle firstRectangle(1, 2, 3, 4);
			CRectangle secondRectangle(4, 6, 3, 4);

			firstRectangle.Intersect(secondRectangle);

			CHECK(firstRectangle.GetLeft() == 1);
			CHECK(firstRectangle.GetTop() == 2);
			CHECK(firstRectangle.GetWidth() == 0);
			CHECK(firstRectangle.GetHeight() == 0);
		}
	}

	WHEN("Two rectangles are created and initialised with the one same side")
	{
		THEN("We can check if the intersection is present, the intersection rectangle will have null properties aside from left and top")
		{
			CRectangle firstRectangle(1, 2, 3, 4);
			CRectangle secondRectangle(4, 2, 3, 4);

			firstRectangle.Intersect(secondRectangle);

			CHECK(firstRectangle.GetLeft() == 1);
			CHECK(firstRectangle.GetTop() == 2);
			CHECK(firstRectangle.GetWidth() == 0);
			CHECK(firstRectangle.GetHeight() == 0);
		}
	}

	WHEN("Two rectangles are created and initialised, second one completely resides inside the first")
	{
		THEN("We can check if the intersection is present, the intersection rectangle will have properties of the second rectangle")
		{
			CRectangle firstRectangle(1, 2, 6, 8);
			CRectangle secondRectangle(2, 3, 2, 2);

			firstRectangle.Intersect(secondRectangle);

			CHECK(firstRectangle.GetLeft() == 2);
			CHECK(firstRectangle.GetTop() == 3);
			CHECK(firstRectangle.GetWidth() == 2);
			CHECK(firstRectangle.GetHeight() == 2);
		}
	}

	WHEN("Two rectangles are created and initialised, first one completely resides inside the second")
	{
		THEN("We can check if the intersection is present, the intersection rectangle will have properties of the first rectangle")
		{
			CRectangle firstRectangle(2, 3, 2, 2);
			CRectangle secondRectangle(1, 2, 6, 8);

			firstRectangle.Intersect(secondRectangle);

			CHECK(firstRectangle.GetLeft() == 2);
			CHECK(firstRectangle.GetTop() == 3);
			CHECK(firstRectangle.GetWidth() == 2);
			CHECK(firstRectangle.GetHeight() == 2);
		}
	}

	WHEN("Two rectangles are created and initialised, only one corner of the second rectangle is inside the first and vice versa")
	{
		THEN("We can check if the intersection is present, the intersection rectangle will have specific properties")
		{
			CRectangle firstRectangle(1, 2, 3, 4);
			CRectangle secondRectangle(2, 3, 10, 12);

			firstRectangle.Intersect(secondRectangle);

			CHECK(firstRectangle.GetLeft() == 2);
			CHECK(firstRectangle.GetTop() == 3);
			CHECK(firstRectangle.GetWidth() == 2);
			CHECK(firstRectangle.GetHeight() == 3);
		}
	}

	WHEN("Two rectangles are created and initialised, two of the corners of the second rectangle are inside the first")
	{
		THEN("We can check if the intersection is present, the intersection rectangle will have specific properties")
		{
			CRectangle firstRectangle(1, 2, 10, 12);
			CRectangle secondRectangle(6, 4, 20, 4);

			firstRectangle.Intersect(secondRectangle);

			CHECK(firstRectangle.GetLeft() == 6);
			CHECK(firstRectangle.GetTop() == 4);
			CHECK(firstRectangle.GetWidth() == 5);
			CHECK(firstRectangle.GetHeight() == 4);
		}
	}

	WHEN("Two rectangles are created and initialised, two of the corners of the first rectangle are inside the second")
	{
		THEN("We can check if the intersection is present, the intersection rectangle will have specific properties")
		{
			CRectangle firstRectangle(6, 4, 20, 4);
			CRectangle secondRectangle(1, 2, 10, 12);

			firstRectangle.Intersect(secondRectangle);

			CHECK(firstRectangle.GetLeft() == 6);
			CHECK(firstRectangle.GetTop() == 4);
			CHECK(firstRectangle.GetWidth() == 5);
			CHECK(firstRectangle.GetHeight() == 4);
		}
	}

}

