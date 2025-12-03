#include <iostream>

#include "../header/FindCollegeGirl.h"

void FindCollegeGirlBehavior::Execute(const std::string& name)
{
    std::cout << "【找女大行为】" << name << " 开始寻找女大学生..." << std::endl;
    std::cout << "【找女大行为】" << name << " 正在浏览社交平台..." << std::endl;
    std::cout << "【找女大行为】" << name << " 找到了心仪的女大学生！" << std::endl;
}
