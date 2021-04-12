
#include "entity.hpp"
#include "map.hpp"

Entity::Entity(char c, int x, int y)
{
    myX = x;
    myY = y;
    ch = c;
    isAlive = true;
    m_attack = 1;
    m_health = 20;
    m_defence = 5;
}

void Entity::walk(Direction dir)
{
    Map *m = m->getInstance();
    switch (dir)
    {
    case NORTH:
        if (m->isWalkable(myX, myY - 1))
        {
            myY--;
        }
        break;
    case EAST:
        if (m->isWalkable(myX + 1, myY))
        {
            myX++;
        }
        break;
    case SOUTH:
        if (m->isWalkable(myX, myY + 1))
        {
            myY++;
        }
        break;
    case WEST:
        if (m->isWalkable(myX - 1, myY))
        {
            myX--;
        }
        break;
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
    return ch;
}

void Entity::setChar(char c)
{
    ch = c;
}

void Entity::takeDamage(int dmg)
{
    m_health -= dmg;

    if(m_health <= 0){
        isAlive = false;
    }
}

void Entity::attack(Entity &entity)
{
    entity.takeDamage(m_attack);
}

void Entity::setTarget(Entity *target)
{
    m_target = target;
}

Entity *Entity::getTarget()
{
    return m_target;
}
