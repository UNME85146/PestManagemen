#pragma once
#include <string>

// 踢人行为类
class KickBehavior
{
public:
    void Execute(const std::string& name, bool adminPrivileges);
};
