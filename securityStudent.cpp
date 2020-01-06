#include <iostream>
#include "securityStudent.h"
#include "degree.h"

SecurityStudent::SecurityStudent() :Student()
{
	major = Degree::SECURITY;
}

SecurityStudent::SecurityStudent(
	string studentID,
	string firstName,
	string lastName,
	string email,
	int age,
	double numDays[],
	Degree degreeProgram) : Student(studentID, firstName, lastName, email, age, numDays)
{
	major = SECURITY;
}

Degree SecurityStudent::getDegreeProgram()
{
	return SECURITY;
}

void SecurityStudent::print()
{
	this->Student::print();
	std::cout << "SECURITY" << std::endl;
}

SecurityStudent::~SecurityStudent()
{
	Student::~Student();
}