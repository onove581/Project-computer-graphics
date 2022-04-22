from OpenGL.GL import *
from OpenGL.GLUT import *
w, h = 500, 500

def initGL():
    glClearColor(1.0, 1.0, 1.0, 1.0)
    glOrtho(-320, 320, -240, 240, -1, 1)
def draw8point(xc,yc,x,y):
    glBegin(GL_POINTS)
    glVertex2i(xc + x, yc + y)
    glVertex2i(xc + y, yc + x)
    glVertex2i(xc + y, yc - x)
    glVertex2i(xc + x, yc - y)
    glVertex2i(xc - x, yc - y)
    glVertex2i(xc - y, yc - x)
    glVertex2i(xc - y, yc + x)
    glVertex2i(xc - x, yc + y)
    glEnd()
def CircleBres(xc, yc,R):
    y = R
    x = 0
    p = 3 - 2 * R
    draw8point(xc, yc, x, y)
    while (x < y):
        if (p < 0):
            p += 4 * x + 6
        else:
            p += 4 * (x - y) + 10
            y = y -1
        x = x +1
        draw8point(xc, yc, x, y)

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
        CircleBres(x, h - y, 100)


def main():
    glutInit()
    glutInitDisplayMode(GLUT_RGBA)
    glutInitWindowSize(500, 500)
    glutInitWindowPosition(0, 0)
    wind = glutCreateWindow("OpenGL Circle Bresenham")
    glutMouseFunc(mouse_event_handler)
    glutDisplayFunc(show_screen)
    glutIdleFunc(show_screen)
    glutMainLoop()

main()