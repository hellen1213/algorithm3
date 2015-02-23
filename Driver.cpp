#include "Find.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <time.h>
#include <sys/time.h>

using namespace std;

int main(){

Find object;
struct timeval start, finish;

//object.method1();

int size = 20000;	//temporary size for point[]
int arg1 = 0;	//arg1 will be the actual size of input
int point[size];

int word;
string input_string;
stringstream ss;

ifstream input("input.txt");
while(!input.eof()){
getline(input, input_string);
ss << input_string;
while(!ss.eof()){
ss >> word;

point[arg1] = word;	//assign the input to point[]

arg1++;
}

ss.clear();
}

size = arg1-1;
int size2 = arg1/2;
int x_pos[size2];
int y_pos[size2];

//put x and y in each point into two different arrays
for(int i =0; i<size; i++){

if(i%2 == 0){
x_pos[i/2] = point[i];

}
if(i%2 == 1){
y_pos[(i-1)/2] = point[i];

}

}

object.sort(x_pos, y_pos, size2);

//populate the array of points
for(int i=0; i<size2; i++)
	cout<< x_pos[i] <<", "<< y_pos[i] <<endl;





//start time here
gettimeofday(&start, NULL);
double t1 = start.tv_sec + (start.tv_usec/1000000.0);

object.method2(x_pos, y_pos, size2);

//end time here
gettimeofday(&finish, NULL);
double t2 = finish.tv_sec + (finish.tv_usec/1000000.0);

cout<< "seconds elapsed for devide and conquer algorithm is: " << t2 - t1 << endl;

cout<<"****length of closest pair is****"<<object.method2(x_pos, y_pos, size2)<<endl;


//start time here
gettimeofday(&start, NULL);
double t3 = start.tv_sec + (start.tv_usec/1000000.0);

object.method3(x_pos, y_pos, size2);

//end time here
gettimeofday(&finish, NULL);
double t4 = finish.tv_sec + (finish.tv_usec/1000000.0);

cout<< "seconds elapsed for brute force algorithm is: " << t4 - t3 << endl;

cout<<"----length of closest pair is----"<<object.method3(x_pos, y_pos, size2)<<endl;


return 0;
}
