from OpenGL import *
from OpenGL.GL import *
from OpenGL.GLU import *
from OpenGL.GLUT import *
import math
w, h = 500, 500


def initGL():
    glClearColor(1.0, 1.0, 1.0, 1.0)
    glOrtho(-320, 320, -240, 240, -1, 1)

def draw4point(xc, yc, x, y):
    glBegin(GL_POINTS)
    glVertex2i(x + xc, y + yc)
    glVertex2i(x + xc, -y + yc)
    glVertex2i(xc - x, yc - y)
    glVertex2i(xc - x, yc + y)
    glEnd()

def EllipsMidpoint(xc, yc, a, b):
    x = 0
    y = b
    x0 = a * a / math.sqrt(a * a + b * b)
    P = b * b - a * a * b + a * a / 4
    draw4point(xc, yc, x, y)
    while (x <= x0):
        if (P < 0):
            P += (b * b) * (2 * x + 3)
        else:
            P += (b * b) * (2 * x + 3) - 2 * a * a * (y - 1)
            y = y - 1

        x = x + 1
        draw4point(xc, yc, x, y)

    x = a
    y = 0

    P = a * a - b * b * a + b * b / 4
    draw4point(xc, yc, x, y)
    while (x > x0):
        if (P < 0):
            P += (a * a) * (2 * y + 3)
        else:
            P += (a * a) * (2 * y + 3) - 2 * b * b * (x - 1)
            x = x - 1
        y = y + 1
        draw4point(xc, yc, x, y)

def iterate():
    glViewport(0, 0, 500, 500)
    glMatrixMode(GL_PROJECTION)
    glLoadIdentity()
    glOrtho(0.0, 500, 0.0, 500, 0.0, 1.0)
    glMatrixMode(GL_MODELVIEW)
    glLoadIdentity()


def show_screen():
    glLoadIdentity()
    iterate()
    glutSwapBuffers()


def mouse_event_handler(button, state, x, y):
    if button == GLUT_LEFT_BUTTON and state == GLUT_UP:
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT)
        EllipsMidpoint(x,h-y , 80, 50)


def main():
    glutInit()
    glutInitDisplayMode(GLUT_RGBA)
    glutInitWindowSize(500, 500)
    glutInitWindowPosition(0, 0)
    wind = glutCreateWindow("Ellips Midpoint")
    glutMouseFunc(mouse_event_handler)
    glutDisplayFunc(show_screen)
    glutIdleFunc(show_screen)
    glutMainLoop()

main()