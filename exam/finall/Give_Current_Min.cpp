#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
    int N, Q;
    cin >> N;

    priority_queue<int, vector<int>, greater<int>> A;

    for (int i = 0; i < N; i++)
    {
        int X;
        cin >> X;
        A.push(X);
    }

    cin >> Q;

    for (int i = 0; i < Q; i++)
    {
        int command;
        cin >> command;

        switch (command)
        {
        case 0:
        {
            int X;
            cin >> X;
            A.push(X);
            cout << A.top() << endl;
            break;
        }
        case 1:
            if (A.empty())
            {
                cout << "Empty" << endl;
            }
            else
            {
                cout << A.top() << endl;
            }
            break;

        case 2:
            if (A.empty())
            {
                cout << "Empty" << endl;
            }
            else
            {
                A.pop();
                if (A.empty())
                {
                    cout << "Empty" << endl;
                }
                else
                {
                    cout << A.top() << endl;
                }
            }
            break;

        default:
            cout << "Invalid Command" << endl;
            break;
        }
    }

    return 0;
}
