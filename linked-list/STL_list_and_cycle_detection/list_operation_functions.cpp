#include <bits/stdc++.h>
using namespace std;

int main()
{

    list<int> l1 = {1, 2, 3, 4, 5, 6, 20, 3, 4, 20, 20};
    // l1.remove(20);
    l1.sort();
    // l1.sort(greater<int>());

    // unique work for only sorted list
    // l1.unique();
    l1.reverse();

    for (int val : l1)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}