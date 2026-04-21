#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<int, int> freqmp ;
        int ans = 0;
        for(int i : nums) freqmp[i]++;
        for (auto &p : freqmp) {
            int i = p.first;
            if (freqmp.count(i + 1)) {
                ans = max(ans, freqmp[i] + freqmp[i + 1]);
            }
        }
        return ans;
    }
};

int main(){
    vector <int> nums ;

}