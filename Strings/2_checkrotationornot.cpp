#include <bits/stdc++.h>
using namespace std;

void rotatedornot(string n, string m) {
    n += n; 
    if (n.find(m) != string::npos) 
        cout << "YES";
    else 
        cout << "NO";
}

int main() {
    string n, m;
    cout << "Enter the first string (n): ";
    cin >> n;
    cout << "Enter the second string (m): ";
    cin >> m;

    if (n.length() != m.length()) {
        cout << "NO" << endl;
    } else {
        rotatedornot(n, m);
        cout << endl;
    }

    return 0;
}
