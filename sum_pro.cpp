#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	ll n,val;
	while(t--){
		cin>>n;
		vector<ll> v;
		ll sum=0,tot=0,pro=0;
		for(ll i=0;i<n;i++){
			cin>>val;
			v.push_back(val);
		}
		for(ll i=0;i<n;i++){
			for(ll j=i+1;j<n;j++){
				pro=v[i]*v[j];
				sum=v[i]+v[j];
				tot+=pro;
				tot+=sum;
			}	
		}
		cout<<tot<<endl;
	}
	return(0);
}
	





