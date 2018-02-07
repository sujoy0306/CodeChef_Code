#include<bits/stdc++.h>
#define ll long long
using namespace std;
int dp[150][150][150],n,arr[150];
int mod=1e9+7;
int find_ans(int pos,ll fi,ll sec){
	if(pos>=n && fi==0 && sec==0)
		return 1;
	if(dp[pos][fi][sec]!=-1)
		return dp[pos][fi][sec];
	ll range=min(fi,sec)+1;
	ll ans=0;
	for(int i=0;i<range;i++){
		ans+=find_ans(pos+1,sec-i,arr[pos+2]+i)%mod;
	}
	dp[pos][fi][sec]=ans%mod;
	return dp[pos][fi][sec];
}
int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		memset(arr,0,sizeof(arr));
		memset(dp,-1,sizeof(dp));
		for(int i=0;i<n;i++)cin>>arr[i];
		cout<<find_ans(0,arr[0],arr[1])%mod<<endl;
	}
	return(0);
}
		
