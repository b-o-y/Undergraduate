/*
* Travis Henderson
* Date last modified: 17/12/23
*
* Date class: YY/MM/DD
*/

#ifndef DATE_H
#define DATE_H

class Date
{
	public:
		Date(); // Default no args constructor.
		Date(int year, int month, int day); // Constructor initializer.
		Date(const Date &other); // Copy constructor.

		// Getters and setters.
		void setDate(int year, int month, int day);
		void setYear(int year);
		void setMonth(int month);
		void setDay(int day);
		const int getYear();
		const int getMoneth();
		const int getDay();

		std::string toString(); // Print date.

		int equals(const Date &other); // Compares this to other.

	private:
		int year;
		int month;
		int day;
};
#endif
