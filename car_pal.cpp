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
	cout.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
		ll n;
		cin>>n;
		vector<ll> arr(n);
		ll t1=0;
		for(ll i=0;i<n;i++){
			cin>>arr[i];
			t1=max(t1,arr[i]);
		}
		ll c,d,s;
		cin>>c>>d>>s;
		double t2;
		t2=(c-1)*t1;
		
		cout<<setprecision(9)<<fixed<<t2<<endl;
	}
	return(0);
}


