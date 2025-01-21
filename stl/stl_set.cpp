#include <iostream>
#include <set>
using namespace std;

int main()
{
    set<int> s; // Declare a set to store unique integers in sorted order
    int n;
    cout << "Enter the number of integers: ";
    cin >> n;

    cout << "Enter " << n << " integers:" << endl;
    while (n--)
    {
        int v;
        cin >> v;
        s.insert(v);
    }

    cout << "Unique integers in sorted order:" << endl;
    for (auto it = s.begin(); it != s.end(); it++)
    {
        cout << *it << endl;
    }

    return 0;
}
