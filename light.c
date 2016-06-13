#include<GL/glut.h>
int e_x=3,e_y=3;
char light;
GLfloat LightAmbient[]={0.9f,0.9f,0.9f,1.0f};
GLfloat LightDiffuse[]={1.0f,1.0f,1.0f,1.0f};
GLfloat LightPosition[]={0.0f,0.10f,2.0f,1.0f};
void display()
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glShadeModel(GL_SMOOTH);
	gluLookAt(e_x,e_y,3,0,0,0,0,0,1);
	glClear(GL_COLOR_BUFFER_BIT);
	//glutSolidCube(3);
	glLightfv(GL_LIGHT1,GL_DIFFUSE, LightDiffuse);
	glLightfv(GL_LIGHT2,GL_AMBIENT, LightAmbient);

	glLightfv(GL_LIGHT1,GL_POSITION, LightPosition);
	glLightfv(GL_LIGHT2,GL_POSITION, LightPosition);

	glEnable(GL_LIGHTING);

	if(light=='A')
	{
		glEnable(GL_LIGHT2);
	}
	else if(light=='D')
	{
		glEnable(GL_LIGHT1);
	}
	else if(light=='B')
	{
		glDisable(GL_LIGHT1);
		glDisable(GL_LIGHT2);
	}
	glColor3f(1,0,0);
	glutWireSphere(0.3,16,16);
	glutSolidTorus(0.275,0.85,8,15);
	glFlush();
}
void kbdfun(unsigned char key,int x,int y)
{
	if(key=='a')
	{
		light='A';
	}
	else if(key=='d')
	{
		light='D';
	}
	else if(key=='b')
	{
		light='B';
	}
	glutPostRedisplay();
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
	glutKeyboardFunc(kbdfun);
	glutMainLoop();
}
