
#include <bits/stdc++.h>
using namespace std;
 

void printSubsequence(string input, string output)
{
 
    if (input.empty()) {
        cout << output << endl;
        return;
    }
 
    printSubsequence(input.substr(1), output + input[0]);
 
    printSubsequence(input.substr(1), output);
}
 
// Driver code
int main()
{
    // output is set to null before passing in as a
    // parameter
    string output = "";
    string input = "abcd";
 
    printSubsequence(input, output);
 
    return 0;
}