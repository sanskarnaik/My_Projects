#ifndef __BLOCK_AGENT__H
#define __BLOCK_AGENT__H

#include "enviro.h"

using namespace enviro;
using namespace std;

class BlockController : public Process, public AgentInterface
{

public:
    BlockController() : Process(), AgentInterface() {}

    void init() {
        /*watch("goal_change", [this](Event e) {
            id = e.value()["x"];
            set = e.value()["y"];
        });*/
    }
    void start() {}
    void update()
    {
        //cout << id << endl;
        //damp_movement();
        if ( id == 2) {
            move_toward(-25,0);
        }
        if ( id == 3) {
            move_toward(-25,0);
        }
        if ( id == 3) {
            move_toward(-25,0);
        }
        if ( id == 4) {
            move_toward(-25,0);
        }
        if ( id == 5) {
            move_toward(-25,0);
        }
        if ( id == 6) {
            move_toward(-25,0);
        }
        if ( id == 7) {
            move_toward(-25,0);
        }
        if ( id == 8) {
            move_toward(-25,0);
        }
        if ( id == 9) {
            move_toward(-25,0);
        }
        /*if ( id == 2) {
            move_toward(-25,0);
        }
        if ( id == 2) {
            move_toward(-25,0);
        }
        if ( id == 2) {
            move_toward(-25,0);
        }
        if ( id == 2) {
            move_toward(-25,0);
        }
        if ( id == 2) {
            move_toward(-25,0);
        }
        if ( id == 2) {
            move_toward(-25,0);
        }
        if ( id == 2) {
            move_toward(-25,0);
        }*/
        
    }
    void stop() {}

    int set;
    int id = 0;
};

class Block : public Agent
{
public:
    Block(json spec, World &world) : Agent(spec, world)
    {
        add_process(c);
    }

private:
    BlockController c;
};

DECLARE_INTERFACE(Block)

#endif