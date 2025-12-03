// FindCollegeGirl.cpp
#include <iostream>
#include "../header/FindCollegeGirl.h"

// 方法功能：执行找女大学生行为
// 参数：
//   - name: 进行找女大学生行为的角色名称
// 功能：模拟寻找女大学生的完整过程
// 返回值：无
void FindCollegeGirlBehavior::Execute(const std::string& name)
{
    std::cout << "【找女大行为】" << name << " 开始寻找女大学生..." << std::endl;
    std::cout << "【找女大行为】" << name << " 正在浏览社交平台..." << std::endl;
    std::cout << "【找女大行为】" << name << " 找到了心仪的女大学生！" << std::endl;
}
