#pragma once
#include <string>
#include <vector>

class Pest
{
public:
    Pest(std::string name, std::vector<std::string> features, int age);
    ~Pest();
    int getAge() const;
    std::string getName() const;
    std::vector<std::string> getFeatures() const;
    void setName(const std::string& name);
    void setFeatures(const std::vector<std::string>& features);
    void setAge(int new_age);
    void displayInfo() const;
    void addFeature(const std::string& features);
    void removeFeature(const std::string& features);
    void clearFeatures();
    void increaseAge(int age);
    void decreaseAge(int age);
    void behavior();
    int getRedTemperature() const;
    void setRedTemperature(int redTemperature);
    void increaseRedTemperature(int num);
    void decreaseRedTemperature(int num);
    void mute();
    void kick();
    void buildGovernance();
    void boast();
    void joinGroupChat();
    void divorce();
    void findCollegeGirl();
    void prostitution();
    bool getAdminPrivileges() const;
    void setAdminPrivileges(bool IsPrivileges);
private:
    std::string m_name;
    std::vector<std::string> m_features;
    uint16_t m_age;
    uint16_t m_redTemperature;
    bool m_adminPrivileges;
};
