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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode dummy(0);
        ListNode *tail = &dummy;

        while (list1 && list2)
        {
            if (list1->val < list2->val)
            {
                tail->next = list1;
                list1 = list1->next;
            }
            else
            {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        } 

        tail->next = list1 ? list1 : list2;

        return dummy.next;
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
    vector<int> a = {1, 2, 4};
    vector<int> b = {1, 3, 4};

    ListNode *l1 = buildList(a);
    ListNode *l2 = buildList(b);

    Solution sol;
    ListNode *res = sol.mergeTwoLists(l1, l2);

    printList(res);
}
