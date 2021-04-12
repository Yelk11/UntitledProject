#include <iostream>
#include <ncurses.h>

#include "map.hpp"
#include "player.hpp"
#include "monster.hpp"
#include "entity.hpp"

int main(int, char **)
{
    initscr();
    cbreak();
    noecho();
    bool done = false;
    int key;

    Monster monster(15, 15);
    Player player(15, 10);

   

    Map *m = m->getInstance();
    
    m->addEntity(player);
    m->addEntity(monster);
    m->generate();

    while (!done)
    {
        m->draw();
        
        key = getch();
        if (key == 27)
        {
            done = true;
        }

        switch (key)
        {
        case 'w':
            player.walk(Entity::NORTH);
            break;
        case 'a':
            player.walk(Entity::WEST);
            break;
        case 's':
            player.walk(Entity::SOUTH);
            break;
        case 'd':
            player.walk(Entity::EAST);
            break;
        }
    }

    endwin();
    return 0;
}
