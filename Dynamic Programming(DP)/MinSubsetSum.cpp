#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long


//Bottom-Up Approach

class Solution
{
public:
    int subset(int arr[], int n, int sum)
    {
    	bool DP[n+1][sum+1];
    	
    	for(int i=0; i<=n; i++){
    		DP[i][0]=true;
		}
		
		for(int i=0; i<=sum; i++){
    		DP[0][i]=true;
		}
		
    	for(int i=1; i<n; i++){
    		for(int j=1; j<=sum; j++){
    			if(arr[i]<=j){
    				DP[i][j] = DP[i-1][j] || DP[i-1][j-arr[i-1]];
				}
				else if(arr[i]>j){
					DP[i][j] = DP[i-1][j];
				}
			}
		}
		
		return DP[n][sum];
    }
    int equalPartition(int n, int arr[])
    {
        // code here
        int sum = 0;
        for (int i = 0; i < n; i++)
            sum += arr[i];

        if (sum % 2 != 0)
            return 0;
        else
            return subset(arr, n, sum / 2);
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

        Solution ob;
        if (ob.equalPartition(n, arr))
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}




