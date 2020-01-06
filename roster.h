#pragma once
#include <iostream>
#include "student.h"

class Roster {
private:
	int lastIndex;
	int maxSize;
	Student** classRosterArray; //an array of pointers
public:
	Roster();
	Roster(int maxSize);

	Student* getStudentIndex(int index);
	void parseThenAdd(string datarow);
	void add(string studentID,
		string firstName,
		string lastName,
		string emailAddress,
		int age,
		int daysInCourse0,
		int daysInCourse1,
		int daysInCourse2,
		Degree program);
	void remove(string studentID);
	void printAll();
	void printInvalidEmails(); 
	void printByDegreeProgram(int degreeProgram);
	void printAverageDaysInCourse(string studentID);
	~Roster();
};