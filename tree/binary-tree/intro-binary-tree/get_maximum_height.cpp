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

    if (root->left == NULL && root->right == NULL)
    {
        return 0;
    }
    int l = getmaxheight(root->left);
    int r = getmaxheight(root->right);

    return max(l, r) + 1;
}

int main()
{
    Node *root = createbinarytree();

    cout << "printing tree" << endl;
    printlevelorder(root);
    cout << endl;
    cout << "max height : " << getmaxheight(root);

    return 0;
}

/*

Input : 1 2 3 4 5 -1 -1 -1 -1 -1 -1

Output:
printing tree
1 2 3 4 5
max height : 2




Key Differences Between Height and Depth

Aspect	               Height	                            Depth
What it Measures	   Longest path from a node to a leaf	Distance from the root to a node
Root Node Value	       Equal to the tree's height	        0
Leaf Node Value	       0 (no children)	                    Equal to the number of edges from root


 */