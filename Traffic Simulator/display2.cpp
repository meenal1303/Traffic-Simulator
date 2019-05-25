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
bool is_between(int a,int b,int c){
	if(a<b && a>c ){
		return true;
	}
	return false;
}

vector<int> v_clash_x(Vechile v0,vector<Vechile> v){
	vector<int> ret;
	
	for(int i=0;i<v.size();i++){
		if(v[i].getPosx()!=v0.getPosx() || v[i].getPosy()!=v0.getPosy()){
			if(((is_between(v[i].getPosy(),v0.getPosy(),v0.getPosy()-v0.getWidth()) || is_between(v[i].getPosy()-v[i].getWidth(),v0.getPosy(),v0.getPosy()-v0.getWidth())) || ((v[i].getPosy()==v0.getPosy() || v[i].getPosy()-v[i].getWidth()==v0.getPosy()-v0.getWidth() )&& v[i].getWidth()>=v0.getWidth()) || (is_between(v0.getPosy(),v[i].getPosy(),v[i].getPosy()-v[i].getWidth()) || is_between(v0.getPosy()-v0.getWidth(),v[i].getPosy(),v[i].getPosy()-v[i].getWidth())) ) && v[i].getPosx()-v[i].getLength()>=v0.getPosx()){
				ret.push_back(v[i].getPosx()-v[i].getLength()-v0.getPosx()); //v[i].getPosx-v[i].getWidth-v0.getPosx // this is the xdis b/w the vechiles ,that is >=1
			}
		}
	}
	if(ret.size()==0){
		ret.push_back(10000);
	}
	return ret;
}
string changex(string s){
    int pos = s.find("="); 
    if(pos==-1){
        pos = s.find(":");
    }
    s = s.substr(pos+1);
    return s;
}
string change2(string s){
    int pos = s.find("=");
    if(pos==-1){
        pos = s.find(":");
    }
    s = s.substr(0,pos);
    return s;
}


int count(vector<int> v,int a){
    int k=0;
    for(int i=0;i<v.size();i++){
        if(v[i]==a)
            k++;
    }
    return k;
}

void display(string **s,Road road){
    for (int i=0;i<road.getRoad_Width()+2;i++){
        for(int j=0;j<road.getRoad_Length();j++){
            cout<<s[j][i];
        }
        cout<<endl;
    }
}


int min_2(int a,int b){
        //cout<< a<<": "<<b<<endl;
	if(b<0 || a<b){
		return a;
	}
	return b;
}
int minimum_all(vector<int> v){
	int min_all=10000;
	for(int i=0;i<v.size();i++){
                //cout<<v[i]<<endl;
		if(v[i]<min_all){
			min_all=v[i];
                }
	}
	return min_all;
}


int check_array(string **s){
    int p=1;
    for (int i=1;i<road.getRoad_Width()+1;i++){
        for(int j=0;j<road.getRoad_Length();j++){
            if(s[i][j]!=" "){
                p=0;
                break;
            }
        }
    }
    return p;
}

// Returns random entering position
int call_value(string** k,Vechile v0){
    srand( time(0));
    bool makeit=true;
    int number;
    int i;
    vector<int> v;
    while(makeit==true){
        
        for(i=1;i<road.getRoad_Width()+1;i++){
            if(k[0][i]==" ")
                v.push_back(i);
        }
        number = rand() % v.size();
        for(i=1;i<v0.getWidth();i++){
            if(count(v,v[number]-i)<=0){
                break;
            }
        }
        if(i==v0.getWidth()){
            makeit=false;
        }
    }
    return v[number];
}

int check_x(Vechile v){
	if(v.getDisx()>v.getSpeed()+v.getAcceleration()){
		return v.getSpeed()+v.getAcceleration();
	}
	else if(v.getDisx()<=v.getSpeed()+v.getAcceleration() && v.getDisx()>v.getSpeed()){
		return v.getSpeed();
	}
	else if(v.getDisx()>v.getSpeed()-v.getAcceleration() && v.getDisx()<=v.getSpeed()){
		return v.getSpeed()-v.getAcceleration(); 
	}
	else if(v.getDisx()>v.getSpeed()-2*v.getAcceleration() && v.getDisx()<=v.getSpeed()-v.getAcceleration()){
		return v.getSpeed()-2*v.getAcceleration(); 
	}
	else if(v.getDisx()>v.getSpeed()-3*v.getAcceleration() && v.getDisx()<=v.getSpeed()-2*v.getAcceleration()){
		return v.getSpeed()-3*v.getAcceleration(); 
	}
	return 0;
}
void x_margin(int k){
    for(int i=0;i<v_in_vechile.size();i++){
        if(i==k){
        if(road.getSignal_Color()=="RED")
            v_in_vechile[i].setDisx(min_2(minimum_all(v_clash_x(v_in_vechile[i],v_in_vechile)),road.getRoad_Signal()-v_in_vechile[i].getPosx()));
        else
            v_in_vechile[i].setDisx(minimum_all(v_clash_x(v_in_vechile[i],v_in_vechile)));
        }
    }
}
void left_lane_change(int k){
    for(int i=0;i<v_in_vechile.size();i++){
        if(i==k){
            if(check_left(v_in_vechile,v_in_vechile[i])==1 && (((v_in_vechile[i].getDisx()<v_in_vechile[i].getSpeed()+v_in_vechile[i].getAcceleration()) && (v_in_vechile[i].getPosy()-v_in_vechile[i].getWidth()>=1) && (minimum_all(v_clash_x(v_in_vechile[i],v_in_vechile))<=(road.getRoad_Signal()-v_in_vechile[i].getPosx()) || (road.getRoad_Signal()-v_in_vechile[i].getPosx()<=0) || v_in_vechile[i].getSpeed()==0 )) )){
                if(v_in_vechile[i].getSpeedy()==0){
                    v_in_vechile[i].setSpeedy((-1)*v_in_vechile[i].getWidth());
                    v_in_vechile[i].setLaneFreq(1);
                }
                else
                    v_in_vechile[i].setSpeedy(0);
            }
            else
                v_in_vechile[i].setSpeedy(0);
        }
    }
}
void right_lane_change(int k){
    for(int i=0;i<v_in_vechile.size();i++){
        if(i==k){
            if(check_right(v_in_vechile,v_in_vechile[i])==1 && (((v_in_vechile[i].getDisx()<v_in_vechile[i].getSpeed()+v_in_vechile[i].getAcceleration()) && (v_in_vechile[i].getPosy()+v_in_vechile[i].getWidth()<=road.getRoad_Width()-1) && (minimum_all(v_clash_x(v_in_vechile[i],v_in_vechile))<=(road.getRoad_Signal()-v_in_vechile[i].getPosx()) || (road.getRoad_Signal()-v_in_vechile[i].getPosx()<=0) || v_in_vechile[i].getSpeed()==0 )) )){
                if(v_in_vechile[i].getSpeedy()==0){
                    v_in_vechile[i].setSpeedy(v_in_vechile[i].getWidth());
                    v_in_vechile[i].setLaneFreq(0);
                }
                else
                    v_in_vechile[i].setSpeedy(0);
            }
            else
                v_in_vechile[i].setSpeedy(0);
        }
    }
}
/*void right_lane_change(int k){
    for(int i=0;i<v_in_vechile.size();i++){
        if(i==k){
            if(check_right(v_in_vechile,v_in_vechile[i])==1 && )
        }
    }
}*/
void set_x_speed(int k){
    for(int i=0;i<v_in_vechile.size();i++){
        if(i==k){
            if(check_x(v_in_vechile[i])>=v_in_vechile[i].getMaxSpeed()){
                    v_in_vechile[i].setSpeed(v_in_vechile[i].getMaxSpeed());	
            }
            else{
                    if(check_x(v_in_vechile[i])<=0){
                        v_in_vechile[i].setSpeed(0);
                    }
                    else{
                            v_in_vechile[i].setSpeed(check_x(v_in_vechile[i]));
                    }
            }
        }
    }
}
void display2(){
    if(time_run<=0){
        infile>>read_k;
        while(read_k=="#"){
            infile.ignore(256,'\n');
            infile>>read_k;
        }
    }
        if(read_k!="END"){
            if(change2(read_k)!="Pass" && change2(read_k)!="Signal"){
                int i;
                for(i=0;i<v_vechile.size();i++){
                    if(v_vechile[i].getType()==change2(read_k)){
                        break;
                    }
                }
                if(i==v_vechile.size())
                    cout<<"This vehicle type is not yet defined"<<endl;
                
                v_vechile[i].setColor(changex(read_k));
                v_vechile[i].setPosx(0);
                v_vechile[i].setPosy(call_value(a,v_vechile[i]));
                
                //func_call for getDisx x_margin
                //func_call right_lane_change
                //func_call set_x_speed
                
                
                
		
                
                for(int i=0;i<v_in_vechile.size();i++){
                    
                    x_margin(i);
                    if(v_in_vechile[i].getLaneFreq()==0){
                        right_lane_change(i);
                        if(v_in_vechile[i].getSpeedy()==0 && v_in_vechile[i].getType()=="bike"){left_lane_change(i);}
                    }
                    else{
                        left_lane_change(i);
                        if(v_in_vechile[i].getSpeedy()==0 && v_in_vechile[i].getType()=="bike"){right_lane_change(i);}
                    }
                    v_in_vechile[i].movey();
                    x_margin(i);
                    set_x_speed(i);
                    v_in_vechile[i].movex();
                    //v_in_vechile[i].movey();
                    v_in_vechile[i].setSpeedy(0);
                }
               
                
                v_in_vechile.push_back(v_vechile[i]);
                
                for (int i=1;i<road.getRoad_Width()+1;i++){
                    for(int j=0;j<road.getRoad_Length();j++){
                        a[j][i]=" ";
                    }
                }
                 
                update(v_in_vechile,a,road);
                display(a,road);
                drawRoad();
            }
            
            if(change2(read_k)=="Pass"){
                if(time_run==0){
                    time_run = stoi(changex(read_k));
                }
                if(time_run>0){
                    
                    for(int i=0;i<v_in_vechile.size();i++){
                       
                    x_margin(i);
                    if(v_in_vechile[i].getLaneFreq()==0){
                        right_lane_change(i);
                        if(v_in_vechile[i].getSpeedy()==0 && v_in_vechile[i].getType()=="bike"){left_lane_change(i);}
                    }
                    else{
                        left_lane_change(i);
                        if(v_in_vechile[i].getSpeedy()==0 && v_in_vechile[i].getType()=="bike"){right_lane_change(i);}
                    }
                    v_in_vechile[i].movey();
                    x_margin(i);
                    set_x_speed(i);
                    v_in_vechile[i].movex();
                    v_in_vechile[i].setSpeedy(0);
                    }
                    
                
                    
                    for (int i=1;i<road.getRoad_Width()+1;i++){
                        for(int j=0;j<road.getRoad_Length();j++){
                            a[j][i]=" ";
                        }
                    }
                    
                    update(v_in_vechile,a,road);
                    display(a,road);
                    drawRoad();
                    time_run--;
                }
            }
            
            if(change2(read_k)=="Signal"){
                road.setSignal_Color(changex(read_k));
                
                for(int i=0;i<v_in_vechile.size();i++){
                    
                    x_margin(i);
                    if(v_in_vechile[i].getLaneFreq()==0){
                        right_lane_change(i);
                        if(v_in_vechile[i].getSpeedy()==0 && v_in_vechile[i].getType()=="bike"){left_lane_change(i);}
                    }
                    else{
                        left_lane_change(i);
                        if(v_in_vechile[i].getSpeedy()==0 && v_in_vechile[i].getType()=="bike"){right_lane_change(i);}
                    }
                    v_in_vechile[i].movey();
                    x_margin(i);
                    set_x_speed(i);
                    v_in_vechile[i].movex();
                    v_in_vechile[i].setSpeedy(0);
                }
                
                
                
                for (int i=1;i<road.getRoad_Width()+1;i++){
                    for(int j=0;j<road.getRoad_Length();j++){
                        a[j][i]=" ";
                    }
                }
                update(v_in_vechile,a,road);
                display(a,road);
                drawRoad();
            }
        }
        else{            
               
                for(int i=0;i<v_in_vechile.size();i++){
               
                    x_margin(i);
                    right_lane_change(i);
                    if(v_in_vechile[i].getLaneFreq()==0){
                        right_lane_change(i);
                        if(v_in_vechile[i].getSpeedy()==0 && v_in_vechile[i].getType()=="bike"){left_lane_change(i);}
                    }
                    else{
                        left_lane_change(i);
                        if(v_in_vechile[i].getSpeedy()==0 && v_in_vechile[i].getType()=="bike"){right_lane_change(i);}
                    }
                    x_margin(i);
                    set_x_speed(i);
                    v_in_vechile[i].movex();
                    v_in_vechile[i].setSpeedy(0);
                }
               
                for (int i=1;i<road.getRoad_Width()+1;i++){
                    for(int j=0;j<road.getRoad_Length();j++){
                        a[j][i]=" ";
                    }
                }
                update(v_in_vechile,a,road);
                if(check_array(a)=='1'){
                    return;
                }
                display(a,road);
                drawRoad();
        }
}

