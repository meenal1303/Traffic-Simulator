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
bool is_between2(int a,int b,int c){
	if(a<b && a>c ){
		return true;
	}
	return false;
}


int check_left(vector<Vechile> v, Vechile v0){
	for(int i=0;i<v.size();i++){
            if(!(v[i].getPosx()==v0.getPosx() && v[i].getPosy()==v0.getPosy())){
                if( ((is_between2(v[i].getPosy(),v0.getPosy()-v0.getWidth(),v0.getPosy()-2*v0.getWidth())) || (is_between2(v[i].getPosy()-v[i].getWidth(),v0.getPosy()-v0.getWidth(),v0.getPosy()-2*v0.getWidth())) || (is_between2(v0.getPosy()-v0.getWidth(),v[i].getPosy(),v[i].getPosy()-v[i].getWidth())) || (is_between2(v0.getPosy()-2*v0.getWidth(),v[i].getPosy(),v[i].getPosy()-v[i].getWidth())) ||( (v0.getPosy()-v0.getWidth()==v[i].getPosy()) && (v[i].getPosy()-v[i].getWidth()==v0.getPosy()-2*v0.getWidth()) ) ) && ( ((is_between2(v[i].getPosx(),v0.getPosx(),v0.getPosx()-v0.getLength())) || (is_between2(v[i].getPosx()-v[i].getLength(),v0.getPosx(),v0.getPosx()-v0.getLength())) || (is_between2(v0.getPosx(),v[i].getPosx(),v[i].getPosx()-v[i].getLength())) || (is_between2(v0.getPosx()-v0.getLength(),v[i].getPosx(),v[i].getPosx()-v[i].getLength())) ||( (v0.getPosx()==v[i].getPosx()) && (v[i].getPosx()-v[i].getLength()==v0.getPosx()-v0.getLength()) ) )  ) ){
                    return 0;
                }
            }
            
        }
    return 1;
}

int check_right(vector<Vechile> v, Vechile v0){
	for(int i=0;i<v.size();i++){
            if(!(v[i].getPosx()==v0.getPosx() && v[i].getPosy()==v0.getPosy())){
                if( ((is_between2(v[i].getPosy(),v0.getPosy()+v0.getWidth(),v0.getPosy())) || (is_between2(v[i].getPosy()-v[i].getWidth(),v0.getPosy()+v0.getWidth(),v0.getPosy())) || (is_between2(v0.getPosy(),v[i].getPosy(),v[i].getPosy()-v[i].getWidth())) || (is_between2(v0.getPosy()+v0.getWidth(),v[i].getPosy(),v[i].getPosy()-v[i].getWidth())) ||( (v0.getPosy()==v[i].getPosy()-v[i].getWidth()) && (v[i].getPosy()==v0.getPosy()+v0.getWidth()) ) ) && ( ((is_between2(v[i].getPosx(),v0.getPosx(),v0.getPosx()-v0.getLength())) || (is_between2(v[i].getPosx()-v[i].getLength(),v0.getPosx(),v0.getPosx()-v0.getLength())) || (is_between2(v0.getPosx(),v[i].getPosx(),v[i].getPosx()-v[i].getLength())) || (is_between2(v0.getPosx()-v0.getLength(),v[i].getPosx(),v[i].getPosx()-v[i].getLength())) ||( (v0.getPosx()==v[i].getPosx()) && (v[i].getPosx()-v[i].getLength()==v0.getPosx()-v0.getLength()) ) )  ) ){
                    return 0;
                }
            }
            
        }
    return 1;
}


