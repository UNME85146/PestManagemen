#pragma once

// 红温值管理类
class RedTemperatureManager
{
public:
    // 方法功能：设置红温值
    // 参数：
    //   - old_redTemperature: 原始红温值（引用类型，将被修改）
    //   - new_redTemperature: 新的红温值
    // 返回值：无
    void setRedTemperature(uint16_t& old_redTemperature, int new_redTemperature);

    // 方法功能：增加红温值
    // 参数：
    //   - redTemperature: 当前红温值（引用类型，将被修改）
    //   - num: 增加的红温值数量
    // 返回值：无
    void increaseRedTemperature(uint16_t& redTemperature, int num);

    // 方法功能：减少红温值
    // 参数：
    //   - redTemperature: 当前红温值（引用类型，将被修改）
    //   - num: 减少的红温值数量
    // 返回值：无
    void decreaseRedTemperature(uint16_t& redTemperature, int num);
};
