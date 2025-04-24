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

vector<int> leftOuterSideView(Node *root)
{
    vector<int> v;
    bool free[100005] = {false};

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
        int level = current.second;

        if (free[level] == false)
        {
            v.push_back(node->val);
            free[level] = true;
        }

        if (node->left)
        {
            q.push({node->left, level + 1});
        }
        else if (node->right)
        {
            q.push({node->right, level + 1});
        }
    }

    sort(v.rbegin(), v.rend());
    return v;
}

vector<int> rightOuterSideView(Node *root)
{

    vector<int> v;
    bool free[100005] = {false};

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
        else if (node->left)
        {
            q.push({node->left, level + 1});
        }
    }

    return v;
}

void outerTreeView(Node *root)
{
    if (!root)
    {
        return;
    }

    vector<int> v1 = leftOuterSideView(root->left);
    vector<int> v2 = {root->val};
    vector<int> v3 = rightOuterSideView(root->right);

    vector<int> v;
    if (v1.size())
        v.insert(v.end(), v1.begin(), v1.end());
    v.insert(v.end(), v2.begin(), v2.end());
    if (v3.size())
        v.insert(v.end(), v3.begin(), v3.end());

    for (int val : v)
    {
        cout << val << " ";
    }
    cout << endl;
}

int main()
{
    Node *bTree = createBinaryTree();
    if (!bTree)
    {
        return 0;
    }

    outerTreeView(bTree);

    return 0;
}
