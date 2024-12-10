#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    int count = 0;

    for (int i = 0; i < n; ++i)
    {
        if (find(a.begin(), a.end(), a[i] + 1) != a.end())
        {
            count++;
        }
    }

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         if (a[j] == a[i] + 1)
    //         {
    //             count++;
    //             break;
    //         }
    //     }
    // }

    cout << count << endl;
    return 0;
}

/*


 */