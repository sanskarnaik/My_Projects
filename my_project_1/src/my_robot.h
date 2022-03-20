#ifndef __MY_ROBOT_AGENT__H
#define __MY_ROBOT_AGENT__H

#include "enviro.h"
#include <vector>
#include <string>

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

        //-------------------------------------------------------------------------------------------------------------
        //Code for Green Robot:
        //-------------------------------------------------------------------------------------------------------------


        //! This if condition is for green robot,
        if (id() == 0) {
            //! this condition checks whether the robot has dropped the box?
            if (flag_1 == 0) {
                move_toward(g_x[i_g], y[j_g], 50, 10);
                if (sensor_reflection_type(0) == boxes[j_g] && sensor_value(0) <= 25) {
                    Agent& other_robot = find_agent(a_g); 
                    attach_to(other_robot);
                    flag_1 = 1;
                    j_g++;
                    if (j_g>4 && set_g) {
                        i_g++;
                        set_g = false;
                    }
                }
            }
            //! This condition check whether the robot reached to the box?
            if (flag_1 == 1) {
                move_toward(-575, 0, 50, 10);
                if (position().x <= -524 && position().y <= 30) {
                    remove_agent(a_g);
                    flag_1 = 0;
                    a_g++;
                }
            }
        }
        //-------------------------------------------------------------------------------------------------------------
        //Code for Red Robot:
        //-------------------------------------------------------------------------------------------------------------


        //! This if condition is for green robot,
        if (id() == 1) {
            //! this condition checks whether the robot has dropped the box?
            if (flag_r1 == 0) {
                move_toward(r_x[i_r], y[j_r], 50, 10);
                if (sensor_reflection_type(0) == boxes[j_r] && sensor_value(0) <= 25) {
                    Agent& other_robot = find_agent(a_r);
                    attach_to(other_robot);
                    flag_r1 = 1;
                    j_r++;
                    if (j_r>4 && set_r) {
                        i_r++;
                        set_r = false;
                    }
                }
            }
            //! This condition check whether the robot reached to the box?
            if (flag_r1 == 1) {
                move_toward(575, 0, 50, 10);
                if (position().x >= 524 && position().y <= 30) {
                    remove_agent(a_r);
                    flag_r1 = 0;
                    a_r++;
                }
            }
        }
    }
    void stop() {}

    //! Position of green boxes:
    vector<double> g_x = {-200,-100};
    //! y-axis position is common for all boxes:
    vector<double> y = {230, 80, -20, -140, -220, 230, 80, -20, -140, -220};
    //! Position of red boxes:
    vector<double> r_x = {200, 100};
 
    int i_g=0, j_g=0;
    int i_r=0, j_r=0;
    bool set_g = true;
    bool set_r = true;
    int flag_1 = 0;
    int flag_r1 = 0;
    int a_g = 2, a_r = 12;

    //! All boxes names:
    vector<string> boxes = {"Block1", 
                            "Block2", 
                            "Block3", 
                            "Block4", 
                            "Block5", 
                            "Block5", 
                            "Block4", 
                            "Block3", 
                            "Block2", 
                            "Block1"};
};


//! This is my My Robot Class, which inherits from Agent class, that why I can use all my agent function.

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