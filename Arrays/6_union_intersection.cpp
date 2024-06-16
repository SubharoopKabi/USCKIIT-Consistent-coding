#include<bits/stdc++.h>
using namespace std;

int doUnion(int a[], int n, int b[], int m) {
    set<int> s;
    for (int i = 0;i < n;i++) s.insert(a[i]);
    for (int i = 0;i < m;i++) s.insert(b[i]);
    return s.size();
}

int doIntersection(int a[], int n, int b[], int m) {
    sort(a, a + n);
    sort(b, b + m);

    int i = 0, j = 0, ans = 0;

    while (i <= j) {
        if (a[i] == b[j]) {
            ans++;
            i++;
            j++;
        }
        else if (a[i] < b[j]) 
            i++;
        else 
            j++;
    }
    return ans;
}

int main(){
    
    int a[] = {1, 2, 4, 5, 6};
    int b[] = {2, 3, 5, 7};
    int n = sizeof(a) / sizeof(a[0]);
    int m = sizeof(b) / sizeof(b[0]);

    int unionSize = doUnion(a, n, b, m);
    int intersectionSize = doIntersection(a, n, b, m);

    cout << "Union size: " << unionSize << endl;
    cout << "Intersection size: " << intersectionSize << endl;

    return 0;
}