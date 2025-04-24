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

vector<int> leftSideView(Node *root)
{
    vector<int> v;

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *curr = q.front();
        q.pop();

        v.push_back(curr->val);

        if (curr->left)
        {
            q.push(curr->left);
        }
        else
        {
            if (curr->right)
            {
                q.push(curr->right);
            }
        }
    }

    sort(v.rbegin(), v.rend());
    return v;
}
vector<int> rightSideView(Node *root)
{
    vector<int> v;

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *curr = q.front();
        q.pop();

        v.push_back(curr->val);

        if (curr->right)
        {
            q.push(curr->right);
        }
        else
        {
            if (curr->left)
            {
                q.push(curr->left);
            }
        }
    }

    return v;
}

void outerTreeView(Node *root)
{
    vector<int> v;

    if (root)
    {

        vector<int> v1 = leftSideView(root->left);
        vector<int> v2 = {root->val};
        vector<int> v3 = rightSideView(root->right);

        v.insert(v.end(), v1.begin(), v1.end());
        v.insert(v.end(), v2.begin(), v2.end());
        v.insert(v.end(), v3.begin(), v3.end());
    }

    for (int val : v)
    {
        cout << val << " ";
    }
}

void preorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->val << " ";
}
int main()
{
    Node *bTree = createBinaryTree();
    if (!bTree)
        return 0;

    if (bTree->left && bTree->right)
    {
        outerTreeView(bTree);
    }
    else if (bTree->left)
    {
        postorder(bTree);
        cout << endl;
    }
    else
    {
        preorder(bTree);
        cout << endl;
    }

    return 0;
}
