#include <bits/stdc++.h>
#include <string.h>
using namespace std;

int isPalindrome(string S) {
    int i = 0;
    int n = S.length() - 1;
    while (i <= n) {
        if (S[i] != S[n]) {
            return 0;
        }
        i++;
        n--;
    }
    return 1;
}

int main() {
    string str;
    cout << "Enter a string: ";
    getline(cin, str); 

    if (isPalindrome(str)) {
        cout << "The string \"" << str << "\" is a palindrome." << endl;
    } else {
        cout << "The string \"" << str << "\" is not a palindrome." << endl;
    }

    return 0;
}
