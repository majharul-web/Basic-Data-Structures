#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node
class Node
{
public:
    int val;
    Node *left;
    Node *right;

    Node(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

// Function to create a binary tree from input
Node *createBinaryTree()
{
    int val;
    cin >> val;

    if (val == -1)
    {
        return NULL;
    }
    Node *root = new Node(val);
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *curr = q.front();
        q.pop();

        int l, r;
        cin >> l >> r;
        if (l != -1)
        {
            curr->left = new Node(l);
            q.push(curr->left);
        }
        if (r != -1)
        {
            curr->right = new Node(r);
            q.push(curr->right);
        }
    }
    return root;
}

// Function to compute the right side view of a binary tree
vector<int> rightSideView(Node *root)
{
    vector<int> v;
    bool free[3005] = {false};

    queue<pair<Node *, int>> q;
    if (root)
    {
        q.push({root, 1});
    }

    while (!q.empty())
    {
        pair<Node *, int> current = q.front();
        q.pop();

        Node *node = current.first;
        int level = current.second;

        if (free[level] == false)
        {
            v.push_back(node->val);
            free[level] = true;
        }

        if (node->right)
        {
            q.push({node->right, level + 1});
        }

        if (node->left)
        {
            q.push({node->left, level + 1});
        }
    }

    return v;
}

int main()
{
    cout << "Enter the tree values in level order (use -1 for NULL):\n";
    Node *bTree = createBinaryTree();

    // Compute the right side view of the tree
    vector<int> result = rightSideView(bTree);

    // Print the result
    cout << "Right side view of the binary tree:\n";
    for (int val : result)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
