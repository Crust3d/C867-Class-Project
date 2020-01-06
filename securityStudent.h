#pragma once
#include <string>
#include "degree.h"
#include "student.h"

class SecurityStudent : public Student
{
public:
	SecurityStudent();
	SecurityStudent(
		string studentID,
		string firstName,
		string lastName,
		string email,
		int age,
		double numDays[],
		Degree degreeProgram
	);

	Degree getDegreeProgram();
	void print();

	~SecurityStudent();
};