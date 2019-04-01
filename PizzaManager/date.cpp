/*
* Travis Henderson
* Date last modified: 17/12/23
*
* Date class: YY/MM/DD
* All months have up to 31 days in this implementation.
*/

#include <iostream>
#include "date.h"
#include <ctime>
#include <string>

// No args constructor, uses todays date.
Date::Date()
{
	time_t now = time(0); // Get time now.
	tm *ltm = localtime(&now);

	setYear(ltm->tm_year);
	setMonth(ltm->tm_mon);
	setDay(ltm->tm_mday);
}

// Constructor.
Date::Date(int y, int m, int d)
{
	setYear(y);
	setMonth(m);
	setDay(d);
}

// Copy constructor.
Date::Date(const Date &other)
{
	Date(other.getYear(), other.getMonth(), other.getDay());
}

// Change an existing date.
void Date::setDate(int y, int m, int d)
{
	setYear(y);
	setMonth(m);
	setDay(d);
}

void Date::setYear(int y)
{
	if (y >= 0)
		year = y;
	else
		std::cout << "Invalid input Date::setYear" << std::endl;
}

void Date::setMonth(int m)
{
	if (m >= 1 || m <= 12)
		month = m;
	else
		std::cout << "Invalid input Date::setMonth" << std::endl;
}

void Date::setDay(int d)
{
	if (d >= 1 || d <= 31)
		day = d;
	else
		std::cout << "Invalid input Date::setDay" << std::endl;
}

const int Date::getYear()
{
	return year;
}

const int Date::getMonth()
{
	return month;
}

const int Date::getDay()
{
	return day;
}

// Returns a string in YY/MM/DD format.
std::string Date::toString()
{
	return getYear() + "/" + getMonth() + "/" + getDay();
}

// Checks if two dates are equal.
int Date::equals(const Date &other)
{
	return this->year == other->year && this->month == other->month && this->day == other->day;
}
	
