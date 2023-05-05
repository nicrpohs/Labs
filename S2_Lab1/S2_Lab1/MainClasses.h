#pragma once
#ifndef MAINCLASSES_H
#define MAINCLASSES_H
#include "BaseClasses.h"
namespace isp
{
	const unsigned char FioWidht = 40;//������ ������� FIO ��� ���������� ������
	const unsigned char GradeWidht = 5;//������ ������� FIO ��� ���������� ������
	const unsigned char OtherWidht = 12;//������ ������ ������� ��� ���������� ������
	const unsigned char tableWidht = FioWidht + GradeWidht +2* OtherWidht + 5;
	class Student :public Person
	{
	private:
		std::string gradebook;
		std::string group;
	public:
		//������������
		Student();
		Student(std::string surname, std::string name, std::string patronymic);
		Student(std::string surname, std::string name, std::string patronymic, std::string gradebook);
		Student(std::string surname, std::string name, std::string patronymic, std::string group, std::string gradebook);
		Student(const Student& s);
		//������������ ���������

		// �������
		std::string get_group();
		std::string get_gradebook();
		//C������
		void set_group(std::string group);
		void set_gradebook(std::string gradebook);
		void set_all(std::string surname, std::string name, std::string patronymic, std::string group, std::string gradebook);
		//��������������� ����������
		friend std::ostream& operator<<(std::ostream& os, const Student& t);
		friend std::istream& operator>>(std::istream& is, Student& t);
		bool operator==(const Student& s) const;
		Student& operator=(const Student& s);
	};

	class Tutor : public Person {
	private:
		std::string post;//���������
		std::string email;
	public:
		//�����������
		Tutor();
		Tutor(std::string surname, std::string name, std::string patronymic);
		Tutor(std::string name, std::string surname, std::string patronymic, std::string post, std::string email);
		const std::string get_post() const;
		const std::string get_email() const;
		const std::string to_string() const;
		void set_post(std::string post);
		void set_email(std::string email);
		friend std::ostream& operator<<(std::ostream& os, const Tutor& t);
		friend std::istream& operator>>(std::istream& is, Tutor& t);
		Tutor& operator=(const Tutor& t);
	};

	class GradeRecord {
	private:
		Student student;
		unsigned int grade;
	public:
		GradeRecord();
		GradeRecord(Student& student);
		GradeRecord(Student& student, int grade);
		const Student& get_student()const ;
		Student& get_student();
		int get_grade();
		void set_student(Student student);
		void set_grade(int grade);
		friend std::ostream& operator<<(std::ostream& os, const GradeRecord& g);
		friend std::istream& operator>>(std::istream& is, GradeRecord& g);
		GradeRecord& operator=(const GradeRecord& g);
	};

	class GradeRegister //�������� ���������
	{
	private:
		std::string university;
		std::string subject;
		Tutor  tutor;
		isp::Date date;
		GradeRecord* records;//������ ��� ������� �� ���������� � ��������
		static const unsigned int sizedelta = 3;
		unsigned int count;//����� ������� ���������
		unsigned int capacity;//������ �������
		const std::string FormTableCapHorLine() const;
		const std::string FormTableCap() const;
		
	public:
		GradeRegister();
		GradeRegister(unsigned int size);
		~GradeRegister();
		bool add(GradeRecord&);         // �������� ������ ��������� (���� ������ �� ������� - ���������)
		bool del(GradeRecord&);      // ������� ��������� ��������� 
		bool del(unsigned int strNum);      // ������� ������ ���������  �� ������ ������
		void set_grade(unsigned int strNum, unsigned int  grade);//���������� ������ ��� �������� � ��������� ������
		void set_grade(Student& student, unsigned int  grade);//���������� ������ ��� ���������� �������� 
		void set_university(std::string university);
		void set_subject(std::string subject);
		void set_tutor(Tutor& tutor);
		void set_date(isp::Date& date);
		std::string get_university();
		std::string get_subject();
		const Tutor get_tutor() const;
		const isp::Date get_date() const;
		friend std::ostream& operator<<(std::ostream& os, const GradeRegister& g);
		friend std::istream& operator>>(std::istream& is, GradeRegister& g);
		GradeRegister& operator=(const GradeRegister& g); //��������� ����� �����������?
	};

}
#endif MAINCLASSES_H