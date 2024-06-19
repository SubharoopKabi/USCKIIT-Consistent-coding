#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

//Binary search
vector<int> findfirstandlastpos(int arr[], int n, int x)
{
    int low = 0, high = n - 1, first_occ = -1, last_occ = -1;
    while (low <= high) {

        int mid = (low + high) / 2;
        if (arr[mid] > x)
            high = mid - 1;
        else if (arr[mid] < x)
            low = mid + 1;

        else {
            first_occ = mid;
            high = mid - 1;
        }
    }

    low = 0, high = n - 1;
    while (low <= high) {

        int mid = (low + high) / 2;
        if (arr[mid] > x)
            high = mid - 1;
        else if (arr[mid] < x)
            low = mid + 1;

        else {
            last_occ = mid;
            low = mid + 1;
        }
    }

    return { first_occ, last_occ };
}


int main(){
    int n, x;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the array (sorted): ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << "Enter the element to find: ";
    cin >> x;

    vector<int> result = findfirstandlastpos(arr, n, x);

    cout << "First occurrence: " << result[0] << endl;
    cout << "Last occurrence: " << result[1] << endl;

    return 0;
}

