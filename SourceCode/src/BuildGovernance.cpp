#include <iostream>
#include "../header/BuildGovernance.h"

// 方法功能：执行建政行为
// 参数：
//   - name: 进行建政行为的角色名称
// 返回值：无
void BuildGovernanceBehavior::Execute(const std::string& name)
{
    std::cout << "【建政行为】" << name << " 开始建政，发表政治观点..." << std::endl;
}
