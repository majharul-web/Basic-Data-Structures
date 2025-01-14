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

int sumOfLeftChildren(Node *root)
{
    if (!root)
    {
        return 0;
    }

    int sum = 0;
    // If the left child exists, add its value to the sum
    if (root->left)
    {
        sum += root->left->val;
    }

    // Recurse for the left and right subtrees
    sum += sumOfLeftChildren(root->left);
    sum += sumOfLeftChildren(root->right);

    return sum;
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

int main()
{
    Node *root = createbinarytree();

    cout << "Printing tree in level order:" << endl;
    printlevelorder(root);
    cout << endl;

    int leftSum = sumOfLeftChildren(root);
    cout << "Sum of left child nodes: " << leftSum << endl;

    return 0;
}
