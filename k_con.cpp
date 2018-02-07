#include<bits/stdc++.h>
#include<cstdio>
#define mod 4294967295
#define mp make_pair
#define pb push_back
#define sc second
#define fi first
#define ll long long
using namespace std;
ll kadane(vector<ll > arr){
	int n=arr.size();
	ll cur=arr[0],max_so_far=arr[0];
	for(int i=1;i<n;i++){
		cur=max(cur+arr[i],arr[i]);
		max_so_far=max(max_so_far,cur);
	}
	return max_so_far;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		ll n,k;
		cin>>n>>k;
		vector<ll > arr;
		for(int i=0;i<n;i++){
			ll v;
			cin>>v;
			arr.pb(v);
		}
		if(k==1)
			cout<<kadane(arr)<<endl;
		else{
			ll sum=0;
			for(int i=0;i<n;i++){
				arr.pb(arr[i]);
				sum+=arr[i];
			}
			ll ans=kadane(arr);
			if(sum>0)
				ans+=((k-2)*sum);
			cout<<ans<<endl;
		}
	}
	return(0);
}
