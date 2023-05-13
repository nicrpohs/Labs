#pragma once
#ifndef BASECLASSES_H
#define BASECLASSES_H
#include <iostream>
#include<string>
#include <iomanip>
namespace isp
{
	template <typename T>
	class IObject
	{
	public:
		virtual ~IObject() = default;
		virtual std::string to_string() const = 0;
		//virtual void swap(T&) = 0;
		virtual T& assign(const T&) = 0;
		//virtual T& copy() = 0;
		virtual void dispose() = 0;
		virtual int cmp(const T&) = 0;
	};



	class Date :protected isp::IObject<Date>
	{
	private:
		int day;
		int month;
		int year;
		bool DateIsCorrect(int day, int month, int year);

		 //заглушки для ненужных в этом классе функций
		 //void swap(Date& d);
		 Date& assign(const Date& d) ;
		 //Date& copy() ;
		 void dispose() ;
		 


	public:
		//конструктор по умолчанию(без параметров)
		Date();
		//конструктор
		Date(int day, int month, int year);
		//сеттер 
		void SetDate(int day, int month, int year);

		//геттеры 
		int GetDay();

		int GetMonth();
		int GetYear();


		void print_Date();
		std::string to_string() const;
		int cmp(const Date& d);//сравнение двух дат

		friend std::ostream& operator<<(std::ostream& os, const Date& d) ;
		friend std::istream& operator>>(std::istream& is, Date& d);
		bool operator==(const Date& d);
		bool operator<(const Date& d);
		bool operator>(const Date& d);
		Date& operator=(const Date& d);
	};
}

class Person
{
protected:
	std::string name;
	std::string surname;
	std::string patronymic;

public:
	Person();
	Person(std::string surname, std::string name, std::string patronymic);
	Person(const Person& p);
	~Person();
	const std::string getFIO() const
		;
	void setFIO(std::string surname, std::string name, std::string patronymic);
	//переопределение операторов
	Person& operator=(const Person& p);
	friend std::ostream& operator<<(std::ostream& os, const Person& p);
	friend std::istream& operator>>(std::istream& is, Person& p);
};


#endif // BASECLASSES_H

