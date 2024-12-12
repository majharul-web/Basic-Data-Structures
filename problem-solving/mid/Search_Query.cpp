#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    sort(v.begin(), v.end()); // Sort the array for binary search

    int q;
    cin >> q;
    while (q--)
    {
        int val;
        cin >> val;

        int l = 0, r = n - 1, flag = 0;

        while (l <= r)
        {
            int mid = l + (r - l) / 2; // Calculate mid to avoid overflow

            if (v[mid] == val)
            {
                flag = 1; // Value found
                break;
            }
            else if (v[mid] > val)
            {
                r = mid - 1; // Search in the left half
            }
            else
            {
                l = mid + 1; // Search in the right half
            }
        }

        if (flag == 1) // Correct comparison
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}
