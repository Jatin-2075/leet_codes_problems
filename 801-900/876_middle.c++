#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        vector<ListNode*> nums ;
        ListNode* curr = head;
        while(curr){
            nums.push_back(curr);
            curr = curr->next;
        }
        int middle = nums.size() / 2;
        return nums[middle];
    }
};

int main() {
    // Example: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* n1 = new ListNode(1);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(3);
    ListNode* n4 = new ListNode(4);
    ListNode* n5 = new ListNode(5);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;

    Solution s;
    ListNode* mid = s.middleNode(n1);

    if (mid) cout << mid->val;

    return 0;
}
