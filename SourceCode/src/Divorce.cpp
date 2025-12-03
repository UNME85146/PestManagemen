#include <iostream>
#include "../header/Divorce.h"

// 方法功能：执行离婚行为
// 参数：
//   - name: 进行离婚行为的角色名称
// 功能：模拟离婚行为的完整过程
// 返回值：无
void DivorceBehavior::Execute(const std::string& name)
{
    std::cout << "【离婚行为】" << name << " 宣布离婚，结束了婚姻关系..." << std::endl;
    std::cout << "【离婚行为】" << name << " 正在处理财产分割..." << std::endl;
    std::cout << "【离婚行为】" << name << " 离婚手续办理完成！" << std::endl;
}
