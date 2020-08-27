#pragma once

enum BATT
{
	BATT_WORKING,
	BATT_SERVICE,
	BATT_FAILURE
};

class Battery
{
private:
	double m_batteryPercentage;
	BATT m_batteryStatus;

public:
	Battery();
	~Battery();
	double getBatteryPercentage();
	void setBatteryPercentage(double percentage);
	BATT getBatteryStatus();
	void setBatteryStatus(BATT status);
};

