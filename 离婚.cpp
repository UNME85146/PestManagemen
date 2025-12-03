#include <iostream>
#include "离婚.h"

void 离婚行为::执行(const std::string& 名字)
{
    std::cout << "【离婚行为】" << 名字 << " 宣布离婚，结束了婚姻关系..." << std::endl;
    std::cout << "【离婚行为】" << 名字 << " 正在处理财产分割..." << std::endl;
    std::cout << "【离婚行为】" << 名字 << " 离婚手续办理完成！" << std::endl;
}
