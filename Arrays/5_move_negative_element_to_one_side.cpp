#include <iostream>
#include <vector>
using namespace std;

void moveNegativesToFront(vector<int>& arr) {
    int left = 0, right = arr.size() - 1;

    while (left <= right) {
        if (arr[left] < 0 && arr[right] >= 0) {
            left++;
            right--;
        }
        else if (arr[left] >= 0 && arr[right] < 0) {
            swap(arr[left], arr[right]);
            left++;
            right--;
        }
        else if (arr[left] < 0 && arr[right] < 0) {
            left++;
        }
        else {
            right--;
        }
    }
}

int main() {
    vector<int> arr = {-12, 11, -13, -5, 6, -7, 5, -3, -6};

    moveNegativesToFront(arr);

    for (int num : arr) {
        cout << num << " ";
    }

    return 0;
}
