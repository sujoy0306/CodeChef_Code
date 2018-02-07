#include<bits/stdc++.h>
#include<cstdio>
#define mod 4294967295
#define mp make_pair
#define pb push_back
#define sc second
#define fi first
#define ll long long
#define loop(i,a,b)for(int i=a;i<b;i++)
using namespace std;
inline void scanint(int &x)

{
    register  int c = getchar();

    x = 0;

    int neg = 0;

    for(;((c<48 || c>57) && c != '-');c = getchar());

    if(c=='-') {neg=1;c=getchar();}

    for(;c>47 && c<58;c = getchar()) {x = (x<<1) + (x<<3) + c - 48;}

    if(neg) x=-x;

}

int main(){
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
    ll n,q,a,b;
    cin>>n;
    vector<ll> arr(n);
    bool fl=false;
    for(ll i=0;i<n;i++){
		cin>>arr[i];
		if(arr[i]!=1)
			fl=true;
	}
	cin>>q;
	vector<pair<ll,ll> >shoot;
	for(ll i=0;i<q;i++){
		cin>>a>>b;
		shoot.pb(mp(a,b));
		if(b!=1)
			fl=true;
	}
	
	if(!fl){
		ll ans=n;
		vector<ll >h;
		for(ll i=0;i<n;i++)
			h.pb(i);
			
		for(ll i=0;i<q;i++){
			for(ll j=0;j<h.size();j++){
				if((shoot[i].first&h[j])==h[j]){
					ans--;
					h.erase(h.begin()+j);
					j--;
				}
			}
			cout<<ans<<endl;
		}
	}
	else{
		ll c=0;
		ll res1=n;
		for(ll i=0;i<q;i++){
			for(ll j=0;j<n;j++){
				if((j&shoot[i].first)==j and arr[j]>0){
					arr[j]-=shoot[i].second;
					if(arr[j]<=0)
						c++;
				}
			}
			res1-=c;
			cout<<res1<<endl;
			c=0;
		}
		
	}
	return(0);
}


