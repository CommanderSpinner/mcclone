#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <string>

class Entity
{
    double cordX, cordY, cordZ;
    float* vertices;
    std::string vertexShader;
    std::string fragmentShader;

    Entity();
    virtual ~Entity();
};

#endif