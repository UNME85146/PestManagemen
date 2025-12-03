#pragma once
#include <string>
#include <vector>

class 害虫
{
public:
    害虫(std::string 名字,std::vector<std::string> 特征,int 年龄 );
    ~害虫();
    int 获取年龄() const;
    std::string 获取名字() const;
    std::vector<std::string> 获取特征() const;
    void 设置名字(const std::string& 名字);
    void 设置特征(const std::vector<std::string>& 特征);
    void 设置年龄(int 年龄);
    void 显示信息() const;
    void 添加特征(const std::string& 特征);
    void 删除特征(const std::string& 特征);
    void 清除特征();
    void 增加年龄(int 年龄);
    void 减少年龄(int 年龄);
    void 行为();
    int 获取红温值() const;
    void 设置红温值(int 红温值);
    void 增加红温值(int 数值);
    void 减少红温值(int 数值);
    void 禁言();
    void 踢人();
    void 建政();
    void 吹牛();
    void 加入QQ群();
    void 离婚();
    void 找女大();
    void 嫖娼();
    bool 获取管理员权限() const;
    void 设置管理员权限(bool 权限);
private:
    std::string 名字;
    std::vector<std::string> 特征;
    int 年龄;
    int 红温值;
    bool 管理员权限;
};

