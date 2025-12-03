#include <algorithm>
#include "../header/RedTemperature.h"

// 方法功能：设置红温值
// 参数：
//   - old_redTemperature: 原始红温值（引用类型，将被修改）
//   - new_redTemperature: 新的红温值
// 功能：只允许设置非负红温值
// 返回值：无
void RedTemperatureManager::setRedTemperature(uint16_t& old_redTemperature, int new_redTemperature)
{
    if (new_redTemperature >= 0)
    {
        old_redTemperature = new_redTemperature;
    }
}

// 方法功能：增加红温值
// 参数：
//   - redTemperature: 当前红温值（引用类型，将被修改）
//   - num: 增加的红温值数量
// 功能：只允许增加正数红温值
// 返回值：无
void RedTemperatureManager::increaseRedTemperature(uint16_t& redTemperature, int num)
{
    if (num > 0)
    {
        redTemperature += num;
    }
}

// 方法功能：减少红温值
// 参数：
//   - redTemperature: 当前红温值（引用类型，将被修改）
//   - num: 减少的红温值数量
// 功能：红温值不会低于0
// 返回值：无
void RedTemperatureManager::decreaseRedTemperature(uint16_t& redTemperature, int num)
{
    if (num > 0)
    {
        redTemperature = std::max(0, redTemperature - num);
    }
}
