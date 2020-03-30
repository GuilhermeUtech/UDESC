#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <GL/glut.h>
#include <GL/gl.h>

int rotX = 0;
int rotY = 0;
GLUquadricObj *pObj;

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

void init()
{
    GLfloat sourceLight[] = { 0.3, 0.3, 0.3, 0.0 };

    glEnable(GL_DEPTH_TEST);
    glFrontFace(GL_CCW);
    glEnable(GL_CULL_FACE);

    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0,GL_AMBIENT,sourceLight);
    glLightfv(GL_LIGHT0,GL_DIFFUSE,sourceLight);
    glEnable(GL_LIGHT0);

    glEnable(GL_COLOR_MATERIAL);

    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);

    glClearColor(0.0, 0.0, 0.0, 0.0);

    pObj = gluNewQuadric();
    gluQuadricNormals(pObj, GLU_SMOOTH);
}

void display(void)
{

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPushMatrix();
        glTranslatef(0.0, -1.0, -5.0);
        glRotatef((GLfloat) rotX, 1.0, 0.0, 0.0);
        glRotatef((GLfloat) rotY, 0.0, 1.0, 0.0);


        glPushMatrix();
            //CABEÇA
            glTranslatef(0.0, 1.5, 0.0);
            glColor3f(1,1,1);
            gluSphere(pObj, 0.23, 50, 50);
            

            //OLHOS
            glColor3f(0.25,0.41,0.88);
            glTranslatef(0.1, 0.1, 0.18);
            gluSphere(pObj, 0.04, 26, 13);

            glTranslatef(-0.2, 0.0, 0.0);
            gluSphere(pObj, 0.04, 26, 13);

            //bola 2
            glTranslatef(0.1, -0.6, -1.2); // (0.1,x,x)
            glColor3f(1,1,1);
            gluSphere(pObj, 0.37, 26, 13);

            //bola 3
            glTranslatef(0.0, -1.0, -1.2); // (0.1,x,x)
            glColor3f(1,1,1);
            gluSphere(pObj, 0.70, 26, 13);



    	    //BRAÇO
    	    glColor3f(0.25,0.25,0.25);
    	    glTranslatef(0.0, 1.2,0.50);
            glRotatef(0.0, 0.0, 0.0, 0.0);
            glRotatef(90, 0.0, 1.0, 0.0);
    	    gluCylinder(pObj, 0.04, 0.02, 0.6, 26,20);
            glTranslatef(0.0, 0.0,-0.07);
            glRotatef(-180, 0.0, 1.0, 0.0);
    	    gluCylinder(pObj, 0.04, 0.02, 0.6, 26,20);


    glPopMatrix();
    glPopMatrix();

    glutSwapBuffers();
}

void keyboard (unsigned char key, int x, int y)
{
    switch (key) {
        case 'a':
        case 'A':
            rotY = (rotY - 5) % 360;
            glutPostRedisplay();
            break;
        case 'd':
        case 'D':
            rotY = (rotY + 5) % 360;
            glutPostRedisplay();
            break;
        case 'w':
        case 'W':
            rotX = (rotX - 5) % 360;
            glutPostRedisplay();
            break;
        case 's':
        case 'S':
            rotX = (rotX + 5) % 360;
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
    glutInitWindowSize(800, 750);
    glutCreateWindow("Boneco de Snow morre no final");
    init();
    glutReshapeFunc(reshape);
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMainLoop();

    return 0;
}