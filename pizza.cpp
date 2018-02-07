#include<bits/stdc++.h>
#include<cstdio>
#define mp make_pair
#define pb push_back
#define sc second
#define fi first
#define ll long long
using namespace std;

int main(){
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	ll t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int pizz[n],pet[n];
		int maxm=INT_MIN;
		for(int i=0;i<n;i++){
			cin>>pizz[i];
			pizz[i]=2*pizz[i];
			maxm=max(maxm,pizz[i]);
		}
		for(int i=0;i<n;i++){
			cin>>pet[i];
		}
	//	cout<<maxm<<endl;
		int dp[n+1][maxm+1];
		memset(dp,0,sizeof(dp));
		for(int i=0;i<=maxm;i++)
			dp[0][i]=1000;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=maxm;j++){
				if(j>=pet[i-1]){
					dp[i][j]=min(dp[i-1][j],dp[i][j-pet[i-1]]+1);
					dp[i][j]=min(dp[i][j],dp[i-1][j-pet[i-1]]+1);
				}
				else
					dp[i][j]=dp[i-1][j];
					
		//		cout<<dp[i][j]<<" ";
			}
		//	cout<<endl;
		}
		int ans=0;
		for(int i=0;i<n;i++){
			ans+=dp[n][pizz[i]];
		}
		cout<<ans<<endl;
	}
	return(0);
}
