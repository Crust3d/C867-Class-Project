#include <iostream>
#include "student.h"


Student::Student()
{
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->age = 0;
	this->email = "";
	for (int i = 0; i < numDaysArraySize; i++) {
		this->numDays[i] = 0;
	}
}

Student::Student(
	string studentID,
	string firstName,
	string lastName,
	string email,
	int age,
	double numDays[])
{
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->age = age;
	this->email = email;
	for (int i = 0; i < numDaysArraySize; i++) {
		this->numDays[i] = numDays[i];
	}
}

//access
string Student::getStudentID() const {
	return studentID;
}

string Student::getFirstName() const {
	return firstName;
}

string Student::getLastName() const {
	return lastName;
}

int Student::getAge() const {
	return age;
}

string Student::getEmail() const {
	return email;
}

double Student::getNumDays(int nums) const {
	return numDays[nums];
}

//mutate
void Student::setStudentID(string studentID) {
	this->studentID = studentID;
}

void Student::setFirstName(string fristName) {
	this->firstName = firstName;
}

void Student::setLastName(string lastName) {
	this->lastName = lastName;
}

void Student::setEmail(string email) {
	this->email = email;
}

void Student::setAge(int age) {
	this->age = age;
}

void Student::setNumDays(double numDays[]) {
	for (int i = 0; i < numDaysArraySize; i++) {
		this->numDays[i] = numDays[i];
	}
}

void Student::print()
{
	std::cout << getStudentID() << "\t";
	std::cout << "First Name: " << getFirstName() << "\t";
	std::cout << "Last Name: " << getLastName() << "\t";
	//std::cout << getEmail() << "\t";
	std::cout << "Age: " << getAge() << "\t";

	std::cout << "daysInCourse: {";
	
	for (int i = 0; i < numDaysArraySize -1; i++)
	{
		std::cout << this->getNumDays(i) << ", ";
	}
	std::cout << this->getNumDays(numDaysArraySize-1) << "}" << "\t";
}

Student::~Student()
{

}