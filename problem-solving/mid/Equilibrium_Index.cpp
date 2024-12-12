#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n; // Input size of the array

    vector<int> nums(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> nums[i]; // Input the elements of the array
    }

    // Calculate the prefix sum of the array
    vector<int> prefixSum(n);
    prefixSum[0] = nums[0];
    for (int i = 1; i < n; i++)
    {
        prefixSum[i] = prefixSum[i - 1] + nums[i];
    }

    // Iterate through the array to find the equilibrium index
    for (int i = 0; i < n; i++)
    {
        int leftSum = (i == 0) ? 0 : prefixSum[i - 1];
        int rightSum = prefixSum[n - 1] - prefixSum[i];

        if (leftSum == rightSum)
        {
            cout << i << endl; // Print the equilibrium index
            return 0;
        }
    }

    // If no equilibrium index is found, print -1
    cout << -1 << endl;
    return 0;
}
