#include <iostream>
#include <vector>
#include <GLUT/glut.h>

using namespace std;

void myInit(){
    glClearColor(1.0,1.0,1.0,0.0);
    glColor3f(0.0,0.0,0.0);
    glLineWidth(5);
    glPointSize(5);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-320, 320, -240, 240);
}

void myDisplay(){
    glClear(GL_COLOR_BUFFER_BIT);
    int x1,y1,x2,y2;
    cout<<"Enter the end point 1 of the clipping line (x1,y1) : ";
    cin>>x1>>y1;
    cout<<"Enter the end point 2 of the clipping line (x2,y2) : ";
    cin>>x2>>y2;
    
    vector<int> sx(4);
    cout<<"Enter the point 1 for the rectangle: ";
    cin>>sx[0];
    cout<<"Enter the point 2 for the rectangle: ";
    cin>>sx[1];
    cout<<"Enter the point 3 for the rectangle: ";
    cin>>sx[2];
    cout<<"Enter the point 4 for the rectangle: ";
    cin>>sx[3];
    //TLBR
    
    int r1,r2;
    
    if(x1<sx[0]){
        r1+=(1>>1);
    }
    
    if(x2<sx[0]){
        r2+=(1>>1);
    }
    
    if(x2<sx[1]){
        r1+=(1>>2);
    }
    
    if(){
        
    }
    
}

int main(int argc, char * argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutCreateWindow("Line Clipping");
    glutDisplayFunc(myDisplay);
    myInit();
    glutMainLoop();
    return 1;
}
