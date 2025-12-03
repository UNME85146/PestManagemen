#include <iostream>

#include "../header/Boast.h"

void BoastBehavior::Execute(const std::string& name)
{
    std::cout << "【吹牛行为】" << name << " 开始吹牛，夸大自己的经历..." << std::endl;
}
