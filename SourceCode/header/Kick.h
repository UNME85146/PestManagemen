#pragma once
#include <string>

// 踢人行为类
class KickBehavior
{
public:
    // 方法功能：执行踢人行为
    // 参数：
    //   - name: 被踢出的角色名称
    //   - adminPrivileges: 操作者是否拥有管理员权限
    // 返回值：无
    void Execute(const std::string& name, bool adminPrivileges);
};
