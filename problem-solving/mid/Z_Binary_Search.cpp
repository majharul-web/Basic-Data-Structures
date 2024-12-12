#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;
    int a[n];

    // Input the array
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    // Sort the array to enable binary search
    sort(a, a + n);

    while (q--)
    {
        int x;
        cin >> x;
        int l = 0, r = n - 1, flag = 0;

        // Binary Search Logic
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (a[mid] == x)
            {
                flag = 1;
                break;
            }
            else if (a[mid] > x)
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }

        // Output the result
        cout << (flag ? "found" : "not found") << endl;
    }

    return 0;
}
