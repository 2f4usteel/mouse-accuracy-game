# Test your mouse accuracy using this simple game implemented in 'OpenGL' using 'C'

This project was created during my college days for the course 'Computer Graphics' which was a part of the curriculum. I used to a play a lot of First Person Shooter games and wanted to significantly boost my aim, Therefore decided to create a simple game which would help me achieve that.

## How does it works?
Once you execute the program, a window is created which has a tiny square inside it. Clicking on that square for the first time, a timer for 60 seconds is started. The score is incremented only when you tap on the square region. You can change the color of the square by tapping anywhere in the window apart from the square. After 60 seconds, the window will disappear and the score will be displayed in the terminal.

## Requirements
* [GCC](https://gcc.gnu.org/)
* [OpenGL](https://www.opengl.org/)
* [GLUT](https://www.opengl.org/resources/libraries/glut/)

Install the requirements mentioned above.
Once the requirements are met, you can move onto execution.

## Execution

Use the following commands to execute the program

**Ubuntu/Debian**

`gcc -o project project.c -lGL -lGLU -lglut`

`./project`

**OSX/MAC**

`gcc -framework OpenGL -framework GLUT -o project project.c`

`./project`

**CMake based build**

` mkdir build && cd build`

 `cmake ..`

 `make`

## Preview
![Preview](https://i.imgur.com/dzMfJvZ.gif)

## Output
![Output](https://i.imgur.com/5QF74q6.png)
