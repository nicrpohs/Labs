#pragma once
#ifndef PROGUI_H
#define PROGUI_H
#include "MainClasses.h"
#include<conio.h>// для _getch()
#include "windows.h"
#include <string>
namespace isp
{
	const unsigned char MenuWidht = 85;
	const unsigned char MenuColWidht = 20;
	
	enum  KeyCodes
	{
		KC_ESC=27,
		KC_DIG_0 = 48,
		KC_DIG_1,
		KC_DIG_2,
		KC_DIG_3,
		KC_DIG_4,
		KC_DIG_5,
		KC_DIG_6,
		KC_DIG_7,
		KC_DIG_8,
		KC_DIG_9
	};
	
	class ProgUI
	{
	private:
		GradeRegister* mGradeRegister;
		void PrintMenu();
		const std::string FormVenuCapHorLine(const char c = '-') const;
	public:
		ProgUI(GradeRegister* mGradeRegister);
		void ExecProgUI();

	};
	
}
#endif