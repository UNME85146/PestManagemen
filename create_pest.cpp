#include <iostream>

#include "../header/Pest.h"

int main()
{
    std::cout << "=== 害虫管理系统测试 ===" << std::endl;

    // 1. 创建害虫对象
    std::cout << "\n1. 创建害虫对象：" << std::endl;
    std::vector<std::string> features = {"嘴硬", "思想顽固", "喜欢吹牛"};
    Pest pest1("害虫", features, 1);
    pest1.displayInfo();

    // 2. 测试获取方法
    std::cout << "\n2. 测试获取方法：" << std::endl;
    std::cout << "名字: " << pest1.getName() << std::endl;
    std::cout << "年龄: " << pest1.getAge() << std::endl;
    std::vector<std::string> features_data = pest1.getFeatures();
    std::cout << "特征数量: " << features_data.size() << std::endl;

    // 3. 测试设置方法
    std::cout << "\n3. 测试设置方法：" << std::endl;
    pest1.setName("害虫");
    pest1.setAge(50);
    pest1.displayInfo();

    // 4. 测试年龄管理
    std::cout << "\n4. 测试年龄管理：" << std::endl;
    pest1.increaseAge(1);
    std::cout << "增加1岁后，年龄: " << pest1.getAge() << std::endl;

    pest1.decreaseAge(1);
    std::cout << "减少1岁后，年龄: " << pest1.getAge() << std::endl;

    // 5. 测试行为方法
    std::cout << "\n5. 测试行为方法：" << std::endl;
    pest1.getFeatures();

    // 6. 测试红温值功能
    std::cout << "\n6. 测试红温值功能：" << std::endl;
    std::cout << "当前红温值: " << pest1.getRedTemperature() << std::endl;

    pest1.increaseRedTemperature(50);
    std::cout << "增加50后，红温值: " << pest1.getRedTemperature() << std::endl;
    pest1.displayInfo();

    pest1.increaseRedTemperature(60);
    std::cout << "\n增加60后，红温值: " << pest1.getRedTemperature() << std::endl;
    pest1.displayInfo();

    std::cout << "\n触发行为（红温值>100，应该触发禁言和踢人）：" << std::endl;
    pest1.behavior();

    // 7. 测试减少红温值
    std::cout << "\n7. 测试减少红温值：" << std::endl;
    pest1.increaseRedTemperature(50);
    std::cout << "减少50后，红温值: " << pest1.getRedTemperature() << std::endl;
    pest1.displayInfo();

    // 8. 测试加入QQ群功能（会自动触发建政和吹牛）
    std::cout << "\n8. 测试加入QQ群功能：" << std::endl;
    Pest pest2("pest2", {"爱建政", "爱吹牛"}, 2);
    pest2.joinGroupChat();

    // 9. 测试管理员权限功能
    std::cout << "\n9. 测试管理员权限功能：" << std::endl;
    std::cout << "当前管理员权限: " << (pest1.getAdminPrivileges() ? "是" : "否") << std::endl;

    // 测试没有管理员权限时，红温值>100无法执行禁言和踢人
    std::cout << "\n测试场景1：没有管理员权限，红温值>100：" << std::endl;
    pest1.increaseRedTemperature(60); // 红温值变为60
    pest1.increaseRedTemperature(50); // 红温值变为110
    pest1.behavior();

    // 授予管理员权限
    std::cout << "\n授予管理员权限：" << std::endl;
    pest1.setAdminPrivileges(true);
    pest1.displayInfo();

    // 测试有管理员权限时，红温值>100可以执行禁言和踢人
    std::cout << "\n测试场景2：有管理员权限，红温值>100：" << std::endl;
    pest1.behavior();

    // 测试单独调用禁言和踢人方法
    std::cout << "\n10. 测试单独调用禁言和踢人方法：" << std::endl;
    Pest pest3("pest3", {"普通群友"}, 1);
    std::cout << "pest3（无管理员权限）尝试禁言：" << std::endl;
    pest3.mute();
    std::cout << "pest3（无管理员权限）尝试踢人：" << std::endl;
    pest3.kick();

    pest3.setAdminPrivileges(true);
    std::cout << "\npest3（有管理员权限）尝试禁言：" << std::endl;
    pest3.mute();
    std::cout << "pest3（有管理员权限）尝试踢人：" << std::endl;
    pest3.kick();

    // 11. 测试离婚和找女大行为
    std::cout << "\n11. 测试离婚和找女大行为：" << std::endl;
    Pest pest4("pest4", {"爱离婚", "爱找女大"}, 3);
    std::cout << "测试离婚行为：" << std::endl;
    pest4.divorce();
    std::cout << "\n测试找女大行为：" << std::endl;
    pest4.findCollegeGirl();

    // 12. 测试嫖娼行为
    std::cout << "\n12. 测试嫖娼行为：" << std::endl;
    Pest pest5("pest5", {"爱嫖娼"}, 4);
    std::cout << "测试嫖娼行为：" << std::endl;
    pest5.prostitution();

    std::cout << "\n=== 生成害虫完毕 ===" << std::endl;

    return 0;
}
