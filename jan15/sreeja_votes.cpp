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
bool byX(const pair<int,int> &a, const pair<int,int> &b)
{
	return a.first < b.first;
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
		ll n,v,sum=0,c=0;
		scanint(n);
		//vector<ll> a;
		for(ll i=0;i<n;i++){
			scanint(v);
			if(v>0)
				c++;
			sum+=v;
		}
		if(100<=sum and 100>sum-c)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;	
	}
	return(0);
}



