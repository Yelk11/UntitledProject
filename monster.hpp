

#include "entity.hpp"


class Monster : public Entity {
    public:
        Monster(int x, int y);
        void attack();
    private:
        int myX;
        int myY;
        char myChar;
        bool isAlive;
};