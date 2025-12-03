#pragma once
#include <string>

// 禁言行为类
class MuteBehavior
{
public:
    // 方法功能：执行禁言行为
    // 参数：
    //   - name: 被禁言的角色名称
    //   - adminPrivileges: 操作者是否拥有管理员权限
    // 返回值：无
    void Execute(const std::string& name, bool adminPrivileges);
};
