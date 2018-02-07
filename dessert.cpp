#include<bits/stdc++.h>
#include<cstdio>
#define mp make_pair
#define pb push_back
#define sc second
#define fi first
#define ll long long
using namespace std;
/*ll find_max(ll *arr,int n){
	ll curr=arr[0];
	ll maxm=arr[0];
	for(int i=1;i<n;i++){
		curr=max(curr+arr[i],arr[i]);
		maxm=max(maxm,curr);
	}
	return maxm;
}
ll find_min(ll *arr,int n){
	ll curr=arr[0];
	ll minm=arr[0];
	for(int i=1;i<n;i++){
		curr=min(curr+arr[i],arr[i]);
		minm=min(minm,curr);
	}
	return minm;
}*/
int main(){
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	ll t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		ll arr[n];
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}
		ll lmax[n],lmin[n],rmax[n],rmin[n];
		lmax[0]=lmin[0]=arr[0];
		ll curr1=arr[0],curr2=arr[0];
		ll maxm=arr[0],minm=arr[0];
		for(int i=1;i<n;i++){
			curr1=max(curr1+arr[i],arr[i]);
			curr2=min(curr2+arr[i],arr[i]);
			maxm=max(maxm,curr1);
			minm=min(minm,curr2);
			lmax[i]=maxm;
			lmin[i]=minm;
		}
		rmax[n-1]=rmin[n-1]=arr[n-1];
		 curr1=curr2=arr[n-1];
		 maxm=minm=arr[n-1];
		for(int i=n-2;i>=0;i--){
			curr1=max(curr1+arr[i],arr[i]);
			curr2=min(curr2+arr[i],arr[i]);
			maxm=max(maxm,curr1);
			minm=min(minm,curr2);
			rmax[i]=maxm;
			rmin[i]=minm;
		}
		ll ans=INT_MIN;
		for(int i=0;i<n-1;i++){
			ans=max(ans,abs(rmax[i+1]-lmin[i]));
			ans=max(ans,abs(lmax[i]-rmin[i+1]));
		}
		cout<<ans<<endl;
	}
	return(0);
}
