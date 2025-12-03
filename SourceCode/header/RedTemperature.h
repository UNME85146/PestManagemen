#pragma once

// 红温值管理类
class RedTemperatureManager
{
public:
    void setRedTemperature(uint16_t& old_redTemperature, int new_redTemperature);
    void increaseRedTemperature(uint16_t& redTemperature, int num);
    void decreaseRedTemperature(uint16_t& redTemperature, int num);
};
