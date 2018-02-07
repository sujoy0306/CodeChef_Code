#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#define ll long long
using namespace std;

int main(){
	ll tc;
	scanf("%lld",&tc);
	while(tc--){
		ll n,m,j;
		scanf("%lld %lld",&n,&m); 
		ll a[n],i;
		for(i=0;i<n;i++)
			scanf("%lld",&a[i]);
			
		ll c_sum[n];
		c_sum[0]=a[0];
		for(i=1;i<n;i++){
			c_sum[i]=c_sum[i-1]+a[i];
		//	cout<<c_sum[i-1]<<" ";
		}
		//cout<<c_sum[n-1]<<endl;
		vector<ll > b;	
		for(i=0;i<m;i++){
			int vl;
			scanf("%lld",&vl);
			b.push_back(vl);
		}
		reverse(b.begin(),b.end());
		for(i=0;i<n-v+1;i++){
			
				
				
		printf("%lld\n",sum);
	}
	return(0);
}
			
