#define _USE_MATH_DEFINES
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <GL/glew.h>
#include <GL/freeglut.h>

class point2D_t
{
public:
    float x;
    float y;
};

class color_t
{
public:
    float r;
    float g;
    float b;
};

typedef struct
{
    float x, y, z;

} point3D_t;

typedef struct
{

    int NumberofVertices;
    short int pnt[32];

} face_t;

typedef struct
{
    float vec[4];
} vector3D_t;

typedef struct
{
    float vec[4];
} matrix3D_t;

typedef struct
{

    int NumberofVertices;
    point3D_t pnt[100];
    int NumberofFaces;
    face_t fc[32];

} object3D_t;

object3D_t prisma = {5,

                     {{0, 100, 0}, {100, 0, 0}, {0, 0, 100}, {-100, 0, 0}, {0, 0, -100}},
                     5,
                     {{3, {0, 1, 2}}, {3, {0, 2, 3}}, {3, {0, 3, 4}}, {3, {0, 4, 1}}, {4, {1, 4, 3, 2}}}};

point2D_t Vector2Point2D(vector3D_t vec)
{

    point2D_t pnt;
    pnt.x = vec.vec[0];
    pnt.y = vec.vec[1];
    return pnt;
}

vector3D_t Point2Vector(point3D_t pnt)
{

    vector3D_t vec;
    vec.vec[0] = pnt.x;
    vec.vec[1] = pnt.y;
    vec.vec[2] = pnt.z;
    vec.vec[3] = 1.;
    return vec;
}

void setColor(color_t col)
{
    glColor3f(col.r, col.g, col.b);
}

void drawPolyline(point2D_t pnt[], int n)
{
    glBegin(GL_LINE_STRIP);
    for (int i = 0; i < n; i++)
    {
        glVertex2f(pnt[i].x, pnt[i].y);
    }
    glEnd();
}

void drawPolygon(point2D_t pnt[], int n)
{
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < n; i++)
    {
        glVertex2f(pnt[i].x, pnt[i].y);
    }
    glEnd();
}

void fillPolygon(point2D_t pnt[], int n, color_t color)
{
    setColor(color);
    glBegin(GL_POLYGON);
    for (int i = 0; i < n; i++)
    {
        glVertex2f(pnt[i].x, pnt[i].y);
    }
    glEnd();
}

void Gradiate(point2D_t pnt[], int n, color_t color)
{

    glBegin(GL_POLYGON);
    for (int i = 0; i < n; i++)
    {
        setColor(color);
        glVertex2f(pnt[i].x, pnt[i].y);
    }
    glEnd();
}

void userdraw(void)
{

}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    userdraw();
    glutSwapBuffers();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowPosition(256, 256);
    glutInitWindowSize(480, 480);
    glutCreateWindow("Test");
    glClearColor(0.0, 0.0, 0.0, 0.0);
    gluOrtho2D(-15., 15., -15.0, 15.0);
    glutIdleFunc(display);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}