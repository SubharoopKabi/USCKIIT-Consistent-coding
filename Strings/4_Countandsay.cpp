#include <iostream>
#include <string>

using namespace std;

string countAndSay(int n) {
    // base condition
    if (n == 1) 
       return "1";

    string arr = countAndSay(n - 1);

    string ans = "";
    for (int i = 0; i < arr.size();) {
        char c = arr[i];
        int count = 0;
        while (i < arr.size() && arr[i] == c) {
            count++;
            i++;
        }
        ans += to_string(count);
        ans += c;
    }
    return ans;
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    if (n <= 0) {
        cout << "Please enter a positive integer." << endl;
        return 1;
    }

    string result = countAndSay(n);
    cout << "The " << n << "-th term of the Count and Say sequence is: " << result << endl;

    return 0;
}
