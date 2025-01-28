#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <string>
#include <vector>
#include <typeinfo>
#include <iostream>

struct Cordinats{
    double cordX, cordY, cordZ;
};

class Entity
{
private:
    static size_t count;
    static size_t totalCreatedEntitys;
    static size_t id;
    void logInstance();
    std::vector<float> vertices;
    std::string vertexShader;
    std::string fragmentShader;
    Cordinats cord;
public:
    Entity(std::string vertexShader, std::string fragmentShader, Cordinats cord, std::vector<float> vertices);
    virtual ~Entity();
    virtual std::string getType() const {
        return typeid(*this).name();
    }
};

#endif
