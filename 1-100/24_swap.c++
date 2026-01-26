#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;

        while (prev->next && prev->next->next) {
            ListNode* a = prev->next;
            ListNode* b = a->next;

            a->next = b->next;
            b->next = a;
            prev->next = b;

            prev = a;
        }

        return dummy->next;
    }
};


int main() {
    // build: 1 -> 2 -> 3 -> 4
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);

    Solution s;
    ListNode* ans = s.swapPairs(head);

    // print list
    while (ans) {
        cout << ans->val << " ";
        ans = ans->next;
    }
}
