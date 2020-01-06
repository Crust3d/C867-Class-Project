#pragma once
#include <string>
#include "degree.h"
#include "student.h"

class NetworkStudent : public Student
{
public:
	NetworkStudent();
	NetworkStudent(
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

	~NetworkStudent();
};