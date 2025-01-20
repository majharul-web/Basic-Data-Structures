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

bool search(Node *root, int val)
{

    if (root == NULL)
        return false;
    if (root->val == val)
        return true;
    if (root->val > val)
        return search(root->right, val);
    else
        return search(root->left, val);
}

int main()
{
    Node *root = createBinaryTree();

    int val;
    cin >> val;

    if (search(root, val))
        cout << "Found !" << endl;
    else
        cout << "Not Found !" << endl;

       return 0;
}