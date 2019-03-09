#include <stdio.h>
#include <string.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include <math.h>

int s1 = 0;

void WindowSize(int w, int h)
{
	glViewport(0, 0, w, h);            //當視窗長寬改變時，畫面也跟著變
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,20,0,20);      //正交投影
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void idle()
{
    glutPostRedisplay();
}

void win()
{
	glClearColor(0, 0, 0, 0.6); 
	glClear(GL_COLOR_BUFFER_BIT);
	GLUquadricObj* head = gluNewQuadric();

	glPushMatrix();   //sun
	if(s1 / 500 % 2 == 0)
		glColor3f(1, 0.5, 0);
	else
		glColor3f(1, 1, 0);
	glTranslatef(10, -11, 0);
	gluDisk(head, 0, 25, 40, 40);
	glPopMatrix();

	glPushMatrix();   //頭 
	glColor3f( 0.95, 0.85, 0.75);
	glTranslatef(10, 13, 0);
	gluDisk(head, 0, 3, 20, 20);
	glPopMatrix();
	
	glPushMatrix();   //身體、腳 
	glColor3f(0, 0, 0.7);
	glRectf(8, 4, 12, 9.7);
	glColor3f(0.2, 0.2, 0.2);
	glRectf(6, 0.5, 8, 4.5);
	glColor3f(0.2, 0.2, 0.2);
	glRectf(10.5, 0, 12.5, 3.9);
	glColor3f(0.2, 0.2, 0.2);
	glTranslatef(5.94, 4, 0);
	glRotatef(-15, 0, 0 ,1);
	glRectf(0, 0, 3.8, 2);	
	glPopMatrix();
	
	glPushMatrix();   //手 
	glColor3f(0, 0, 0.7);
	glTranslatef(5, 5, 0);
	glRotatef(-20, 0, 0 ,1);
	glRectf(0, 0, 2, 5);
	glPopMatrix();
	glPushMatrix();
	glColor3f(0, 0, 0.7);
	glTranslatef(12, 9.5, 0);
	glRotatef(-10, 0, 0 ,1);
	glRectf(0, 0, 2, 6);	
	glPopMatrix();
	
	if(s1 / 200 % 2 == 0)
		glColor3f(1, 0, 0);
	else
		glColor3f(0, 0, 0);
	glRasterPos2f(4,17);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'W');
	//glColor3f(1, 0, 0);
	glRasterPos2f(10,17);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'I');
	//glColor3f(1, 0, 0);
	glRasterPos2f(16,17);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'N');
	
	s1++;

}




void display()
{
	win();
	
	
	glutSwapBuffers();
}


int main()
{
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
 	glutInitWindowSize(600,600);         //視窗長寬
 	glutInitWindowPosition(300,80);         //視窗左上角的位置
 	glutCreateWindow("SKI JUMP");      //建立視窗

 	glutReshapeFunc(WindowSize);
 	glutDisplayFunc(display);
 	glutIdleFunc(idle);

 	glutMainLoop();

	return 0;
}