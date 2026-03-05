#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> ans;

void solve(string curr, int open, int close, int n)
{
    if (curr.length() == 2 * n)
    {
        ans.push_back(curr);
        return;
    }

    if (open < n)
    {
        solve(curr + "(", open + 1, close, n);
    }

    if (close < open)
    {
        solve(curr + ")", open, close + 1, n);
    }
}

int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;

    solve("", 0, 0, n);

    cout << "Valid Parentheses:\n";
    for (string s : ans)
    {
        cout << s << endl;
    }

    return 0;
}