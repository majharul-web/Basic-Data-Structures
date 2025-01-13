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

Node *createbinarytree()
{
    int val;
    cin >> val;

    if (val == -1)
    {
        return NULL; // Tree is empty
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

void printlevelorder(Node *root)
{
    if (!root)
    {
        cout << "Tree is empty" << endl;
        return;
    }

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *curr = q.front();
        q.pop();
        cout << curr->val << " ";

        if (curr->left)
        {
            q.push(curr->left);
        }
        if (curr->right)
        {
            q.push(curr->right);
        }
    }
}

int countleafnode(Node *root)
{
    if (!root)
    {
        return 0;
    }

    if (root->left == NULL && root->right == NULL)
    {
        return 1;
    }
    int l = countleafnode(root->left);
    int r = countleafnode(root->right);

    return l + r;
}

int main()
{
    Node *root = createbinarytree();

    cout << "printing tree" << endl;
    printlevelorder(root);
    cout << endl;
    cout << "leaf count : " << countleafnode(root);

    return 0;
}

/*

Input : 1 2 3 4 5 -1 -1 -1 -1 -1 -1

Output:
printing tree
1 2 3 4 5
leaf count : 3


 */