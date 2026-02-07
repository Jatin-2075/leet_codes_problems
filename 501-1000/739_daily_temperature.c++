#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans(temperatures.size(),0);
        stack<int> st;

        for(int i = 0; i < temperatures.size(); i++){
            while(!st.empty() && temperatures[i] > temperatures[st.top()]){
                int id = st.top();
                st.pop();
                ans[id] = i - id;
            }
            st.push(i);
        }
        return ans;
    }
};

int main() {

    int n;
    cout << "Enter number of days: ";
    cin >> n;

    vector<int> temp(n);

    cout << "Enter temperatures: ";
    for(int i = 0; i < n; i++) {
        cin >> temp[i];
    }

    Solution s;
    vector<int> result = s.dailyTemperatures(temp);

    cout << "Answer: ";
    for(int x : result) {
        cout << x << " ";
    }

    return 0;
}
