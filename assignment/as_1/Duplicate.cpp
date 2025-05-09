#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<long long int> A(N);

    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    sort(A.begin(), A.end());

    int isDuplicate = 0;

    for (int i = 1; i < N; i++)
    {
        if (A[i] == A[i - 1])
        {
            isDuplicate = 1;
            break;
        }
    }

    if (isDuplicate == 1)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }

    return 0;
}
