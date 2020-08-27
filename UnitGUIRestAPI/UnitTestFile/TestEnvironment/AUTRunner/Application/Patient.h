#pragma once

#include <string>
class Patient
{
private:
	std::string m_patientName;
	long m_age;
	char m_gender;
	std::string m_patientID;

public:
	Patient();
	~Patient();
	std::string getPatientName();
	void setPatientName(std::string name);
	long getAge();
	void setAge(long age);
	char getGender();
	void setGender(char gender);
	std::string getPatientID();
	void generatePatientID();
};

