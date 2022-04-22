from OpenGL.GL import *
from OpenGL.GLUT import *
from OpenGL.raw.GLU import gluOrtho2D




arrayOfPoint = []

width, height = 800, 600
class Point:
    def __init__(self, x, y) -> None:
        self.x = x
        self.y = y
def LineMidPoint(x1,y1,x2,y2):
    dx = x2 -x1
    dy = y2 - y1

    p = 2 * dy - dx
    x = x1
    y = y1
    glBegin(GL_POINTS)

    glVertex2i(x, y)
    while(x<x2):
        if(p<=0):
            p+=2*dy
        else:
            p+=2 *(dy-dx)
            y= y+1
        x=x+1
        glVertex2i(x, y)
    glEnd()
def draw():
    glClear(GL_COLOR_BUFFER_BIT)
    glPushMatrix()
    if(len(arrayOfPoint) == 2):
        LineMidPoint(arrayOfPoint[0].x, arrayOfPoint[0].y,
                 arrayOfPoint[1].x, arrayOfPoint[1].y)
    glPopMatrix()
    glutSwapBuffers()
def myInit():
    glClearColor(1.0, 1.0, 0.0, 1.0)  # RGBA
    glColor3f(0.2, 0.5, 0.4)  # RGB
    gluOrtho2D(0, 800, 600, 0)
    glPointSize(1.0)

def handleMouseFunc(button, state, x, y):
        print(f"x:{x} y:{y}")
        if (button == GLUT_LEFT_BUTTON and state == GLUT_DOWN):
            if (len(arrayOfPoint) < 2):
                arrayOfPoint.append(Point(x, y))
                glutPostRedisplay()
def main():

    glutInit()
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB)
    glutInitWindowSize(640, 480)
    glutInitWindowPosition(200, 200)
    glutCreateWindow("Midpoint")
    myInit()
    glutDisplayFunc(draw)
    glutMouseFunc(handleMouseFunc)
    glutMainLoop()
main()



