#include <iostream>
#include "../header/Mute.h"

// 方法功能：执行禁言行为
// 参数：
//   - 名字: 被禁言的角色名称
//   - 管理员权限: 操作者是否拥有管理员权限
// 返回值：无
void MuteBehavior::Execute(const std::string& 名字, bool 管理员权限)
{
    // 检查是否拥有管理员权限
    if (!管理员权限)
    {
        // 没有管理员权限时输出警告信息
        std::cout << "【权限不足】" << 名字 << " 没有管理员权限，无法执行禁言操作！" << std::endl;
        return; // 结束方法执行
    }
    // 拥有管理员权限时执行禁言操作
    std::cout << "【系统警告】" << 名字 << " 已被禁言！" << std::endl;
}
