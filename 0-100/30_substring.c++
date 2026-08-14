#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {

        vector<int> ans;

        if (words.empty() || s.empty())
            return ans;

        int wordLen = words[0].size();
        int wordCount = words.size();
        int totalLen = wordLen * wordCount;

        if (totalLen > s.size())
            return ans;

        unordered_map<string, int> required;

        for (string word : words)
            required[word]++;

        for (int offset = 0; offset < wordLen; offset++) {

            int left = offset;
            int count = 0;

            unordered_map<string, int> current;

            for (int right = offset;
                 right + wordLen <= s.size();
                 right += wordLen) {

                string word = s.substr(right, wordLen);

                if (required.find(word) == required.end()) {
                    current.clear();
                    count = 0;
                    left = right + wordLen;
                    continue;
                }

                current[word]++;
                count++;

                while (current[word] > required[word]) {

                    string leftWord = s.substr(left, wordLen);

                    current[leftWord]--;
                    left += wordLen;
                    count--;
                }

                if (count == wordCount) {
                    ans.push_back(left);

                    string leftWord = s.substr(left, wordLen);
                    current[leftWord]--;
                    left += wordLen;
                    count--;
                }
            }
        }

        return ans;
    }
};

int main() {

    string s = "barfoothefoobarman";
    vector<string> words = {"foo", "bar"};

    Solution so;

    vector<int> ans = so.findSubstring(s, words);

    for (int x : ans) {
        cout << x << " ";
    }

    return 0;
}