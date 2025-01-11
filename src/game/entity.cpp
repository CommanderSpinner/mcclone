#include "game/entity.hpp"

// counter of how many Entitys there are
size_t Entity::count = 0;

Entity::Entity(std::string vertexShader, std::string fragmentShader, Cordinats cord, std::vector<float> vertices)
{
    this->vertexShader = vertexShader;
    this->fragmentShader = fragmentShader;
    this->cord = cord;
    this->vertices = vertices;
    this->count++;
}

Entity::~Entity()
{
    this->count--;
}

