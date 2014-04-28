#include <stdlib.h>
#include <stdio.h>
#include <GL/glut.h>
int score=0;
float rectX = 0.f;
float rectY = 0.f;

void init()
{
   glClearColor (0.0, 0.0, 0.0, 0.0);
}
 
float random1()
{
    return rand() % 3 - 1;
}
 
void drawObjects(GLenum mode)
{
   if(mode == GL_SELECT)
   glMatrixMode(GL_MODELVIEW);
   glLoadName(1);
   glPushMatrix();
   glTranslatef(rectX, rectY, 0.f);
   glColor3ub(rand()%255,rand()%255,rand()%255); //object in random color mode
   //glColor3f(1.0,1.0,1.0); // for static color comment the above code and uncomment this line.
   glRectf(-0.05f, -0.05f, 0.05f, 0.05f);
   glPopMatrix();
}
 
void display()
{
   glClear(GL_COLOR_BUFFER_BIT);
   drawObjects(GL_RENDER);
   glFlush();
}

void processHits (GLint hits, GLuint buffer[])
{
   if(hits==1)
   {
      Timer(0); //start timer on first click..
      score++;
   }
   if(hits>=1)
   {
       rectX = random1();
       rectY = random1();
       printf("Your Score is %d Clicks Per Minute!\n",score);
   }
   
}
 
 
#define SIZE 512
 
void mouse(int button, int state, int x, int y)
{
   GLuint selectBuf[SIZE];
   GLint hits;
   GLint viewport[4];
   if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
   {
   glGetIntegerv (GL_VIEWPORT, viewport);
   glSelectBuffer (SIZE, selectBuf);
   glRenderMode(GL_SELECT);
   glInitNames();
   glPushName(0);
   glMatrixMode (GL_PROJECTION);
   glPushMatrix ();
   glLoadIdentity ();
/*  create 5x5 pixel picking region near cursor location */
   gluPickMatrix ((GLdouble) x, (GLdouble) (viewport[3] - y),
                  5.0, 5.0, viewport);
   gluOrtho2D (-2.0, 2.0, -2.0, 2.0);
   drawObjects(GL_SELECT);
   glMatrixMode (GL_PROJECTION);
   glPopMatrix ();
   glFlush ();
   hits = glRenderMode (GL_RENDER);
   processHits (hits, selectBuf);
   glutPostRedisplay();
   }
}
 
void reshape(int w, int h)
{
   glViewport(0, 0, w, h);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   gluOrtho2D (-2.0, 2.0, -2.0, 2.0);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}
 
void keyboard(unsigned char key, int x, int y)
{
   switch (key) {
   case 27:        // ?!?
         exit(0);
         break;
   }
}
 
 
void Timer1()
{
  exit(0);
}
 
int Timer(int iUnused)
{
   
    glutTimerFunc(10000, Timer1, 0);
   
}
 
/* Main Loop */
void main(int argc, char** argv)
{
   
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
   glutInitWindowSize (400, 400);
   glutInitWindowPosition (80, 100);
   glutCreateWindow ("click on the object, fast!");
   init ();
   glutReshapeFunc (reshape);
   glutDisplayFunc(display);
   glutMouseFunc (mouse);
   glutKeyboardFunc (keyboard);
   //Timer(0);
   glutMainLoop();
}

//***********************************************************************//
//                                                                      //
//  A Simple CLick Game, checking your reflexes for 60 seconds...      //
//                                                                    //     
//   Author: Suresh Bist.K (Ma'Ga BA*STeEl)                          //
//                                                                  //
//   Program: OpenGL and Picking                                   //
//                                                                //
//   Description:Click on the object(rectangle) for a  minute!   //     
//                                                              //
//   Date:         28 April 2014                               //
//                                                            //
//   License: Free!                                          //
//                                                          //
//   Contact : FB/2f4usteel                                // 
//           : Steam/2f4usteel                            //
//           : g+/2f4usteel                              //
//           : reddit/2f4usteel                         //
//           : youtube/2f4usteel                       //
//           : github/2f4usteel                       //
//***************************************************//
