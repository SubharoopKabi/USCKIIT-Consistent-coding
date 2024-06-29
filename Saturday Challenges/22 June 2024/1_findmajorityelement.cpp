#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

int majorityElement(int a[], int size)
{

    map<int, int> mp;
    for (int i = 0;i < size;i++) {
        mp[a[i]]++;
    }
    for (auto i : mp) {
        if (i.second > size / 2) {
            return i.first;
        }
    }
    return -1;

}

int main(){
    int arr[] = {3, 3, 4, 2, 4, 4, 2, 4, 4};
    int size = sizeof(arr) / sizeof(arr[0]);
    int result = majorityElement(arr, size);

    if (result != -1) {
        cout << "The majority element is " << result << endl;
    } else {
        cout << "There is no majority element." << endl;
    }

    return 0;
}