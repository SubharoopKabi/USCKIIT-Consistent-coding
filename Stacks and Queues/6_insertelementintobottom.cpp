#include <iostream>
#include <stack>

using namespace std;

stack<char> st;

void insert_at_bottom(char x) {
    if (st.empty()) {
        st.push(x);
    } else {
        char a = st.top();
        st.pop();
        insert_at_bottom(x);
        st.push(a);
    }
}

int main() {
    st.push('A');
    st.push('B');
    st.push('C');
    st.push('D');

    insert_at_bottom('X');

    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;

    return 0;
}
