#ifndef STUDENTWORLD_H_
#define STUDENTWORLD_H_

#include "GameWorld.h"
#include "GameConstants.h"
#include <string>
#include <algorithm>
#include <list>
#include "Actor.h"

// Students:  Add code to this file, StudentWorld.cpp, Actor.h, and Actor.cpp

class StudentWorld : public GameWorld
{
public:
	StudentWorld(std::string assetDir)
		: GameWorld(assetDir)
	{
       
	}

    virtual int init();

    virtual int move();
    
    virtual void cleanUp();
    

private:
    Tunnel_Man* player;
    Earth* level[60][60];
    std::list<Actor*> game_Entities;
    int levelNumber;
    int BoulderCount;
    int GoldNuggetCount;
    int BarrelCount;
};

#endif // STUDENTWORLD_H_
