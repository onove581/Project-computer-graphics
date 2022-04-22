#include <GL/glu.h>
#include<GL/glut.h>
GLfloat T= 0;
void Spin (){
	T =  T + 0.005;
	if (T>360)
		T = 0;
		glutPostRedisplay();
	}

 void MyInit(){
 	glClearColor(0,0,0,1);
 	glColor3f(1,0,0);
 	}
 	
void Line (GLfloat A[], GLfloat B[])
{
	glBegin(GL_LINES);
    		glVertex3fv(A);  
    		glVertex3fv(B);
    	glEnd(); 	
}
void Cube (GLfloat V0 [], GLfloat V1 [],GLfloat V2 [], GLfloat V3 [], GLfloat V4 [], GLfloat V5 [],GLfloat V6 [],GLfloat V7 [] )
{
	glColor3f(1,0,0);
	Line(V0,V1);	Line(V0,V3);	Line(V0,V4);	Line(V1,V2);	Line(V1,V5);
	Line(V2,V3);	Line(V2,V6);	Line(V3,V7);	Line(V4,V5);	Line(V5,V6);
	Line(V6,V7);	Line(V7,V4);
}	
void Draw(){
	GLfloat V [8] [3] = {
						{-0.5, 0.5, 0.5},
						{ 0.5, 0.5, 0.5},
						{ 0.5,-0.5, 0.5},
						{-0.5,-0.5, 0.5},
						
						{-0.5, 0.5,-0.5},
						{ 0.5, 0.5,-0.5},
						{ 0.5,-0.5,-0.5},
						{-0.5,-0.5,-0.5},
					};		
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glRotatef(T,0.5,1,0);
	Cube(V[0], V[1], V[2], V[3], V[4],V[5],V[6],V[7]);
	glutSwapBuffers();
    	}
int main (int c, char *V[]){
	glutInit(&c,V);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(250, 250);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE| GLUT_DEPTH);
	glutCreateWindow("MÔ HÌNH KHUNG KET NOI");  
	MyInit();
	glutDisplayFunc(Draw);
	glutIdleFunc(Spin);
	glutMainLoop();
	return 0;
	}
