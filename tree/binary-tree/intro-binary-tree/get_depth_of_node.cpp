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

int getmaxheight(Node *root)
{
    if (!root)
    {
        return 0;
    }

    int l = getmaxheight(root->left);
    int r = getmaxheight(root->right);

    return max(l, r) + 1;
}

// Function to calculate depth of a node with given value
int getdepth(Node *root, int val, int depth = 0)
{
    if (!root)
    {
        return -1; // Node not found
    }

    if (root->val == val)
    {
        return depth;
    }

    int leftDepth = getdepth(root->left, val, depth + 1);
    if (leftDepth != -1)
    {
        return leftDepth;
    }

    return getdepth(root->right, val, depth + 1);
}

int main()
{
    Node *root = createbinarytree();

    cout << "printing tree" << endl;
    printlevelorder(root);
    cout << endl;
    cout << "max height : " << getmaxheight(root) << endl;

    // Example to find depth of a node
    int nodeValue;
    cout << "Enter node value to find depth: ";
    cin >> nodeValue;

    int depth = getdepth(root, nodeValue);
    if (depth != -1)
    {
        cout << "Depth of node " << nodeValue << " : " << depth << endl;
    }
    else
    {
        cout << "Node " << nodeValue << " not found in the tree." << endl;
    }

    return 0;
}

/*
Input tree:
1 2 3 4 5 -1 -1 -1 -1 -1 -1

printing tree
1 2 3 4 5
max height : 3
Enter node value to find depth: 3
Depth of node 3 : 1


*/
