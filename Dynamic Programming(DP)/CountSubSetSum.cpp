#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long

//Recursive Approach
/*
class Solution
{
public:
    int CountSubset(int arr[], int n, int sum, int count)
    {
        if (n == 0 && sum != 0)
            return count += 0;
        if (sum == 0)
            return count += 1;

        if (arr[n - 1] <= sum)
        {
            return count = CountSubset(arr, n - 1, sum, count) + CountSubset(arr, n - 1, sum - arr[n - 1], count);
        }

        else
        {
            return count = CountSubset(arr, n - 1, sum, count);
        }
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, target;
        cin >> n >> target;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        Solution ob;
        if (int ans = ob.CountSubset(arr, n, target, 0))
            cout << ans << "\n";
        else
            cout << "No\n";
    }
}
*/

//Bottom-Up appr0ach

class Solution
{
public:
    int CountSubset(int arr[], int n, int sum)
    {
        int DP[n + 1][sum + 1];

        for (int i = 0; i <= n; i++)
        {
            DP[i][0] = 1;
        }

        for (int i = 1; i <= sum; i++)
        {
            DP[0][i] = 0;
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= sum; j++)
            {
                if (arr[i - 1] <= j)
                {
                    DP[i][j] = DP[i - 1][j] + DP[i - 1][j - arr[i - 1]];
                }

                else
                {
                    DP[i][j] = DP[i - 1][j];
                }
            }
        }

        return DP[n][sum];
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, target;
        cin >> n >> target;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        Solution ob;
        if (int ans = ob.CountSubset(arr, n, target))
            cout << ans << "\n";
        else
            cout << "No\n";
    }
}