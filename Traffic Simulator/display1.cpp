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
using namespace std;

string change(string s){
    int pos = s.find("="); 
    if(pos==-1){
        pos = s.find(":");
    }
    s = s.substr(pos+1);
    return s;
}
string change2x(string s){
    int pos = s.find("=");
    if(pos==-1){
        pos = s.find(":");
    }
    s = s.substr(0,pos);
    return s;
}

void display1(){
    string file;
    cin>>file;
    infile.open(file); // handling many configuration file 
    if(!infile.is_open()){
        cout<< "Error opening file"<< endl;
    }    
    //reading refreshMills
    string rd; 
    infile>>rd;
    while(rd=="#"){
        infile.ignore(256,'\n');
        infile>>rd;
    } rd=change(rd);
    refreshMills=stoi(rd);
    infile>>rd;
    while(rd=="#"){
        infile.ignore(256,'\n');
        infile>>rd;
    } rd=change(rd);
    radius=stod(rd);
    //road parameters
    string a1; 
    infile>>a1;
    while(a1=="#"){
        infile.ignore(256,'\n');
        infile>>a1;
    } a1=change(a1);
    road.setRoad_ID(stoi(a1)); infile>>a1;
    while(a1=="#"){
        infile.ignore(256,'\n');
        infile>>a1;
    } a1=change(a1);
    road.setRoad_Length(stoi(a1)); infile>>a1;
    while(a1=="#"){
        infile.ignore(256,'\n');
        infile>>a1;
    } a1=change(a1);
    road.setRoad_Width(stoi(a1)); infile>>a1;
    while(a1=="#"){
        infile.ignore(256,'\n');
        infile>>a1;
    } a1=change(a1);
    road.setRoad_Signal(stoi(a1));
    
    a=new string*[road.getRoad_Length()];//7
        for(int i=0;i<road.getRoad_Length();i++)
            a[i]=new string[road.getRoad_Width()+2];
    for(int i=0;i<road.getRoad_Width()+2;i++){
            for(int j=0;j<road.getRoad_Length();j++){
                    a[j][i]=" ";
            }
    }
    
    for(int k=0;k<road.getRoad_Width()+2;k++){
        if(k==0 || k==road.getRoad_Width()+1){
            for(int i=0;i<road.getRoad_Length();i++){
                a[i][k]="-";
            }
        }
    }
    string k;
    infile>>k;
    while(k=="#"){
        infile.ignore(256,'\n');
        infile>>k;
    } k=change(k); //number of vechiles to be defined
    int t = stoi(k);
    int i=0;
    string a2;
    while(t>0){
        if(i==0){
            infile>>a1;
            while(a1=="#"){
                infile.ignore(256,'\n');
                infile>>a1;
            }
            infile>>a2;
            while(a2=="#"){
                infile.ignore(256,'\n');
                infile>>a2;
            }
        }
        else{
            a1=a2;
            infile>>a2;
            while(a2=="#"){
                infile.ignore(256,'\n');
                infile>>a2;
            }
        }
        Vechile v;
        while(change2x(a2)!="Vechile_Type" ){
            v.setType(change(a1)); 
                if(change2x(a2)=="Vechile_Length")
                    v.setLength(stoi(change(a2))); 
                if(change2x(a2)=="Vechile_Width"){
                    v.setWidth(stoi(change(a2)));
                }
                if(change2x(a2)=="Vechile_MaxSpeed")
                    v.setMaxSpeed(stoi(change(a2)));
                if(change2x(a2)=="Vechile_Acceleration")
                    v.setAcceleration(stoi(change(a2)));
                if(change2x(a2)=="Vechile_Color")
                    v.setColor(change(a2));
            infile>>a2;
            while(a2=="#"){
                infile.ignore(256,'\n');
                infile>>a2;
            }
            if(change2x(a2)=="Vechile_Type" || a2=="end"){
                v_vechile.push_back(v);
            }  
            if(a2=="end"){
                break;
            }
        }  
        i++;
        t=t-1;
    }    
}
