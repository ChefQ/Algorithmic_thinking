/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1 
#define FALSE 0
#define length 6
#define SIZE 100000
void print_array(int * );
// this funtions returns all the integers in the compare array that equal to ref_int
int * starting_points(int ref_int, int * comp_arr);

// compare reference array with compare array from the left
// return True if arries are the same
int check_left(int* ref_arr, int* comp_arr, int* comp_indicies );

// compare reference array with compare array from the right
// return True if arries are the same
int check_right(int* ref_arr, int* comp_arr, int* comp_indicies);
    
int main()
{
    int n;
    
    scanf("%d", &n);
    int temp;
    int snowflakes[SIZE][length];
    for(int i = 0; i< n; i++){
        for(int j = 0; j < length; j ++){
            scanf("%d", &temp);
            snowflakes[i][j] = temp;
        }
    }
 
    // for each item in the list run compare and print the if there are the same
    //int count = 0;
    int* comp_indicies;
    int* comp_arr;
    int* ref_arr;
    int leftChecked;
    int rightChecked;
   // char result[5];
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j ++){
           comp_arr = snowflakes[j];
           ref_arr = snowflakes[i];
           comp_indicies = starting_points(ref_arr[0], comp_arr );
           leftChecked = check_left(ref_arr, comp_arr, comp_indicies );
           rightChecked = check_right(ref_arr, comp_arr, comp_indicies );
           if(rightChecked == TRUE || leftChecked  == TRUE){
               
               printf("Twin snowflakes found.\n");
               return 0;
           }
           
           
        }
    }
    
    printf("No two snowflakes are alike.\n");
    return 0;
}


// this funtions returns all the integers in the compare array that equal to ref_int
int * starting_points(int ref_int, int * comp_arr){
    // create array using malloc    
    // the extra 1 is at the beginning of the array
    // it tells us the number of starting_points to check
    int * points = (int*) calloc((length + 1),  sizeof(float));
    // go through array
    for(int i = 0; i < length; i ++){
        // check comp_arr for indices then add it to the array
        if(ref_int == comp_arr[i]){
            points[0] += 1;
            points[points[0]] = i;
        }
    }
    return points;
    // return indexes and the number of indexes
}

void print_array(int * array){
    for(int i = 0; i < length ; i++){
        printf("%d", array[i] );
    }
}

/*
Returns true or false depending on if it's correct or not.
*/
int check_left(int* ref_arr, int* comp_arr, int* comp_indicies ){
    int numOfPoints = comp_indicies[0];
    // for each numOfPoints
    // go through the ref_arr and comp_arr and compare from the left
    // starting at 0 for ref_arr and the respectived indexes for comp_arr
    // if one any character doesn't break inner loop
    int index;
    //This count is to keep track of failled checks
    int count;
    int comp_index;
    for(int i = 0; i < numOfPoints; i ++){
        index = comp_indicies[i+1];
         count = 1;
        for(int j = 0; j < length; j ++){
            comp_index = index-j;
            if(comp_index < 0){
                comp_index = comp_index + length;
            }
            if(ref_arr[j] != comp_arr[comp_index]){
                break;
            }
            count++;
            if(count == length){
            return TRUE;
            }
        }
    }
   return FALSE;
    
}

int check_right(int* ref_arr, int* comp_arr, int* comp_indicies ){
    int numOfPoints = comp_indicies[0];
    // for each numOfPoints
    // go through the ref_arr and comp_arr and compare from the left
    // starting at 0 for ref_arr and the respectived indexes for comp_arr
    // if one any character doesn't break inner loop
    int index;
    //This count is to keep track of failled checks
    int count;
    int comp_index;
    for(int i = 0; i < numOfPoints; i ++){
        index = comp_indicies[i+1];
        count = 1;
        for(int j = 0; j < length; j ++){ // checks
            comp_index = (index+j)%length;
            if(ref_arr[j] != comp_arr[comp_index]){
                break;
              //  printf("not the same");
            }
            count +=1;
            if(count == length){
            return TRUE;
            }
        }
    }
    return FALSE;
}
