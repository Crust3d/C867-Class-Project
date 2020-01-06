#pragma once
#include <string>
#include "degree.h"
#include "student.h"

class SoftwareStudent : public Student
{
public:
	SoftwareStudent();
	SoftwareStudent(
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

	~SoftwareStudent();
};