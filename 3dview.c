#include<GL/glut.h>
void display()
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.1,0.2,0.1,0,0,0,0,0,1);
	glClear(GL_COLOR_BUFFER_BIT);
	glutWireCube(0.9);
	glFlush();
}
int main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitWindowSize(300,300);
	glutCreateWindow("My Window");
	glutDisplayFunc(display);
	glutMainLoop();
}
