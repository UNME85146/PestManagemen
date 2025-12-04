#include <iostream>
#include <random>
#include <ctime>
#include "../header/Quotes.h"

// 构造函数：初始化语录列表
QuotesManager::QuotesManager()
{
    // 初始化时添加默认语录
    m_quotes.push_back("硕士论文是真水");
}

// 方法功能：添加语录
// 参数：
//   - quote: 要添加的语录内容
// 返回值：无
void QuotesManager::addQuote(const std::string& quote)
{
    if (!quote.empty())
    {
        m_quotes.push_back(quote);
    }
}

// 方法功能：获取随机语录
// 返回值：随机选择的语录内容
std::string QuotesManager::getRandomQuote() const
{
    if (m_quotes.empty())
    {
        return "";
    }

    // 使用随机数生成器
    static std::mt19937 generator(static_cast<unsigned int>(std::time(nullptr)));
    std::uniform_int_distribution<size_t> distribution(0, m_quotes.size() - 1);
    size_t randomIndex = distribution(generator);

    return m_quotes[randomIndex];
}

// 方法功能：获取指定索引的语录
// 参数：
//   - index: 语录索引
// 返回值：指定索引的语录内容，如果索引无效则返回空字符串
std::string QuotesManager::getQuote(int index) const
{
    if (index >= 0 && static_cast<size_t>(index) < m_quotes.size())
    {
        return m_quotes[index];
    }
    return "";
}

// 方法功能：获取所有语录
// 返回值：所有语录的常量引用
const std::vector<std::string>& QuotesManager::getAllQuotes() const
{
    return m_quotes;
}

// 方法功能：显示所有语录
// 返回值：无
void QuotesManager::displayAllQuotes() const
{
    std::cout << "【害虫语录列表】" << std::endl;
    for (size_t i = 0; i < m_quotes.size(); ++i)
    {
        std::cout << "  " << (i + 1) << ". " << m_quotes[i] << std::endl;
    }
}

// 方法功能：获取语录总数
// 返回值：语录总数
size_t QuotesManager::getQuoteCount() const
{
    return m_quotes.size();
}

