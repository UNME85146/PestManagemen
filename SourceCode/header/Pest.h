#pragma once
#include <string>
#include <vector>

// 害虫类 - 表示一个有特定行为和属性的害虫角色
class Pest
{
public:
    // 构造函数：创建害虫对象
    // 参数：
    //   - name: 害虫名称
    //   - features: 害虫特征列表
    //   - age: 害虫年龄
    Pest(std::string name, std::vector<std::string> features, int age);

    // 析构函数：销毁害虫对象
    ~Pest();

    // 方法功能：获取害虫年龄
    // 返回值：害虫年龄
    int getAge() const;

    // 方法功能：获取害虫名称
    // 返回值：害虫名称
    std::string getName() const;

    // 方法功能：获取害虫特征列表
    // 返回值：害虫特征列表的常量引用
    std::vector<std::string> getFeatures() const;

    // 方法功能：设置害虫名称
    // 参数：
    //   - name: 新的害虫名称
    // 返回值：无
    void setName(const std::string& name);

    // 方法功能：设置害虫特征列表
    // 参数：
    //   - features: 新的特征列表
    // 返回值：无
    void setFeatures(const std::vector<std::string>& features);

    // 方法功能：设置害虫年龄
    // 参数：
    //   - new_age: 新的年龄值
    // 返回值：无
    void setAge(int new_age);

    // 方法功能：显示害虫信息
    // 返回值：无
    void displayInfo() const;

    // 方法功能：添加特征到特征列表
    // 参数：
    //   - features: 要添加的特征
    // 返回值：无
    void addFeature(const std::string& features);

    // 方法功能：从特征列表中移除指定特征
    // 参数：
    //   - features: 要移除的特征
    // 返回值：无
    void removeFeature(const std::string& features);

    // 方法功能：清空特征列表
    // 返回值：无
    void clearFeatures();

    // 方法功能：增加年龄
    // 参数：
    //   - age: 增加的年龄值
    // 返回值：无
    void increaseAge(int age);

    // 方法功能：减少年龄
    // 参数：
    //   - age: 减少的年龄值
    // 返回值：无
    void decreaseAge(int age);

    // 方法功能：执行默认行为
    // 返回值：无
    void behavior();

    // 方法功能：获取红温值
    // 返回值：当前红温值
    int getRedTemperature() const;

    // 方法功能：设置红温值
    // 参数：
    //   - redTemperature: 新的红温值
    // 返回值：无
    void setRedTemperature(int redTemperature);

    // 方法功能：增加红温值
    // 参数：
    //   - num: 增加的红温值数量
    // 返回值：无
    void increaseRedTemperature(int num);

    // 方法功能：减少红温值
    // 参数：
    //   - num: 减少的红温值数量
    // 返回值：无
    void decreaseRedTemperature(int num);

    // 方法功能：执行禁言行为
    // 返回值：无
    void mute();

    // 方法功能：执行踢人行为
    // 返回值：无
    void kick();

    // 方法功能：执行建政行为
    // 返回值：无
    void buildGovernance();

    // 方法功能：执行吹牛行为
    // 返回值：无
    void boast();

    // 方法功能：加入群聊行为
    // 返回值：无
    void joinGroupChat();

    // 方法功能：执行离婚行为
    // 返回值：无
    void divorce();

    // 方法功能：执行找女大学生行为
    // 返回值：无
    void findCollegeGirl();

    // 方法功能：执行嫖娼行为
    // 返回值：无
    void prostitution();

    // 方法功能：说出随机语录
    // 返回值：无
    void sayQuote();

    // 方法功能：获取管理员权限状态
    // 返回值：是否拥有管理员权限
    bool getAdminPrivileges() const;

    // 方法功能：设置管理员权限状态
    // 参数：
    //   - IsPrivileges: 是否授予管理员权限
    // 返回值：无
    void setAdminPrivileges(bool IsPrivileges);

private:
    // 成员变量：害虫名称
    std::string m_name;

    // 成员变量：害虫特征列表
    std::vector<std::string> m_features;

    // 成员变量：害虫年龄
    uint16_t m_age;

    // 成员变量：红温值，表示情绪激动程度
    uint16_t m_redTemperature;

    // 成员变量：是否拥有管理员权限
    bool m_adminPrivileges;
};
