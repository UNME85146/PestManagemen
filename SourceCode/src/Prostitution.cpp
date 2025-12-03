#include <iostream>

#include "../header/Prostitution.h"

void ProstitutionBehavior::Execute(const std::string& name)
{
    std::cout << "【嫖娼行为】" << name << " 开始寻找嫖娼场所..." << std::endl;
    std::cout << "【嫖娼行为】" << name << " 正在联系相关人员..." << std::endl;
    std::cout << "【嫖娼行为】" << name << " 完成了嫖娼行为！" << std::endl;
}
