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

int sumNonLeafNodes(Node *root)
{
    if (!root)
        return 0;

    int sum = 0;
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *curr = q.front();
        q.pop();

        if (curr->left != NULL || curr->right != NULL)
        {
            sum += curr->val;
        }

        if (curr->left)
            q.push(curr->left);
        if (curr->right)
            q.push(curr->right);
    }
    return sum;
}

int main()
{
    Node *bTree = createbinarytree();

    int result = sumNonLeafNodes(bTree);
    cout << result << endl;

    return 0;
}
