#include "BaseClasses.h"
using namespace std;
using namespace isp;

#pragma region class Date
	bool Date::DateIsCorrect(int day, int month, int year)
	{
		bool iscorrect = true;
		bool leap_year = ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
		if (day < 1 || month < 1 || year < 1 && day>31 && month>12) {
			iscorrect = false;
		}
		else {
			if (month == 2)
			{
				iscorrect = leap_year ? day <= 29 : day <= 28;
				
			}
			else if(month==4 || month == 6|| month == 9 || month == 11) iscorrect = day <= 30;
			else iscorrect = day <= 31;
		}
		/*	алгоритм проверки корректности*/
		return iscorrect;
	}

	//конструктор по умолчанию(без параметров)
Date::Date()
	{
		day = 0;
		month = 0;
		year = 0;
	}
	//конструктор
Date::Date(int day, int month, int year)
	{
		if (DateIsCorrect(day, month, year))
		{
			this->day = day;
			this->month = month;
			this->year = year;
		}
		else {


			this->day = 0;
			this->month = 0;
			this->year = 0;
		}
	}
	//сеттер 
	void Date::SetDate(int day, int month, int year)
	{
		if (DateIsCorrect(day, month, year))
		{
			this->day = day;
			this->month = month;
			this->year = year;
		}
		else {


			this->day = 0;
			this->month = 0;
			this->year = 0;
		}
	}
	//геттеры 
	int Date::GetDay()
	{
		return day;
	}
	int Date::GetMonth() {
		return month;
	}
	int Date::GetYear() {
		return year;
	}
	std::string Date::to_string() const
	{
		return std::to_string(day) + "." + std::to_string(month) + "." + std::to_string(year);
	}
	void Date::print_Date() {
		std::cout <<Date::to_string() << std::endl;
	}
	/* std::ostream& operator<<(std::ostream& os, const Date& d);
	 std::istream& operator>>(std::istream& is, Date& d);*/
	Date& Date:: operator=(const Date& d)
	{
		/*this->day = d.day;
		this->month = d.month;
		this->year = d.year;
		return *this;*/
		return this->assign(d);
	}

	
	Date& Date::assign(const Date& d)
	{
		this->day = d.day;
		this->month = d.month;
		this->year = d.year;
		return *this;
	};
	
	void  Date::dispose() {

	};

	int Date::cmp(const Date& d)
	{
		int rez;
		if (this->day == d.day && this->month == d.month && this->year == d.year)
			rez = 0;
		else
		{
			if (year < d.year)
				rez = -1;
			else if (year > d.year)
				rez = 1;
			else {
				if (month < d.month)
					rez = -1;
				else if (month > d.month)
					rez = 1;
				else {
					if (day < d.day)
						rez = -1;
					else if (day > d.day)
						rez = 1;
				}
			}

		}
		return rez;
	}
	bool Date::operator==(const Date& d)
	{
		return cmp(d)==0;
	}
	bool Date::operator<(const Date& d)
	{
		return cmp(d) < 0;
	}
	bool Date::operator>(const Date& d)
	{
		return cmp(d) > 0;
	}
std::ostream& isp::operator<<(std::ostream& os, const Date& date)
{

	return os << date.to_string();
}

std::istream& isp::operator>>(std::istream& is, Date& d)
{
	return is >> d.day >> d.month >> d.year;

}

#pragma endregion class Date

#pragma region class Person



Person::Person() :Person("", "", "") {};
Person::Person(string surname, string name, string patronymic)
{
	//cout << this << " Person constructor(string name)" << endl;
	this->name = name;
	this->surname = surname;
	this->patronymic = patronymic;
};

Person::Person(const Person& p)
{
	//cout << this << "  copy constructor" << endl;
	this->name = p.name;
	this->surname = p.surname;
	this->patronymic = p.patronymic;

};
Person::~Person()
{
	//cout << this << "  destructor" << endl;

}

const string Person::getFIO() const
{
	return this->surname + " " + this->name + " " + this->patronymic;
}

void Person::setFIO(string surname, string name, string patronymic)
{
	//cout << this << " Person constructor(string name)" << endl;
	this->name = name;
	this->surname = surname;
	this->patronymic = patronymic;
};
Person& Person::operator=(const Person& p)
{
	this->name = p.name;
	this->surname = p.surname;
	this->patronymic = p.patronymic;
	return *this;
}

ostream& operator<<(ostream& os, const Person& p)
{
	return os << p.surname << " " << p.name << " " << p.patronymic;

}

istream& operator>>(istream& is, Person& p)
{
	return is >> p.surname >> p.name >> p.patronymic;

}

#pragma endregion
