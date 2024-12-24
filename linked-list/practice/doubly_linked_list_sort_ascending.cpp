#include <bits/stdc++.h>
using namespace std;

int main()
{
    list<int> dll; // Doubly linked list using STL
    int val;

    // Input values into the list
    while (true)
    {
        cin >> val;
        if (val == -1)
        {
            break;
        }
        dll.push_back(val);
    }

    // Sort the list using STL sort
    dll.sort();

    // Print the sorted list
    for (int x : dll)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
