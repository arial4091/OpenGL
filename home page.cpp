#include <stdio.h>
#include <string.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include <math.h>

class Circle {
public:
   float cx, cy, r;
   float arr[8][30][2];
   
   Circle(){ cx = 0.0; cy = 0.0; r = 1.0;}
   Circle(float x, float y, float rr);
private:
   void mir(int mirror,int empty, int a, int b);   //對向量(a,b)做鏡射
   bool inside(float x, float y);

}; //-----------gludisk 內建的畫圓程式------------

void WindowSize(int , int );            //負責視窗及繪圖內容的比例
void Display();
void ski();
void print(char* str, float x, float y);

int main()
{
   glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
   glutInitWindowSize(550,550);         //視窗長寬
   glutInitWindowPosition(300,80);         //視窗左上角的位置
   glutCreateWindow("Home Page");      //建立視窗
   
   glutReshapeFunc(WindowSize);
   glutDisplayFunc(Display);

   glutMainLoop();
   return 0;
}

void Display(void)
{
   glClearColor(0.0, 0.0, 0.0, 0.0);   
   glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   glBegin(GL_POLYGON);
      glColor3f( 1, 1, 1);glVertex2f(3.0, 18.6);
      glColor3f( 1, 1, 1);glVertex2f(3.0, 10.0);
      glColor3f( 1, 1, 1);glVertex2f(17.0, 10.0);
      glColor3f( 1, 1, 1);glVertex2f(17.0, 18.6); 
   glEnd();

   Circle c1(5.5, 15.75, 2.152), c2(10.0, 15.75, 2.15), c3(14.5, 15.75, 2.15),
          c4(7.75, 13.0, 2.15), c5(12.25, 13.0, 2.15);
   int i, j;   
   
   glEnable(GL_LINE_SMOOTH);
   glLineWidth(5.0);
   glBegin(GL_LINE_LOOP);
      for(i = 0; i < 8; i++){         
            for(j = 0; j < 30; j++){
               glColor3f( 0, 0, 1);
               glVertex2fv(c1.arr[i][j]);
            }
      }
   glEnd();
   glBegin(GL_LINE_LOOP);
      for(i = 0; i < 8; i++){         
            for(j = 0; j < 30; j++){
               glColor3f( 0, 0, 0);
               glVertex2fv(c2.arr[i][j]);
            }
      }
    glEnd();
    glBegin(GL_LINE_LOOP);
      for(i = 0; i < 8; i++){         
            for(j = 0; j < 30; j++){
               glColor3f( 1, 0, 0);
               glVertex2fv(c3.arr[i][j]);
            }
      }
    glEnd();
    glBegin(GL_LINE_LOOP);
      for(i = 0; i < 8; i++){         
            for(j = 0; j < 30; j++){
               glColor3f( 1, 1, 0);
               glVertex2fv(c4.arr[i][j]);
            }
      }
    glEnd();
    glBegin(GL_LINE_LOOP);
      for(i = 0; i < 8; i++){         
            for(j = 0; j < 30; j++){
               glColor3f( 0, 1, 0);
               glVertex2fv(c5.arr[i][j]);
            }
      }
   glEnd();
   glLineWidth(1.0);
   
   glColor3f( 0, 0, 1);
   print("S    k    i", 5.4, 9.4);
   glColor3f( 1, 0, 0);
   print("J    u    m", 9.2, 9.4);
   glColor3f( 1, 1, 0);
   print("p    i", 11.9, 9.4);
   glColor3f( 0, 1, 0);
   print("n    g", 13.5, 9.4);

   ski();

   
   glutSwapBuffers();
}


void WindowSize(int w, int h)
{
   //printf("目前視窗大小為%dX%d\n",w,h);
   glViewport(0, 0, w, h);            //當視窗長寬改變時，畫面也跟著變
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   gluOrtho2D(0,20,0,20);      //正交投影
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}

Circle:: Circle(float x, float y, float rr)
{
   cx = x; cy = y; r = rr;
   float sec = sqrt(2) / 58 * r;
   float x_sec = (r - sec*29) / 29;
   float x_halve = x_sec / 2;
   float x_eigh = x_sec / 8;
   int i;

   arr[0][0][0] = cx + r;
   arr[0][0][1] = cy;
   for(i = 1; i < 30; i++){
      arr[0][i][1] = arr[0][i-1][1] + sec;
      if ( inside(arr[0][i-1][0] - x_halve, arr[0][i][1]))
         arr[0][i][0] = arr[0][i-1][0] - x_eigh;
      else
         arr[0][i][0] = arr[0][i-1][0] - x_sec;
   }
   arr[0][29][0] = ((r * sqrt(2) / 2 + cx) + arr[0][29][0]*2) / 3;
   arr[0][29][1] = ((r * sqrt(2) / 2 + cy) + arr[0][29][1]*2) / 3;

   mir(0, 1, 1, 1);        //45~90
   mir(1, 2, 0, 1);       //90~135
   mir(0, 3, 0, 1);        //135~180
   mir(3, 4, 1, 0);     //180~225
   mir(2, 5, 1, 0);     //225~270
   mir(1, 6, 1, 0);      //270~315
   mir(0, 7, 1, 0);       //315~360
}

bool Circle:: inside(float x, float y)
{
   double ans;
   ans = x*x + cx*cx -2*x*cx + y*y + cy*cy -2*cy*y - r*r;
   return (ans <= 0);
}

void Circle:: mir(int mirror,int empty, int a, int b)
{
   int i;

   if(a == 1 && b == 1){
      for(i = 0; i < 30; i++){
         arr[empty][29-i][1] = arr[mirror][i][0] - cx + cy;
         arr[empty][29-i][0] = arr[mirror][i][1] - cy + cx;
      }
   }

   else if(a == 1 && b == 0){
      for(i = 0; i < 30; i++){
         arr[empty][29-i][1] = (arr[mirror][i][1] - cy) * -1 + cy;
         arr[empty][29-i][0] = arr[mirror][i][0];
      }
   }

   else if(a == 0 && b == 1){
      for(i = 0; i < 30; i++){
         arr[empty][29-i][1] = arr[mirror][i][1];
         arr[empty][29-i][0] = (arr[mirror][i][0] - cx) * -1 + cx;
      }
   }
}

void ski()
{
  Circle head(10, 8.2, 0.7);
  int i, j;

  glBegin(GL_TRIANGLE_FAN);   //頭 
      for(i = 0; i < 8; i++){
        for(j = 0; j < 30; j++){
            glColor3f( 1, 0, 0);
            glVertex2fv(head.arr[i][j]);
        }
      }
  glEnd();
  glBegin(GL_POLYGON);  //身體 
      glColor3f( 0, 1, 0);glVertex2f(9.2, 7.5);
      glColor3f( 0, 1, 0);glVertex2f(10.2, 7.1);
      glColor3f( 0, 1, 0);glVertex2f(9.0, 4.4);
      glColor3f( 0, 1, 0);glVertex2f(8.0, 4.7);
  glEnd();
  glBegin(GL_POLYGON);  //滑板 
      glColor3f( 0.6, 0, 1);glVertex2f(4.1, 1.5);
      glColor3f( 0.6, 0, 1);glVertex2f(15.2, 1.8);
      glColor3f( 0.6, 0, 1);glVertex2f(15.3, 1.1);
      glColor3f( 0.6, 0, 1);glVertex2f(4.2, 0.8);
  glEnd();
  glBegin(GL_POLYGON);  //腳 
      glColor3f( 1, 1, 0);glVertex2f(8.0, 4.5);
      glColor3f( 1, 1, 0);glVertex2f(9.0, 4.2);
      glColor3f( 1, 1, 0);glVertex2f(10.0, 1.3);
      glColor3f( 1, 1, 0);glVertex2f(9.2, 1.1);
  glEnd();
  glLineWidth(3.0);
  glEnable(GL_LINE_SMOOTH);
  glBegin(GL_LINES);        //拐杖 
      glColor3f( 1, 0.8, 1);glVertex2f(12.8, 7.7);
      glColor3f( 1, 0.6, 1);glVertex2f(12.5, 0.60);     
  glEnd();
  glLineWidth(1.0);
  glBegin(GL_POLYGON);    //手 
      glColor3f( 0, 0, 1);glVertex2f(10.3, 7.1);
      glColor3f( 0, 0, 1);glVertex2f(13.6, 6.8);
      glColor3f( 0, 0, 1);glVertex2f(13.4, 6.0);
      glColor3f( 0, 0, 1);glVertex2f(10.1, 6.3);
  glEnd();
}

void print(char* str, float x, float y)
{
  glRasterPos2f(x,y);

  int len = strlen(str);
  for (int i = 0; i < len; i++)
      glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,str[i]);
}