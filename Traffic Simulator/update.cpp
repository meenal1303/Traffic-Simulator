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
using namespace std;

void update(vector<Vechile> v,string **s,Road road){
  int i,j,r,q,k;
    for(i=0;i<v.size();i++){
    	for(k=1;k<road.getRoad_Width()+1;k++){
    		if(v[i].getPosy()==k){
    			for(r=k;(r>k-v[i].getWidth() && r>0);r--){
		            for(j=0;j<road.getRoad_Length();j++){
		        		if(v[i].getPosx()==j){
		        			for(q=j;(q>j-v[i].getLength() && q>=0);q--){
		        				s[q][r]=v[i].getType().substr(0,1);
		        			}
		        		}
		        	}
		        }
    		}
        }    		
    }
}
