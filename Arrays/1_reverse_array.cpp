/*C++ program to reverse an array time complexity: O(n)*/
#include <iostream>
using namespace std;
void reverseArray(int a[], int start, int end)
{
    while (start < end)
    {
        int temp = a[start];
        a[start] = a[end];
        a[end] = temp;
        start++;
        end--;
    }
}

int main()
{
    int a[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(a) / sizeof(a[0]);
    //original array
    cout<<"Original array is :"<<endl; 
    for (int i = 0; i < n; i++)
    {
        cout << a[i];
    }
    cout<<endl;
    //function calling
    reverseArray(a, 0, n - 1);
    cout << "Reversed array is" << endl;
    //print the reversed array
    for (int i = 0; i < n; i++)
    {
        cout << a[i];
    
    }
    return 0;
}