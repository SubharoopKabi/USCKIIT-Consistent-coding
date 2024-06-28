#include <iostream>
#include <vector>

using namespace std;

int celebrity(vector<vector<int> >& M, int n) {
    int i = 0, j = n - 1, celeb = -1;

    // eliminating those which are not celeb.
    while (i < j) {

        // i follows j, means i is not celeb
        if (M[i][j] == 1) {
            celeb = j;
            i++;
        }
        // i doesn't follow j, means j is not celeb
        else {
            j--;
            celeb = i;
        }
    }

    // checking if celeb is not following someone, and everyone is following celeb.
    for (int i = 0;i < n;i++) {
        if (celeb != i && (M[celeb][i] == 1 || M[i][celeb] == 0)) {
            return -1;
        }
    }
    return celeb;
}

int main() {
    // Example input
    vector<vector<int>> M = { 
        {0, 1, 0},
        {0, 0, 0},
        {0, 1, 0}
    };
    int n = M.size();
    
    int celeb = celebrity(M, n);
    
    if (celeb == -1) {
        cout << "There is no celebrity." << endl;
    } else {
        cout << "The celebrity is person " << celeb << "." << endl;
    }

    return 0;
}