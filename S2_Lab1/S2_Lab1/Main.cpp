#include "MainClasses.h"
using namespace std;
using namespace isp;
int main()
{
	GradeRecord GR;
	

	Student st("Paykov", "Ivan", "Serg", "1234", "w-12135");
	Student st1("Bonch-Bruevich", "Solomonsash", "OzyOglyevich","1234", "w-45678");
	Student st2("Usova", "Marina", "Batkovna", "1234", "x-87962");

	GR.set_student(st);
	GR.set_grade(5);
	
	
	/*cout << GR << endl;
	cout << GR1 << endl;*/
	
	GradeRegister G_register(10);
	isp::Date d(12, 12, 2012);
	G_register.set_date(d);
	Tutor t("Petrov", "Igor", "Alekseevich","assist","my@milo.yu");
	G_register.set_tutor(t);
	G_register.set_subject("matan");
	G_register.set_university("UNN");
	G_register.add(GR);
	
	GR.get_student().set_all("Bonch-Bruevich", "Solomonsash", "OzyOglyevich", "1234", "w-45678");
	GR.set_grade(5);
	G_register.add(GR);

	GR.get_student().set_all("Usova", "Marina", "Batkovna", "1234", "x-87962");
	GR.set_grade(5);
	G_register.add(GR);
	GR.get_student().set_all("Popova", "Anna", "Ivanovna", "1234", "x-58123");
	GR.set_grade(5);
	G_register.add(GR);
	cout << G_register;
	return 0;
}