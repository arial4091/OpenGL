#include <stdio.h>
#include <string.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include <math.h>

/* GLUT callback Handlers */
float i = 0;
float r = 5;
int plus = 1;

float change_r()
{
    
    if(r > 12 && r < 17)
        plus = 2;   
    else if(r < 3.5 && r > -1.5)
        plus = -1;
        
    else if(r > 17){
        r = 12;
        plus = 0;
    }
    else if(r < -1.5){
        r = 3.5;
        plus = 1;
    }
    if(plus == 1)
        r += 0.001;
    else if(plus == 0)
        r -= 0.001;
    else if(plus == 2){
        r += 0.001;
        return 12;
    }
    else if(plus == -1){
        r -= 0.001;
        return 3.5;
    }
    
    return r;   
}

static void 
resize(int width, int height)
{
    const float ar = (float) width / (float) height;
    
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity() ;
}

static void 
display(void)
{
    const double t = glutGet(GLUT_ELAPSED_TIME) / 8000.0;
    const double a = t*360.0;

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 

    glPushMatrix();
        gluLookAt(change_r()*cos(i),0,change_r()*sin(i)-4,0,0,-4,0,1,0);    
        glColor3d(1,0,0);
        glTranslated(-1,0.2,-4);
        glutSolidTorus(0.04,0.4,25,25);
        glColor3d(0,0,0);
        glTranslated(1,0,0);
        glutSolidTorus(0.04,0.4,25,25);
        glColor3d(0,0,1);
        glTranslated(1,0,0);
        glutSolidTorus(0.04,0.4,25,25);
        glColor3d(0,1,0);
        glTranslated(-1.5,-0.4,-0.1);
        glutSolidTorus(0.04,0.4,25,25);
        glColor3d(1,1,0);
        glTranslated(1,0,0);
        glutSolidTorus(0.04,0.4,25,25);
    glPopMatrix();
    i -= 0.003;
    

    glutSwapBuffers();
}

static void 
idle(void)
{
    glutPostRedisplay();
}

const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

/* Program entry point */

int 
main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(600,600);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("FreeGLUT Shapes");

    glutReshapeFunc(resize);
    glutDisplayFunc(display);
    glutIdleFunc(idle);

    glClearColor(1,1,1,1);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);

    glutMainLoop();

    return 0;
}

