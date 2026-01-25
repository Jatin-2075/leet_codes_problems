#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast){
                ListNode* start = head;

                while(start != slow){
                    start = start->next;
                    slow = slow->next;
                }
                return start;
            }
        }
        return NULL;
    }
};

int main() {
    // Create nodes: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    // Create a cycle: 5 -> 3
    head->next->next->next->next->next = head->next->next;

    Solution sol;
    ListNode* cycleStart = sol.detectCycle(head);

    if (cycleStart)
        cout << "Cycle starts at node with value: " << cycleStart->val << endl;
    else
        cout << "No cycle" << endl;

    return 0;
}
