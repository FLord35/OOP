#include "CRectangle.h"
#include "consts.h"

CRectangle::CRectangle(int initialLeft, int initialTop, int initialWidth, int initialHeight)
{
	SetLeft(initialLeft);
	SetTop(initialTop);
	SetWidth(initialWidth);
	SetHeight(initialHeight);
}

void CRectangle::Move(int dx, int dy)
{
	//Без initial переменных width и height могут быть пересчитаны в RecalculateProperties() и перенос пройдёт неверно
	int initialWidth = width;
	int initialHeight = height;

	SetLeft(left * dx);
	SetTop(top * dy);

	SetWidth(initialWidth);
	SetHeight(initialHeight);
}

void CRectangle::Scale(int sx, int sy)
{
	if (sx > 0 && sy > 0)
	{
		SetWidth(width * sx);
		SetHeight(height * sy);
	}
}

//Используемый метод проверки пересечения между объектами:
//https://code.tutsplus.com/collision-detection-using-the-separating-axis-theorem--gamedev-169t
bool CRectangle::Intersect(CRectangle const& other) 
{
	double firstHalfWidth = static_cast<double>(right - left) / 2;
	double firstHalfHeight = static_cast<double>(bottom - top) / 2;

	rct::DoubleCoordinates firstCenter = { left + firstHalfWidth, top + firstHalfHeight };

	double secondHalfWidth = static_cast<double>(other.right - other.left) / 2;
	double secondHalfHeight = static_cast<double>(other.bottom - other.top) / 2;

	rct::DoubleCoordinates secondCenter = { other.left + secondHalfWidth, other.top + secondHalfHeight };

	double lengthX = abs(firstCenter.x - secondCenter.x);
	double lengthY = abs(firstCenter.y - secondCenter.y);

	double gapX = lengthX - secondHalfWidth - firstHalfWidth;
	double gapY = lengthY - secondHalfHeight - firstHalfHeight;

	if (gapX < 0 && gapY < 0)
	{
		int newTop = std::max(top, other.top);
		int newBottom = std::min(bottom, other.bottom);
		int newLeft = std::max(left, other.left);
		int newRight = std::min(right, other.right);

		SetLeft(newLeft);
		SetTop(newTop);
		SetRight(newRight);
		SetBottom(newBottom);

		return true;
	}
	else
	{
		SetHeight(0);
		SetWidth(0);

		return false;
	}
}

const int CRectangle::GetHeight()const
{
	return height;
}

void CRectangle::SetHeight(int newHeight)
{
	if (newHeight > 0)
	{
		height = newHeight;
	}
	else
	{
		height = 0;
	}

	RecalculateCoordinates();
}

const int CRectangle::GetWidth()const
{
	return width;
}

void CRectangle::SetWidth(int newWidth)
{
	if (newWidth > 0)
	{
		width = newWidth;
	}
	else
	{
		width = 0;
	}

	RecalculateCoordinates();
}

const int CRectangle::GetLeft()const
{
	return left;
}

void CRectangle::SetLeft(int newLeft)
{
	left = newLeft;

	RecalculateProperties();
}

const int CRectangle::GetTop()const
{
	return top;
}

void CRectangle::SetTop(int newTop)
{
	top = newTop;

	RecalculateProperties();
}

const int CRectangle::GetRight()const
{
	return right;
}

void CRectangle::SetRight(int newRight)
{
	right = newRight;

	RecalculateProperties();
}

const int CRectangle::GetBottom()const
{
	return bottom;
}

void CRectangle::SetBottom(int newBottom)
{
	bottom = newBottom;

	RecalculateProperties();
}

const int CRectangle::GetArea()const
{
	return area;
}

const int CRectangle::GetPerimeter()const
{
	return perimeter;
}

void CRectangle::RecalculateCoordinates()
{
	right = left + width;
	bottom = top + height;

	RecalculateArea();
	RecalculatePerimeter();
}

void CRectangle::RecalculateProperties()
{
	width = right - left;
	if (width < 0)
	{
		width = 0;
		RecalculateCoordinates();
	}

	height = bottom - top;
	if (height < 0)
	{
		height = 0;
		RecalculateCoordinates();
	}

	RecalculateArea();
	RecalculatePerimeter();
}

void CRectangle::RecalculateArea()
{
	area = width * height;
}

void CRectangle::RecalculatePerimeter()
{
	perimeter = (width + height) * 2;
}
