#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

// Given an array Arr of N positive integers. 
//Your task is to find the elements whose value is equal to that of its index value.

int binarySearch(int arr[], int low, int high)
{
    if (high >= low)
    {
        int mid = (low + high) / 2;
        if (mid + 1 == arr[mid])
            return mid;
        if (mid > arr[mid])
            return binarySearch(arr, (mid + 1), high);
        else
            return binarySearch(arr, low, (mid - 1));
    }

    return -1;
}

int main(){
    int arr[] = {-10, -5, 0, 3, 7, 9, 12, 13}; 
    int n = sizeof(arr) / sizeof(arr[0]);  
    int fixedPoint = binarySearch(arr, 0, n - 1); 

    if (fixedPoint == -1) {
        printf("No Fixed Point found in the array.\n");
    } else {
        printf("Fixed Point found at index %d, where arr[%d] = %d.\n", fixedPoint, fixedPoint, arr[fixedPoint]);
    }

    return 0;
}









