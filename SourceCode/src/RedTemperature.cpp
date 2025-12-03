#include <algorithm>
#include "../header/RedTemperature.h"

void RedTemperatureManager::setRedTemperature(uint16_t& old_redTemperature, int new_redTemperature)
{
    if (new_redTemperature >= 0) {
        old_redTemperature = new_redTemperature;
    }
}

void RedTemperatureManager::increaseRedTemperature(uint16_t& redTemperature, int num)
{
    if (num > 0) {
        redTemperature += num;
    }
}

void RedTemperatureManager::decreaseRedTemperature(uint16_t& redTemperature, int num)
{
    if (num > 0) {
        redTemperature = std::max(0, redTemperature - num);
    }
}
