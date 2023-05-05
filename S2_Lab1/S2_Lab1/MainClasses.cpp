#/*include <iostream>
#include <iomanip>*/
#include "MainClasses.h"
//using namespace std;
namespace isp
{
#pragma region class Student
	
	//Конструкторы
	Student::Student() :Person()
	{
		//cout << this << " Student constructor()" << endl;
	}
	Student::Student(std::string surname, std::string name, std::string patronymic) :Person(surname, name, patronymic)
	{


	};
	Student::Student(std::string surname, std::string name, std::string patronymic, std::string gradebook) :Person(surname, name, patronymic)
	{
		this->gradebook = gradebook;
	}
	Student::Student(std::string surname, std::string name, std::string patronymic, std::string group, std::string gradebook) :Person(surname, name, patronymic)
	{
		this->gradebook = gradebook;
		this->group = group;

	}
	Student::Student(const Student& s) :Person(s)
	{
		//cout << "copy constructor student";
		this->group = s.group;
		this->gradebook = s.gradebook;
	}
	//Конструкторы окончание

	// Геттеры
	std::string Student::get_group()
	{
		return group;
	}
	std::string Student::get_gradebook()
	{
		return gradebook;
	}
	//Cеттеры
	void Student::set_group(std::string group)
	{
		this->group = group;
	}
	void Student::set_gradebook(std::string gradebook)
	{
		this->gradebook = gradebook;
	}
	void Student::set_all(std::string surname, std::string name, std::string patronymic, std::string group, std::string gradebook)
	{
		this->name = name;
		this->surname = surname;
		this->patronymic = patronymic;
		this->gradebook = gradebook;
		this->group = group;
	}
	//Окончание сеттеров

	//переопределение операторов

	bool Student::operator==(const Student& s) const
	{
		bool rez = false;
		if (this == &s) rez = true;//сам на себя
		if ((name == s.name) && (surname == s.surname) && (patronymic == s.patronymic) && (group == s.group) && (gradebook == s.gradebook)) rez = true;
		return rez;
	}
	Student& Student::operator=(const Student& s)
	{
		this->name = s.name;
		this->surname = s.surname;
		this->patronymic = s.patronymic;
		this->group = s.group;
		this->gradebook = s.gradebook;
		return *this;
	}

	std::ostream& operator<<(std::ostream& os, const Student& s)
	{
		//setw() Ширину строки минимальную, нужен инклюд iomanip
		os <<  "|"<<std::setw(FioWidht) << std::left << s.getFIO() << "|";
		os << std::setw(OtherWidht) << std::right << s.group << "|";
		os << std::setw(OtherWidht) << std::right << s.gradebook << "|";
		return os;

	}

	std::istream& operator>>(std::istream& is, Student& s)
	{
		std::cout << " Entering student..." << std::endl;
		std::cout << "  Surname:";
		is >> s.surname;
		std::cout << "  Name:";
		is >> s.name;
		std::cout << "  Patronymic:";
		is >> s.patronymic;
		std::cout << "  Group:";
		is >> s.group;
		std::cout << "  Gradebook:";
		is >> s.gradebook;
		return is;

	}

#pragma endregion class Student

#pragma region class Tutor
	
	Tutor::Tutor() :Person() {}
	Tutor::Tutor(std::string surname, std::string name, std::string patronymic) :Person(surname, name, patronymic) {}
	Tutor::Tutor(std::string surname, std::string name, std::string patronymic, std::string post, std::string email) :Person(surname, name, patronymic)
	{
		this->post = post;
		this->email = email;
	}
	const std::string Tutor::get_post() const
	{
		return post;
	}
	const std::string Tutor::get_email() const
	{
		return email;
	}
	const std::string Tutor::to_string() const
	{
		std::string rez = getFIO();
		if (post != "") rez += "\tpost: " + post;
		if (email != "") rez += "\temail: " + email;
		return rez;
	}
	void Tutor::set_post(std::string post)
	{
		this->post = post;
	}
	void Tutor::set_email(std::string email)
	{
		this->email = email;
	}
	Tutor& Tutor::operator=(const Tutor& t)
	{
		this->name = t.name;
		this->surname = t.surname;
		this->patronymic = t.patronymic;
		this->email = t.email;
		this->post = t.post;
		return *this;
	}
	std::ostream& operator<<(std::ostream& os, const Tutor& t)
	{
		os << t.to_string();

		return os;

	}
	std::istream& operator>>(std::istream& is, Tutor& t)
	{
		std::cout << " Entering tutor..." << std::endl;
		std::cout << "  Surname:";
		is >> t.surname;
		std::cout << "  Name:";
		is >> t.name;
		std::cout << "  Patronymic:";
		is >> t.patronymic;
		std::cout << "  Email:";
		is >> t.email;
		std::cout << "  Post:";
		is >> t.post;
		return is;

	}
#pragma endregion class Tutor

#pragma region class GradeRecord
	

	GradeRecord::GradeRecord()
	{

	}
	GradeRecord::GradeRecord(Student& student, int grade)
	{
		this->student = student;
		this->grade = grade;

	}
	GradeRecord::GradeRecord(Student& student)
	{
		this->student = student;
	}
	 Student& GradeRecord::get_student() 
	{
		return student;
	}
	int GradeRecord::get_grade()
	{
		return grade;
	}
	void GradeRecord::set_student(Student student)
	{
		this->student = student;
	}
	void GradeRecord::set_grade(int grade)
	{
		this->grade = grade;
	}
	GradeRecord& GradeRecord::operator=(const GradeRecord& g)
	{
		this->student = g.student;
		this->grade = g.grade;
		return *this;
	}
	std::ostream& operator<<(std::ostream& os, const GradeRecord& g)
	{
		char sp = ' ';
		os << g.student;
		if (g.grade > 0 && g.grade < 6)
			os << std::setw(GradeWidht) << std::right << g.grade << "|";
		else os << std::setw(GradeWidht) << std::right << sp<< '|';
		return os;

	}
	std::istream& operator>>(std::istream& is, GradeRecord& g)
	{
		int grade;
		std::cout << "New grade record: " << std::endl;
		is >> g.student;
		std::cout << " Enter grade:";
		is >> grade;

		if (grade > 0 && grade < 6)
			g.grade = grade;
		else grade = 0;
		return is;

	}
#pragma endregion class GradeRecord

#pragma region class GradeRegister
	
	GradeRegister::GradeRegister()
	{
		records = nullptr;
		count = 0;
		capacity = 0;

	}
	GradeRegister::GradeRegister(unsigned int capacity)
	{
		if(capacity>0)
		{ 
		records = new GradeRecord[capacity];
		this->capacity = capacity;
		this->count = 0;
		}
		else
		{
			records = nullptr;
			count = 0;
			capacity = 0;
		}
	}
	GradeRegister::~GradeRegister()
	{
		if (records != nullptr) delete[] records;
	}
	bool GradeRegister::add(GradeRecord& new_record)
	{
		if (capacity > count)
		{
			records[count] = new_record;
			count++;
		}
		else if(count)//записи есть, массив надо скопировать-расширить
		{
			capacity += sizedelta;
			GradeRecord* tmp = new GradeRecord[capacity];//в текущем масс. count элементов
			int i;
			for (i = 0; i < count; ++i) tmp[i] = records[i];
			count++;
			tmp[i] = new_record;
			delete[] records;
			//records = new GradeRecord[capacity];

			//for (i = 0; i < count; ++i) records[i]=tmp[i]  ;
			records = tmp;
			//delete[] tmp;
			

		}
		else
		{
			capacity += sizedelta;
			records = new GradeRecord[capacity];
			records[count] = new_record;
			++count;



		}
		
		return true;
	}

	void GradeRegister::set_university(std::string university)
	{
		this->university = university;
	}
	void GradeRegister::set_subject(std::string subject)
	{
		this->subject = subject;
	}
	void GradeRegister::set_tutor(Tutor& tutor)
	{
		this->tutor = tutor;
	}
	void GradeRegister::set_date(isp::Date& date)
	{
		this->date = date;
	}
	std::string GradeRegister::get_university()
	{
		return university;
	}
	std::string GradeRegister::get_subject()
	{
		return subject;
	}
	const Tutor GradeRegister::get_tutor() const
	{
		return tutor;
	}
	const isp::Date GradeRegister::get_date() const
	{
		return date;
	}
	std::istream& operator>>(std::istream& is, GradeRegister& g_register)
	{
		return is;
	}
	const std::string GradeRegister::FormTableCap() const
	{
		std::string title = "FIO";
		std::string rez = GradeRegister::FormTableCapHorLine()+"\n";
		
		return GradeRegister::FormTableCapHorLine();
	}
	const std::string GradeRegister::FormTableCapHorLine() const
	{
		
		std::string rez = "";
		for (int i = 0; i < tableWidht; ++i) rez += "-";
		return rez;
	}

	std::ostream& operator<<(std::ostream& os, const GradeRegister& g_reg)
	{
		std::string title = "FIO";
		os << std::endl << "\tGRADE REGISTER\n\n";
		os << "University: " << g_reg.university << std::endl;
		os << "Subject: " << g_reg.subject << std::endl;
		os << "Tutor: " << g_reg.tutor << std::endl;
		os << "Date: " << g_reg.date << std::endl;
		//Шапка таблицы
		os << g_reg.FormTableCapHorLine() << std::endl;
		os << "|" << std::setw(FioWidht) << std::left << title << "|";
		title = "Group";
		os << std::setw(OtherWidht) << std::right << title << "|";
		title = "Gradebook";
		os << std::setw(OtherWidht) << std::right << title << "|";
		title = "Grade";
		os << std::setw(GradeWidht) << std::right << title << "|" << std::endl;
		os << g_reg.FormTableCapHorLine() << std::endl;
		
		if (g_reg.records != nullptr)
		{
			for (unsigned int i = 0; i < g_reg.count; i++)
			{
				os << g_reg.records[i]<<std::endl;
				os << g_reg.FormTableCapHorLine() << std::endl;
			}
		}
		os << std::endl;
		os << "\t\t______________" << g_reg.get_tutor().getFIO()<<"\n\n";
		return os;
	}
#pragma endregion class GradeRegister
}