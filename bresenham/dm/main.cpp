#include <iostream>
#include <GLUT/glut.h>

void myInit(){
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glColor3f(0.0f, 0.0f, 0.0f);
    glPointSize(4);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-320.0, 320.0, -240.0, 240.0);
}


int slp(int x1, int y1, int x2, int y2){
    if(x1==x2)
        return 1.1;
    return (y2-y1)/(x2-x1);
}

void bresenham(int x1,int y1, int x2, int y2){
    int dx = x2-x1;
    int dy = y2-y1;
    int incx, incy;
    int slope = slp(x1,y1,x2,y2);
    dx > 0 ? incx = 1 : incx = -1;
    dy > 0 ? incy = 1 : incy = -1;
    
    int x = x1, y = y1;
    
    if(slope>=1){
        int pk = 2*dy-dx;
        while(x<x2){
            glBegin(GL_POINTS);
            glVertex2i(x,y);
            glEnd();
            if(pk>0){
                pk = pk + 2*dy - dx;
                x += incx;
            }
            else{
                pk = pk + 2*dy;
            }
            y+=incy;
        }
    }
    else{
        int pk = 2*dx-dy;
        while(x<x2){
            glBegin(GL_POINTS);
            glVertex2i(x,y);
            glEnd();
            if(pk>0){
                pk = pk + 2*dx - dy;
                y += incy;
            }
            else{
                pk = pk + 2*dx;
            }
            x+=incx;
        }
    }
    glFlush();
}

void myDisplay(){
    glClear(GL_COLOR_BUFFER_BIT);
    bresenham(70, 300, 200, 200);
    bresenham(40, 50, 150, 120);
    glFlush();
}

int main(int argc, char * argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutCreateWindow("Bressenham's Circle Drawing Algorithm");
    glutDisplayFunc(myDisplay);
    myInit();
    glutMainLoop();
    return 1;
}
