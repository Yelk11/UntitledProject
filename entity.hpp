#ifndef H_ENTITY
#define H_ENTITY




class Entity
{

public:
    enum Direction
    {
        NORTH,
        SOUTH,
        EAST,
        WEST
    };
    
    Entity(char c, int x, int y);
    void walk(Direction dir);
    void setChar(char c);
    int getY();
    int getX();
    char getChar();
    virtual void takeDamage(int dmg);
    virtual void attack(Entity* entity);
    void setTarget(Entity* target);
    Entity* getTarget();
private:
    int myX;
    int myY;
    char ch;
    int m_health;
    int m_attack;
    int m_defence;
    bool isAlive;
    Entity* m_target;
    
};

#endif