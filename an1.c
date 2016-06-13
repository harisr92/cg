
#include <GL/glut.h>

int rAngle=0;


/*Call back function for display changes*/

void display(void)
{
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glRotatef(-rAngle, 0.0f, 0.0f, -1.0f);
	glBegin(GL_TRIANGLES); //Begin triangle coordinates
	//Triangle
	glVertex3f(-0.5f, 0.5f, -5.0f);
	glVertex3f(-1.0f, 1.5f, -5.0f);
	glVertex3f(-1.5f, 0.5f, -5.0f);
	glEnd(); //End triangle coordinates
	glutSwapBuffers(); //Send the 3D scene to the screen
}

void time_update(int value){
    rAngle += 1.0f;
    if(rAngle > 360){
        rAngle -= 360;
    }
    glutPostRedisplay(); // Inform GLUT that the display has changed
    glutTimerFunc(25,time_update,0);//Call update after each 25 millisecond
}
void reshape(int width,int height)
{
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0,
				   (double)width / (double)height,
				   1.0,
				   200.0);
}

int main(int argc,char ** argv)
{
	
	/*init window*/
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(250,250);
	glutInitWindowPosition(100,100);
	glutCreateWindow("Hello GL");
	
    /*init GL*/
	glClearColor(0.0,0.0,0.0,0.0);
	


	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutTimerFunc(25,time_update,0);
	
	/*Loop forever */
	glutMainLoop();
	return 0;
}