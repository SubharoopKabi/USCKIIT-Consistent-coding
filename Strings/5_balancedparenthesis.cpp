#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool ispar(string x) {
    stack<char> s;
    for (char c : x) {
        if (c == '[' || c == '{' || c == '(') {
            s.push(c);
        }
        else {
    
            if (s.size() == 0) {
                return false;
            }
            else if (c == ']' && s.top() == '[') s.pop();
            else if (c == '}' && s.top() == '{') s.pop();
            else if (c == ')' && s.top() == '(') s.pop();
            else {  
                return false;
            }
        }
    }

    return s.empty();
}

int main() {
    string input;
    cout << "Enter a string with brackets: ";
    cin >> input;

    if (ispar(input)) {
        cout << "String is balanced." << endl;
    } else {
        cout << "String is not balanced." << endl;
    }

    return 0;
}
