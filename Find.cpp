#include"Find.h"
#include<cmath>

Find::Find(){
}
Find::~Find(){
}

//d&c
double Find::method2(int arr1[], int arr2[], int length){

double path = sqrt( abs(arr1[0] - arr1[1])*abs(arr1[0] - arr1[1]) + abs(arr2[0] - arr2[1])*abs(arr2[0] - arr2[1]) );

 if(length <= 3){

//find the shortest distance("brute force")
   for(int i = 0; i<length; i++){

	for(int j = i+1; j<length; j++){

		if(path > sqrt( (arr1[i] - arr1[j])*(arr1[i] - arr1[j]) + (arr2[i] - arr2[j])*(arr2[i] - arr2[j]) ) )
			path = sqrt( (arr1[i] - arr1[j])*(arr1[i] - arr1[j]) + (arr2[i] - arr2[j])*(arr2[i] - arr2[j]) );
	}
   }
   
   return path;
 }
 else{

   //arr1[] has all x_pos, arr2[] contains all y_pos
   int left = length/2;
   int right = length/2 + length%2;


   //x of points in array from 1->(length/2)
   int arr_xl[left];

   for(int i = 0; i < left; i++){
	arr_xl[i] = arr1[i];

   }

   int arr_xr[right];

   for(int i = 0; i < right; i++){
	arr_xr[i] = arr1[left + i];

   }

   //x of middle point
   int x_m = arr1[length/2];


   //y of points in array from 1 to (length/2)
   int arr_yl[left];
   for(int i = 0; i < left; i++){
	arr_yl[i] = arr2[i];

   }
   

   int arr_yr[right];

   for(int i = 0; i < right; i++){
	arr_yr[i] = arr2[left + i];

   }
  

   double path_l = method2(arr_xl, arr_yl, left);
   double path_r = method2(arr_xr, arr_yr, right);
 
   //get the value of d
   double d_min = path_r;

   if(path_l < d_min)
	d_min = path_l;

   int length1 = length;
   int d_arr_y[length1];	// contain the points between 2d
   int d_arr_x[length1];
   int num = 0;

   for(int i=0; i<length; i++){

	if(abs(arr1[i] - x_m) < d_min){

	   d_arr_y[num] = arr2[i];
	   d_arr_x[num] = arr1[i];
	   num++;
	}
   }
   length1 = num;

   path = d_min;



   sort(d_arr_y, d_arr_x, num);



   for(int i=0; i<num; i++){
	int j = i-3;
	if(j>=0){
	   j = i-3;
	}else{
	   j = 0;
	}
	int k = i+3;
	if(k<=num){
	   k = i+3;
	}else{
	   k = num;
	}
	
	for(int m = j; m < k; m++){
		if(m != i && path > sqrt( abs(d_arr_x[i] - d_arr_x[m])*abs(d_arr_x[i] - d_arr_x[m]) + abs(d_arr_y[i] - d_arr_y[m])*abs(d_arr_y[i] - d_arr_y[m]) )){

			path = sqrt( abs(d_arr_x[i] - d_arr_x[m])*abs(d_arr_x[i] - d_arr_x[m]) + abs(d_arr_y[i] - d_arr_y[m])*abs(d_arr_y[i] - d_arr_y[m]) );

		}//end_if
	}//end_for

   }//end_for




return path;
 }
 	
 
}










double Find::method3(int arr3[], int arr4[], int length){

    double path = sqrt( (arr3[0] - arr3[1])*(arr3[0] - arr3[1]) + (arr4[0] - arr4[1])*(arr4[0] - arr4[1]) );

   for(int i=0; i<length; i++){
	for(int j=i+1; j<length; j++){

	   if(path > sqrt( (arr3[i] - arr3[j])*(arr3[i] - arr3[j]) + (arr4[i] - arr4[j])*(arr4[i] - arr4[j]) )){

		path = sqrt( (arr3[i] - arr3[j])*(arr3[i] - arr3[j]) + (arr4[i] - arr4[j])*(arr4[i] - arr4[j]) );

	   }
	}
	
   }
   return path;
  
}

//insertion sort
void Find::sort(int arr5[], int arr6[], int length){

int i, j, tmp, tmp2;
for(i=1; i<length; i++){
  j=i;
  while(j>0 && arr5[j-1]>arr5[j]){
   tmp = arr5[j];
   arr5[j] = arr5[j-1];
   arr5[j-1] = tmp;

   tmp2 = arr6[j];
   arr6[j] = arr6[j-1];
   arr6[j-1] = tmp2;
   j--;
   }
}
}

