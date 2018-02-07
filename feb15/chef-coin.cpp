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
   // scanint(t);
   cin>>t;
    while(t--){
		ll n;
		cin>>n;
		vector<ll> arr(n);
		for(ll i=0;i<n;i++){
			cin>>arr[i];
		}
		sort(arr.begin(),arr.end());
		ll freq=1,max_freq=1;
		for(ll i=1;i<n;i++){
			if(arr[i-1]!=arr[i]){
				max_freq=max(max_freq,freq);
				freq=1;
			}
			else
				freq++;
		}
		max_freq=max(max_freq,freq);
		cout<<n-max_freq<<endl;
	}
	return(0);
}



