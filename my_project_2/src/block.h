#ifndef __BLOCK_AGENT__H
#define __BLOCK_AGENT__H

#include "enviro.h"

using namespace enviro;
using namespace std;

class BlockController : public Process, public AgentInterface
{

public:
    BlockController() : Process(), AgentInterface() {}

    void init() {}
    void start() {}
    void update() {}
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