#pragma once
#include <string>
#include "../Application/Patient.h"
#include "../Application/Battery.h"
#include "../MathLib.h"

class Api
{
	Battery m_batt;
	Patient m_patient;
	MathLibrary::Arithmetic m_arithmetic;
public:
	
	Api();
	~Api();

	std::string Run(std::string testcase);

};

