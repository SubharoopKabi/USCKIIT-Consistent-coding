#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

int findDuplicate(vector<int>& nums) {
    set<int> s;
    for (int i = 0;i < nums.size();i++) {
        if (s.find(nums[i]) != s.end()) {
            return nums[i];
        }
        s.insert(nums[i]);
    }
    return 1;
}


int main() {
    
    vector<int> nums = {1, 3, 4, 2, 5, 3};

    int duplicate = findDuplicate(nums);

    if (duplicate != -1) {
        cout << "The duplicate number is: " << duplicate << endl;
    } else {
        cout << "No duplicate found." << endl;
    }

    return 0;
}