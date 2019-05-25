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
#include "opengl_function.h"
void drawRoad(){
    glClear(GL_COLOR_BUFFER_BIT);
    //Road
    glColor3f(0.5,0.5,0.5);
    glBegin(GL_POLYGON);
        glVertex2f(0.0,0.0);
        glVertex2f((road.getRoad_Length()),0.0);
        glVertex2f((road.getRoad_Length()),-(road.getRoad_Width()+2));
        glVertex2f(0.0,-(road.getRoad_Width()+2));
    glEnd();
    
    //Divider line
    float l=0.0;
    while(l<road.getRoad_Length()){
        glColor3f(1,1,1);
        glBegin(GL_POLYGON);
            glVertex2f(l,-(road.getRoad_Width()/2)-1);
            glVertex2f(l+2,-(road.getRoad_Width()/2)-1);
            glVertex2f(l+2,-(road.getRoad_Width()/2)-1+0.5);
            glVertex2f(l,-(road.getRoad_Width()/2)-1+0.5);
        glEnd();
        
            //background
            glColor3f(1,1,1);
            glBegin(GL_POLYGON);
                glVertex2f(l,-(road.getRoad_Width()+2));
                glVertex2f(l+2,-(road.getRoad_Width()+2));
                glVertex2f(l+2,-(road.getRoad_Width()+2)-2.5);
                glVertex2f(l,-(road.getRoad_Width()+2)-2.5);
            glEnd();
            glBegin(GL_POLYGON);
                glVertex2f(l,0.0);
                glVertex2f(l+2,0.0);
                glVertex2f(l+2,2.5);
                glVertex2f(l,2.5);
            glEnd();
        
        l=l+5.0;
    }
    glColor3f(1,1,1);
    for(int k=1;k<road.getRoad_Width()+1;){
        //int k=0;
        glBegin(GL_POLYGON);
            glVertex2f(road.getRoad_Signal(),-k);
            glVertex2f(road.getRoad_Signal()+road.getRoad_Length()/12,-k);
            glVertex2f(road.getRoad_Signal()+road.getRoad_Length()/12,-k-(road.getRoad_Width()/13));
            glVertex2f(road.getRoad_Signal(),-k-(road.getRoad_Width()/13));
        glEnd();
        k=k+road.getRoad_Width()/8;
    }
    //Side divider
    glColor3f(1,1,0);
    glBegin(GL_POLYGON);
        glVertex2f(0.0,0.0);
        glVertex2f((road.getRoad_Length()),0.0);
        glVertex2f((road.getRoad_Length()),0.4);
        glVertex2f(0.0,0.4);
    glEnd();
    
    glBegin(GL_POLYGON);
        glVertex2f(0.0,-road.getRoad_Width()-2);
        glVertex2f((road.getRoad_Length()),-road.getRoad_Width()-2);
        glVertex2f((road.getRoad_Length()),-road.getRoad_Width()-2-0.4);
        glVertex2f(0.0,-road.getRoad_Width()-2-0.4);
    glEnd();

        for(int i=0;i<v_in_vechile.size();i++){
            //glTranslatef(v_in_vechile[i].getPosx(), v_in_vechile[i].getPosy(), 0.0f); 
            string colour = v_in_vechile[i].getColor();
            if(colour=="RED")
                glColor3f(1,0,0);
            if(colour=="GREEN")
                glColor3f(0,1,0);
            if(colour=="BLUE")
                glColor3f(0,0,1);
            if(colour=="YELLOW")
                glColor3f(1,1,0);
            if(colour=="BLACK")
                glColor3f(0,0,0);
            if(colour=="WHITE")
                glColor3f(1,1,1);
            if(colour=="PINK")
                glColor3ub(255,51,255);
            if(colour=="CYAN")
                glColor3ub(0,255,255);
            if(colour=="GOLDEN")
                glColor3ub(153,153,0);
            glBegin(GL_POLYGON);
                glVertex2f(v_in_vechile[i].getPosx(),-(v_in_vechile[i].getPosy()));
                glVertex2f(v_in_vechile[i].getPosx(),-(v_in_vechile[i].getPosy())+v_in_vechile[i].getWidth());
                glVertex2f(v_in_vechile[i].getPosx()-v_in_vechile[i].getLength(),-(v_in_vechile[i].getPosy())+v_in_vechile[i].getWidth());
                glVertex2f(v_in_vechile[i].getPosx()-v_in_vechile[i].getLength(),-(v_in_vechile[i].getPosy()));
            glEnd();
        }
    //Traffic light
    if(road.getSignal_Color()=="RED")
        glColor3f(1,0,0);
    if(road.getSignal_Color()=="GREEN")
        glColor3f(0,1,0);
    float x1,y1,x2,y2;
    float angle;
    //double radius=0.38;
    y1 = radius,x1=road.getRoad_Signal();
        glBegin(GL_TRIANGLE_FAN);
            glVertex2f(x1,y1);

            for(angle=0.0f ; angle<2*3.14159 + 3; angle+=0.2){
                x2 = x1+sin(angle)*radius;
                y2 = y1+cos(angle)*radius;
                glVertex2f(x2,y2);
            }
        glEnd();
    
        y1=2*radius + radius;
        glBegin(GL_TRIANGLE_FAN);
            glVertex2f(x1,y1);

            for(angle=0.0f ; angle<2*3.14159 + 3; angle+=0.2){
                x2 = x1+sin(angle)*radius;
                y2 = y1+cos(angle)*radius;
                glVertex2f(x2,y2);
            }
        glEnd();
        
        y1=4*radius + radius;
        glBegin(GL_TRIANGLE_FAN);
            glVertex2f(x1,y1);

            for(angle=0.0f ; angle<2*3.14159 + 3; angle+=0.2){
                x2 = x1+sin(angle)*radius;
                y2 = y1+cos(angle)*radius;
                glVertex2f(x2,y2);
            }
        glEnd();
        
    glutSwapBuffers();
}

