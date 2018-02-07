#include<iostream>
#include <algorithm>
#include<cstdio>
#include<vector>
#include<cstring>
#include<climits>
#define ll long long
using namespace std;
ll dp[300][300],m;
ll min_move(ll c_sum[],ll l,ll r,ll a[]){
	return -(c_sum[r]+a[l]-c_sum[l]);
}

ll max_move(ll c_sum[],ll l,ll r,ll a[]){
	return (c_sum[r]+a[l]-c_sum[l]);
}

ll mini_max(ll c,ll l,ll r,ll b[],ll sum[],ll a[]){
	ll j,v=b[c];
	ll max1=0;
	ll l1,r1;
	if(dp[l][r]!=-1)
		return dp[l][r];
		
	//base case
	if(c==m-1){
		for(j=l;j<=r-v+1;j++){
				if((sum[j+v-1]+a[j]-sum[j])>max1){
					max1=(sum[j+v-1]+a[j]-sum[j]);
					l1=j;
					r1=j+v-1;
				}
		}
		//cout<<max1<<endl;
		
		if(c&1)
			return dp[l1][r1]=-max1;
		else
			return dp[l1][r1]=max1;
	}
	
	// other case....		
	ll minm=INT_MAX,maxm=0,sum1;
	for(j=l;j<=r-v+1;j++){
		if(c&1){
			sum1=mini_max(c+1,j+1,j+v-2,b,sum,a);
			minm=min(min_move(sum,j,j+v-1,a)+sum1,minm);
		}	
		else{
			sum1=mini_max(c+1,j+1,j+v-2,b,sum,a);
			//cout<<sum1<<endl;
			maxm=max(max_move(sum,j,j+v-1,a)+sum1,maxm);
		}
	}
	if(c&1)
		return dp[l][r]=minm;
	else
		return dp[l][r]=maxm;
	
}
int main(){
	ll tc;
	scanf("%lld",&tc);
	while(tc--){
		ll n;
		scanf("%lld %lld",&n,&m); 
		ll a[n],i,b[m];
		for(i=0;i<n;i++)
			scanf("%lld",&a[i]);
			
		ll c_sum[n];
		
		c_sum[0]=a[0];
		for(i=1;i<n;i++){
			c_sum[i]=c_sum[i-1]+a[i];
		//	cout<<c_sum[i-1]<<" ";
		}	
		for(i=0;i<m;i++)
			scanf("%lld",&b[i]);
		
		memset(dp,-1,sizeof(dp));
		for(i=0;i<n;i++)
			dp[i][i]=a[i];
		printf("%lld\n",mini_max(0,0,n-1,b,c_sum,a));
	}
	return(0);
}
			
