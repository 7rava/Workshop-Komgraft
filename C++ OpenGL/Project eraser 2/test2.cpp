#define _USE_MATH_DEFINES
#include <windows.h>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <GL/glew.h>
#include <GL/freeglut.h>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"


/* Global variables */
char title[] = "PROJECT 1 - ERASER";

GLfloat anglePyramid = 0.0f;
GLfloat angleCube = 0.0f;
int refreshMills = 15;

unsigned int id[0];
const char* filename1 = "kuning.bmp";

void setup(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);

    
     glEnable(GL_DEPTH_TEST); // Enable depth testing.

    // Turn on OpenGL lighting.
    glEnable(GL_LIGHTING);

    // Material property vectors.
    float matAmbAndDif[] = {0.0, 0.0, 1.0, 1.0};
    float matSpec[] = {1.0, 1.0, 1, 0, 1.0};
    float matShine[] = {50.0};

    // Material properties of ball.
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, matAmbAndDif);
    glMaterialfv(GL_FRONT, GL_SPECULAR, matSpec);
    glMaterialfv(GL_FRONT, GL_SHININESS, matShine);

    // Cull back faces.
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
    
}

void loadTextureFromFile(const char *filename, unsigned int texture)
{
    glBindTexture(GL_TEXTURE_2D, texture);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    // load and generate the texture
    int width, height, nrChannels;
    unsigned char *data = stbi_load(filename, &width, &height, &nrChannels, 0);
    if (data)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        // glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        printf("Failed to load texture");
        // cout << "Failed to load texture" << endl;
    }
    stbi_image_free(data);
}
void initGL()
{
    glClearColor(0.0f, 0.5f, 1.0f, 1.0f);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING); //enable light from a single source
    glEnable(GL_LIGHT0); //enable white light , diffuse and specular components
    glEnable(GL_COLOR_MATERIAL); //track the current color
    glDepthFunc(GL_LEQUAL);
    glShadeModel(GL_SMOOTH);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glEnable(GL_TEXTURE_2D);

    glLoadIdentity();
    glTranslatef(1.5f, 0.0f, -7.0f);
    glRotatef(angleCube, 1.0f, 1.0f, 1.0f);

    glBegin(GL_QUADS);

    // KAIN
    glColor3f(0.0f, 0.0f, 0.1f); // Hitam
    glVertex3f( 1.5f, 0.5f, -0.1f   );
    glVertex3f( -1.5f, 0.5f, -0.1f  );
    glVertex3f( -1.5f, 0.5f, 0.1f   );
    glVertex3f(1.5f, 0.5f, 0.1f    );

    // Bottom face (y = -1.0f)
    glColor3f(0.0f, 0.0f, 0.1f);
    glVertex3f(1.5f, -0.5f, 0.1f   );
    glVertex3f(-1.5f, -0.5f, 0.1f  );
    glVertex3f(-1.5f, -0.5f, -0.1f );
    glVertex3f(1.5f, -0.5f, -0.1f  );

    // Front face  (z = 1.0f)
    glColor3f(0.0f, 0.0f, 0.1f     );
    glVertex3f(1.5f, 0.5f, 0.1f    );
    glVertex3f(-1.5f, 0.5f, 0.1f   );
    glVertex3f(-1.5f, -0.5f, 0.1f  );
    glVertex3f(1.5f, -0.5f, 0.1f   );

    // Back face (z = -1.0f)
    glColor3f(0.0f, 0.0f, 0.1f);
    glVertex3f(1.5f, -0.5f, -0.1f  );
    glVertex3f(-1.5f, -0.5f, -0.1f );
    glVertex3f(-1.5f, 0.5f, -0.1f  );
    glVertex3f(1.5f, 0.5f, -0.1f   );

    // Left face (x = -1.0f)
    glColor3f(0.0f, 0.0f, 0.1f);
    glVertex3f(-1.5f, 0.5f, 0.1f   );
    glVertex3f(-1.5f, 0.5f, -0.1f  );
    glVertex3f(-1.5f, -0.5f, -0.1f );
    glVertex3f(-1.5f, -0.5f, 0.1f  );

    // Right face (x = 1.0f)
    glColor3f(0.0f, 0.0f, 0.1f);
    glVertex3f(1.5f, 0.5f, -0.1f   );
    glVertex3f(1.5f, 0.5f, 0.1f    );
    glVertex3f(1.5f, -0.5f, 0.1f   );
    glVertex3f(1.5f, -0.5f, -0.1f  );

    // BADAN
    // Top face
    glColor3f(0.91f, 0.76f, 0.65f); // Cream
    glVertex3f(1.45f, 0.45f, 0.11f   );
    glVertex3f(-1.45f, 0.45f, 0.11f  );
    glVertex3f(-1.45f, 0.45f, 0.55f  );
    glVertex3f(1.45f, 0.45f, 0.55f   );

    // Bottom face (y = -1.0f)
    glColor3f(0.91f, 0.76f, 0.65f); // Cream
    glVertex3f(1.45f, -0.45f, 0.55f     );
    glVertex3f(-1.45f, -0.45f, 0.55f    );
    glVertex3f(-1.45f, -0.45f, 0.11f    );
    glVertex3f(1.45f, -0.45f, 0.11f     );

    // Front face  (z = 1.0f)
    glColor3f(0.91f, 0.76f, 0.65f); // Cream
    glVertex3f(1.45f, 0.45f, 0.55f      );
    glVertex3f(-1.45f, 0.45f, 0.55f     );
    glVertex3f(-1.45f, -0.45f, 0.55f    );
    glVertex3f(1.45f, -0.45f, 0.55f     );

    // Left face (x = -1.0f)
    glColor3f(0.91f, 0.76f, 0.65f); // Cream
    glVertex3f(-1.45f, 0.45f, -0.0f     );
    glVertex3f(-1.45f, 0.45f, 0.55f     );
    glVertex3f(-1.45f, -0.45f, 0.55f    );
    glVertex3f(-1.45f, -0.45f, -0.0f    );

    // right face
    glColor3f(0.91f, 0.76f, 0.65f); // Cream
    glVertex3f(1.45f, 0.45f, 0.55f      );
    glVertex3f(1.45f, 0.45f, -0.0f      );
    glVertex3f(1.45f, -0.45f, -0.0f     );
    glVertex3f(1.45f, -0.45f, 0.55f     );

    // PEGANGAN
    glBindTexture(GL_TEXTURE_2D, id[0]);
    glColor3f(1.0f, 1.0f, 1.0f); // Putih
    glVertex3f(1.45f, 0.45f, 0.55f      );
    glVertex3f(-1.45f, 0.45f, 0.55f     );
    glVertex3f(-1.55f, 0.5f, 0.65f      );
    glVertex3f(1.55f, 0.5f, 0.65f       );

    // Bottom face (y = -1.0f)
    glColor3f(1.0f, 1.0f, 1.0f); // Putih
    glVertex3f(1.55f, -0.5f, 0.65f      );
    glVertex3f(-1.55f, -0.5f, 0.65f     );
    glVertex3f(-1.45f, -0.45f, 0.55f    );
    glVertex3f(1.45f, -0.45f, 0.55f     );

    // Front face  (z = 1.0f)
    glColor3f(1.0f, 1.0f, 1.0f); // Putih
    glVertex3f(1.55f, 0.5f, 0.65f       );
    glVertex3f(-1.55f, 0.5f, 0.65f      );
    glVertex3f(-1.55f, -0.5f, 0.65f     );
    glVertex3f(1.55f, -0.5f, 0.65f      );

    // Left face (x = -1.0f)
    glColor3f(1.0f, 1.0f, 1.0f); // Putih
    glVertex3f(-1.55f, 0.5f, 0.65f      );
    glVertex3f(-1.45f, 0.45f, 0.55f     );
    glVertex3f(-1.45f, -0.45f, 0.55f    );
    glVertex3f(-1.55f, -0.5f, 0.65f     );

    // right face
    glColor3f(1.0f, 1.0f, 1.0f); // Putih
    glVertex3f(1.55f, 0.5f, 0.65f       );
    glVertex3f(1.45f, 0.45f, 0.55f      );
    glVertex3f(1.45f, -0.45f, 0.55f     );
    glVertex3f(1.55f, -0.5f, 0.65f      );

    glEnd();

    glutSwapBuffers();

    angleCube -= 0.15f;
}

void timer(int value)
{
    glutPostRedisplay();
    glutTimerFunc(refreshMills, timer, 0);
}

void reshape(GLsizei width, GLsizei height)
{
    if (height == 0)
        height = 1;
    GLfloat aspect = (GLfloat)width / (GLfloat)height;

    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, aspect, 0.1f, 100.0f);
}

/* Main function: GLUT runs as a console application starting at main() */
int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(25, 50);
    glutCreateWindow(title);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    initGL();
    // setup();
    glGenTextures(1, &id[0]);
    loadTextureFromFile(filename1, id[0]);
    glutTimerFunc(0, timer, 0);
    glutMainLoop();
    return 0;

}