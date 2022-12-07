#include <GLUT/glut.h>
#include <iostream>


void myInit(){
    glClearColor(1.0,1.0,1.0,0.0);
    glColor3f(0.0,0.0,0.0);
    glLoadIdentity();
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    glOrtho(-500, 500, -500, 500, -500, 500);
    glMatrixMode(GL_MODELVIEW);
}

int i=0;

void myDisplay1(int){
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        gluLookAt(0, 0, 1, 0, 0, 0, 0, 1, 0);
        glPushMatrix();
        glColor3f(0.0,0.0,0.0);
        glTranslatef(360-i, 360-i, 0);
        glRotatef(i, 1, 1, 1);
        glScalef(10, 10, 10);
        glutSolidTeapot(4);
        glPopMatrix();
        glPushMatrix();
        glColor3f(0.0,0.0,0.0);
        glTranslatef(0, -30, 0);
        glScalef(1, 0.1, 1);
        glutWireCube(100);
        glPopMatrix();
        i++;
        if(i==360)
        {
            i=359;
        }
    glFlush();
    glutTimerFunc(10, myDisplay1, 0);
}

void myDisplay(){

}

int main(int argc, char * argv[]) {
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1000, 1000);
    glutCreateWindow("3D Animations");
    glutDisplayFunc(myDisplay);
    glutTimerFunc(10, myDisplay1, 0);
    myInit();
    glutMainLoop();
    return 1;
}
