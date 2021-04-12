
#include "entity.hpp"
#include "map.hpp"
Map *map = map->getInstance();

Entity::Entity(char c, int x, int y)
{
    myX = x;
    myY = y;
    ch = c;
    isAlive = true;
    m_attack = 10;
    m_health = 20;
    m_defence = 5;
}

void Entity::walk(Direction dir)
{
    Map *m = m->getInstance();

    int tempX = myX;
    int tempY = myY;
    switch (dir)
    {
    case NORTH:
        tempY--;
        break;
    case EAST:
        tempX++;
        break;
    case SOUTH:
        tempY++;
        break;
    case WEST:
        tempX--;
        break;
    }
    if (m->getEntity(tempX, tempY) != nullptr)
    {
        attack(m->getEntity(tempX, tempY));
    }
    else if (m->isWalkable(tempX, tempY))
    {
        myY = tempY;
        myX = tempX;
    }
}

int Entity::getX()
{
    return myX;
}

int Entity::getY()
{
    return myY;
}

char Entity::getChar()
{
    if (!isAlive)
    {
        return 'X';
    }
    return ch;
}

void Entity::setChar(char c)
{
    ch = c;
}

void Entity::takeDamage(int dmg)
{
    m_health -= dmg;

    if (m_health <= 0)
    {
        isAlive = false;
    }
}

void Entity::attack(Entity *entity)
{
    entity->takeDamage(m_attack);
}

void Entity::setTarget(Entity *target)
{
    m_target = target;
}

Entity *Entity::getTarget()
{
    return m_target;
}
