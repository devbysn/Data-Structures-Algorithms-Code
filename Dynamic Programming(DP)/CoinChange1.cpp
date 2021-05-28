#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long

/* class solution
{

public:
    ll count(int S[], int m, int n)
    {
        //code here.

        if (n == 0)
            return 1;
        if (m <= 0)
            return 0;

        if (S[m - 1] <= n)
        {
            return count(S, m - 1, n) + count(S, m, n - S[m - 1]);
        }

        else
            return count(S, m - 1, n);
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int size_of_array, target;
        cin >> size_of_array >> target;
        int arr[size_of_array];
        for (int i = 0; i < size_of_array; i++)
        {
            cin >> arr[i];
        }

        solution ob;
        cout << "Ways of collectiong chiller of the given amount : " << ob.count(arr, size_of_array, target) << endl;
    }
    return 0;
} */

class solution
{

public:
    ll count(int S[], int m, int n)
    {
        //code here.
        ll DP[m + 1][n + 1];

        for (int i = 0; i <= m; i++)
        {
            DP[i][0] = 1;
        }

        for (int i = 1; i <= n; i++)
        {
            DP[0][i] = 0;
        }

        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (S[i - 1] <= j)
                {
                    DP[i][j] = DP[i - 1][j] + DP[i][j - S[i - 1]];
                }

                else
                {
                    DP[i][j] = DP[i - 1][j];
                }
                /* code */
            }
        }

        return DP[m][n];
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int size_of_array, target;
        cin >> size_of_array >> target;
        int arr[size_of_array];
        for (int i = 0; i < size_of_array; i++)
        {
            cin >> arr[i];
        }

        solution ob;
        cout << "Ways of collectiong chiller of the given amount : " << ob.count(arr, size_of_array, target) << endl;
    }
    return 0;
}