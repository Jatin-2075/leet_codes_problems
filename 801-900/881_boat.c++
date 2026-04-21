#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int ans = 0, left = 0, right = people.size() - 1;

        sort(people.begin(), people.end());

        while(left <= right){
            if((people[left] + people[right]) <= limit){
                ans++;
                left++;
            }
            else ans++;
            right--;
        }
        return ans;
    }
};

int main(){
    vector<int> people = {3,5,3,4};
    int limit = 3;

    Solution s;
    cout << s.numRescueBoats(people, limit);
    return 0;
}