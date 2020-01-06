#pragma once
#include <string>
#include <iostream>
#include "degree.h"

using std::string;

class Student //Represents each student.
{
public:
	const static int numDaysArraySize = 3;

protected:
	string studentID;
	string firstName;
	string lastName;
	string email;
	int age;
	double numDays[numDaysArraySize];
	Degree major;

public:
	Student();
	Student(
		string studentID,
		string firstName,
		string lastName,
		string email,
		int age,
		double numDays[]);

	string getStudentID() const;
	string getFirstName() const;
	string getLastName() const;
	string getEmail() const;
	int getAge() const;
	double getNumDays(int numDays) const;

	void setStudentID(string studentID);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmail(string email);
	void setAge(int age);
	void setNumDays(double numDays[]);

	virtual Degree getDegreeProgram() = 0;
	virtual void print() = 0;

	~Student();
};