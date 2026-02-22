#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (!head)
            return nullptr;

        ListNode *curr = head;

        while (curr && curr->next)
        {
            if (curr->val == curr->next->val)
            {
                curr->next = curr->next->next;
            }
            else
            {
                curr = curr->next;
            }
        }

        return head;
    }
};

ListNode *buildList(vector<int> v)
{
    if (v.empty())
        return nullptr;
    ListNode *head = new ListNode(v[0]);
    ListNode *curr = head;

    for (int i = 1; i < v.size(); i++)
    {
        curr->next = new ListNode(v[i]);
        curr = curr->next;
    }
    return head;
}

void printList(ListNode *head)
{
    while (head)
    {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

int main()
{
    vector<int> v = {1, 1, 2, 3, 3};

    ListNode *head = buildList(v);

    Solution sol;
    head = sol.deleteDuplicates(head);

    printList(head);
}
