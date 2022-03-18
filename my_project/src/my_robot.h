#ifndef __MY_ROBOT_AGENT__H
#define __MY_ROBOT_AGENT__H

#include "enviro.h"
#include <chrono>
#include "styles.h"

using namespace enviro;
using namespace std;

class MyRobotController : public Process, public AgentInterface
{

public:
    MyRobotController() : Process(), AgentInterface() {}

    void init() {}
    void start() {}
    void update()
    {

        if (itr < 11 && id() == 0) {
            if ((position().x == -575 && position().y == 0) || flag_1 == 1) {
                move_toward(-450,0,50,10);
                flag_1 = 1; 
                if (position().x >= -450.1 && position().y >= -0.1) {
                    flag_1 = 0;
                    flag_2 = 1;
                }
            }
            if (flag_2 == 1) {
                move_toward(-450, 200, 50 ,10);
                if (position().x >= -450.1 && position().y >= 199.9) {
                    flag_2 = 0;
                    flag_3 = 1;
                }
            }
            if (flag_3 == 1) {
                move_toward(-250, 200, 50 ,10);
                if (position().x >= -250.14 && position().y >= 199) {
                    flag_3 = 0;
                    flag_4 = 1;
                }
            }
            if (flag_4 == 1) {
                move_toward(-250, 0, 50 ,10);
                if (position().x >= -250.3 && position().y <= -0.1) {
                    flag_4 = 0;
                    flag_5 = 1;
                }
            }
            if (flag_5 == 1) {
                move_toward(-150, 0, 50 ,10);
                if (position().x >= -150.3 && position().y >= 0) {
                    flag_5 = 0;
                    flag_6 = 1;
                }
            }
            if (flag_6 == 1) {
                
                if (k==2) {
                    move_toward(50,0, 50, 10);
                if (sensor_reflection_type(0) == "Block" && sensor_value(0) <= 25) {
                    Agent& other_robot = find_agent(2); 
                    attach_to(other_robot);
                    flag_6 = 0;
                    flag_7 = 1;
                }
                }
                if (k>2) {
                    move_toward(50,0, 50, 10);
                if (sensor_reflection_type(0) == "Block" && sensor_value(0) <= 25) {
                    Agent& other_robot = find_agent(k+15); 
                    attach_to(other_robot);
                    flag_6 = 0;
                    flag_7 = 1;
                }
                }
                     
            }
            if (flag_7 == 1) {
                move_toward(-150, 0, 50, 10);
                if (position().x <= -149 && position().y >= 0) {
                    flag_7 = 0;
                    flag_8 = 1;
                }
            }
            if (flag_8 == 1) {
                move_toward(-250, 0, 50 ,10);
                if (position().x <= -249 && position().y <= -0.1) {
                    flag_8 = 0;
                    flag_9 = 1;
                }
            }
            if (flag_9 == 1) {
                move_toward(-250, 200, 50 ,10);
                if (position().x <= -249 && position().y >= 199) {
                    flag_9 = 0;
                    flag_10 = 1;
                }
            }
            if (flag_10 == 1) {
                move_toward(-425, 200, 50 ,10);
                if (position().x <= -424 && position().y >= 199) {
                    flag_10 = 0;
                    flag_11 = 1;
                }
            }
            if (flag_11 == 1) {
                move_toward(-400, 0, 50, 10);
                if (position().x <= -390 && position().y <= -0.3) {
                    flag_11 = 0;
                    flag_12 = 1;
                }
            }
            if (flag_12 == 1) {
                move_toward(-525, 0, 50, 10); 
                if (position().x <= -524 && position().y <= -0.1) {
                    reset_flag();
                    if (k==2) {
                        remove_agent(k);
                    } else {
                        remove_agent(k+15);
                    }
                    k++;
                    flag_1 = 1;
                    itr++;
                    Agent& v = add_agent("Block", 60, 0, 0, BLOCK1_STYLE);
                }
            }
        }
        //cout << position().x << "," << position().y << endl;



        if (itr < 11 & id() == 1) {
            cout << position().x << "," << position().y << endl;
            if ((position().x == 575 && position().y == 0) || flag_1 == 1) {
                move_toward(450,0,50,10);
                flag_1 = 1; 
                if (position().x <= 451 && position().y >= 0) {
                    flag_1 = 0;
                    flag_2 = 1;
                }
            }
            if (flag_2 == 1) {
                move_toward(450, 200, 50 ,10);
                if (position().x >= 449 && position().y >= 199.9) {
                    flag_2 = 0;
                    flag_3 = 1;
                }
            }
            if (flag_3 == 1) {
                move_toward(250, 200, 50 ,10);
                if (position().x <= 249 && position().y >= 199) {
                    flag_3 = 0;
                    flag_4 = 1;
                }
            }
            if (flag_4 == 1) {
                move_toward(250, 0, 50 ,10);
                if (position().x <= 249 && position().y >= 0) {
                    flag_4 = 0;
                    flag_6 = 1;
                }
            }
            /*if (flag_5 == 1) {
                move_toward(150, 0, 50 ,10);
                if (position().x >= -150.3 && position().y >= 0) {
                    flag_5 = 0;
                    flag_6 = 1;
                }
            }*/
            if (flag_6 == 1) {
                
                if (k==3) {
                    move_toward(150,0, 50, 10);
                if (sensor_reflection_type(0) == "Block" && sensor_value(0) <= 25) {
                    Agent& other_robot = find_agent(3); 
                    attach_to(other_robot);
                    flag_6 = 0;
                    flag_8 = 1;
                }
                }
                if (k>3) {
                    move_toward(150,0, 50, 10);
                if (sensor_reflection_type(0) == "Block" && sensor_value(0) <= 25) {
                    Agent& other_robot = find_agent(k+15); 
                    attach_to(other_robot);
                    flag_6 = 0;
                    flag_8 = 1;
                }
                }
                     
            }
            /*if (flag_7 == 1) {
                move_toward(150, 0, 50, 10);
                if (position().x <= -149 && position().y >= 0) {
                    flag_7 = 0;
                    flag_8 = 1;
                }
            }*/
            if (flag_8 == 1) {
                move_toward(250, 0, 50 ,10);
                if (position().x >= 249 && position().y <= -0.1) {
                    flag_8 = 0;
                    flag_9 = 1;
                }
            }
            if (flag_9 == 1) {
                move_toward(250, 200, 50 ,10);
                if (position().x >= 249 && position().y <= 199) {
                    flag_9 = 0;
                    flag_10 = 1;
                }
            }
            if (flag_10 == 1) {
                move_toward(425, 200, 50 ,10);
                if (position().x >= 424 && position().y <= 199) {
                    flag_10 = 0;
                    flag_11 = 1;
                }
            }
            if (flag_11 == 1) {
                move_toward(400, 0, 50, 10);
                if (position().x >= 390 && position().y <= -0.3) {
                    flag_11 = 0;
                    flag_12 = 1;
                }
            }
            if (flag_12 == 1) {
                move_toward(525, 0, 50, 10); 
                if (position().x >= 524 && position().y <= -0.1) {
                    reset_flag();
                    if (k==3) {
                        remove_agent(k);
                    } else {
                        remove_agent(k+15);
                    }
                    k++;
                    flag_1 = 1;
                    itr++;
                    Agent& v = add_agent("Block", 150, 0, 0, BLOCK2_STYLE);
                }
            }
        }
    }
    void stop() {}

    void reset_flag() {
        flag_1 = 0;
        flag_2 = 0;
        flag_3 = 0;
        flag_4 = 0;
        flag_5 = 0;
        flag_6 = 0;
        flag_7 = 0;
        flag_8 = 0;
        flag_9 = 0;
        flag_10 = 0;
        flag_11 = 0;
        flag_12 = 0;
        flag = 0;
    }

    private :

    int flag_1 = 0;
    int flag_2 = 0;
    int flag_3 = 0;
    int flag_4 = 0;
    int flag_5 = 0;
    int flag_6 = 0;
    int flag_7 = 0;
    int flag_8 = 0;
    int flag_9 = 0;
    int flag_10 = 0;
    int flag_11 = 0;
    int flag_12 = 0;
    int k = 2;
    int flag = 0;
    int itr = 1;
};

class MyRobot : public Agent
{
public:
    MyRobot(json spec, World &world) : Agent(spec, world)
    {
        add_process(c);
    }

private:
    MyRobotController c;
};

DECLARE_INTERFACE(MyRobot)

#endif