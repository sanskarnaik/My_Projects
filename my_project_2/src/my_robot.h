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
//---------------------------------------------------------------------------------------------------------------
// Program for Green Robot Starts:
//--------------------------------------------------------------------------------------------------------------- 
        
        //! This if condition checks the no. of iterations, to bring the block and to deposit.
        //! it sould be eqaul to 10.
        //! and id == 0 represents, it is my first robot.
        //! All other if conditions represents my way points to simulate my robot.

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
                
                
                //! This condition checks for my box, and if the robot and box are too close,
                //! then robot attaches with my box.

                if (k==2) {
                    move_toward(50,0, 50, 10);
                    if (sensor_reflection_type(0) == "Block" && sensor_value(0) <= 25) {
                        Agent& other_robot = find_agent(k); 
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
                    //! This function adds the agent from the simulation screen:
                    Agent& v = add_agent("Block", 60, 0, 0, BLOCK1_STYLE);
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
                    //! This function removes the agent from the simulation screen:    
                        remove_agent(k);
                        k+=2;
                    } else {
                        remove_agent(k+15);
                        k+=2;
                    }
                    flag_1 = 1;
                    itr++;
                }
            }
        }
//---------------------------------------------------------------------------------------------------------------
// Program for Red Robot Starts:
//---------------------------------------------------------------------------------------------------------------        
        
        //! This if condition checks the no. of iterations, to bring the block and to deposit.
        //! it sould be equal to 10.
        //! and id == 1 represents, it is my second robot.
        //! All other if conditions represents my way points to simulate my robot.
        


        if (itr_r < 11 && id() == 1) {
            //cout << position().x << "," << position().y << endl;
            //cout << flag_r4 << endl;
            if ((position().x == 575 && position().y == 0) || flag_r1 == 1) {
                move_toward(450,0,50,10);
                flag_r1 = 1; 
                if (position().x <= 451 && position().y >= 0) {
                    flag_r1 = 0;
                    flag_r2 = 1;
                }
            }
            if (flag_r2 == 1) {
                move_toward(450, 200, 50 ,10);
                if (position().x >= 449 && position().y >= 199.9) {
                    flag_r2 = 0;
                    flag_r3 = 1;
                }
            }
            if (flag_r3 == 1) {
                move_toward(250, 200, 50 ,10);
                if (position().x <= 251 && position().y <= 199) {
                    flag_r3 = 0;
                    flag_r4 = 1;
                }
            }
            if (flag_r4 == 1) {
                move_toward(250, 0, 50 ,10);
                if (position().x <= 250 && position().y <= 0) {
                    flag_r4 = 0;
                    flag_r6 = 1;
                }
            }

            if (flag_r6 == 1) {

                //! This condition checks for my box, and if the robot and box are too close,
                //! then robot attaches with my box.
                
                if (i==3) {
                    move_toward(150,0, 50, 10);
                    if (sensor_reflection_type(0) == "Block" && sensor_value(0) <= 25) {
                        Agent& other_robot = find_agent(i); 
                        attach_to(other_robot);
                        flag_r6 = 0;
                        flag_r8 = 1;
                    }
                }
                if (i>3) {
                    move_toward(150,0, 50, 10);
                    if (sensor_reflection_type(0) == "Block" && sensor_value(0) <= 25) {
                        Agent& other_robot = find_agent(i+13); 
                        attach_to(other_robot);
                        flag_r6 = 0;
                        flag_r8 = 1;
                    }
                }
                     
            }

            if (flag_r8 == 1) {
                move_toward(250, 0, 50 ,10);
                if (position().x >= 249 && position().y <= -0.1) {
                    flag_r8 = 0;
                    flag_r9 = 1;
                    //! This function adds the agent from the simulation screen:
                    Agent& v = add_agent("Block", 135, 0, 0, BLOCK2_STYLE);
                }
            }
            if (flag_r9 == 1) {
                move_toward(250, 200, 50 ,10);
                if (position().x >= 249 && position().y >= 199) {
                    flag_r9 = 0;
                    flag_r10 = 1;
                }
            }
            if (flag_r10 == 1) {
                move_toward(450, 200, 50 ,10);
                if (position().x >= 449 && position().y <= 201) {
                    flag_r10 = 0;
                    flag_r11 = 1;
                }
            }
            if (flag_r11 == 1) {
                move_toward(450, 0, 50, 10);
                if (position().x >= 449 && position().y <= -0.3) {
                    flag_r11 = 0;
                    flag_r12 = 1;
                }
            }
            if (flag_r12 == 1) {
                move_toward(525, 0, 50, 10); 
                if (position().x >= 524 && position().y <= 5) {
                    reset_flag();
                    if (i==3) {
                        //! This function removes the agent from the simulation screen:
                        remove_agent(i);
                        i+=2;
                    } else {
                        remove_agent(i+13);
                        i+=2;
                    }
                    
                    flag_r1 = 1;
                    itr_r++;
                }
            }
        }
    }

    void stop() {}

    
    //! This function reset my all flags so that, the robot can repeat it's path.
    //! I have used two types of flags, one for my blue robot, and the other which has r in that,
    //! for my red robot.

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

        flag_r1 = 0;
        flag_r2 = 0;
        flag_r3 = 0;
        flag_r4 = 0;
        flag_r5 = 0;
        flag_r6 = 0;
        flag_r7 = 0;
        flag_r8 = 0;
        flag_r9 = 0;
        flag_r10 = 0;
        flag_r11 = 0;
        flag_r12 = 0;
    }

    //! This is where i defined all my variables.
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
    //! This variable keeps a check on which box to pull, for green robot:
    int k = 2; 
    //! This variable keeps a check on the no. of boxes pulled so far:
    int itr = 1;

    int flag_r1 = 0;
    int flag_r2 = 0;
    int flag_r3 = 0;
    int flag_r4 = 0;
    int flag_r5 = 0;
    int flag_r6 = 0;
    int flag_r7 = 0;
    int flag_r8 = 0;
    int flag_r9 = 0;
    int flag_r10 = 0;
    int flag_r11 = 0;
    int flag_r12 = 0;
    //! This variable keeps a check on the no. of boxes pulled so far:
    int itr_r = 1;
    //! This variable keeps a check on which box to pull, for red robot:
    int i = 3;
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