#include <algorithm>
#include "红温.h"

void 红温管理::设置(int& 红温值, int 新红温值)
{
    if (新红温值 >= 0) {
        红温值 = 新红温值;
    }
}

void 红温管理::增加(int& 红温值, int 数值)
{
    if (数值 > 0) {
        红温值 += 数值;
    }
}

void 红温管理::减少(int& 红温值, int 数值)
{
    if (数值 > 0) {
        红温值 = std::max(0, 红温值 - 数值);
    }
}
