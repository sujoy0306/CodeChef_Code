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
		ll n,q;
		scanint(n);
		scanint(q);
		vector<ll> arr(n),l(n),r(n);
		for(ll i=0;i<n;i++){
			scanint(arr[i]);
			//arr.pb(v);
		}
		l[0]=arr[0];
		for(ll i=1;i<n;i++){
			l[i]=__gcd(l[i-1],arr[i]);
		}
		r[n-1]=arr[n-1];
		for(ll i=n-2;i>=0;i--){
			r[i]=__gcd(r[i+1],arr[i]);
		}
		ll left,right;
		while(q--){
			scanint(left);
			scanint(right);
			left--;right--;
			ll ans;
			if(left==0)
				ans=r[right+1];
			else if(right==n-1)
				ans=l[left-1];
			else
				ans=__gcd(l[left-1],r[right+1]);
			cout<<ans<<endl;
		}
	}
	return(0);
}



