#include <iostream>
#include "networkStudent.h"
#include "degree.h"

NetworkStudent::NetworkStudent() :Student()
{
	major = Degree::NETWORKING;
}

NetworkStudent::NetworkStudent(
	string studentID,
	string firstName,
	string lastName,
	string email,
	int age,
	double numDays[],
	Degree degreeProgram) :Student(studentID, firstName, lastName, email, age, numDays)
{
	major = NETWORKING;
}

Degree NetworkStudent::getDegreeProgram()
{
	return NETWORKING;
}

void NetworkStudent::print()
{
	this->Student::print();
	std::cout << "NETWORKING" << std::endl;
}

NetworkStudent::~NetworkStudent()
{
	Student::~Student();
}