Goal:

Goal of the project is the robot have to go to pick the block passing the hurdles and have to follow the same route all the way to end and drop the box there. Once the box is droped the new box will aprear and the robot will go to collect the box again and the bring it back to drop at robot's origin location. One robot will do this thing 10 times. So 2 will do 20. 

Key Challenges:

1) There are numerous Key challenges we had experienced. The 1st one passing the robot from the walls and have to make there is enough window for the robot to pass and make sure it won't get hit while coming back since there will be a addtional box on the tip of the robot. 
2) The second challenge was the match the checkpoints without hitting the walls.
3) Challege was the find the coordinates of the checkpoint and make sure it comes under the range of the movement.
4) Additionally, attaching the block to the robot was a trick part, but the instruction was provided so it help to see how to attach and delete the block.

Describes how to install and run the code:

1. As you are currently on my git repo, 
there are many steps to download:

    Go to code green button:

    1) you can use the https command to clone:
     https://github.com/sanskarnaik/Project.git

    2) you can use the SSH command to clone:
    git@github.com:sanskarnaik/Project.git

    3) you can download my repo completely using the Download Zip Button.

2. Describes how to run and/or use the project:

Assuming you have docker installed,.
Just run this command on terminal:
docker run -p80:80 -p8765:8765 -v $PWD:/source -it klavins/enviro:v1.4 bash

use your local address in place of $PWD where you downloaded the code.

After that just use:
Make Command
enviro command

open http://localhost on your browser, and you can see the program running.

3. Acknowedges all sources of information or code used:

I used Professor Tamara's Github repo, specifically demo code, and readme files.
https://github.com/tbonaciUW/EEP_520_Winter2022

I also used Professor Klavins Github repo, specifically "ENVIRO: The multi-agent, multi-user, multi-everything simulator" readme on https://github.com/klavinslab/enviro.

and

https://github.com/klavinslab/enviro/tree/master/examples

for Prof Klavins coded examples.

Thank You.