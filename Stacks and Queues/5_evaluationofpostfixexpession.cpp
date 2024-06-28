#include <iostream>
#include <stack>
#include <string>
#include <sstream>

using namespace std;

// Function to evaluate a postfix expression
int evaluatePostfix(const string& expression) {
    stack<int> s;
    
    for (char ch : expression) {
        if (ch == ' ') {
            continue; // Skip spaces
        } else if (isdigit(ch)) {
 
            s.push(ch - '0');
        } else {
            int operand2 = s.top(); s.pop();
            int operand1 = s.top(); s.pop();
            int result;

            switch (ch) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    result = operand1 / operand2;
                    break;
                default:
                    cerr << "Unsupported operator: " << ch << endl;
                    return -1;
            }

            s.push(result);
        }
    }

    return s.top();
}

int main() {
    string postfix = "53+82-*"; // Example postfix expression: (5 + 3) * (8 - 2)

    int result = evaluatePostfix(postfix);
    cout << "The result of the postfix expression is: " << result << endl;

    return 0;
}
