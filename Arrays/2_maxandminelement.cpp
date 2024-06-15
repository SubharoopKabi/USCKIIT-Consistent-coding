#include<iostream>
using namespace std;

int main()
{
    int arr[] = { 1000, 11, 445, 1, 330, 3000 };
               
    int n = 6;

    int max = arr[0];
    int min = arr[1];

    for (int i = 1;i < n;i++) {
        if (arr[i] > max) 
          max = arr[i];
        if (arr[i] < min) 
          min = arr[i];
    }
    cout << "Minimum elemnt :  " << min <<endl<< "Maximum element : " << max;
}