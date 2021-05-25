#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ff              first
#define ss              second
#define ll             long long
#define pb              push_back
#define vi              vector<ll>
#define mii             map<ll,ll>


// Recursive Solution
/*
bool isSubsetSum(ll arr[], ll n, ll sum){
	if(n==0)return false;
	if(sum==0)return true;
	
	if((arr[n-1])<=sum){
		return max(isSubsetSum(arr, n-1, sum), isSubsetSum(arr, n-1, sum-arr[n-1]));
	}
	else{
		return isSubsetSum(arr, n-1, sum);
	}
}

void solve(){
	ll arr[] = { 3, 34, 4, 12, 5, 2 };                   //here we can take values i'm hard coding values
    ll sum = 9;
    ll n = sizeof(arr) / sizeof(arr[0]);
    if (isSubsetSum(arr, n, sum) == true)
        cout<<("Found a subset with given sum")<<endl;
    else
        cout<<("No subarr with given sum")<<endl;
}


int main(){
	int t=1;                             //i'm hard coding values so no need to take iterations
	while(t--){
		solve();
	}
}

*/



// DP Bottom-Up Solution

/*
void solve()
{
	ll arr[] = {1, 5, 11, 5};
	ll sum=1;
	ll n = sizeof(arr)/sizeof(0);
    bool dp[n + 1][sum + 1];
 
    // If sum is 0, then answer is true
    for (int i = 0; i <= n; i++)
        dp[i][0] = true;
 
    // If sum is not 0 and set is empty,
    // then answer is false
    for (int i = 1; i <= sum; i++)
        dp[0][i] = false;
 
    // Fill the dp table in botton up manner
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (j < arr[i - 1])
                dp[i][j] = dp[i - 1][j];
            if (j >= arr[i - 1])
                dp[i][j] = dp[i - 1][j]
                               || dp[i - 1][j - arr[i - 1]];
        }
    }
 
    
 
    if(dp[n][sum]==true)cout<<"True"<<endl;
    else cout<<"False"<<endl;
}


int main(){
	ll t=1;                                          //i'm hard coding values so no need to take iterations
	while(t--){
		solve();
	}
}

*/


// Memoization or Top-Down aproach

#include <bits/stdc++.h>
using namespace std;
 
int tab[1000][1000];
 
int subset(int a[], int n, int sum)
{
     
    if (sum == 0)
        return 1;
         
    if (n <= 0)
        return 0;
   
    if (tab[n - 1][sum] != -1)
        return tab[n - 1][sum];
   
    if (a[n - 1] > sum)
        return tab[n - 1][sum] = subset(a, n - 1, sum);
    else
    {
        return tab[n - 1][sum] = subset(a, n - 1, sum) ||
                       subset(a, n - 1, sum - a[n - 1]);
    }
}
 
int main()
{
    memset(tab, -1, sizeof(tab));
    int n = 5;
    int arr[] = {1, 5, 3, 7, 4};
    int sum = 12;
 
    if (subset(arr, n, sum))
    {
        cout << "YES" << endl;
    }
    else
        cout << "NO" << endl;
   
}
