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

Pest::Pest(std::string name, std::vector<std::string> features, int age)
    : m_name(name), m_features(features), m_age(age), m_redTemperature(0), m_adminPrivileges(false)
{
}

Pest::~Pest()
{
    // 析构函数不需要特殊操作，vector和string会自动清理
}

int Pest::getAge() const
{
    return m_age;
}

std::string Pest::getName() const
{
    return m_name;
}

std::vector<std::string> Pest::getFeatures() const
{
    return m_features;
}

void Pest::setName(const std::string& new_Name)
{
    m_name = new_Name;
}

void Pest::setFeatures(const std::vector<std::string>& new_features)
{
    m_features = new_features;
}

void Pest::setAge(int new_age)
{
    if (new_age >= 0) {
        m_age = new_age;
    }
}

void Pest::displayInfo() const
{
    std::cout << "Pest信息：" << std::endl;
    std::cout << "名字: " << m_name << std::endl;
    std::cout << "年龄: " << m_age << std::endl;
    std::cout << "红温值: " << m_redTemperature;
    if (m_redTemperature > 100) {
        std::cout << " (危险！)";
    }
    std::cout << std::endl;
    std::cout << "管理员权限: " << (m_adminPrivileges ? "是" : "否") << std::endl;
    std::cout << "特征: ";

    if (m_features.empty()) {
        std::cout << "无特征";
    } else {
        for (size_t i = 0; i < m_features.size(); ++i) {
            std::cout << m_features[i];
            if (i != m_features.size() - 1) {
                std::cout << ", ";
            }
        }
    }
    std::cout << std::endl;
}

void Pest::addFeature(const std::string& new_features)
{
    // 检查是否已存在该特征
    auto it = std::find(m_features.begin(), m_features.end(), new_features);
    if (it == m_features.end()) {
        m_features.push_back(new_features);
    }
}

void Pest::removeFeature(const std::string& featureToBeDeleted)
{
    auto it = std::find(m_features.begin(), m_features.end(), featureToBeDeleted);
    if (it != m_features.end()) {
        m_features.erase(it);
    }
}

void Pest::clearFeatures()
{
    m_features.clear();
}

void Pest::increaseAge(int numberOfYears)
{
    if (numberOfYears > 0) {
        m_age += numberOfYears;
    }
}

void Pest::decreaseAge(int numberOfYears)
{
    if (numberOfYears > 0) {
        m_age = std::max(0, m_age - numberOfYears);
    }
}

int Pest::getRedTemperature() const
{
    return m_redTemperature;
}

void Pest::setRedTemperature(int new_redTemperature)
{
    RedTemperatureManager redTemperatureObj;
    redTemperatureObj.setRedTemperature(m_redTemperature, new_redTemperature);
}

void Pest::increaseRedTemperature(int num)
{
    RedTemperatureManager redTemperatureObj;
    redTemperatureObj.increaseRedTemperature(m_redTemperature, num);
}

void Pest::decreaseRedTemperature(int num)
{
    RedTemperatureManager redTemperatureObj;
    redTemperatureObj.decreaseRedTemperature(m_redTemperature, num);
}

void Pest::mute()
{
    MuteBehavior muteObj;
    muteObj.Execute("name", m_adminPrivileges);
}

void Pest::kick()
{
    KickBehavior kickObj;
    kickObj.Execute("name", m_adminPrivileges);
}

void Pest::buildGovernance()
{
    BuildGovernanceBehavior buildGovernanceObj;
    buildGovernanceObj.Execute("name");
}

void Pest::boast()
{
    BoastBehavior boastObj;
    boastObj.Execute("name");
}

void Pest::joinGroupChat()
{
    std::cout << "【系统通知】" << m_name << " 加入了QQ群！" << std::endl;
    buildGovernance();
    boast();
}

bool Pest::getAdminPrivileges() const
{
    return m_adminPrivileges;
}

void Pest::setAdminPrivileges(bool privileges)
{
    m_adminPrivileges = privileges;
    if (privileges) {
        std::cout << "【权限变更】" << m_name << " 获得了管理员权限！" << std::endl;
    } else {
        std::cout << "【权限变更】" << m_name << " 失去了管理员权限！" << std::endl;
    }
}

void Pest::divorce()
{
    DivorceBehavior divorceObj;
    divorceObj.Execute(m_name);
}

void Pest::findCollegeGirl()
{
    FindCollegeGirlBehavior findCollegeGirlObj;
    findCollegeGirlObj.Execute(m_name);
}

void Pest::prostitution()
{
    ProstitutionBehavior prostitutionObj;
    prostitutionObj.Execute(m_name);
}

void Pest::behavior()
{
    std::cout << m_name << "正在活动..." << std::endl;

    // 检查红温值，如果大于100且拥有管理员权限则触发禁言和踢人
    if (m_redTemperature > 100) {
        std::cout << "【警告】" << m_name << " 的红温值已达到 " << m_redTemperature << "，触发惩罚机制！" << std::endl;
        if (m_adminPrivileges) {
            mute();
            kick();
        } else {
            std::cout << "【提示】" << m_name << " 没有管理员权限，无法执行禁言和踢人操作！" << std::endl;
        }
        return;
    }

    // 根据特征显示不同的行为
    if (!m_features.empty()) {
        std::cout << "当前特征: ";
        for (const auto& 特质 : m_features) {
            std::cout << 特质 << " ";
        }
        std::cout << std::endl;
    }

    // 根据年龄显示不同的行为状态
    if (m_age == 0) {
        std::cout << "这是新生的Pest" << std::endl;
    } else if (m_age < 3) {
        std::cout << "这是年轻的Pest，活动活跃" << std::endl;
    } else {
        std::cout << "这是成熟的Pest，经验丰富" << std::endl;
    }
}
