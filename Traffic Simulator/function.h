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

extern Road road;
extern string **a;
extern vector<Vechile> v_vechile;
extern vector<Vechile> v_in_vechile;
extern ifstream infile;
extern int run;
extern int time_run;
extern string read_k;
extern string read_a1;
extern int refreshMills;
extern double radius;

void update(vector<Vechile> v,string **s,Road road);
vector<int> v_clash_x(Vechile v0,vector<Vechile> v);
int check_right(vector<Vechile> v, Vechile v0);
int check_left(vector<Vechile> v, Vechile v0);
void display1();
void display2();
int temp();
