#include <GL/glut.h>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <fstream>
#include "Road.h"
#include "Vechile.h"
#include "function.h"
#include "opengl_function.h"
using namespace std;

Road road;
string **a;
vector<Vechile> v_vechile;
vector<Vechile> v_in_vechile;
ifstream infile;
int run=0;
int time_run;
string read_k;
string read_a1;
int refreshMills;
double radius;

/* Called back when timer expired */
void Timer(int value) {
   glutPostRedisplay();      // Post re-paint request to activate display()
   glutTimerFunc(refreshMills, Timer, 0); // next Timer call milliseconds later
}

void initGL() {
   //Set "clearing" or background color (Black and opaque)
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}
// Function to escape screen
void keyboard(unsigned char key, int x, int y) {
   switch (key) {
      case 27:     // ESC key
         exit(0);
         break;
   }
}

int main(int argc, char* argv[]){
    display1();
    infile>>read_a1;
    while(read_a1=="#"){
        infile.ignore(256,'\n');
        infile>>read_a1;
    }
    time_run=0;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(2000, 2000);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Traffic System");
    gluOrtho2D(0,road.getRoad_Length(),-(road.getRoad_Width()+2+2.5),2.5 );
    if(read_a1=="START"){
        glutDisplayFunc(display2);
    }else{
        infile>>read_a1; 
        while(read_a1=="#"){
            infile.ignore(256,'\n');
            infile>>read_a1;
        }
    }
    glutTimerFunc(0, Timer, 0);
    glutKeyboardFunc(keyboard);
    initGL();
    glutMainLoop();
    return 0;   
}
