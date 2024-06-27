#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

bool areIsomorphic(string str1, string str2) {
    unordered_map<char, char> mp, mp2;
    int n = str1.size();
    int m = str2.size();
    if (m != n) return false;
    for (int i = 0; i < n; i++) {
        if (mp.find(str1[i]) == mp.end()) 
           mp[str1[i]] = str2[i];
        if (mp2.find(str2[i]) == mp2.end()) 
           mp2[str2[i]] = str1[i];

        if (mp[str1[i]] != str2[i] || mp2[str2[i]] != str1[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    string str1, str2;

    cout << "Enter the first string: ";
    cin >> str1;

    cout << "Enter the second string: ";
    cin >> str2;

    if (areIsomorphic(str1, str2)) {
        cout << "The strings \"" << str1 << "\" and \"" << str2 << "\" are isomorphic." << endl;
    } else {
        cout << "The strings \"" << str1 << "\" and \"" << str2 << "\" are not isomorphic." << endl;
    }

    return 0;
}

