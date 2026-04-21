#include <bits/stdc++.h>
using namespace std;

class MinStack {
public:
    stack<int> s;
    stack<int> mins;

    MinStack() { }

    void push(int val) { 
        s.push(val);

        if(mins.empty()) mins.push(val);
        else {
            mins.push(min(val, mins.top()));
        }
    }

    void pop() { if(!s.empty()) {s.pop(); mins.pop(); } }

    int top() { return s.top(); }

    int getMin() { return mins.top(); }
};

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    MinStack st;

    // Example usage (you can change as you want)
    st.push(5);
    st.push(2);
    st.push(8);

    cout << "Top element: " << st.top() << endl;
    cout << "Min element: " << st.getMin() << endl;

    st.pop();

    cout << "After pop, top: " << st.top() << endl;

    return 0;
}
