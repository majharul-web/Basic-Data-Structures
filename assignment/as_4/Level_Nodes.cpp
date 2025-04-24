#include <bits/stdc++.h>
using namespace std;

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

vector<int> getNodesExactLevel(Node *root, int level)
{
    vector<int> v;
    queue<pair<Node *, int>> q;

    if (root)
    {
        q.push({root, 0});
    }

    while (!q.empty())
    {
        pair<Node *, int> current = q.front();
        q.pop();

        Node *node = current.first;
        int nodeLevel = current.second;

        if (nodeLevel == level)
        {
            v.push_back(node->val);
        }

        if (node->left)
        {
            q.push({node->left, nodeLevel + 1});
        }
        if (node->right)
        {
            q.push({node->right, nodeLevel + 1});
        }
    }
    return v;
}

int main()
{
    Node *bTree = createBinaryTree();

    int level;
    cin >> level;

    vector<int> exactLevelNodes = getNodesExactLevel(bTree, level);

    if (exactLevelNodes.empty())
    {
        cout << "Invalid" << endl;
    }
    else
    {
        for (int val : exactLevelNodes)
        {
            cout << val << " ";
        }
    }

    return 0;
}
