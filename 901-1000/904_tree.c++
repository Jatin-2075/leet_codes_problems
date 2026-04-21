#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> mp;

        int left = 0, right = 0, ans = 0;

        for(; right < fruits.size(); right++){
            mp[fruits[right]]++;

            while(mp.size() > 2){
                mp[fruits[left]]--;
                if(mp[fruits[left]] == 0) mp.erase(fruits[left]);
                left++;
            }

            ans = max(ans, right - left + 1);
        }
    }
};

int main() {
    vector <int> fruits = {0,1,2,2};

    Solution s;
    cout << s.totalFruit(fruits);
}