#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        string row = "";

        for (int j = 1; j <= N; j++)
        {
            if (i == j && i + j == N + 1)
            {
                row += "X";
            }
            else if (i == j)
            {
                row += "\\";
            }
            else if (i + j == N + 1)
            {
                row += "/";
            }
            else
            {
                row += " ";
            }
        }
        cout << row << endl;
    }

    return 0;
}
