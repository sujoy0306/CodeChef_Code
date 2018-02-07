#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	ll t;
	cin>>t;
	while(t--){
		ll sum=0,a,n,ans=0;
		cin>>n;
		ll arr[4];
		memset(arr,0,sizeof(arr));
		for(ll i=0;i<n;i++){
			cin>>a;
			arr[a%4]++;
			sum+=(a);
		}
		if(sum%4!=0)
			cout<<-1<<endl;
		else{
			ans=min(arr[1],arr[3]);
			ll mxm=max(arr[1],arr[3]);
			mxm-=ans;
			ans+=arr[2]/2;
				
			if(arr[2]%2!=0){
				ans+=2;
				mxm-=2;
			}
			ans+=(mxm/4)*3;
			cout<<ans<<endl;
		}
				
				
	}
	return(0);
}
			
		
	
