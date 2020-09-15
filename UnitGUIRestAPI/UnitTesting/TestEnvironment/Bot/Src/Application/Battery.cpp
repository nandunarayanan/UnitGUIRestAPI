#include "Battery.h"

/*!
 * @brief  default constructor
 */
Battery::Battery()
{

}

/*!
 * @brief default destructor
 */
Battery::~Battery()
{

}

/*!
 * @brief This function returns the current battery percentage
 * @return the current battery percentage
 */
double Battery::getBatteryPercentage()
{
    return m_batteryPercentage;
}

/*!
 * @brief This function sets the current battery percentage
 * @param current battery percentage
 */
void Battery::setBatteryPercentage(double percentage)
{
    m_batteryPercentage = percentage;
}

/*!
 * @brief This function returns the current battery status
 * @return current battery status
 */
BATT Battery::getBatteryStatus()
{
    return m_batteryStatus;
}

/*!
 * @brief This function sets the current battery status
 * @param current battery status
 */
void Battery::setBatteryStatus(BATT status)
{
    m_batteryStatus = status;
}
