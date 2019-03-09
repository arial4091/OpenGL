//Dev C++ 5.4.1

#include <stdio.h>
#include <string.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include <math.h>

void ski();
void background2();
void right_view();

unsigned int count = 0;
float color_change[7] = {0};
float a = 0, b = 0, c = 0;
float r1 = 0, trax = 0, tray = 0, r2 = 0, tt1 = 0, tt2 = 0;
bool drop = false;
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

void lamp_change()
{
	if(count <= 20000)	
		count++;
	if(count >= 3000 && count < 5000){
		color_change[0] += 0.1;
		if(color_change[0] >= 0.4)
			color_change[0] = 0.4;
	}
	if(count >= 5000 && count < 7000){
		color_change[1] += 0.1;
		if(color_change[1] >= 0.4)
			color_change[1] = 0.4;
	}
	if(count >= 7000 && count < 9000){
		color_change[2] += 0.1;
		if(color_change[2] >= 0.4)
			color_change[2] = 0.4;
	}
	if(count >= 7140 && count < 20000){
		color_change[3] -= 0.004;
		color_change[4] -= 0.008;		
	}
	if(count >= 7040 && count < 7160){
		color_change[5] += 0.2;
		color_change[6] += 0.2;
	}
}

void first_back()
{
	glClearColor(1.0, 1.0, 1.0, 1.0); 
	glClear(GL_COLOR_BUFFER_BIT);
	GLUquadricObj* lamp = gluNewQuadric();
	lamp_change();	
	
	glBegin(GL_LINES);
		glLineWidth(20.0);  //跑道線 
		glColor3f( 0, 0, 0);glVertex2f(11, 20);
		glColor3f( 0, 0, 0);glVertex2f(1, 0);
		glColor3f( 0, 0, 0);glVertex2f(25, 20);
		glColor3f( 0, 0, 0);glVertex2f(15, 0);
		glLineWidth(1.0);
	glEnd();	
	glPushMatrix();    //起跑線 
		glColor3f( 1, 1, 0);
		glTranslatef(3.05, 4, 0);
        glRotated(-27.71,0,0,1);
        glRectf(0.0,0.0,12.267,0.4);
    glPopMatrix();
	glPushMatrix();    //紅綠燈
		glColor3f( 0, 0.2, 0);  
		glTranslatef(2.0, 11, 0);
        glRectf(0.0,0.0,2.5,7); 
        glTranslatef(0.75, -1, 0);
        glRectf(0.0,0.0,1,1);
	glPopMatrix();
	glPushMatrix();    //紅燈
		glColor3f( 0.6+color_change[0], 0, 0);
        glTranslatef(3.25, 16.65, 0);
        gluDisk(lamp,0,1,30,30);
	glPopMatrix();
	glPushMatrix();    //黃燈
		glColor3f( 0.6+color_change[1], 0.6+color_change[1], 0);
        glTranslatef(3.25, 14.5, 0);
        gluDisk(lamp,0,1,30,30);
	glPopMatrix();
	glPushMatrix();    //綠燈
		glColor3f( 0, 0.6+color_change[2], 0);
        glTranslatef(3.25, 12.25, 0);
        gluDisk(lamp,0,1,30,30);
	glPopMatrix();
	glPushMatrix();
		glTranslatef(color_change[3], color_change[4], 0);
		ski();
	glPopMatrix();	
}

void ski()
{
	int i, j;
	GLUquadricObj* head = gluNewQuadric();
			
	glPushMatrix();        //頭
		glColor3f( 0.95, .85, 0.75);
		glTranslatef(11, 15, 0);  
		gluDisk(head,0,1,30,30); 
	glPopMatrix();
	glBegin(GL_POLYGON);  //身體 
		glColor3f( 0, 0, 0.7);glVertex2f(9.9, 13.9);
		glColor3f( 0, 0, 0.7);glVertex2f(12.2, 13.8);
		glColor3f( 0, 0, 0.7);glVertex2f(12.0, 9.8);
		glColor3f( 0, 0, 0.7);glVertex2f(9.7, 9.9);
	glEnd();
	glBegin(GL_POLYGON);  //右雪橇
		glColor3f( 0.6, 0.4, 0.4);glVertex2f(8.6, 2.4);
		glColor3f( 0.6, 0.4, 0.4);glVertex2f(9.7, 2.3);
		glColor3f( 0.6, 0.4, 0.4);glVertex2f(10.0, 8.5);
		glColor3f( 0.6, 0.4, 0.4);glVertex2f(8.9, 8.6);
	glEnd();
	glBegin(GL_POLYGON);  //左雪橇
		glColor3f( 0.6, 0.4, 0.4);glVertex2f(10.7, 2.3);
		glColor3f( 0.6, 0.4, 0.4);glVertex2f(11.7, 2.0);
		glColor3f( 0.6, 0.4, 0.4);glVertex2f(13.0, 8.2);
		glColor3f( 0.6, 0.4, 0.4);glVertex2f(12.0, 8.5);
	glEnd();	
	glBegin(GL_POLYGON);  //右大腿
		glColor3f( 0.3, 0.3, 0.3);glVertex2f(9.7, 9.7);
		glColor3f( 0.3, 0.3, 0.3);glVertex2f(10.9, 9.65);
		glColor3f( 0.3, 0.3, 0.3);glVertex2f(10.3, 7.65);
		glColor3f( 0.3, 0.3, 0.3);glVertex2f(9.2, 7.7);
	glEnd();
	glBegin(GL_POLYGON);  //右小腿
		glColor3f( 0.3, 0.3, 0.3);glVertex2f(9.2, 7.7);
		glColor3f( 0.3, 0.3, 0.3);glVertex2f(10.3, 7.7);
		glColor3f( 0.3, 0.3, 0.3);glVertex2f(9.8, 5.2);
		glColor3f( 0.3, 0.3, 0.3);glVertex2f(8.9, 5.6);
	glEnd();
	glBegin(GL_POLYGON);  //左大腿
		glColor3f( 0.3, 0.3, 0.3);glVertex2f(10.8, 9.65);
		glColor3f( 0.3, 0.3, 0.3);glVertex2f(12.0, 9.6);
		glColor3f( 0.3, 0.3, 0.3);glVertex2f(12.2, 7.6);
		glColor3f( 0.3, 0.3, 0.3);glVertex2f(11.0, 7.6);
	glEnd();
	glBegin(GL_POLYGON);  //左小腿
		glColor3f( 0.3, 0.3, 0.3);glVertex2f(11.0, 7.6);
		glColor3f( 0.3, 0.3, 0.3);glVertex2f(12.2, 7.6);
		glColor3f( 0.3, 0.3, 0.3);glVertex2f(12.4, 5.5);
		glColor3f( 0.3, 0.3, 0.3);glVertex2f(11.5, 5.2);
	glEnd();
	glPushMatrix();    //右手杖 
		if(count >= 7020){
			glTranslatef(9.65, 13.4, 0);
			glRotated(color_change[5],0,0,1);
			glTranslatef(-9.65, -13.4, 0);
		}
		glColor3f( 1, 0, 0);
		glTranslatef(7.05, 5.3, 0);
        glRotated(7.0,0,0,1);
        glRectf(0.0,0.0,0.3,7.0);
	glPopMatrix(); 
	glPushMatrix();         //左手杖 
		if(count >= 7020){
			glTranslatef(12.35, 13.275, 0);
			glRotated(color_change[6],0,0,1);
			glTranslatef(-12.35, -13.275, 0);
		}
        glTranslatef(13.7, 4.3, 0);  
        glRotated(0,0,0,1);
        glRectf(0.0,0.0,0.3,7.0);
    glPopMatrix();
    glPushMatrix();        //右手
    	if(count >= 7020){
    		glTranslatef(9.65, 13.4, 0);
			glRotated(color_change[5],0,0,1);
			glTranslatef(-9.65, -13.4, 0);
    	}
	glBegin(GL_POLYGON);  
		glColor3f( 0, 0, 0.7);glVertex2f(9.7, 13.9);
		glColor3f( 0, 0, 0.7);glVertex2f(9.6, 12.9);
		glColor3f( 0, 0, 0.7);glVertex2f(6.6, 10.6);
		glColor3f( 0, 0, 0.7);glVertex2f(6.0, 11.0);
	glEnd();
	glPopMatrix(); 
	glPushMatrix();       //左手
		if(count >= 7020){
			glTranslatef(12.35, 13.275, 0);
			glRotated(color_change[6],0,0,1);
			glTranslatef(-12.35, -13.275, 0);
		}
	glBegin(GL_POLYGON);  
		glColor3f( 0, 0, 0.7);glVertex2f(12.4, 13.8);
		glColor3f( 0, 0, 0.7);glVertex2f(14.6, 10.0);
		glColor3f( 0, 0, 0.7);glVertex2f(13.9, 9.7);
		glColor3f( 0, 0, 0.7);glVertex2f(12.35, 12.75);
	glEnd();  
	glPopMatrix(); 
}

void background2()
{
	GLUquadricObj* stone = gluNewQuadric();
	
	glPushMatrix();
	glBegin(GL_TRIANGLES);  //聖誕樹 1
		glColor3f( 0, 1, 0);glVertex2f(30, 16);
		glColor3f( 0, 1, 0);glVertex2f(28, 13);
		glColor3f( 0, 1, 0);glVertex2f(32, 13);
		glColor3f( 0, 1, 0);glVertex2f(30, 14);
		glColor3f( 0, 1, 0);glVertex2f(27.5, 11);
		glColor3f( 0, 1, 0);glVertex2f(32.5, 11);
		glColor3f( 0, 1, 0);glVertex2f(30, 13);
		glColor3f( 0, 1, 0);glVertex2f(27, 9);
		glColor3f( 0, 1, 0);glVertex2f(33, 9);
	glEnd();
	glColor3f( 0.3, 0.1, 0.1);glRectf(29, 9, 31, 0);	
	
	glTranslatef(3, -0.5, 0);
	glBegin(GL_TRIANGLES);  //聖誕樹 2
		glColor3f( 0, 0.8, 0);glVertex2f(30, 16);
		glColor3f( 0, 0.8, 0);glVertex2f(28, 13);
		glColor3f( 0, 0.8, 0);glVertex2f(32, 13);
		glColor3f( 0, 0.8, 0);glVertex2f(30, 14);
		glColor3f( 0, 0.8, 0);glVertex2f(27.5, 11);
		glColor3f( 0, 0.8, 0);glVertex2f(32.5, 11);
		glColor3f( 0, 0.8, 0);glVertex2f(30, 13);
		glColor3f( 0, 0.8, 0);glVertex2f(27, 9);
		glColor3f( 0, 0.8, 0);glVertex2f(33, 9);
	glEnd();
	glColor3f( 0.3, 0.1, 0.1);glRectf(29, 9, 31, 0);
	
	glTranslatef(20, -1.5, 0);
	glBegin(GL_TRIANGLES);  //聖誕樹 3
		glColor3f( 0, 0.8, 0);glVertex2f(30, 16);
		glColor3f( 0, 0.8, 0);glVertex2f(28, 13);
		glColor3f( 0, 0.8, 0);glVertex2f(32, 13);
		glColor3f( 0, 0.8, 0);glVertex2f(30, 14);
		glColor3f( 0, 0.8, 0);glVertex2f(27.5, 11);
		glColor3f( 0, 0.8, 0);glVertex2f(32.5, 11);
		glColor3f( 0, 0.8, 0);glVertex2f(30, 13);
		glColor3f( 0, 0.8, 0);glVertex2f(27, 9);
		glColor3f( 0, 0.8, 0);glVertex2f(33, 9);
	glEnd();
	glColor3f( 0.3, 0.1, 0.1);glRectf(29, 9, 31, 0);
	
	glTranslatef(40, -4, 0);
	glBegin(GL_TRIANGLES);  //聖誕樹 4
		glColor3f( 0, 1, 0);glVertex2f(30, 16);
		glColor3f( 0, 1, 0);glVertex2f(28, 13);
		glColor3f( 0, 1, 0);glVertex2f(32, 13);
		glColor3f( 0, 1, 0);glVertex2f(30, 14);
		glColor3f( 0, 1, 0);glVertex2f(27.5, 11);
		glColor3f( 0, 1, 0);glVertex2f(32.5, 11);
		glColor3f( 0, 1, 0);glVertex2f(30, 13);
		glColor3f( 0, 1, 0);glVertex2f(27, 9);
		glColor3f( 0, 1, 0);glVertex2f(33, 9);
	glEnd();
	glColor3f( 0.3, 0.1, 0.1);glRectf(29, 9, 31, 0);
	glPopMatrix();
	
	glPushMatrix();  //雪人  
	glColor3f(1, 1, 1);  // 身體 
	glTranslatef(60, 6, 0);
	gluDisk(stone, 0, 2.5, 20, 20);
	glTranslatef(0, 3.4, 0);
	gluDisk(stone, 0, 1.7, 20, 20);
	glColor3f(0, 0, 0);  // 眼睛 
	glTranslatef(-0.6, 0.5, 0);
	gluDisk(stone, 0, 0.2, 20, 20);
	glTranslatef(1.2, 0, 0);
	gluDisk(stone, 0, 0.2, 20, 20);
	glTranslatef(-0.6, -0.2, 0);
	glBegin(GL_TRIANGLES);  //鼻子
		glColor3f( 1, 0.6, 0);glVertex2f(0, 0);
		glColor3f( 1, 0.6, 0);glVertex2f(-1, -1);
		glColor3f( 1, 0.6, 0);glVertex2f(0.3, -0.6);
	glEnd();	
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(86, 1.6, 0);
	glBegin(GL_TRIANGLES);  //房子 
		glColor3f( 0.6, 0.2, 0.2);glVertex2f(0, 7);
		glColor3f( 0.2, 0.1, 0.1);glVertex2f(-3.3, 3);
		glColor3f( 0.2, 0.2, 0.2);glVertex2f(3.3, 3);
	glEnd();
	glColor3f( 0.4, 0.3, 0.3);
	glRectf(-2, -2, 2, 3);
	glColor3f( 0.6, 0.6, 0.5);
	glRectf(-0.8, 1, 0.8, 2.6);
	glColor3f( 0, 0, 0);
	glRectf(-0.05, 1, 0.05, 2.6);
	glRectf(-0.8, 1.75, 0.8, 1.85);
	
	glPopMatrix();
	
	glBegin(GL_POLYGON);  //跑道 
		glColor3f( 1, 1, 1);glVertex2f(0, 11);
		glColor3f( 1, 1, 1);glVertex2f(100, 0);
		glColor3f( 1, 1, 1);glVertex2f(100, 0);
		glColor3f( 1, 1, 1);glVertex2f(0, 0);
	glEnd();

	glPushMatrix();   //石頭 
	glColor3f(1, 1, 1);
	glTranslatef(16, 9, 0);
	gluDisk(stone, 0, 1.5, 20, 20);
	glTranslatef(-1.2, 0, 0);
	gluDisk(stone, 0, 1.5, 20, 20);
	glPopMatrix();	
	
	
	
}

void right_view()
{
	glClearColor(0.4, 0.4, 1.0, 0.6); 
	glClear(GL_COLOR_BUFFER_BIT);
	GLUquadricObj* stone = gluNewQuadric();
	
	glPushMatrix(); 
	glTranslatef(a, 0, 0);
	background2();
	glPopMatrix();
	if(a >= -80){
		a -= 0.01;
		b -= 0.0011;
	}
	if(a <= -80){
		c += 0.01;
		b -= 0.0011;
	}
		
	glPushMatrix();   //整個人的移動
	glTranslatef(c, b, 0);

	glPushMatrix();   //頭 
	glColor3f( 0.95, 0.85, 0.75);
	glTranslatef(2, 14, 0);
	gluDisk(stone, 0, 0.4, 20, 20);
	glPopMatrix();
	
	glPushMatrix();   //身體、腳 
	glColor3f(0, 0, 0.7);
	glRectf(1.8, 12, 2.2, 13.5);
	glColor3f(0.2, 0.2, 0.2);
	glTranslatef(1.46, 10.6, 0);
	glRotatef(-15, 0, 0 ,1);
	glRectf(0, 0, 0.4, 1.4);	
	glPopMatrix();
	
	glPushMatrix();   //雪橇
	glColor3f(0.4, 0.2, 0.2);
	glTranslatef(0.8, 10.6, 0);
	glRotatef(-13, 0, 0 ,1);
	glRectf(0, 0, 2, 0.2);
	glColor3f(0, 0, 0.7);  //手 
	glTranslatef(0.8, 2.5, 0);
	glRotatef(4, 0, 0 ,1);
	glRectf(0, 0, 1.2, 0.3);
	glColor3f( 1, 0, 0);
	glTranslatef(0.9, -2.7, 0);
	glRectf(0.0,0.0,0.1,3.5);
	glPopMatrix();
	
	glPopMatrix();
	
	
}

void fly_back()
{
	glClearColor(0.4, 0.4, 1.0, 0.6); 
	glClear(GL_COLOR_BUFFER_BIT);
	GLUquadricObj* circle = gluNewQuadric();

	glBegin(GL_POLYGON);  //滑雪道 
		glColor3f( 1, 1, 1);glVertex2f(0, 0); 
		glColor3f( 1, 1, 1);glVertex2f(0, 7);
		glColor3f( 1, 1, 1);glVertex2f(8, 12);
		glColor3f( 1, 1, 1);glVertex2f(20, 10);
		glColor3f( 1, 1, 1);glVertex2f(20, 0);		
	glEnd();
	
	glPushMatrix();  //弧形滑雪道 
	glColor3f( 0.4, 0.4, 1);
	glTranslatef(0, 16, 0);	
	gluDisk(circle, 0, 10, 30, 20);
	glPopMatrix();
	
	glPushMatrix();  //人
	glTranslatef(0, 16, 0);	
	if (drop && tray <= 2){
		glTranslatef(tt1, tt2, 0);	
		tt1 += 0.008;
		tt2 -= 0.0017;
	}
	if(r1 <= 64)
		r1 += 0.05;
	else{
		glTranslatef(6.5+trax, -4+tray, 0);
		glRotatef(r2, 0, 0, 1);
		glTranslatef(-6.5-trax, 4-tray, 0);
		glTranslatef(trax, tray, 0);
		if(!drop && tray <=9){
			tray += 0.006;
			trax += 0.002;
		}
		else if (drop && tray >= 2){
			tray -= 0.006;
			trax += 0.002;
		}
		if(tray >= 9)
			drop = true;
		
		if(r2 <= 640)
			r2 += 0.24;
	}
	glRotatef(r1, 0, 0, 1);
	
	glPushMatrix(); 	
	glColor3f( 0.95, .85, 0.75);  //頭 
	glTranslatef(-1, -6.6, 0);
	gluDisk(circle, 0, 0.4, 20, 20);
	glPopMatrix();
	glColor3f( 0, 0, 0.7);   //身體 
	glRectf(-1.25, -7.1, -0.75, -8.5);
	glColor3f( 0.3, 0.3, 0.3);  //腳 
	glRectf(-1.25, -8.6, -0.75, -10);
	glColor3f( 0.6, 0.4, 0.4);   //雪橇 
	glRectf(-2.25, -10, 0.25, -10.2);
	glPushMatrix();    
	glColor3f( 0, 0, 0.7);     //手
	glTranslatef(-0.75, -7.3, 0);
	glRotatef(-19, 0, 0, 1);
	glRectf(0, 0, 1.45, -0.3);
	glColor3f( 1, 0, 0);    //手杖 
	glTranslatef(1.3, 0.3, 0);
	glRotatef(-90, 0, 0, 1);
	glRectf(0, 0, 3.6, 0.15);
	
	glPopMatrix();
	glPopMatrix();
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
	if(glutGet(GLUT_ELAPSED_TIME) <= 6500)
		first_back();
	
	else if(glutGet(GLUT_ELAPSED_TIME) > 6500 && glutGet(GLUT_ELAPSED_TIME) <= 11500)
		fly_back();
	else if(glutGet(GLUT_ELAPSED_TIME) > 11500 && glutGet(GLUT_ELAPSED_TIME) <= 20000)
		right_view();
	else if(glutGet(GLUT_ELAPSED_TIME) > 20000 && glutGet(GLUT_ELAPSED_TIME) <= 32000)
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