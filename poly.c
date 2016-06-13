#include<GL/glut.h>
#include<GL/gl.h>
#include <GL/glu.h>
#include<stdio.h>

void display()
{
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(2.0,1.5,1.0);
  glBegin(GL_POLYGON);
  glVertex2f(250,250);
  glVertex2f(350,50);
  glVertex2f(450,200);
  glEnd();
  glFlush();
}
int main(int argc,char *argv[])
{
  glutInit(&argc,argv);
  glutCreateWindow("Test");
  gluOrtho2D(0,500,0,500);
  glutDisplayFunc(display);
  glutMainLoop();
  return 0;
}
