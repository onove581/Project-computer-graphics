#include <iostream>
#include <GL/glut.h>

using namespace std;

static float controlPoints[6][4][3] = {
	{{-3.0, 0.0, 5.0}, {-0.25, 0.0, 5.0}, {0.25, 0.0, 5.0}, {3.0, 0.0, 5.0}},
	{{-3.0, 0.0, 3.0}, {-0.25, 0.0, 3.0}, {0.25, 0.0, 3.0}, {3.0, 0.0, 3.0}},
	{{-3.0, 0.0, 1.0}, {-0.25, 0.0, 1.0}, {0.25, 0.0, 1.0}, {3.0, 0.0, 1.0}},
	{{-3.0, 0.0, -1.0}, {-0.25, 0.0, -1.0}, {0.25, 0.0, -1.0}, {3.0, 0.0, -1.0}},
	{{-3.0, 0.0, -3.0}, {-0.25, 0.0, -3.0}, {0.25, 0.0, -3.0}, {3.0, 0.0, -3.0}},
	{{-3.0, 0.0, -5.0}, {-0.25, 0.0, -5.0}, {0.25, 0.0, -5.0}, {3.0, 0.0, -5.0}},
};

static float Xangle = 30.0, Yangle = 0.0, Zangle = 0.0;
static int rowCount = 0, columnCount = 0;
void writeStrokeString(void *font, char *string){  
   char *c;

   for (c = string; *c != '\0'; c++) glutStrokeCharacter(font, *c);
}

void setup(void) {
   glClearColor(1.0, 1.0, 1.0, 0.0); 
}

// Ve mat phang
void drawScene(void){
   int i, j;
   glClear (GL_COLOR_BUFFER_BIT);
   glLoadIdentity();

   gluLookAt(0.0, 0.0, 12.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

   // Rotate 
   glRotatef(Zangle, 0.0, 0.0, 1.0);
   glRotatef(Yangle, 0.0, 1.0, 0.0);
   glRotatef(Xangle, 1.0, 0.0, 0.0);

   glPointSize(5.0);

   // Các diem xanh
   glColor3f(0.0, 1.0, 0.0);
   glBegin(GL_POINTS);
      for (i = 0; i < 6; i++)
         for (j = 0; j < 4; j++)
            glVertex3fv(controlPoints[i][j]);
   glEnd();
   
   // Ve da dien mat phang
   glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
   glColor3f(0.7, 0.7, 0.7);
   for (i = 0; i < 5; i++)
   {
      glBegin(GL_QUAD_STRIP);
      for (j = 0; j < 4; j++)
	  {
         glVertex3fv(controlPoints[i][j]);
		 glVertex3fv(controlPoints[i+1][j]);
	  }
      glEnd();
   }

   // Diem dieu khien
   glColor3f(1.0, 0.0, 0.0);
   glBegin(GL_POINTS);
      glVertex3fv(controlPoints[rowCount][columnCount]);
   glEnd();

   // Chi dinh be mat
   glMap2f(GL_MAP2_VERTEX_3, 0, 1, 3, 4, 0, 1, 12, 6, controlPoints[0][0]); 
   glEnable(GL_MAP2_VERTEX_3); 

   // Ve be mat bezier gan luoi
   glColor3f(0.0, 0.0, 0.0);
   glMapGrid2f(20, 0.0, 1.0, 20, 0.0, 1.0);
   glEvalMesh2(GL_LINE, 0, 20, 0, 20);

   // truc toa do
   glLineWidth(2.0);
   glColor3f(0.0, 0.0, 1.0);
   glBegin(GL_LINES);
	   glVertex3f(-6.0, 0.0, 0.0);
       glVertex3f(6.0, 0.0, 0.0);
       glVertex3f(5.75, 0.0, 0.25);
       glVertex3f(6.0, 0.0, 0.0);
       glVertex3f(5.75, 0.0, -0.25);
       glVertex3f(6.0, 0.0, 0.0);

	   glVertex3f(0.0, -6.0, 0.0);
       glVertex3f(0.0, 6.0, 0.0);
       glVertex3f(0.25, 5.75, 0.0);
       glVertex3f(0.0, 6.0, 0.0);
       glVertex3f(-0.25, 5.75, 0.0);
       glVertex3f(0.0, 6.0, 0.0);

	   glVertex3f(0.0, 0.0, -6.0);
       glVertex3f(0.0, 0.0, 6.0);
	   glVertex3f(0.25, 0.0, 5.75);
	   glVertex3f(0.0, 0.0, 6.0);
	   glVertex3f(-0.25, 0.0, 5.75);
	   glVertex3f(0.0, 0.0, 6.0);
   glEnd();
   glLineWidth(1.0);

   // nhan truc
   glPushMatrix();
   glTranslatef(6.1, 0.0, 0.0);
   glScalef(0.005, 0.005, 0.005);
   writeStrokeString(GLUT_STROKE_ROMAN, "X");
   glPopMatrix();

   glPushMatrix();
   glTranslatef(0.0, 6.1, 0.0);
   glScalef(0.005, 0.005, 0.005);
   writeStrokeString(GLUT_STROKE_ROMAN, "Y");
   glPopMatrix();

   glPushMatrix();
   glTranslatef(0.0, 0.0, 6.1);
   glScalef(0.005, 0.005, 0.005);
   writeStrokeString(GLUT_STROKE_ROMAN, "Z");
   glPopMatrix();

   glutSwapBuffers();
}

// cua so window
void resize(int w, int h){
   glViewport(0, 0, (GLsizei)w, (GLsizei)h); 
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   gluPerspective(60.0, (float)w/(float)h, 1.0, 50.0);
   glMatrixMode(GL_MODELVIEW);
}

// nut ban phim
void keyInput(unsigned char key, int x, int y){
   switch(key) {
      case 27:
         exit(0);
         break;
      case 'x':
         Xangle += 5.0;
		 if (Xangle > 360.0) Xangle -= 360.0;
         glutPostRedisplay();
         break;
      case 'X':
         Xangle -= 5.0;
		 if (Xangle < 0.0) Xangle += 360.0;
         glutPostRedisplay();
         break;
      case 'y':
         Yangle += 5.0;
		 if (Yangle > 360.0) Yangle -= 360.0;
         glutPostRedisplay();
         break;
      case 'Y':
         Yangle -= 5.0;
		 if (Yangle < 0.0) Yangle += 360.0;
         glutPostRedisplay();
         break;
      case 'z':
         Zangle += 5.0;
		 if (Zangle > 360.0) Zangle -= 360.0;
         glutPostRedisplay();
         break;
      case 'Z':
         Zangle -= 5.0;
		 if (Zangle < 0.0) Zangle += 360.0;
         glutPostRedisplay();
         break;
      case 9:
		 {
		    if (rowCount < 5) rowCount++;
		    else rowCount = 0;
		 }
		 glutPostRedisplay();
		 break;
      case ' ':
		 {
		    if (columnCount < 3) columnCount++;
		    else columnCount = 0;
		 }
         glutPostRedisplay();
         break;
      default:
         break;
   }
}

void specialKeyInput(int key, int x, int y){
   if (key == GLUT_KEY_LEFT) controlPoints[rowCount][columnCount][0] -= 0.1;
   if (key == GLUT_KEY_RIGHT) controlPoints[rowCount][columnCount][0] += 0.1;
   if (key == GLUT_KEY_DOWN) controlPoints[rowCount][columnCount][1] -= 0.1;
   if (key == GLUT_KEY_UP) controlPoints[rowCount][columnCount][1] += 0.1;
   if (key == GLUT_KEY_PAGE_DOWN) controlPoints[rowCount][columnCount][2] -= 0.1;
   if (key == GLUT_KEY_PAGE_UP) controlPoints[rowCount][columnCount][2] += 0.1;
   glutPostRedisplay();
}

void printInteraction(void){
   cout << "Chuc nang:" << endl;
   cout << "nhan space va tab chon diem dieu khien" << endl
        << "nhan trai phai dieu khien truc z" << endl
        << "nhan mui ten len xuong dieu khien truc y" << endl
        << "nham len xuong dieu khien truc z." << endl
        << "Nham phim x,y,z de xoay." << endl;
}

int main(int argc, char **argv) {
   printInteraction();
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); 
   glutInitWindowSize(500, 500);
   glutInitWindowPosition(100, 100); 
   glutCreateWindow("bezierSurface");
   setup(); 
   glutDisplayFunc(drawScene); 
   glutReshapeFunc(resize);  
   glutKeyboardFunc(keyInput);
   glutSpecialFunc(specialKeyInput);
   glutMainLoop(); 

   return 0;  
}

