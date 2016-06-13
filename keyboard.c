#include<GL/glut.h>
int e_x=3,e_y=3;
void display()
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(e_x,e_y,3,0,0,0,0,0,1);
	glClear(GL_COLOR_BUFFER_BIT);
	glutSolidCube(3);
	glFlush();
}
void reshape(int w, int h)
{
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(90,w/(float)h,0.1,100.0);
	glMatrixMode(GL_MODELVIEW);
}
void keyboard(int key, int x, int y)
{
	switch(key)
	{
		case GLUT_KEY_UP:
			e_y++;
			break;
		case GLUT_KEY_DOWN:
			e_y--;
			break;
		case GLUT_KEY_LEFT:
			e_x--;
			break;
		case GLUT_KEY_RIGHT:
			e_x++;
			break;
	}
	glutPostRedisplay();
}
int main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitWindowSize(300,300);
	glutCreateWindow("My Window");
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutSpecialFunc(keyboard);
	glutMainLoop();
}
