#include <iostream>
#include <vector>
#include <algorithm>

void threeWayPartition(std::vector<int>& array, int a, int b) {
    int low = 0, high = array.size() - 1, mid = 0;

    while (mid <= high) {
        if (array[mid] < a) {
            std::swap(array[mid++], array[low++]);
        } else if (array[mid] > b) {
            std::swap(array[high--], array[mid]);
        } else {
            mid++;
        }
    }
}

int main() {
    std::vector<int> array = {1, 4, 3, 2, 5, 6, 7, 8, 9, 0};
    int a = 3, b = 7;

    threeWayPartition(array, a, b);

    for (int num : array) {
        std::cout << num << " ";
    }

    return 0;
}
