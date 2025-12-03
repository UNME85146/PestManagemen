#include <iostream>
#include "禁言.h"

void 禁言行为::执行(const std::string& 名字, bool 管理员权限)
{
    if (!管理员权限) {
        std::cout << "【权限不足】" << 名字 << " 没有管理员权限，无法执行禁言操作！" << std::endl;
        return;
    }
    std::cout << "【系统警告】" << 名字 << " 已被禁言！" << std::endl;
}
