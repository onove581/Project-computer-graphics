#define GL_SILENCE_DEPRECATION
#include <iostream>

#include <stdio.h>
#include <stdlib.h>
#include <GL/GLUT.h>
#include <math.h>

#define PI 3.1415927


void draw_cylinder(GLfloat radius,
                   GLfloat height,
                   float R,
                   float G,
                   float B)
{
    GLfloat x              = 0.0;
    GLfloat y              = 0.0;
    GLfloat angle          = 0.0;
    GLfloat angle_stepsize = 0.1;

    // ve tube
    glColor3f(1,1,1);
    glBegin(GL_QUAD_STRIP);
    angle = 0.0;
        while( angle < 2*PI ) {
            x = radius * cos(angle);
            y = radius * sin(angle);
            glVertex3f(x, y , height);
            glVertex3f(x, y , 0.0);
            angle = angle + angle_stepsize;
        }
        glVertex3f(radius, 0.0, height);
        glVertex3f(radius, 0.0, 0.0);
    glEnd();

    //ve duong tron tren mat tru
    glColor3f(1,0,0);
    glBegin(GL_POLYGON);
    angle = 0.0;
        while( angle < 2*PI ) {
            x = radius * cos(angle);
            y = radius * sin(angle);
            glVertex3f(x, y , height);
            angle = angle + angle_stepsize;
        }
        glVertex3f(radius, 0.0, height);
    glEnd();
}


void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    glTranslatef(0.0,-0.4,-3.0);
    glRotatef(-40, 1.0, 0.0, 0.0);

    draw_cylinder(0.3, 1.0, 1.0 , 1.0, 1.0);

    glFlush();
}


// thay doi kich thuoc cua so
void reshape(int width, int height)
{
    if (width == 0 || height == 0) return;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(40.0, (GLdouble)width/(GLdouble)height,
                   0.5, 20.0);

    glMatrixMode(GL_MODELVIEW);
    glViewport(0, 0, width, height);
}

int main(int argc, char **argv)
{

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640,480);
    glutCreateWindow("LAB 5 - Hinh tru");
    glClearColor(0.0,0.0,0.0,0.0);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();

    return 0;
}

