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

void preorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->val << " ";
    if (root->right)
        preorder(root->right);
    else if (root->left)
        preorder(root->left);
}

void postorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    if (root->left)
        postorder(root->left);
    else if (root->right)
        postorder(root->right);
    cout << root->val << " ";
}
int main()
{
    Node *bTree = createBinaryTree();
    if (!bTree)
        return 0;

    postorder(bTree->left);
    cout << bTree->val << " ";
    preorder(bTree->right);

    return 0;
}
