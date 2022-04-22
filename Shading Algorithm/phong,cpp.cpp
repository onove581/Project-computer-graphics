#include <GL/glut.h>

void myinit()
{
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_shininess[] = { 50.0 };
    GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };

    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
}

void display(void)
{
     glClearColor(0, 153, 230, 0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glutSolidSphere(1,500,500);
    glFlush();
}

void myReshape(GLsizei w, GLsizei h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

        glOrtho (-1.5, 1.5, -1.5*(GLfloat)480/(GLfloat)640, 
            1.5*(GLfloat)480/(GLfloat)640, -10.0, 10.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}


int main(int argc,char** argv)
{
	glutInit(&argc,argv);
    glutInitWindowSize (600, 600);
    glutInitWindowPosition (150,150);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGBA |GLUT_DEPTH);
    glutCreateWindow("Phong Shading");
    glutDisplayFunc(display);
    glutReshapeFunc (myReshape);
    myinit();
    glutMainLoop();
}

