import logging
from OpenGL.GL import *
from OpenGL.GLUT import *
from OpenGL.GLU import *

import OpenGL
OpenGL.ERROR_CHECKING = False
width, height = 800, 600
arrayOfPoint = []


class Point:
    def __init__(self, x, y) -> None:
        self.x = x
        self.y = y


def drawLine(x1, y1, x2, y2):
    print(f"{x1} {y1} {x2} {y2}")
    originDx = x2-x1
    originDy = y2-y1
    dx = abs(originDx)
    dy = abs(originDy)
    incx = originDx//dx
    incy = originDy//dy

    const1 = 2*dy
    const2 = 2*(dy-dx)
    p = 2*dx-dy
    x = x1
    y = y1
    glBegin(GL_POINTS)
    while (x-x2 != 0):
        print(f"{x} {y}")
        glVertex2f(x, y)
        if (p < 0):
            p += const1
        else:
            p += const2
            y += incy
        x += incx
    glEnd()


def draw():
    glClear(GL_COLOR_BUFFER_BIT)
    glPushMatrix()
    if(len(arrayOfPoint) == 2):
        drawLine(arrayOfPoint[0].x, arrayOfPoint[0].y,
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
    if(button == GLUT_LEFT_BUTTON and state == GLUT_DOWN):
        if(len(arrayOfPoint) < 2):
            arrayOfPoint.append(Point(x, y))
            glutPostRedisplay()


glutInit()
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB)
glutInitWindowSize(width, height)
glutInitWindowPosition(200, 200)
window = glutCreateWindow("hellp")
myInit()
glutDisplayFunc(draw)
glutMouseFunc(handleMouseFunc)
glutMainLoop()