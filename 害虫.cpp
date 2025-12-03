#include <iostream>
#include <algorithm>

#include "害虫.h"

害虫::害虫(std::string 名字, std::vector<std::string> 特征, int 年龄)
    : 名字(名字), 特征(特征), 年龄(年龄), 红温值(0)
{
}

害虫::~害虫()
{
    // 析构函数不需要特殊操作，vector和string会自动清理
}

int 害虫::获取年龄() const
{
    return 年龄;
}

std::string 害虫::获取名字() const
{
    return 名字;
}

std::vector<std::string> 害虫::获取特征() const
{
    return 特征;
}

void 害虫::设置名字(const std::string& 新名字)
{
    名字 = 新名字;
}

void 害虫::设置特征(const std::vector<std::string>& 新特征)
{
    特征 = 新特征;
}

void 害虫::设置年龄(int 新年龄)
{
    if (新年龄 >= 0) {
        年龄 = 新年龄;
    }
}

void 害虫::显示信息() const
{
    std::cout << "害虫信息：" << std::endl;
    std::cout << "名字: " << 名字 << std::endl;
    std::cout << "年龄: " << 年龄 << std::endl;
    std::cout << "红温值: " << 红温值;
    if (红温值 > 100) {
        std::cout << " (危险！)";
    }
    std::cout << std::endl;
    std::cout << "特征: ";

    if (特征.empty()) {
        std::cout << "无特征";
    }
    else {
        for (size_t i = 0; i < 特征.size(); ++i) {
            std::cout << 特征[i];
            if (i != 特征.size() - 1) {
                std::cout << ", ";
            }
        }
    }
    std::cout << std::endl;
}

void 害虫::添加特征(const std::string& 新特征)
{
    // 检查是否已存在该特征
    auto it = std::find(特征.begin(), 特征.end(), 新特征);
    if (it == 特征.end()) {
        特征.push_back(新特征);
    }
}

void 害虫::删除特征(const std::string& 要删除的特征)
{
    auto it = std::find(特征.begin(), 特征.end(), 要删除的特征);
    if (it != 特征.end()) {
        特征.erase(it);
    }
}

void 害虫::清除特征()
{
    特征.clear();
}

void 害虫::增加年龄(int 年数)
{
    if (年数 > 0) {
        年龄 += 年数;
    }
}

void 害虫::减少年龄(int 年数)
{
    if (年数 > 0) {
        年龄 = std::max(0, 年龄 - 年数);
    }
}

int 害虫::获取红温值() const
{
    return 红温值;
}

void 害虫::设置红温值(int 新红温值)
{
    if (新红温值 >= 0) {
        红温值 = 新红温值;
    }
}

void 害虫::增加红温值(int 数值)
{
    if (数值 > 0) {
        红温值 += 数值;
    }
}

void 害虫::减少红温值(int 数值)
{
    if (数值 > 0) {
        红温值 = std::max(0, 红温值 - 数值);
    }
}

void 害虫::禁言()
{
    std::cout << "【系统警告】" << 名字 << " 已被禁言！" << std::endl;
}

void 害虫::踢人()
{
    std::cout << "【系统警告】" << 名字 << " 已被踢出！" << std::endl;
}

void 害虫::行为()
{
    std::cout << 名字 << "正在活动..." << std::endl;

    // 检查红温值，如果大于100则触发禁言和踢人
    if (红温值 > 100) {
        std::cout << "【警告】" << 名字 << " 的红温值已达到 " << 红温值 << "，触发惩罚机制！" << std::endl;
        禁言();
        踢人();
        return;
    }

    // 根据特征显示不同的行为
    if (!特征.empty()) {
        std::cout << "当前特征: ";
        for (const auto& 特质 : 特征) {
            std::cout << 特质 << " ";
        }
        std::cout << std::endl;
    }

    // 根据年龄显示不同的行为状态
    if (年龄 == 0) {
        std::cout << "这是新生的害虫" << std::endl;
    }
    else if (年龄 < 3) {
        std::cout << "这是年轻的害虫，活动活跃" << std::endl;
    }
    else {
        std::cout << "这是成熟的害虫，经验丰富" << std::endl;
    }
}