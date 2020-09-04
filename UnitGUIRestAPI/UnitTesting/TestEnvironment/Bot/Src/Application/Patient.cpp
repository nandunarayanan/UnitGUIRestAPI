#include "Patient.h"

#include <time.h>
#include <iostream>
#include <stdlib.h>

Patient::Patient():
	m_patientName(""),
	m_age(0),
	m_gender('N'),
	m_patientID("INVALID")
{
}

Patient::~Patient()
{
}

std::string Patient::getPatientName()
{
	return m_patientName;
}

void Patient::setPatientName(std::string name)
{
	m_patientName = name;
}

long Patient::getAge()
{
	return m_age;
}

void Patient::setAge(long age)
{
	m_age = age;
}

char Patient::getGender()
{
	return m_gender;
}

void Patient::setGender(char gender)
{
	m_gender = gender;
}

std::string Patient::getPatientID()
{
	return m_patientID;
}

void Patient::generatePatientID()
{
    srand(time(0));

    int len = 6;
    char valid[] = "1234567890ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char rand_array[250];
    const int l = 62;               // 62 is the length of string 'valid'

    for (int i = 0; i < len; ++i)
    {
        rand_array[i] = valid[rand() % l];
    }

    std::cout << "The Random Array is :\n" << rand_array;
}
