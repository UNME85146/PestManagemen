#pragma once
#include <string>
#include <vector>

// 害虫语录管理类
class QuotesManager
{
public:
    // 构造函数：初始化语录列表
    QuotesManager();

    // 方法功能：添加语录
    // 参数：
    //   - quote: 要添加的语录内容
    // 返回值：无
    void addQuote(const std::string& quote);

    // 方法功能：获取随机语录
    // 返回值：随机选择的语录内容
    std::string getRandomQuote() const;

    // 方法功能：获取指定索引的语录
    // 参数：
    //   - index: 语录索引
    // 返回值：指定索引的语录内容，如果索引无效则返回空字符串
    std::string getQuote(int index) const;

    // 方法功能：获取所有语录
    // 返回值：所有语录的常量引用
    const std::vector<std::string>& getAllQuotes() const;

    // 方法功能：显示所有语录
    // 返回值：无
    void displayAllQuotes() const;

    // 方法功能：获取语录总数
    // 返回值：语录总数
    size_t getQuoteCount() const;

private:
    // 成员变量：语录列表
    std::vector<std::string> m_quotes;
};

