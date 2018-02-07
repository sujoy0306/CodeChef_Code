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
const ll N = 1000100;
bool sec(const pair<int,int> &a, const pair<int,int> &b)
{
	return a.second < b.second;
}
inline void scanint(ll &x)

{
    register  ll c = getchar();

    x = 0;

    ll neg = 0;

    for(;((c<48 || c>57) && c != '-');c = getchar());

    if(c=='-') {neg=1;c=getchar();}

    for(;c>47 && c<58;c = getchar()) {x = (x<<1) + (x<<3) + c - 48;}

    if(neg) x=-x;

}

int main(){
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    ll t;
    scanint(t);
    while(t--){
		vector<pair<ll,ll> >arr;
		ll n,a,b;
		scanint(n);
		for(ll i=0;i<n;i++){
			scanint(a);
			scanint(b);
			arr.pb(mp(a,b));
		}
		sort(arr.begin(),arr.end(),sec);
		ll j=1,i=0,c=0,ans=0;
		while(j<n){
			if(arr[i].second>=arr[j].first){
				j++;
				c++;
			}
			else{
				ans+=c;
				i=j;
				j++;
				c=0;
			}
		}
		ans+=c;
		cout<<n-ans<<endl;
	}
	return(0);
}



