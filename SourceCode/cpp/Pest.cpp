#include <iostream>
#include <algorithm>

#include "../header/Pest.h"
#include "../header/Divorce.h"
#include "../header/FindCollegeGirl.h"
#include "../header/Prostitution.h"
#include "../header/BuildGovernance.h"
#include "../header/Mute.h"
#include "../header/Kick.h"
#include "../header/Boast.h"
#include "../header/RedTemperature.h"
#include "../header/Quotes.h"

// 构造函数：初始化害虫对象
// 参数：
//   - name: 害虫名称
//   - features: 害虫特征列表
//   - age: 害虫年龄
// 功能：创建害虫对象并初始化所有成员变量
Pest::Pest(std::string name, std::vector<std::string> features, int age)
    : m_name(name), m_features(features), m_age(age), m_redTemperature(0), m_adminPrivileges(false)
{
}

// 析构函数：销毁害虫对象
// 功能：自动清理所有资源，无需手动操作
Pest::~Pest()
{
    // 析构函数不需要特殊操作，vector和string会自动清理
}

// 方法功能：获取害虫年龄
// 返回值：害虫年龄
int Pest::getAge() const
{
    return m_age;
}

// 方法功能：获取害虫名称
// 返回值：害虫名称
std::string Pest::getName() const
{
    return m_name;
}

// 方法功能：获取害虫特征列表
// 返回值：害虫特征列表的副本
std::vector<std::string> Pest::getFeatures() const
{
    return m_features;
}

// 方法功能：设置害虫名称
// 参数：
//   - new_Name: 新的害虫名称
// 返回值：无
void Pest::setName(const std::string& new_Name)
{
    m_name = new_Name;
}

// 方法功能：设置害虫特征列表
// 参数：
//   - new_features: 新的特征列表
// 返回值：无
void Pest::setFeatures(const std::vector<std::string>& new_features)
{
    m_features = new_features;
}

// 方法功能：设置害虫年龄
// 参数：
//   - new_age: 新的年龄值
// 功能：只允许设置非负年龄
// 返回值：无
void Pest::setAge(int new_age)
{
    if (new_age >= 0)
    {
        m_age = new_age;
    }
}

// 方法功能：显示害虫的完整信息
// 返回值：无
void Pest::displayInfo() const
{
    std::cout << "Pest信息：" << std::endl;
    std::cout << "名字: " << m_name << std::endl;
    std::cout << "年龄: " << m_age << std::endl;

    // 显示红温值，并添加危险警告
    std::cout << "红温值: " << m_redTemperature;
    if (m_redTemperature > 100)
    {
        std::cout << " (危险！)";
    }
    std::cout << std::endl;

    // 显示管理员权限状态
    std::cout << "管理员权限: " << (m_adminPrivileges ? "是" : "否") << std::endl;

    // 显示特征列表
    std::cout << "特征: ";
    if (m_features.empty())
    {
        std::cout << "无特征";
    }
    else
    {
        for (size_t i = 0; i < m_features.size(); ++i)
        {
            std::cout << m_features[i];
            if (i != m_features.size() - 1)
            {
                std::cout << ", ";
            }
        }
    }
    std::cout << std::endl;
}

// 方法功能：添加特征到特征列表
// 参数：
//   - new_features: 要添加的特征
// 功能：如果特征已存在则不重复添加
// 返回值：无
void Pest::addFeature(const std::string& new_features)
{
    // 检查是否已存在该特征
    auto it = std::find(m_features.begin(), m_features.end(), new_features);
    if (it == m_features.end())
    {
        m_features.push_back(new_features);
    }
}

// 方法功能：从特征列表中移除指定特征
// 参数：
//   - featureToBeDeleted: 要移除的特征
// 功能：如果特征存在则移除，不存在则不执行任何操作
// 返回值：无
void Pest::removeFeature(const std::string& featureToBeDeleted)
{
    auto it = std::find(m_features.begin(), m_features.end(), featureToBeDeleted);
    if (it != m_features.end())
    {
        m_features.erase(it);
    }
}

// 方法功能：清空特征列表
// 返回值：无
void Pest::clearFeatures()
{
    m_features.clear();
}

// 方法功能：增加年龄
// 参数：
//   - numberOfYears: 增加的年龄值
// 功能：只允许增加正数年龄
// 返回值：无
void Pest::increaseAge(int numberOfYears)
{
    if (numberOfYears > 0)
    {
        m_age += numberOfYears;
    }
}

// 方法功能：减少年龄
// 参数：
//   - numberOfYears: 减少的年龄值
// 功能：年龄不会低于0
// 返回值：无
void Pest::decreaseAge(int numberOfYears)
{
    if (numberOfYears > 0)
    {
        m_age = std::max(0, m_age - numberOfYears);
    }
}

// 方法功能：获取红温值
// 返回值：当前红温值
int Pest::getRedTemperature() const
{
    return m_redTemperature;
}

// 方法功能：设置红温值
// 参数：
//   - new_redTemperature: 新的红温值
// 功能：通过RedTemperatureManager类来设置红温值
// 返回值：无
void Pest::setRedTemperature(int new_redTemperature)
{
    RedTemperatureManager redTemperatureObj;
    redTemperatureObj.setRedTemperature(m_redTemperature, new_redTemperature);
}

// 方法功能：增加红温值
// 参数：
//   - num: 增加的红温值数量
// 功能：通过RedTemperatureManager类来增加红温值
// 返回值：无
void Pest::increaseRedTemperature(int num)
{
    RedTemperatureManager redTemperatureObj;
    redTemperatureObj.increaseRedTemperature(m_redTemperature, num);
}

// 方法功能：减少红温值
// 参数：
//   - num: 减少的红温值数量
// 功能：通过RedTemperatureManager类来减少红温值
// 返回值：无
void Pest::decreaseRedTemperature(int num)
{
    RedTemperatureManager redTemperatureObj;
    redTemperatureObj.decreaseRedTemperature(m_redTemperature, num);
}

// 方法功能：执行禁言行为
// 功能：调用MuteBehavior类的Execute方法
// 返回值：无
void Pest::mute()
{
    MuteBehavior muteObj;
    muteObj.Execute("name", m_adminPrivileges);
}

// 方法功能：执行踢人行为
// 功能：调用KickBehavior类的Execute方法
// 返回值：无
void Pest::kick()
{
    KickBehavior kickObj;
    kickObj.Execute("name", m_adminPrivileges);
}

// 方法功能：执行建政行为
// 功能：调用BuildGovernanceBehavior类的Execute方法
// 返回值：无
void Pest::buildGovernance()
{
    BuildGovernanceBehavior buildGovernanceObj;
    buildGovernanceObj.Execute("name");
}

// 方法功能：执行吹牛行为
// 功能：调用BoastBehavior类的Execute方法
// 返回值：无
void Pest::boast()
{
    BoastBehavior boastObj;
    boastObj.Execute("name");
}

// 方法功能：加入群聊行为
// 功能：模拟加入QQ群并自动执行建政和吹牛行为
// 返回值：无
void Pest::joinGroupChat()
{
    std::cout << "【系统通知】" << m_name << " 加入了QQ群！" << std::endl;
    buildGovernance(); // 加入群聊后自动建政
    boast(); // 加入群聊后自动吹牛
}

// 方法功能：获取管理员权限状态
// 返回值：是否拥有管理员权限
bool Pest::getAdminPrivileges() const
{
    return m_adminPrivileges;
}

// 方法功能：设置管理员权限状态
// 参数：
//   - privileges: 是否授予管理员权限
// 功能：更新管理员权限状态并输出变更信息
// 返回值：无
void Pest::setAdminPrivileges(bool privileges)
{
    m_adminPrivileges = privileges;
    if (privileges)
    {
        std::cout << "【权限变更】" << m_name << " 获得了管理员权限！" << std::endl;
    }
    else
    {
        std::cout << "【权限变更】" << m_name << " 失去了管理员权限！" << std::endl;
    }
}

// 方法功能：执行离婚行为
// 功能：调用DivorceBehavior类的Execute方法
// 返回值：无
void Pest::divorce()
{
    DivorceBehavior divorceObj;
    divorceObj.Execute(m_name);
}

// 方法功能：执行找女大学生行为
// 功能：调用FindCollegeGirlBehavior类的Execute方法
// 返回值：无
void Pest::findCollegeGirl()
{
    FindCollegeGirlBehavior findCollegeGirlObj;
    findCollegeGirlObj.Execute(m_name);
}

// 方法功能：执行嫖娼行为
// 功能：调用ProstitutionBehavior类的Execute方法
// 返回值：无
void Pest::prostitution()
{
    ProstitutionBehavior prostitutionObj;
    prostitutionObj.Execute(m_name);
}

// 方法功能：说出随机语录
// 功能：使用QuotesManager获取随机语录并输出
// 返回值：无
void Pest::sayQuote()
{
    QuotesManager quotesManager;
    std::string quote = quotesManager.getRandomQuote();
    if (!quote.empty())
    {
        std::cout << "【害虫语录】" << m_name << " 说: \"" << quote << "\"" << std::endl;
    }
    else
    {
        std::cout << "【提示】" << m_name << " 暂时没有语录可说" << std::endl;
    }
}

// 方法功能：执行默认行为
// 功能：根据红温值、特征和年龄显示不同的行为状态
// 返回值：无
void Pest::behavior()
{
    std::cout << m_name << "正在活动..." << std::endl;

    // 检查红温值，如果大于100且拥有管理员权限则触发惩罚机制
    if (m_redTemperature > 100)
    {
        std::cout << "【警告】" << m_name << " 的红温值已达到 " << m_redTemperature << "，触发惩罚机制！" << std::endl;
        if (m_adminPrivileges)
        {
            mute(); // 执行禁言
            kick(); // 执行踢人
        }
        else
        {
            std::cout << "【提示】" << m_name << " 没有管理员权限，无法执行禁言和踢人操作！" << std::endl;
        }
        return; // 结束方法执行
    }

    // 根据特征显示不同的行为
    if (!m_features.empty())
    {
        std::cout << "当前特征: ";
        for (const auto& 特质 : m_features)
        {
            std::cout << 特质 << " ";
        }
        std::cout << std::endl;
    }

    // 根据年龄显示不同的行为状态
    if (m_age == 0)
    {
        std::cout << "这是新生的Pest" << std::endl;
    }
    else if (m_age < 3)
    {
        std::cout << "这是年轻的Pest，活动活跃" << std::endl;
    }
    else
    {
        std::cout << "这是成熟的Pest，经验丰富" << std::endl;
    }
}
