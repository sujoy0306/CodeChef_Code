#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll mod_exp(ll y,ll p){
	ll x=10;
    ll res = 1;      // Initialize result
 
    x = x % p;  // Update x if it is more than or 
                // equal to p
 
    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;
 
        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;  
    }
   // cout<<res<<endl;
    return res;
}
ll length(ll tmp){
	ll c=0;
	while(tmp){
		tmp/=10;
		c++;
	}
	return c;
}
void binary(ll val,vector<ll > &v,ll m){
	list<ll > b;
	while(val){
		int r=val%2;
		b.push_back(r);
		val/=2;
	}
	ll res=0;
	int len=b.size();
	//cout<<"Len"<<len<<endl;
	list<ll>::iterator it=b.begin();
	for(int i=0;i<len;i++){
		res+=(*it*v[i]);
	//	cout<<*it<<"  "<<v[i]<<endl;
		it++;
	}
	cout<<res%m<<endl;
}
int main(){
	std::ios::sync_with_stdio(false);
	int t;
	cin>>t;
	ll a,n,m;
	while(t--){
		cin>>a>>n>>m;
		ll res=a;
		ll cnt=n;
		vector<ll> v;
		v.push_back(res);
		ll len=length(a);
		while(cnt>1){
			res=(((res%m)*mod_exp(len,m))+res)%m;
			v.push_back(res);
			cnt--;
			len+=len;
		}
		//ll len=length(a)*pow(2,n-1);
		if(len==n*length(a))
			cout<<res<<endl;
		else
			binary(n*length(a),v,m);
	}
	return(0);
}
