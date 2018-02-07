#include<bits/stdc++.h>
#include<cstdio>
#define mod 4294967295
#define mp make_pair
#define pb push_back
#define sc second
#define fi first
#define ll long long
using namespace std;
const ll N = 1000100;
bool byX(const pair<int,int> &a, const pair<int,int> &b)
{
	return a.first < b.first;
}

void find_ans(vector<int> arr[],vector<ll> dp,vector<ll> temp,int n){
	for(int i=0;i<n-1;i++){
		int sz=arr[i].size();
		if(i==0)
			for(int j=0;j<sz;j++)dp[j]=0;
			
		int sz1=arr[i+1].size();
		for(int j=0;j<sz1;j++){
			ll val=arr[i+1][j],res=0;
			for(int k=0;k<sz;k++){
				res=max(res,dp[k]+abs(val-arr[i][k])*(i+1));
			}
			temp[j]=res;
		}
		for(int j=0;j<sz1;j++){
			dp[(j-1+sz1)%sz1]=temp[j];
		}
	}
	ll res=0;
	int sz1=arr[n-1].size();
	for(int i=0;i<sz1;i++){
		res=max(res,dp[i]);
	}
	cout<<res<<endl;		
}
int main(){
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n,a,m;
		cin>>n;
		vector<int> arr[n];
		for(int i=0;i<n;i++){
			cin>>m;
			for(int j=0;j<m;j++){
				cin>>a;
				arr[i].push_back(a);
			}
		}
		if(n==2){
			int maxm1=0,maxm2=0,minm1=1000006,minm2=1000006;
			int sz=arr[0].size();
			for(int i=0;i<sz;i++){
				maxm1=max(arr[0][i],maxm1);
				minm1=min(minm1,arr[0][i]);
			}
			 sz=arr[1].size();
			for(int i=0;i<sz;i++){
				maxm2=max(arr[1][i],maxm2);
				minm2=min(minm2,arr[1][i]);
			}
			cout<<max(maxm1-minm2,maxm2-minm1)<<endl;
		}
		else{
			vector<ll> dp(N+1),tmp(N+1);
			find_ans(arr,dp,tmp,n);
		}
		
	}	
	return(0);
}


