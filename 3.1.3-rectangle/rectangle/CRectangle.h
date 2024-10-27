#pragma once
class CRectangle
{
	public:
		CRectangle(int, int, int, int);

		void Move(int dx, int dy);
		void Scale(int sx, int sy);
		bool Intersect(CRectangle const& other);

		const int GetHeight()const;
		void SetHeight(int);

		const int GetWidth()const;
		void SetWidth(int);

		const int GetLeft()const;
		void SetLeft(int);

		const int GetTop()const;
		void SetTop(int);

		const int GetRight()const;
		void SetRight(int);

		const int GetBottom()const;
		void SetBottom(int);

		const int GetArea()const;
		const int GetPerimeter()const;

	private:
		int height = 0;
		int width = 0;
		int left = 0;
		int top = 0;
		int right = 0;
		int bottom = 0;
		int area = 0;
		int perimeter = 0;

		void RecalculateCoordinates();
		void RecalculateProperties();

		void RecalculateArea();
		void RecalculatePerimeter();
};

