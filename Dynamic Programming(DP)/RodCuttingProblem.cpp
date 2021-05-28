#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long

//Recursive Solution

//Time Complexity of the above implementation is O(n^2)
/* 
class solution
{
public:
    int rodCut(int price[], int n)
    {
        // base case
        if (n == 0)
        {
            return 0;
        }

        int maxValue = INT_MIN;

        // one by one, partition the given rod of length `n` into two parts
        // of length (1, n-1), (2, n-2), (3, n-3), … ,(n-1, 1), (n, 0)
        // and take maximum
        for (int i = 1; i <= n; i++)
        {
            // rod of length `i` has a cost `price[i-1]`
            int cost = price[i - 1] + rodCut(price, n - i);

            if (cost > maxValue)
            {
                maxValue = cost;
            }
        }

        return maxValue;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        solution ob;
        cout << "Total Profit is : " << ob.rodCut(arr, n) << endl;
    }
    return 0;
} */

class solution
{
public:
    int rodCut(int price[], int n)
    {
        int T[n + 1];

        for (int i = 0; i <= n; i++)
        {
            T[i] = 0;
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= i; j++)
            {
                T[i] = max(T[i], price[j - 1] + T[i - j]);
            }
        }

        // `T[n]` stores the maximum profit achieved from a rod of length `n`
        return T[n];
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        solution ob;
        cout << "Total Profit is : " << ob.rodCut(arr, n) << endl;
    }
    return 0;
}