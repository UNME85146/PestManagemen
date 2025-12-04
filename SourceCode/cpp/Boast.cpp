#include <iostream>
#include "../header/Boast.h"

// 方法功能：执行吹牛行为
// 参数：
//   - name: 进行吹牛行为的角色名称
// 返回值：无
void BoastBehavior::Execute(const std::string& name)
{
    // 输出吹牛行为的执行信息
    std::cout << "【吹牛行为】" << name << " 开始吹牛，夸大自己的经历..." << std::endl;
}
