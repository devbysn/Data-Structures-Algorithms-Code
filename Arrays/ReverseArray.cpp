#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ff              first
#define ss              second
#define ll             long long
#define pb              push_back
#define vi              vector<ll>
#define mii             map<ll,ll>

/*

// Iterative approach

void reverse(int [], int);
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
		reverse(arr, n);
		
		for(int i=0; i<n; i++){
			cout<<arr[i]<<"\t";
		}
	}
}

void reverse(int arr[], int n){
	int low=0, hi=n-1;
	while(low<hi){
		int temp = arr[low];
		arr[low]=arr[hi];
		arr[hi]=temp;
		low++;
		hi--;
	}
}

*/


//Recursive approach

void reverse(int [], int, int);

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
		int start=0, end=n-1;
		reverse(arr, start, end);
		
		for(int i=0; i<n; i++){
			cout<<arr[i]<<"\t";
		}
	}
}


void reverse(int arr[], int start, int end){
	if (start >= end)
    return;
     
    int temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;
     
    reverse(arr, start + 1, end - 1);
}
