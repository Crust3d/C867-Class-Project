#include <iostream>
#include <string>
#include "roster.h"
#include "student.h"
#include "networkStudent.h"
#include "securityStudent.h"
#include "softwareStudent.h"

using std::string;
using std::cout;

Roster::Roster()
{
	this->maxSize = 0;
	this->lastIndex = -1;
	this->classRosterArray = nullptr;
}

Roster::Roster(int maxSize)
{
	this->maxSize = maxSize;
	this->lastIndex = -1;
	this->classRosterArray = new Student * [maxSize];
}

Student* Roster::getStudentIndex(int index)
{
	return classRosterArray[index];
};

void Roster::parseThenAdd(string dataRow)
{
	if (lastIndex < maxSize) {
		lastIndex++;
		Degree degreeProgram;
		if (dataRow.find("SECURITY") != string::npos) degreeProgram = SECURITY;
		else if (dataRow.find("NETWORK") != string::npos) degreeProgram = NETWORKING;
		else if (dataRow.find("SOFTWARE") != string::npos) degreeProgram = SOFTWARE;
		else
		{
			std::cerr << "ERROR INVALID DEGREE ENTRY.";
			exit(-1);
		}

		int rest = dataRow.find(","); //get studentID
		string sID = dataRow.substr(0, rest);

		int full = rest + 1; //get firstName
		rest = dataRow.find(",", full);
		string fName = dataRow.substr(full, rest - full);

		full = rest + 1; //get lastName
		rest = dataRow.find(",", full);
		string lName = dataRow.substr(full, rest - full);

		full = rest + 1; //get email
		rest = dataRow.find(",", full);
		string Email = dataRow.substr(full, rest - full);

		full = rest + 1; //get age
		rest = dataRow.find(",", full);
		int Age = stod(dataRow.substr(full, rest - full));

		full = rest + 1; //get numDays[0]
		rest = dataRow.find(",", full);
		double numDays0 = stod(dataRow.substr(full, rest - full));

		full = rest + 1; //get numDays[1]
		rest = dataRow.find(",", full);
		double numDays1 = stod(dataRow.substr(full, rest - full));

		full = rest + 1; //get numDays[2]
		rest = dataRow.find(",", full);
		double numDays2 = stod(dataRow.substr(full, rest - full));

		add(sID, fName, lName, Email, Age, numDays0, numDays1, numDays2, degreeProgram);
	}
	else
	{
		std::cerr << "ERROR, TOO MANY INPUT STRINGS.\n";
		exit(-1);
	}
}

void Roster::add(string studentID,
	string firstName,
	string lastName,
	string emailAddress,
	int age,
	int daysInCourse0,
	int daysInCourse1,
	int daysInCourse2,
	Degree program)
{
	double numDays[Student::numDaysArraySize];
	numDays[0] = daysInCourse0;
	numDays[1] = daysInCourse1;
	numDays[2] = daysInCourse2;
	if (program == SECURITY) classRosterArray[lastIndex] = new SecurityStudent(studentID, firstName, lastName, emailAddress, age, numDays, program);
	else if (program == NETWORKING) classRosterArray[lastIndex] = new NetworkStudent(studentID, firstName, lastName, emailAddress, age, numDays, program);
	else classRosterArray[lastIndex] = new SoftwareStudent(studentID, firstName, lastName, emailAddress, age, numDays, program);
}

void Roster::remove(string studentID)
{
	for (int i = 0; i <= lastIndex; i++) {
		if (classRosterArray[i]->getStudentID() == studentID )
		{
			delete this->classRosterArray[i];
			for (i; i < maxSize; i++) {
				classRosterArray[i] = classRosterArray[i + 1];
			}
			lastIndex--;

			cout << "Student Removed. Reprinting List:\n";

			printAll();
		}
		else if (i == lastIndex && classRosterArray[i]->getStudentID() != studentID)
		{ 
			std::cerr << "ERROR, STUDENT ID NOT FOUND.\n";
			//exit(-1);
		}
	}

}

void Roster::printAll()
{
	for (int i = 0; i <= lastIndex; i++) { classRosterArray[i]->print(); }
}

void Roster::printInvalidEmails() // must include '@' '.' and have no ' 'spaces.
{
	for (int i = 0; i <= lastIndex; i++)
	{
		bool valid = true;
		if (classRosterArray[i]->getEmail().find(" ") != string::npos ||
			classRosterArray[i]->getEmail().find("@" ) == string::npos ||
			classRosterArray[i]->getEmail().find(".") == string::npos)
		{
			valid = false;
			cout << classRosterArray[i]->getEmail() << "\n";
		}
		else { valid = true; }
	}
}

void Roster::printByDegreeProgram(int degreeProgram)
{
	for (int i = 0; i <= lastIndex; i++)
	{
		if (classRosterArray[i]->getDegreeProgram() == degreeProgram)
		{
			classRosterArray[i]->print();
		}
	}
}

void Roster::printAverageDaysInCourse(string studentID)
{
	for (int i = 0; i <= lastIndex; i++)
	{
		if (classRosterArray[i]->getStudentID() == studentID)
		{
			double avg[Student::numDaysArraySize];
			for (int j = 0; j < Student::numDaysArraySize; j++)
			{
				avg[j] = classRosterArray[i]->getNumDays(j);
			}
				cout << "Average days in course by student " << classRosterArray[i]->getStudentID()
					<< " was: " << (avg[0] + avg[1] + avg[2]) / 3 << "\n";
			
		}
	}
}

Roster::~Roster()
{
	for (int i = 0; i <= lastIndex; i++)
	{
		delete this->classRosterArray[i];
	}
	delete classRosterArray;
}



int main()
{
	cout << "C867 - Scripting and Programming - Applications" << "\n";
	cout << "C++" << "\n";
	cout << "Student ID: 000957010" << "\n";
	cout << "Christian Dewey" << "\n";

	int numStudents = 5;

	const string studentData[5] =
	{ "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	"A5,Christian,Dewey,cdewey2@wgu.edu,25,45,20,33,SOFTWARE" };

	Roster* classRoster = new Roster(numStudents);

	for (int i = 0; i < numStudents; i++)
	{
		classRoster->parseThenAdd(studentData[i]);
	}

	cout << "Printing Student Roster:\n";

	classRoster->printAll();

	cout << "Printing Invalid emails:\n";

	classRoster->printInvalidEmails();

	cout << "Average Days Spent on Each Course:\n";

	for (int i = 0; i < numStudents; i++)
	{
		classRoster->printAverageDaysInCourse(classRoster->getStudentIndex(i)->getStudentID());
	}

	cout << "Printing all SOFTWARE students:\n";

	classRoster->printByDegreeProgram(SOFTWARE);

	cout << "Removing Student A3.\n";

	classRoster->remove("A3");
	
	cout << "Removing Student A3.\n";

	classRoster->remove("A3");

	
	system("pause");
	return 0;
}