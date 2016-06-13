#include <GL/glut.h>
#include <stdio.h>
#include<math.h>

void line(int x0,int y0,int xe,int ye)
{
  int dx=xe-x0,dy=ye-y0,steps,k;
  float xinc,yinc,x=x0,y=y0;
  glBegin(GL_POINTS);
  if(abs(dx)>abs(dy))
  steps=abs(dx);
  else
  steps=abs(dy);
  xinc=(float)dx/(float)steps;
  yinc=(float)dy/(float)steps;
  glVertex2i(round(x),round(y));
  for(k=0;k<steps;k++)
  {
    x+=xinc;
    y+=yinc;
    glVertex2i(round(x),round(y));
  }
  glEnd();
}

void display()
{
  glClear(GL_COLOR_BUFFER_BIT);
  line(0,0,400,400);
  glFlush();
}

int main(int argc,char *argv[])
{
  glutInit(&argc,argv);
  glutCreateWindow("Line DDa");
  gluOrtho2D(0,500,0,500);
  glutDisplayFunc(display);
  glutMainLoop();
}
