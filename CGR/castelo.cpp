/* g++ main.cpp -o firstOpenGlApp -lglut -lGLU -lGL */
// ./firstOpenGlApp

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

int rotX = 15;
int rotY = 0;
int list;
GLUquadricObj *pObj;

void init()
{
    GLfloat sourceLight[] = { 0.25, 0.25, 0.25, 1.0 };

    glEnable(GL_DEPTH_TEST);
    glFrontFace(GL_CCW);
    glEnable(GL_CULL_FACE);

    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0,GL_AMBIENT,sourceLight);
    glLightfv(GL_LIGHT0,GL_DIFFUSE,sourceLight);
    glEnable(GL_LIGHT0);

    glEnable(GL_COLOR_MATERIAL);

    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);

    glClearColor(1.0, 1.0, 1.0, 1.0);

    pObj = gluNewQuadric();
    gluQuadricDrawStyle(pObj, GLU_FILL);
    gluQuadricNormals(pObj, GLU_SMOOTH);

    list = glGenLists(7);

    glNewList(list, GL_COMPILE);
        gluCylinder(pObj, 0.2, 0.2, 0.7, 15, 10);
    glEndList();

    glNewList(list+1, GL_COMPILE);
        gluCylinder(pObj, 0.22, 0.0, 0.4, 15, 10);
    glEndList();

    glNewList(list+2, GL_COMPILE);
        gluCylinder(pObj, 0.2, 0.2, 1.2, 15, 10);
    glEndList();

    glNewList(list+3, GL_COMPILE);
        glBegin(GL_QUADS);
            glVertex3f(1.0, 0.0, 0.1);
            glVertex3f(1.0, 0.5, 0.1);
            glVertex3f(-1.0, 0.5, 0.1);
            glVertex3f(-1.0, 0.0, 0.1);

            glVertex3f(-1.0, 0.0, -0.1);
            glVertex3f(-1.0, 0.5, -0.1);
            glVertex3f(1.0, 0.5, -0.1);
            glVertex3f(1.0, 0.0, -0.1);

            glVertex3f(1.0, 0.5, 0.1);
            glVertex3f(1.0, 0.5, -0.1);
            glVertex3f(-1.0, 0.5, -0.1);
            glVertex3f(-1.0, 0.5, 0.1);

            glVertex3f(1.0, 0.0, -0.1);
            glVertex3f(1.0, 0.0, 0.1);
            glVertex3f(-1.0, 0.0, 0.1);
            glVertex3f(-1.0, 0.0, -0.1);

            glVertex3f(-1.0, 0.5, 0.1);
            glVertex3f(-1.0, 0.5, -0.1);
            glVertex3f(-1.0, 0.0, -0.1);
            glVertex3f(-1.0, 0.0, 0.1);

            glVertex3f(1.0, 0.5, -0.1);
            glVertex3f(1.0, 0.5, 0.1);
            glVertex3f(1.0, 0.0, 0.1);
            glVertex3f(1.0, 0.0, -0.1);

        glEnd();
    glEndList();

    glNewList(list+4, GL_COMPILE);
        glBegin(GL_QUADS);
            GLfloat x = 0.3;
            GLfloat y = 0.7;
            GLfloat z = 0.2;

            glVertex3f(x, y-y, z);
            glVertex3f(x, y, z);
            glVertex3f(-x, y, z);
            glVertex3f(-x, y-y, z);

            glVertex3f(-x, y-y, -z);
            glVertex3f(-x, y, -z);
            glVertex3f(x, y, -z);
            glVertex3f(x, y-y, -z);

            glVertex3f(x, y, z);
            glVertex3f(x, y, -z);
            glVertex3f(-x, y, -z);
            glVertex3f(-x, y, z);

            glVertex3f(x, y-y, -z);
            glVertex3f(x, y-y, z);
            glVertex3f(-x, y-y, z);
            glVertex3f(-x, y-y, -z);

            glVertex3f(-x, y, z);
            glVertex3f(-x, y, -z);
            glVertex3f(-x, y-y, -z);
            glVertex3f(-x, y-y, z);

            glVertex3f(x, y, -z);
            glVertex3f(x, y, z);
            glVertex3f(x, y-y, z);
            glVertex3f(x, y-y, -z);

            
        glEnd();
    glEndList();

    glNewList(list+5, GL_COMPILE);
        gluCylinder(pObj, 0.376, 0.0, 0.4, 25, 10);
    glEndList();

    glNewList(list+6, GL_COMPILE);
      glBegin(GL_QUADS);

      
      glVertex3f(1.0, 0.0, 0.1);
      glVertex3f(1.0, 2, 0.1);
      glVertex3f(-1.0, 2, 0.1);
      glVertex3f(-1.0, 0.0, 0.1);

      glVertex3f(-1.0, 0.0, -0.1);
      glVertex3f(-1.0, 2, -0.1);
      glVertex3f(1.0, 2, -0.1);
      glVertex3f(1.0, 0.0, -0.1);

      glVertex3f(1.0, 2, 0.1);
      glVertex3f(1.0, 2, -0.1);
      glVertex3f(-1.0, 2, -0.1);
      glVertex3f(-1.0, 2, 0.1);

      glVertex3f(1.0, 0.0, -0.1);
      glVertex3f(1.0, 0.0, 0.1);
      glVertex3f(-1.0, 0.0, 0.1);
      glVertex3f(-1.0, 0.0, -0.1);

      glVertex3f(-1.0,2, 0.1);
      glVertex3f(-1.0, 2, -0.1);
      glVertex3f(-1.0, 0.0, -0.1);
      glVertex3f(-1.0, 0.0, 0.1);

      glVertex3f(1.0, 2, -0.1);
      glVertex3f(1.0, 2, 0.1);
      glVertex3f(1.0, 0.0, 0.1);
      glVertex3f(1.0, 0.0, -0.1);
      glEnd();

    glEndList();



}

void reshape(int w, int h)
{
    GLfloat fa;

    if(h == 0)
        h = 1;

    glViewport(0, 0, w, h);

    fa = (GLfloat)w/(GLfloat)h;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(35.0, fa, 1.0, 40.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void display(void)
{

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPushMatrix();
        glTranslatef(0.0, 0.0, -7.0);
        glRotatef((GLfloat) rotX, 1.0, 0.0, 0.0);
        glRotatef((GLfloat) rotY, 0.0, 1.0, 0.0);
        glRotatef(90, 1.0, 0.0, 0.0);

        // torre 1
        glPushMatrix();
            glColor3f(0.1,0.1,0.1);
            glTranslatef(1.0, 1.0, 0.0);
            glCallList(list);
            glPushMatrix();
                glRotatef(180, 1.0, 0.0, 0.0);
                glCallList(list+1);
            glPopMatrix();
        glPopMatrix();

        
        // torre 2
        glPushMatrix();
            glColor3f(0.1,0.1,0.1);
            glTranslatef(-1.0, 1.0, 0.0);
            glCallList(list);
            glPushMatrix();
                glRotatef(180, 1.0, 0.0, 0.0);

                glCallList(list+1);
            glPopMatrix();
        glPopMatrix();
        
        // torre 3
        glPushMatrix();
            glColor3f(0.1,0.1,0.1);
            glTranslatef(-1.0, -1.0, 0.0);
            glCallList(list);
            glPushMatrix();
                glRotatef(180, 1.0, 0.0, 0.0);

                glCallList(list+1);
            glPopMatrix();
        glPopMatrix();

        // torre 4 - maior torre
        glPushMatrix();
            glColor3f(0.1,0.1,0.1); // especifica a cor do
            glTranslatef(1.0, -1.0, -0.0);   /*Especifica a posicao da torre no espaço*/
            glCallList(list); //padrão é só list
            glPushMatrix();
                glRotatef(180, 1.0, 0.0, 0.0);
                glCallList(list+1);
            glPopMatrix();
        glPopMatrix();
        

        // muro 1
        glColor3f(0.2,0.2,0.2);
        glPushMatrix();
            glTranslatef(0.0, 1.0, 0.7);
            glRotatef(-90, 1.0, 0.0, 0.0);
            glCallList(list+3);
        glPopMatrix();

        // muro 2
        glPushMatrix();
            glTranslatef(1.0, 0.0, 0.7);
            glRotatef(-90, 1.0, 0.0, 0.0);
            glRotatef(90, 0.0, 1.0, 0.0);
            glCallList(list+3);
        glPopMatrix();

        // muro 3
        glPushMatrix();
            glColor3f(0.2,0.2,0.2);
            glTranslatef(-1.0, 0.0, 0.7);
            glRotatef(-90, 1.0, 0.0, 0.0);
            glRotatef(90, 0.0, 1.0, 0.0);
            glCallList(list+3);
        glPopMatrix();

        // muro 4
        glPushMatrix();
            glColor3f(0.2,0.2,0.2);
            glTranslatef(0.0, -1.0, 0.7);
            glRotatef(-90, 1.0, 0.0, 0.0);
            glCallList(list+3);
        glPopMatrix();

        // portal
        glPushMatrix();

            glColor3f(0.4,0.4,0.4);
            glTranslatef(0.0, 1.0, 0.7);
            glRotatef(-90, 1.0, 0.0, 0.0);

            glCallList(list+4);
            glTranslatef(0.0, 0.7, 0.03);
            glRotatef(-90, 1.0, 0.0, 0.0);

            glCallList(list+5);
            glPopMatrix();

        // chao
          glPushMatrix();
            glTranslatef(0, -1, 0.55);
            glRotatef(0, 1.0, 0.0, 0.0);
            glColor3f(0.33,0.42,0.18);
          glCallList(list+6);

        glPopMatrix();

        // tentativa de fazer uma porta
        glPushMatrix();
            glColor3f(0,0,0);
            glTranslatef(0.0, -10.0, 0.7);
            glRotatef(-90, 10.0, 0.0, 0.0);
            glCallList(list+7);
        glPopMatrix();




    glPopMatrix();

    glutSwapBuffers();
}

void keyboard (unsigned char key, int x, int y)
{
    switch (key) {
        case 'a':
        case 'A':
            rotY = (rotY + 5) % 360;
            glutPostRedisplay();
            break;
        case 'd':
        case 'D':
            rotY = (rotY - 5) % 360;
            glutPostRedisplay();
            break;
        case 'w':
        case 'W':
            rotX = (rotX + 5) % 360;
            glutPostRedisplay();
            break;
        case 's':
        case 'S':
            rotX = (rotX - 5) % 360;
            glutPostRedisplay();
            break;
        case 'q':
        case 'Q':
        case 27:
            exit(0);
            break;
        default:
            break;
    }
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(1000, 1000);
    glutCreateWindow("Castelo");
    init();
    glutReshapeFunc(reshape);
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}