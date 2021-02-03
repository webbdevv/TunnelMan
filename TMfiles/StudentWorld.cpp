#include "StudentWorld.h"
#include <string>
using namespace std;

GameWorld* createStudentWorld(string assetDir)
{
	return new StudentWorld(assetDir);
}

// Students:  Add code to this file (if you wish), StudentWorld.h, Actor.h and Actor.cpp
int StudentWorld::init(){
    /* Your init() method is responsible for creating the current level’s oil field and populating
           it with Earth, Boulders, Barrels of Oil, and Gold Nuggets (we’ll show you how below),
           and constructing a virtual representation of the current level in your StudentWorld class,
           using one or more data structures that you come up with. This function must return the
           value GWSTATUS_CONTINUE_GAME (defined in GameConstants.h). */
    for(int i = 0; i < 60; i++)
    {
        for(int j = 0; j < 60; j++)
        {
            
            if(j >= 30 && j <= 33 && i >= 4) //create the mineshaft. Don't create earth objects in this area
                continue;
            level[i][j] = new Earth(TID_EARTH, j, i);    //create the board with 60 by 60 earth objects
        }
    }
    player = new Tunnel_Man;
    
    //player = new Tunnel_Man;    //initialize the player
    //int boulderCount = min(current_level_number / 2 + 2, 9);
    //int GoldNuggets = max(5-current_level_number / 2, 2);
    //int L = min(2 + current_level_number, 21);
    
    //delete the area where the tunnel should be 
    return GWSTATUS_CONTINUE_GAME;
}

int StudentWorld::move()
{
    /*This means that it is responsible for asking each of the game’s actors (e.g.,
    the TunnelMan, each Regular Protester or Hardcore Protester, Boulders, etc.) to try to
    do something: e.g., move themselves and/or perform their specified behavior. Finally,
    this method is responsible for disposing of (i.e., deleting) actors (e.g., a Squirt from the
    TunnelMan’s squirt gun that has run its course, a Regular Protester who has left the oil
    field, a Boulder that has fallen and crashed into Earth below, etc.) that need to disappear
    14
    during a given tick. For example, if a Boulder has completed its fall and disintegrated in
    the Earth below, then its state should be set to “dead,” and the after all of the actors in
    the game get a chance to do something during the tick, the move() method should
    remove that Boulder from the game world (by deleting its object and removing any
    reference to the object from the StudentWorld’s data structures). Your move() method
    will automatically be called once during each tick of the game by our provided game
    framework. You will never call the move() method yourself.*/
    
    // This code is here merely to allow the game to build, run, and terminate after you hit enter a few times.
    // Notice that the return value GWSTATUS_PLAYER_DIED will cause our framework to end the current level.
    decLives();
    return GWSTATUS_PLAYER_DIED;
}

void StudentWorld::cleanUp()
{
    /*The cleanup() method is responsible
    for freeing all actors (e.g., all Regular Protester objects, all Hardcore Protester objects,
    all Earth and Boulder objects, the TunnelMan object, all Goodie objects (like Water,
    Gold Nuggets, Barrels of oil), Squirt objects, etc.) that are currently active in the game.
    This includes all actors created during either the init() method or introduced during
    subsequent game ticks (e.g., a Hardcore Protester that was added to the oil field during
    the middle of a level, or a Squirt of water shot by the TunnelMan just before they
    complete the level) that have not yet been removed from the game.*/
}
