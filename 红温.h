#pragma once

// 红温值管理类
class 红温管理
{
public:
    void 设置(int& 红温值, int 新红温值);
    void 增加(int& 红温值, int 数值);
    void 减少(int& 红温值, int 数值);
};
