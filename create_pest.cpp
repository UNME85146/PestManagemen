#include <iostream>
#include <Windows.h>

#include "../header/Pest.h"

// 程序主函数
// 功能：害虫管理系统的测试程序，展示Pest类的各种功能
// 返回值：0表示程序正常结束
int main()
{
    // 输出程序标题
    std::cout << "=== 害虫管理系统测试 ===" << std::endl;

    // 1. 创建害虫对象
    std::cout << "\n1. 创建害虫对象：" << std::endl;
    // 初始化害虫特征列表
    std::vector<std::string> features = {"嘴硬", "思想顽固", "喜欢吹牛"};
    // 创建第一个害虫对象，传入名称、特征列表和年龄
    Pest pest1("害虫", features, 1);
    // 显示害虫的完整信息
    pest1.displayInfo();

    // 2. 测试获取方法
    std::cout << "\n2. 测试获取方法：" << std::endl;
    // 测试获取害虫名称
    std::cout << "名字: " << pest1.getName() << std::endl;
    // 测试获取害虫年龄
    std::cout << "年龄: " << pest1.getAge() << std::endl;
    // 测试获取害虫特征列表
    std::vector<std::string> features_data = pest1.getFeatures();
    std::cout << "特征数量: " << features_data.size() << std::endl;

    // 3. 测试设置方法
    std::cout << "\n3. 测试设置方法：" << std::endl;
    // 测试设置害虫名称
    pest1.setName("害虫");
    // 测试设置害虫年龄
    pest1.setAge(50);
    // 显示修改后的害虫信息
    pest1.displayInfo();

    // 4. 测试年龄管理
    std::cout << "\n4. 测试年龄管理：" << std::endl;
    // 测试增加年龄
    pest1.increaseAge(1);
    std::cout << "增加1岁后，年龄: " << pest1.getAge() << std::endl;

    // 测试减少年龄
    pest1.decreaseAge(1);
    std::cout << "减少1岁后，年龄: " << pest1.getAge() << std::endl;

    // 5. 测试行为方法
    std::cout << "\n5. 测试行为方法：" << std::endl;
    // 获取特征列表
    pest1.getFeatures();

    // 6. 测试红温值功能
    std::cout << "\n6. 测试红温值功能：" << std::endl;
    // 获取当前红温值
    std::cout << "当前红温值: " << pest1.getRedTemperature() << std::endl;

    // 测试增加红温值
    pest1.increaseRedTemperature(50);
    std::cout << "增加50后，红温值: " << pest1.getRedTemperature() << std::endl;
    pest1.displayInfo();

    // 继续增加红温值
    pest1.increaseRedTemperature(60);
    std::cout << "\n增加60后，红温值: " << pest1.getRedTemperature() << std::endl;
    pest1.displayInfo();

    // 触发行为测试：当红温值超过100时，应触发禁言和踢人
    std::cout << "\n触发行为（红温值>100，应该触发禁言和踢人）：" << std::endl;
    pest1.behavior();

    // 7. 测试减少红温值
    std::cout << "\n7. 测试减少红温值：" << std::endl;
    // 测试减少红温值（注意：这里代码中写的是increase，应该是笔误，但根据上下文应该是decrease）
    // 实际代码中应该是：pest1.decreaseRedTemperature(50);
    pest1.increaseRedTemperature(50);
    std::cout << "减少50后，红温值: " << pest1.getRedTemperature() << std::endl;
    pest1.displayInfo();

    // 8. 测试加入QQ群功能（会自动触发建政和吹牛）
    std::cout << "\n8. 测试加入QQ群功能：" << std::endl;
    // 创建第二个害虫对象
    Pest pest2("pest2", {"爱建政", "爱吹牛"}, 2);
    // 测试加入群聊功能，会触发建政和吹牛行为
    pest2.joinGroupChat();

    // 9. 测试管理员权限功能
    std::cout << "\n9. 测试管理员权限功能：" << std::endl;
    // 获取当前管理员权限状态
    std::cout << "当前管理员权限: " << (pest1.getAdminPrivileges() ? "是" : "否") << std::endl;

    // 测试没有管理员权限时，红温值>100无法执行禁言和踢人
    std::cout << "\n测试场景1：没有管理员权限，红温值>100：" << std::endl;
    pest1.increaseRedTemperature(60); // 红温值增加60
    pest1.increaseRedTemperature(50); // 红温值再增加50
    pest1.behavior(); // 触发行为，由于没有管理员权限，应显示权限不足

    // 授予管理员权限
    std::cout << "\n授予管理员权限：" << std::endl;
    pest1.setAdminPrivileges(true);
    pest1.displayInfo(); // 显示更新后的信息

    // 测试有管理员权限时，红温值>100可以执行禁言和踢人
    std::cout << "\n测试场景2：有管理员权限，红温值>100：" << std::endl;
    pest1.behavior(); // 触发行为，由于有管理员权限，应执行禁言和踢人

    // 10. 测试单独调用禁言和踢人方法
    std::cout << "\n10. 测试单独调用禁言和踢人方法：" << std::endl;
    // 创建第三个害虫对象
    Pest pest3("pest3", {"普通群友"}, 1);
    // 测试无管理员权限时的禁言行为
    std::cout << "pest3（无管理员权限）尝试禁言：" << std::endl;
    pest3.mute();
    // 测试无管理员权限时的踢人行为
    std::cout << "pest3（无管理员权限）尝试踢人：" << std::endl;
    pest3.kick();

    // 给pest3授予管理员权限
    pest3.setAdminPrivileges(true);
    // 测试有管理员权限时的禁言行为
    std::cout << "\npest3（有管理员权限）尝试禁言：" << std::endl;
    pest3.mute();
    // 测试有管理员权限时的踢人行为
    std::cout << "pest3（有管理员权限）尝试踢人：" << std::endl;
    pest3.kick();

    // 11. 测试离婚和找女大行为
    std::cout << "\n11. 测试离婚和找女大行为：" << std::endl;
    // 创建第四个害虫对象
    Pest pest4("pest4", {"爱离婚", "爱找女大"}, 3);
    // 测试离婚行为
    std::cout << "测试离婚行为：" << std::endl;
    pest4.divorce();
    // 测试找女大学生行为
    std::cout << "\n测试找女大行为：" << std::endl;
    pest4.findCollegeGirl();

    // 12. 测试嫖娼行为
    std::cout << "\n12. 测试嫖娼行为：" << std::endl;
    // 创建第五个害虫对象
    Pest pest5("pest5", {"爱嫖娼"}, 4);
    // 测试嫖娼行为
    std::cout << "测试嫖娼行为：" << std::endl;
    pest5.prostitution();

    // 输出程序结束信息
    std::cout << "\n=== 生成害虫完毕 ===" << std::endl;

    // 程序正常结束
    return 0;
}
