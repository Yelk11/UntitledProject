#ifndef H_MAP
#define H_MAP

#include <vector>
#include "entity.hpp"



class Map
{

public:
    Map();
    void generate();
    void draw();
    static Map *getInstance();
    void addEntity(Entity& entity);
    bool isWalkable(int x, int y);
    Entity* getEntity(int x, int y);
private:
    char map[31][92];
    std::vector<Entity*> entityList;
    char ground;
    char wall;
};

#endif