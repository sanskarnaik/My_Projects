Holy Special:

Happy Holi!!
May God paint the canvas of your life with vibrant hues.
When I made this, it was Holy in India, festival of colours.
So I kept the theme of my simulation screen as colourful.

Goal of the Project:

1. For my first project, I need to pull 10 boxes each from my single robot. The boxes are kept in an area in a grid.The robot goes to the box and bring the box to the marked area, and the box disappers.

2. For my second project, I need to move my robots through obstacles, and to pick the box, and to drop it in the marked area. I also need to repeat these steps for 10 times each for one robot.

Challenges I faced:

1. First of all enviro is a new concept for me, before attempting the project I need to study all the required methods, classes and objects I need for my project which was time consuming.

2. It was difficult to select which paradigm to use to implement my project, both FSM and Process models are perfect. But I went with Process model, as it is more easy :).

3. Then to choose the way points for which my robot moves one by one, was very difficult, it took more time than writing complete code.

4. Then to add and remove blocks, synchronously was a challenge, as the id() changes when you add or remove block, we need to keep a track on each id() of box.

5. First I made code for the first robots, replicating the code for 2nd robot was difficult as, the directio changed and points changed too, thus making the robot move similar became a challenge.

6. Then to choose a perfect point in the simulation where I can keep the boxes, so that each time robot comes and hit the same position.

Describes how to install and run the code:

1. As you are currently on my git repo, 
there are many steps to download:

    Go to green code button:

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

After that just type:
Make 
enviro 

after that:
open http://localhost on your browser, and you can see the program running.

3. Acknowedges all sources of information or code used:

I used Professor Tamara's Github repo, specifically demo code, and readme files.
https://github.com/tbonaciUW/EEP_520_Winter2022

I also used Professor Klavins Github repo, specifically "ENVIRO: The multi-agent, multi-user, multi-everything simulator" readme on https://github.com/klavinslab/enviro.

and

https://github.com/klavinslab/enviro/tree/master/examples

for Prof Klavins coded examples.

Thank You.
