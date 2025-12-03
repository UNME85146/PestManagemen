#pragma once
#include <string>

// 禁言行为类
class MuteBehavior
{
public:
    void Execute(const std::string& name, bool adminPrivileges);
};
