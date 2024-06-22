#include <iostream>
#include <stack>
#include <cstring> // For strlen

char* reverse(char* S, int len) {
    std::stack<char> s; // Using char instead of int for character stack
    for (int i = 0; i < len; i++) {
        s.push(S[i]);
    }

    for (int i = 0; i < len; i++) {
        S[i] = s.top();
        s.pop();
    }
    return S;
}

int main() {
    // Example string
    char str[] = "Hello, World!";
    int len = strlen(str);

    // Print original string
    std::cout << "Original string: " << str << std::endl;

    // Reverse the string
    char* reversedStr = reverse(str, len);

    // Print reversed string
    std::cout << "Reversed string: " << reversedStr << std::endl;

    return 0;
}
