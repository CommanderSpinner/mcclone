#include "game/entity.hpp"

Entity::Entity(std::string vertexShader, std::string fragmentShader, Cordinats cord, std::vector<float> vertices)
{
    this->vertexShader = vertexShader;
    this->fragmentShader = fragmentShader;
    this->cord = cord;
    this->vertices = vertices;
}

Entity::~Entity()
{

}

