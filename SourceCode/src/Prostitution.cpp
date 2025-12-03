#include <iostream>
#include "../header/Prostitution.h"

// 方法功能：执行嫖娼行为
// 参数：
//   - name: 进行嫖娼行为的角色名称
// 功能：模拟嫖娼行为的完整过程
// 返回值：无
void ProstitutionBehavior::Execute(const std::string& name)
{
    std::cout << "【嫖娼行为】" << name << " 开始寻找嫖娼场所..." << std::endl;
    std::cout << "【嫖娼行为】" << name << " 正在联系相关人员..." << std::endl;
    std::cout << "【嫖娼行为】" << name << " 完成了嫖娼行为！" << std::endl;
}
