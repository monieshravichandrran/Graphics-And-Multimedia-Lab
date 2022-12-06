#include <iostream>
#include <GLUT/glut.h>

using namespace std;


void myInit(){
    glClearColor(1.0,1.0,1.0,1.0);
    glColor3f(0.0,0.0,0.0);
    glLineWidth(4);
    glPointSize(4);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-320, 320, -240, 240);
}


void midpoint(int xc, int yc, int r){
    int x = 0;
    int y = r;
    int pk = 1-r;
    while(x<=y){
        glBegin(GL_POINTS);
        glVertex2i(x+xc,y+yc);
        glVertex2i(x+xc,-y+yc);
        glVertex2i(-x+xc,y+yc);
        glVertex2i(-x+xc,-y+yc);
        glVertex2i(y+xc,x+yc);
        glVertex2i(y+xc,-x+yc);
        glVertex2i(-y+xc,x+yc);
        glVertex2i(-y+xc,-x+yc);
        glEnd();
        x++;
        if(pk>=0){
            pk = pk + 2*x - 2*y;
            y--;
        }
        else{
            pk = pk + 2*x;
        }
    }
    glFlush();
}

void myDisplay(){
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POINTS);
    midpoint(0,0,100);
    glEnd();
    glFlush();
}

int main(int argc, char * argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutCreateWindow("MidPoint Circle Algorithm");
    glutDisplayFunc(myDisplay);
    myInit();
    glutMainLoop();
    return 1;
}
