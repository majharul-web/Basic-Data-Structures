#include <iostream>
#include <set>
using namespace std;

int main()
{
    set<int> s;
    int n;
    cin >> n;

    while (n--)
    {
        int v;
        cin >> v;
        s.insert(v);
    }

    if (s.size() <= 1)
    {
        cout << "NO";
    }
    else
    {
        auto it = s.begin();
        it++;

        cout << *it << endl;
    }

    return 0;
}
