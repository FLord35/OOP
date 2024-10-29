#include "CTime.h"

CTime::CTime(unsigned inputHours, unsigned inputMinutes, unsigned inputSeconds)
{
	seconds = inputHours * SECONDS_IN_AN_HOUR + inputMinutes * SECONDS_IN_A_MINUTE + inputSeconds;

	if (IsTimeValid())
	{
		throw std::out_of_range(OUT_OF_RANGE_EXCEPTION_MESSAGE);
	}
}

CTime::CTime(unsigned timeStamp)
{
	seconds = timeStamp;

	if (IsTimeValid())
	{
		throw std::out_of_range(OUT_OF_RANGE_EXCEPTION_MESSAGE);
	}
}

unsigned CTime::GetHours() const
{
	return seconds / SECONDS_IN_AN_HOUR;
}

unsigned CTime::GetMinutes() const
{
	return seconds / SECONDS_IN_A_MINUTE;
}

unsigned CTime::GetSeconds() const
{
	return seconds;
}

CTime& CTime::operator++()
{
	seconds++;

	if (!IsTimeValid())
	{
		seconds = 0;
	}

	return *this;
}

CTime& CTime::operator--()
{
	seconds--;

	if (!IsTimeValid())
	{
		seconds = SECONDS_IN_A_DAY;
	}

	return *this;
}

CTime CTime::operator++(int)
{
	CTime temp = *this;
	++*this;
	return temp;
}

CTime CTime::operator--(int)
{
	CTime temp = *this;
	--*this;
	return temp;
}

CTime CTime::operator+(const CTime& time)
{
	int temp = seconds + time.GetSeconds();

	if (!IsTimeValid(temp))
	{
		temp = temp - SECONDS_IN_A_DAY - 1;
	}

	CTime tempTime(temp);

	return tempTime;
}

CTime CTime::operator-(const CTime& time)
{
	int temp = seconds + time.GetSeconds();

	if (!IsTimeValid(temp))
	{
		temp = temp + SECONDS_IN_A_DAY + 1;
	}

	CTime tempTime(temp);

	return tempTime;
}

CTime& CTime::operator+=(const CTime& time)
{
	*this = *this + time;

	return *this;
}

CTime& CTime::operator-=(const CTime& time)
{
	*this = *this - time;

	return *this;
}

CTime CTime::operator*(const int& number)
{
	int temp = seconds * number;

	CTime tempTime(temp);

	return tempTime;
}

CTime operator*(const int& number, const CTime& time)
{
	int temp = time.GetSeconds() * number;

	return temp;
}

int CTime::operator/(const CTime& time)
{
	int temp = seconds / time.GetSeconds();

	return temp;
}

CTime CTime::operator/(const int& number)
{
	int temp = seconds / number;

	CTime tempTime(temp);

	return tempTime;
}

CTime& CTime::operator*=(const int& time)
{
	*this = *this * time;

	return *this;
}

CTime& CTime::operator/=(const int& time)
{
	*this = *this / time;

	return *this;
}

bool CTime::operator==(const CTime& time) const
{
	if (GetSeconds() == time.GetSeconds())
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool CTime::operator!=(const CTime& time) const
{
	return !(*this == time);
}

bool CTime::operator>(const CTime& time) const
{
	return !(*this <= time);
}

bool CTime::operator<(const CTime& time) const
{
	return !(*this >= time);
}

bool CTime::operator>=(const CTime& time) const
{
	if (GetSeconds() >= time.GetSeconds())
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool CTime::operator<=(const CTime& time) const
{
	if (GetSeconds() <= time.GetSeconds())
	{
		return true;
	}
	else
	{
		return false;
	}
}

std::ostream& operator<<(std::ostream& outputStream, const CTime& time)
{
	unsigned tempHours = time.GetHours();
	unsigned tempMinutes = time.GetMinutes();
	unsigned tempSeconds = time.GetSeconds();

	outputStream << tempHours << OUTPUT_STREAM_SEPARATOR << tempMinutes << OUTPUT_STREAM_SEPARATOR << tempSeconds;

	return outputStream;
}

std::istream& operator>>(std::istream& inputStream, CTime& time)
{
	unsigned tempHours;
	unsigned tempMinutes;
	unsigned tempSeconds;
	char junk;

	inputStream >> tempHours >> junk >> tempMinutes >> junk >> tempSeconds;

	CTime tempTime(tempHours, tempMinutes, tempSeconds);

	if (tempTime.IsTimeValid())
	{
		time = tempTime;
	}

	return inputStream;
}

bool CTime::IsTimeValid()
{
	if (seconds > SECONDS_IN_A_DAY || seconds < 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool CTime::IsTimeValid(int time)
{
	if (time > SECONDS_IN_A_DAY || seconds < 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}