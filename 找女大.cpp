#include <iostream>
#include "找女大.h"

void 找女大行为::执行(const std::string& 名字)
{
    std::cout << "【找女大行为】" << 名字 << " 开始寻找女大学生..." << std::endl;
    std::cout << "【找女大行为】" << 名字 << " 正在浏览社交平台..." << std::endl;
    std::cout << "【找女大行为】" << 名字 << " 找到了心仪的女大学生！" << std::endl;
}
