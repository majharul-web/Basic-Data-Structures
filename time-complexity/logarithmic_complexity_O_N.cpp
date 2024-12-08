#include <bits/stdc++.h>
using namespace std;

/*
#How to understand is it linear complexity

1.this code complexity == Logarithmic O(logN)
2.loop increment/decrement part using * or /
*/

int main()
{
    int n;
    cin >> n;
    int k = 2;

    // for (int i = 1; i <= n; i *= 2)
    // {
    //     cout << i << endl;
    // }

    // for (int i = n; i >= 1; i /= 3)
    // {
    //     cout << i << endl;
    // }

    for (int i = 1; i < n; i++)
    {
        cout << i << endl;
        i = i * k;
    }

    return 0;
}