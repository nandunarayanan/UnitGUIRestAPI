#include "Battery.h"

Battery::Battery()
{

}

Battery::~Battery()
{

}

double Battery::getBatteryPercentage()
{
	return m_batteryPercentage;
}

void Battery::setBatteryPercentage(double percentage)
{
	m_batteryPercentage = percentage;
}

BATT Battery::getBatteryStatus()
{
	return m_batteryStatus;
}

void Battery::setBatteryStatus(BATT status)
{
	m_batteryStatus = status;
}