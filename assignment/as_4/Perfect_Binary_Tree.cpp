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

int calculateDepth(Node *root)
{

    if (!root)
        return -1;

    if (root->left == NULL && root->right == NULL)
        return 1;

    int l = calculateDepth(root->left);
    int r = calculateDepth(root->right);

    return max(l, r) + 1;
}

int countNodes(Node *root)
{
    if (!root)
        return 0;

    int leftCount = countNodes(root->left);
    int rightCount = countNodes(root->right);

    return leftCount + rightCount + 1;
}

bool isPerfectBinaryTree(Node *root)
{
    if (!root)
        return false;

    int depth = calculateDepth(root);
    int totalNodes = countNodes(root);

    return totalNodes == round(pow(2, depth) - 1);
}

int main()
{
    Node *bTree = createBinaryTree();

    if (isPerfectBinaryTree(bTree))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}
