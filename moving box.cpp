#include <stdio.h>
#include <string.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include <math.h>


float i = 0, j = 0, k = 0, r = 0;
float char_co[10] = {0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9};
bool char_re[10] = {0};
float rec_co[4] = {0, 0, 0.5, 1.0};
bool rec_re[4] = {0, 0, 0, 1.0};

float char_change(int k, float sec)
{
	if(char_re[k])
		char_co[k] -= sec;
	else
		char_co[k] += sec;
	if(char_co[k] > 1.0)
		char_re[k] = 1;
	
	else if(char_co[k] < 0.0)
		char_re[k] = 0;

	return char_co[k];
}

float rec_change(int k, float sec)
{
	if(rec_re[k])
		rec_co[k] -= sec;
	else
		rec_co[k] += sec;
	if(rec_co[k] >= 1.0)
		rec_re[k] = 1;
	
	else if(rec_co[k] <= 0.0)
		rec_re[k] = 0;

	return rec_co[k];
}

void WindowSize(int w, int h)
{
	glViewport(0, 0, w, h);            //當視窗長寬改變時，畫面也跟著變
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,20,0,20);      //正交投影
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

static void idle()
{
    glutPostRedisplay();
}

void display()
{
	glClearColor(0.0, 0.0, 0.0, 0.0); 
	glClear(GL_COLOR_BUFFER_BIT);
	

    glPushMatrix();
    	glColor3f(0, 1,rec_change(0, 0.001));
		glRectf(0.0,9.5,20.0,10.0);
		
        glColor3f(rec_change(1, 0.0001),rec_change(1, 0.0001),1); //first box
        glTranslatef(i, 0, 0);
		glRectf(-2.0,10.0,2.0,14.0);
		i += 0.004;
		if(i > 22.0)
			i = -8;
	glPopMatrix();
	glPushMatrix();
		glColor3f(rec_change(2, 0.0005),rec_change(2, 0.0005),1); //second box
        glTranslatef(j, 0, 0);
		glRectf(8.0,10.0,12.0,14.0);
		j += 0.004;
		if(j > 12.0)
			j = -18;
	glPopMatrix();
	glPushMatrix();
		glColor3f(rec_change(3, 0.0005),rec_change(3, 0.0005),1); //third box
        glTranslatef(k, 0, 0);
		glRectf(18.0,10.0,22.0,14.0);
		k += 0.004;		
		if(k > 2.0)
			k = -28;
    glPopMatrix();
    
    glPushMatrix();
    	glColor3f(1,char_change(0, 0.0005),char_change(0, 0.0005));
    	glTranslatef(10, 4.5, 0);
		glRotatef(r, 0, 0, 1);
    	r += 0.01;    	
    	glRasterPos2f(0,3.0);    	
    	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,'M');
    	
    	glColor3f(1,char_change(1, 0.0001),char_change(1, 0.0001));
		glRotated(-30,0,0,1);
    	glRasterPos2f(0,3.0);
    	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,'O');
    	
    	glColor3f(1,char_change(2, 0.0001),char_change(2, 0.0001));
		glRotated(-30,0,0,1);
		glRasterPos2f(0,3.0);
    	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,'V');
    	
    	glColor3f(1,char_change(3, 0.0001),char_change(3, 0.0001));
    	glRotated(-30,0,0,1);
		glRasterPos2f(0,3.0);		
    	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,'I');
    	
    	glColor3f(1,char_change(4, 0.0001),char_change(4, 0.0001));
		glRotated(-30,0,0,1);
		glRasterPos2f(0,3.0);		
    	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,'N');
    	
    	glColor3f(1,char_change(5, 0.0001),char_change(5, 0.0001));
    	glRotated(-30,0,0,1);
		glRasterPos2f(0,3.0);		
    	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,'G');
    	
    	glColor3f(1,char_change(6, 0.0001),char_change(6, 0.0001));
    	glRotated(-60,0,0,1);
		glRasterPos2f(0,3.0);		
    	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,'B');
    	
    	glColor3f(1,char_change(7, 0.0001),char_change(7, 0.0001));
    	glRotated(-30,0,0,1);
		glRasterPos2f(0,3.0);		
    	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,'O');
    	
    	glColor3f(1,char_change(8, 0.0001),char_change(8, 0.0001));
    	glRotated(-30,0,0,1);
		glRasterPos2f(0,3.0);
    	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,'X');
		
		glColor3f(1,char_change(9, 0.0001),char_change(9, 0.0001));    	
    	glRotated(-30,0,0,1);
		glRasterPos2f(0,3.0);		
    	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,'!');
    	
    	
    glPopMatrix();

    glutSwapBuffers();

}

int main()
{
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
 	glutInitWindowSize(600,600);         //視窗長寬
 	glutInitWindowPosition(300,80);         //視窗左上角的位置
 	glutCreateWindow("Moving Square");      //建立視窗

 	glutReshapeFunc(WindowSize);
 	glutDisplayFunc(display);
 	glutIdleFunc(idle);

 	glutMainLoop();

	return 0;
}