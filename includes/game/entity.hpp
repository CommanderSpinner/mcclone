#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <string>
#include <vector>

struct Cordinats{
    double cordX, cordY, cordZ;
};

class Entity
{
private:
    std::vector<float> vertices;
    std::string vertexShader;
    std::string fragmentShader;
    Cordinats cord;
    Entity(std::string vertexShader, std::string fragmentShader, Cordinats cord, std::vector<float> vertices vertices);
public:
    virtual ~Entity();
};

#endif
