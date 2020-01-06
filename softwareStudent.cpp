#include <iostream>
#include "softwareStudent.h"
#include "degree.h"

SoftwareStudent::SoftwareStudent() :Student()
{
	major = Degree::SOFTWARE;
}

SoftwareStudent::SoftwareStudent(
	string studentID,
	string firstName,
	string lastName,
	string email,
	int age,
	double numDays[],
	Degree degreeProgram) : Student(studentID, firstName, lastName, email, age, numDays)
{
	major = SOFTWARE;
}

Degree SoftwareStudent::getDegreeProgram()
{
	return SOFTWARE;
}

void SoftwareStudent::print()
{
	this->Student::print();
	std::cout << "SOFTWARE" << std::endl;
}

SoftwareStudent::~SoftwareStudent()
{
	Student::~Student();
}