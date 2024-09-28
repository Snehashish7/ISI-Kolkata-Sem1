#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))
int main()
{
    //call lengthOfLIS
    return 0;
}
int helper(int* nums,int curr_index, int prev_index, int n){
    if(curr_index == n)
        return 0;
    int incl = INT_MIN;
    if(prev_index == -1 || nums[curr_index] > nums[prev_index]){
        incl = helper(nums,curr_index+1, curr_index, n)+1;
    }
    int excl = helper(nums,curr_index+1, prev_index,n);
    return fmax(incl,excl);
}

int lengthOfLIS(int* nums, int numsSize) {
    return helper(nums,0,-1, numsSize); //array, current_index, prev_index
}