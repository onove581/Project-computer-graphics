#define GL_SILENCE_DEPRECATION
#include <iostream>

#include <GL/glut.h>

GLfloat xRotated, yRotated, zRotated;

GLdouble base=1;
GLdouble height=1.5;
GLint slices =50;
GLint stacks =50;


void displayCone(void)
{

    glMatrixMode(GL_MODELVIEW);

    glClear(GL_COLOR_BUFFER_BIT);
  
    glLoadIdentity();
    
    // dich chuyen hinh theo z
    glTranslatef(0.0,0.0,-8.0);
    // Red color used to draw.
    glColor3f(1, 1, 1);
    // thay doi ma tran
    // quay ve truc x
    glRotatef(xRotated,1.0,0.0,0.0);
    // quay ve truc y
    glRotatef(yRotated,0.0,1.0,0.0);
    // quay ve truc z
    glRotatef(zRotated,0.0,0.0,1.0);

    glScalef(1.0,1.0,1.0);
    glutSolidCone(base,height,slices,stacks);
    glFlush();
 
}

void reshapeCone(int x, int y)
{
    if (y == 0 || x == 0) return;  
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
     
    gluPerspective(40.0,(GLdouble)x/(GLdouble)y,0.5,20.0);
 
    glViewport(0,0,x,y);  
}

void idleCone(void)
{
 
     yRotated += 0.01;
     
    displayCone();
}


int main (int argc, char **argv)
{
    glutInit(&argc, argv);
     glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400,350);
    glutCreateWindow("LAB5 - Hinh Non");
    glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
    xRotated = yRotated = zRotated = 30.0;
     xRotated=33;
     yRotated=40;
    glClearColor(0.0,0.0,0.0,0.0);
    glutDisplayFunc(displayCone);
   glutReshapeFunc(reshapeCone);
    glutIdleFunc(idleCone);
    glutMainLoop();
    return 0;
}

