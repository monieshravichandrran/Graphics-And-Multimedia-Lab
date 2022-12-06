#include <GLUT/glut.h>
#include <iostream>

using namespace std;


void myDisplay1(){
    
}


void delay(){
    for(int i=1;i<1e3;i++){
        for(int j=1;j<1e3;j++);
    }
}


void circle(int xc, int yc, int r){
    int x = 0, y = r;
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
            pk = pk + 2*x - 2*y + 1;
            y--;
        }
        else{
            pk = pk + 2*x + 1;
        }
    }
    glBegin(GL_POINTS);
    glEnd();
}

void myDisplay(int){
    glClear(GL_COLOR_BUFFER_BIT);
    for(int i=0;i<200;i++){
        glClear(GL_COLOR_BUFFER_BIT);
        circle(-100+i,0,100);
        delay();
        glFinish();
    }
}

void myInit(){
    glClearColor(1.0,1.0,1.0,0.0);
    glColor3f(0.0,0.0,0.0);
    glLineWidth(5);
    glPointSize(5);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-320.0, 320.0, -240.0, 240.0);
}

int main(int argc, char * argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutCreateWindow("Animations");
    glutDisplayFunc(myDisplay1);
    myInit();
    glutTimerFunc(100, myDisplay, 0);
    glutMainLoop();
    return 1;
}
