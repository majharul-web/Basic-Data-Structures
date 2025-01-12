#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;

    Node(int val) : val(val), left(NULL), right(NULL) {}
};

// Function for level-order traversal
void levelorder(Node *root)
{
    if (!root)
        return;

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *curr = q.front();
        q.pop();

        cout << curr->val << " ";
        if (curr->left)
            q.push(curr->left);
        if (curr->right)
            q.push(curr->right);
    }
}

int main()
{
    int n;
    cin >> n;

    if (n == -1)
    {
        cout << "Tree is empty" << endl;
        return 0;
    }

    Node *root = new Node(n); // Create root node
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *curr = q.front();
        q.pop();

        int l, r;
        cin >> l >> r;

        // Create left child if input is not -1
        if (l != -1)
        {
            curr->left = new Node(l);
            q.push(curr->left);
        }

        // Create right child if input is not -1
        if (r != -1)
        {
            curr->right = new Node(r);
            q.push(curr->right);
        }
    }

    levelorder(root);
    return 0;
}
