#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node
{
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val)
    {
        val = _val;
    }

    Node(int _val, vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};

class Solution
{
public:
    int maxDepth(Node *root)
    {
        if (!root)
            return 0;

        queue<Node *> q;
        q.push(root);

        int depth = 0;

        while (!q.empty())
        {
            int n = q.size();

            while (n--)
            {
                Node *node = q.front();
                q.pop();

                for (Node *child : node->children)
                {
                    if (child)
                        q.push(child);
                }
            }

            depth++;
        }

        return depth;
    }
};

int main()
{

    Node *root = new Node(1);
    Node *n2 = new Node(2);
    Node *n3 = new Node(3);
    Node *n4 = new Node(4);
    Node *n5 = new Node(5);
    Node *n6 = new Node(6);

    root->children = {n3, n2, n4};
    n3->children = {n5, n6};

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        int n = q.size();

        while (n--)
        {
            Node *curr = q.front();
            q.pop();

            cout << curr->val << " ";

            for (Node *child : curr->children)
                q.push(child);
        }

        cout << endl;
    }

    return 0;
}