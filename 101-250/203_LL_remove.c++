#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution
{
public:
    ListNode *removeElements(ListNode *head, int val){
        ListNode *dummy = new ListNode(0);
        dummy->next = head;

        ListNode *prev = dummy;
        ListNode *curr = head;

        while (curr){
            if (curr->val == val) prev->next = curr->next;
            else prev = curr; 
            curr = curr->next;
        }

        return dummy->next;
    }
};

ListNode *createList(vector<int> &arr)
{
    if (arr.empty())
        return nullptr;

    ListNode *head = new ListNode(arr[0]);
    ListNode *temp = head;

    for (int i = 1; i < arr.size(); i++)
    {
        temp->next = new ListNode(arr[i]);
        temp = temp->next;
    }
    return head;
}
void printList(ListNode *head)
{
    while (head)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int val;
    cin >> val;

    ListNode *head = createList(arr);

    Solution obj;
    head = obj.removeElements(head, val);

    printList(head);
}
