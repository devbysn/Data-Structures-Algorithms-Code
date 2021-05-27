#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ff              first
#define ss              second
#define ll             long long
#define pb              push_back
#define vi              vector<ll>
#define mii             map<ll,ll>


class Solution{
public:

    int subset(int arr[], int n, int sum){
        if(n==0)return 0;
        if(sum==0)return 1;
        
        if(arr[n-1]<=sum){
            return subset(arr, n-1, sum) || subset(arr, n-1, sum-arr[n-1]);
        }
        
        else{
            return subset(arr, n-1, sum);
        }
    }
    int equalPartition(int n, int arr[])
    {
        // code here
        int sum=0;
        for(int i=0; i<n; i++)
            sum+=arr[i];
        
        if(sum%2!=0)return 0;
        else return subset(arr, n, sum/2);
        
        
    }
};



int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int arr[n];
		for(int i=0; i<n; i++){
			cin>>arr[i];
		}
		
		Solution ob;
		if(ob.equalPartition(n, arr))
			cout<<"Yes\n";
		else 
			cout<<"No\n";
	}
}
