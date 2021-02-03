#ifndef ACTOR_H_
#define ACTOR_H_

#include "GraphObject.h"
class Actor : public GraphObject
{
    public:
        Actor(int imageID, int startX, int startY, Direction dir = right, double size = 1.0, unsigned int depth = 0) : GraphObject(imageID, startX, startY, dir, size, depth) {}
        
        bool isAlive();   //returns whether the entity is alive
        void setAlive();  //sets entity to an alive state
        void setDead();         //set this entity to dead and let the game know
        virtual ~Actor() { }                //virtual destructor
    private:
        virtual void CheckTicks() = 0;  //gives the ticks of a particular Actor
        bool CheckRange(const Actor*& other);    //Check range from this entity to any other intended entity
        bool m_alive;
};

class Earth : public Actor
{
    public:
        //virtual constructor for earth objects
        Earth(int imageID = TID_EARTH, int startX = 0, int startY = 0, Direction dir = right, double size = .25, unsigned int depth = 3) : Actor(imageID, startX, startY, dir, size, depth)
    { setVisible(true); setAlive(); }   //constructor sets Earth to visible and sets it to alive

        //virtual destructor for earth objects
        virtual ~Earth() {}
    
    private:
    void CheckTicks() {}      //dummy, should never be called
};

class Person : public Actor
{
    public:
        Person(int imageID, int startX, int startY, Direction dir = right, double size = 1.0, unsigned int depth = 0) : Actor(imageID, startX, startY, dir, size, depth) {}
        virtual void getAnnoyed() = 0;  //pure virtual function because there are no persons, only protesters etc.
        virtual void foundNugget() = 0; //pure virtual, protestor and TMan should specialize this function
        virtual ~Person() {}
    
    private:
};

class Regular_Protestor : public Person
{
    public:
    Regular_Protestor(int imageID = TID_PROTESTER, int startX = 0, int startY = 0, Direction dir = right, double size = 1.0, unsigned int depth = 0) : Person(imageID, startX, startY, dir, size, depth) {}
    virtual ~Regular_Protestor() {}
    virtual void getAnnoyed();  //defines how Regular protestors get annoyed.
    virtual void foundNugget(); //defines how Regular protestors get nuggests REDEF IN HC Protestor
    
    private:
};

class Hardcore_Protestor : public Regular_Protestor
{
    public:
    Hardcore_Protestor(int imageID = TID_HARD_CORE_PROTESTER, int startX = 0, int startY = 0, Direction dir = right, double size = 1.0, unsigned int depth = 0) : Regular_Protestor(imageID, startX, startY, dir, size, depth) {}
    virtual ~Hardcore_Protestor() {}
    virtual void foundNugget();
    virtual void getAnnoyed();
    private:
};

class Tunnel_Man : public Person
{
    public:
    Tunnel_Man(int imageID = TID_PLAYER, int startX = 30, int startY = 60, Direction dir = right, double size = 1.0, unsigned int depth = 0) : Person(imageID, startX, startY, dir, size, depth)
    { setVisible(true);}
        virtual ~Tunnel_Man() {}
    private:
    void CheckTicks() {}         //dummy, needed to create object
    void foundNugget() {}   //temp FIX
    void getAnnoyed() {}    //temp FIX
};

class Dangerous_Entity : public Actor
{
    public:
        Dangerous_Entity (int imageID, int startX, int startY, Direction dir = right, double size = 1.0, unsigned int depth = 0) : Actor(imageID, startX, startY, dir, size, depth) {}
        virtual void AnnoyPerson();   //annoy Person
        void checkFront();            //Check what is in front of it
    private:
};

class Boulder : public Dangerous_Entity
{
    public: Boulder(int imageID = TID_BOULDER, int startX = 0, int startY = 0, Direction dir = right, double size = 1.0, unsigned int depth = 0) : Dangerous_Entity(imageID, startX, startY, dir, size, depth) {}
    private:
};

class Squirt : public Dangerous_Entity
{
    public:
        Squirt(int imageID = TID_WATER_SPURT, int startX = 0, int startY = 0, Direction dir = right, double size = 1.0, unsigned int depth = 0) : Dangerous_Entity(imageID, startX, startY, dir, size, depth) {}
    private:
};

class Item : public Actor
{
    public:
        Item(int imageID, int startX, int startY, Direction dir = right, double size = 1.0, unsigned int depth = 0) : Actor(imageID, startX, startY, dir, size, depth) {}
    private:
};

class Barrel : public Item
{
    public:
        Barrel(int imageID = TID_BARREL, int startX = 0, int startY = 0, Direction dir = right, double size = 1.0, unsigned int depth = 2) : Item(imageID, startX, startY, dir, size, depth) {}
    private:
};

class Gold : public Item
{
    public:
        Gold(int imageID = TID_GOLD, int startX = 0, int startY = 0, Direction dir = right, double size = 1.0, unsigned int depth = 2) : Item(imageID, startX, startY, dir, size, depth) {}
    private:
};

class Sonar : public Item
{
    public:
        Sonar(int imageID = TID_SONAR, int startX = 0, int startY = 0, Direction dir = right, double size = 1.0, unsigned int depth = 2) : Item(imageID, startX, startY, dir, size, depth) {}
    private:
};

class Water : public Item
{
    public:
        Water(int imageID = TID_WATER_POOL, int startX = 0, int startY = 0, Direction dir = right, double size = 1.0, unsigned int depth = 2) : Item(imageID, startX, startY, dir, size, depth) {}
    private:
};
// Students:  Add code to this file, Actor.cpp, StudentWorld.h, and StudentWorld.cpp

/*GraphObject(int imageID, int startX, int startY,
DIRECTION startDirection, float size = 1.0,
unsigned int depth = 0);
void setVisible(bool shouldIDisplay);
void getX() const;
void getY() const;
void moveTo(int x, int y);
DIRECTION getDirection() const; // Directions: up, down, left, right
void setDirection(DIRECTION d); // Directions: up, down, left, right*/

/*TID_PLAYER // for the TunnelMan
TID_PROTESTER // a regular protester
TID_HARD_CORE_PROTESTER // a hardcore protester
TID_WATER_SPURT // for a squirt of water from the TunnelMan
TID_BOULDER
TID_BARREL // a barrel of oil
TID_EARTH // a 1x1 square of earth
TID_GOLD // a gold nugget
TID_SONAR // a sonar kit
TID_WATER_POOL // a water pool to refill the squirt gun*/

/*NOTE: When you create a new game object, always remember that if you want it to be
displayed on the screen, you must call its setVisible() method with a value of true!*/

#endif // ACTOR_H_
