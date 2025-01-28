#include "game/entity.hpp"

// counter of how many Entitys there are
size_t Entity::count = 0;
size_t Entity::totalCreatedEntitys = 0;
size_t Entity::id = 0;

Entity::Entity(std::string vertexShader, std::string fragmentShader, Cordinats cord, std::vector<float> vertices)
{
    this->vertexShader = vertexShader;
    this->fragmentShader = fragmentShader;
    this->cord = cord;
    this->vertices = vertices;

    this->count++;
    this->totalCreatedEntitys++;
    this->id = totalCreatedEntitys;
}

Entity::~Entity()
{
    this->count--;
    std::cout << "entity:" << this->id << " destroyed, type:" << this->getType() << "\n";
}

