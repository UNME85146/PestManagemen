#include <iostream>
#include "吹牛.h"

void 吹牛行为::执行(const std::string& 名字)
{
    std::cout << "【吹牛行为】" << 名字 << " 开始吹牛，夸大自己的经历..." << std::endl;
}
