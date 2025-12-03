#include <iostream>

#include "../header/Divorce.h"

void DivorceBehavior::Execute(const std::string& name)
{
    std::cout << "【离婚行为】" << name << " 宣布离婚，结束了婚姻关系..." << std::endl;
    std::cout << "【离婚行为】" << name << " 正在处理财产分割..." << std::endl;
    std::cout << "【离婚行为】" << name << " 离婚手续办理完成！" << std::endl;
}
