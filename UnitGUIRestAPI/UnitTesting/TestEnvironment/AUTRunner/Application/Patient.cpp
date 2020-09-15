#include "Patient.h"

#include <time.h>
#include <iostream>
#include <stdlib.h>
/*!
 * @brief default constructor
 */
Patient::Patient():
	m_patientName(""),
	m_age(0),
	m_gender('N'),
	m_patientID("INVALID")
{
}
/*!
 * @brief default destructor
 */
Patient::~Patient()
{
}
/*!
 * @brief This function returns the patient name
 * @return the patient name
 */
 
std::string Patient::getPatientName()
{
	return m_patientName;
}

/*!
 * @brief This function sets the patient name
 * @param name patient name
 */
void Patient::setPatientName(std::string name)
{
	m_patientName = name;
}
/*!
 * @brief This function returns the age of patient
 * @param age is the patient age
 */
long Patient::getAge()
{
	return m_age;
}
/*!
 * @brief This function sets the age
 * @return patient age
 */
void Patient::setAge(long age)
{
	m_age = age;
}

/*!
 * @brief This function returns the gender of patient
 * @return the patient gender
 */
char Patient::getGender()
{
	return m_gender;
}
/*!
 * @brief This function returns the gender of patient
 * @param gender is the patient gender
 */
void Patient::setGender(char gender)
{
	m_gender = gender;
}
/*!
 * @brief This function returns the patient ID
 * @param ID is the patient
 */
std::string Patient::getPatientID()
{
	return m_patientID;
}

/*!
 * @brief This function generates a random patientID
 */
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
