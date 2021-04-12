#include <iostream>
#include <ncurses.h>

#include "map.hpp"

static Map *instance_;

Map *Map::getInstance()
{
    if (instance_ == NULL)
    {
        instance_ = new Map();
    }
    return instance_;
}

Map::Map()
{
    ground = '.';
    wall = '#';
}

void Map::generate()
{
    for (int y = 0; y < 31; y++)
    {
        for (int x = 0; x < 92; x++)
        {
            map[y][x] = '.';
        }
    }
    for (int i = 0; i < 31; i++)
    {
        map[i][10] = '#';
    }
}

void Map::draw()
{

    for (int y = 0; y < 31; y++)
    {
        for (int x = 0; x < 92; x++)
        {
            mvaddch(y, x, map[y][x]);
        }
    }
    for (std::size_t i = 0; i < entityList.size(); ++i)
    {
        
        mvaddch(entityList[i]->getY(), entityList[i]->getX(), entityList[i]->getChar());
    }
}

void Map::addEntity(Entity& entity)
{
    entityList.push_back(&entity);
}

bool Map::isWalkable(int x, int y)
{
    return map[y][x] == ground;
}

Entity* Map::getEntity(int x, int y){
    for (std::size_t i = 0; i < entityList.size(); ++i)
    {
        if(entityList[i]->getY() == y && entityList[i]->getX() == x){
            return entityList[i];
        }
    }
    return nullptr;
}
