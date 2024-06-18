#include <iostream>
#include <algorithm>
using namespace std;

int minJumps(int arr[], int n) {
    // Base conditions
    if (n <= 1) return 0;
    if (arr[0] == 0) return -1;

    int maxReach = arr[0]; // The farthest we can reach initially
    int step = arr[0];     // Steps we can still take
    int jump = 1;          // Initial jump count

    // Traverse the array
    for (int i = 1; i < n; i++) {
        // Check if we have reached the end of the array
        if (i == n - 1) return jump;

        // Update maxReach
        maxReach = std::max(maxReach, arr[i] + i);

        // Use a step to move to the next element
        step--;

        // If no more steps left
        if (step == 0) {
            // We must have used a jump
            jump++;

            // If the current index is greater or equal to the max reach, we can't move further
            if (i >= maxReach) return -1;

            // Re-initialize steps to the number of steps to reach maxReach from position i
            step = maxReach - i;
        }
    }
    return -1; // If the end is not reachable
}

int main() {
    // Define an array of integers
    int arr[] = {2, 3, 1, 1, 2, 4, 2, 0, 1, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Call the function and store the result
    int result = minJumps(arr, n);

    // Print the result
    if (result == -1) {
        std::cout << "End is not reachable from the given array." <<endl;
    } else {
        std::cout << "Minimum number of jumps to reach the end: " << result <<endl;
    }

    return 0;
}
