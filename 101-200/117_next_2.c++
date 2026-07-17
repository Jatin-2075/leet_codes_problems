#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node(int x) {
        val = x;
        left = right = next = nullptr;
    }
};

Node* connect(Node* root) {
    if (root == nullptr)
        return root;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();
        Node* prev = nullptr;

        for (int i = 0; i < size; i++) {
            Node* curr = q.front();
            q.pop();

            if (prev != nullptr)
                prev->next = curr;

            prev = curr;

            if (curr->left)
                q.push(curr->left);

            if (curr->right)
                q.push(curr->right);
        }

        prev->next = nullptr;
    }

    return root;
}

void printLevels(Node* root) {
    Node* level = root;

    while (level != nullptr) {
        Node* curr = level;

        while (curr != nullptr) {
            cout << curr->val << " ";
            curr = curr->next;
        }

        cout << "NULL\n";
        level = level->left;
    }
}

int main() {

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->left = new Node(6);
    root->right->right = new Node(7);

    connect(root);

    printLevels(root);

    return 0;
}
