#pragma once
#include <string>
#include "../Application/Patient.h"
#include "../Application/Battery.h"
#include "../MathLib.h"

class Bot
{
	Battery m_batt;
	Patient m_patient;
	MathLibrary::Arithmetic m_arithmetic;
public:
	
	Bot();
	~Bot();

	std::string RunUnitTest(std::string testcase);

};

