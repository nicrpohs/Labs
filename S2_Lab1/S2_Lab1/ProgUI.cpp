#include "ProgUI.h"
namespace isp
{
	ProgUI::ProgUI(GradeRegister* mGradeRegister)
	{
		this->mGradeRegister = mGradeRegister;
	}
	void ProgUI::ExecProgUI()
	{
		char KeyCode = 0;

		do
		{
			
			//выводим т.н. меню приложения
			PrintMenu();
			std::cout << *mGradeRegister << '\n';
			//std::cout << (int)KeyCode << '\n';
			std::cout << "Ваш выбор:";
			KeyCode = _getche();
			std::cout << std::endl;
			Sleep(100);
			
			switch (KeyCode)
			{

			case KC_DIG_1:
			{
				std::string unv;
				std::cout << "Учебное заведение: ";
				std::getline(std::cin, unv);
				mGradeRegister->set_university(unv);
			}
			break; 
			case KC_DIG_2:
			{
				std::string unv;
				
				std::cout << "Учебная дисциплина: ";
				std::getline(std::cin, unv);
				mGradeRegister->set_subject(unv);
			}
				break;
			case KC_DIG_3:
			{
				isp::Tutor t;
				std::cin >> t;
				mGradeRegister->set_tutor(t);
			}
				break;
			case KC_DIG_4:
			{
				
				isp::Date date;
				std::cin >> date;
				mGradeRegister->set_date(date);
			}
				break;
			case KC_DIG_5:
			{
				isp::GradeRecord record;
				std::cin >> record;
				mGradeRegister->add(record);
				
			}
				break;
			case KC_DIG_6:
			{
				unsigned int num = -1;
				std::cout << "Введите номер строки для удаления: ";
				std::cin >> num;
				bool done = true;
				done = mGradeRegister->del(num - 1);
				if (!done)
				{
					std::cout << "Нет строки с таким номером... ";
					//Sleep(1500);
				}
			}
				break;
			case KC_DIG_7:
			{
				unsigned int num = -1;
				std::cout << "Введите номер строки для изменения студента: ";
				std::cin >> num;
				if (num - 1 < 0 || num - 1 > mGradeRegister->Count())
					std::cout << "Нет строки с таким номером... ";
				else
				{
					GradeRecord& record = mGradeRegister->get_grade_record(num - 1);
					std::cout << "Введите студента: ";
					Student st;
					std::cin >> st;


					record.set_student(st);
				}
			}
				break;
			case KC_DIG_8:
			{
				unsigned int num = -1;
				std::cout << "Введите номер строки для изменения оценки: ";
				std::cin >> num;
				if(num-1<0|| num - 1> mGradeRegister->Count())
					std::cout << "Нет строки с таким номером... ";
				else
				{
					GradeRecord &record = mGradeRegister->get_grade_record(num - 1);
					std::cout << "Введите оценку: ";
					std::cin >> num;

					record.set_grade(num);
				}
				
			}
				break;
			};
			std::cin.clear();
			system("cls");
		} while (KeyCode != KC_ESC);

	}
	void ProgUI::PrintMenu()
	{
		std::cout << FormVenuCapHorLine('+') << std::endl;
		std::cout << "|" << std::setw(MenuWidht - 2) << std::left << " Лабораторная работа 'Зачетная ведомость' (исполнитель Пайков И.С. & Co)" << "|" << std::endl;
		std::cout << "|" << std::setw(MenuWidht - 2) << std::right << "(для выхода из программы нажмите клавишу 'ESCAPE'...) " << "|" << std::endl ;
		std::cout << FormVenuCapHorLine('+') << std::endl << std::endl << std::endl;
		
		std::cout << FormVenuCapHorLine('=') << std::endl;
		std::cout << "|" << std::setw(MenuWidht-2) << std::left << "     Для изменения данных зачетной ведомости нажмите одну из следующих клавиш:" << "|" << std::endl;
		std::cout << FormVenuCapHorLine() << std::endl;
		std::cout << "|" << std::setw(MenuColWidht) << std::left << " 1 - уч.заведение " << "|" << std::setw(MenuColWidht) << std::left << " 2 - дисциплина ";
		std::cout << "|" << std::setw(MenuColWidht) << std::left << " 3 - преподаватель " << "|" << std::setw(MenuColWidht) << std::left << " 4 - дата " << "|"<<std::endl;
		std::cout << FormVenuCapHorLine('=') << std::endl;
		
		std::cout << "|" << std::setw(MenuWidht - 2) << std::left << "          Операции с табличной частью ведомости (студенты, оценки):" << "|" << std::endl;
		std::cout << FormVenuCapHorLine() << std::endl;
		std::cout << "|" << std::setw(MenuColWidht) << std::left << " 5 - новая строка " << "|"<<std::setw(MenuColWidht) << std::left << " 6 - удалить строку ";
		std::cout << "|" << std::setw(MenuColWidht) << std::left << " 7-изменить студента" << "|" << std::setw(MenuColWidht) << std::left << " 8-изменить оценку " << "|" << std::endl;
		std::cout << FormVenuCapHorLine('=') << std::endl;
	}

	const std::string ProgUI::FormVenuCapHorLine(const char c) const
	{

		std::string rez = "";
		for (int i = 0; i < isp::MenuWidht; ++i) rez += c;
		return rez;
	}
}