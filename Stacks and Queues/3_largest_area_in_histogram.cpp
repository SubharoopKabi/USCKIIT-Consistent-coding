#include <iostream>
#include <stack>
#include <vector>
#include <algorithm> // For reverse function
#include <climits> // For LLONG_MIN
using namespace std;

#include<iostream>
using namespace std;


long long getMaxArea(long long arr[], int n)
{
    stack<pair<long long, long long>> s;
    vector<long long> left_small, right_small;


    // code for nearest left small 
    for (int i = 0;i < n;i++) {

        // pop till the top of stack is having no. and is less that current array element.
        while (s.size() > 0 && s.top().first >= arr[i]) s.pop();

        // 0 pushing means if there is no building on left side then there will be ground at -1th index.
        if (s.size() == 0) left_small.push_back(-1);

        // if stack is not empty means we have next greater element from current ele. on left at the top of stack.
        else left_small.push_back(s.top().second);

        // push the current element.
        s.push({ arr[i], i });
    }


    // clear the stack
    while (s.size()) s.pop();

    // code for nearest right small
    for (int i = n - 1;i >= 0;i--) {

        // pop till the top of stack is having no. and is greater than that of current array element.
        while (s.size() > 0 && s.top().first >= arr[i]) s.pop();

        // as if there is no building smaller on right means it will be ground of nth place.
        if (s.size() == 0) right_small.push_back(n);

        // if stack is not empty means we have next greater element from current ele. on right at the top of stack.
        else right_small.push_back(s.top().second);

        // push the current element.
        s.push({ arr[i], i });
    }
    reverse(right_small.begin(), right_small.end());


    // now we have 2 array showing nearest left and nearest right.

    // now find and maximizing the area.
    long long mx = LONG_LONG_MIN;
    for (int i = 0;i < n;i++) {
        long long height = arr[i];
        long long width = right_small[i] - left_small[i] - 1;
        mx = max(mx, height * width);
    }

    return mx;
}

int main(){
    // Example histogram
    long long arr[] = {6, 2, 5, 4, 5, 1, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Calculate and print the maximum area
    cout << "Maximum rectangular area in the histogram is: " << getMaxArea(arr, n) << endl;

    return 0;
}