#include <iostream>
#include <queue>
using namespace std;

class MyStack {
public:
    queue<int> q;

    void push(int x) {
        q.push(x);
        int n = q.size();

        for(int i = 0; i < n-1; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {
        int t = q.front();
        q.pop();
        return t;
    }

    int top() {
        return q.front();
    }

    bool empty() {
        return q.empty();
    }
};

int main() {
    MyStack st;

    st.push(1);
    st.push(2);
    st.push(3);

    cout << "Top: " << st.top() << endl;   // 3
    cout << "Pop: " << st.pop() << endl;   // 3
    cout << "Top after pop: " << st.top() << endl; // 2

    cout << "Empty? " << st.empty() << endl;

    return 0;
}
