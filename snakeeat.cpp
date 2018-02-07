#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define sc second
#define fi first
#define ll long long
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
	int t;
	scanint(t);
	while(t--){
		vector<int> v;
		int a,n,q;
		scanint(n);scanint(q);
		for(int i=0;i<n;i++){
			scanint(a);
			v.pb(a);
		}
		sort(v.begin(),v.end());
		for(int i=0;i<q;i++){
			scanint(a);
			auto low=lower_bound (v.begin(), v.end(),a);
			int in=low-v.begin();
			int ans=n-in;
			int sz=in-1;
			while(v[in-1]+sz>=a && sz>=0){
				ans++;
				sz-=(a-v[in-1]);
				in--;
			}
			printf("%d\n",ans);
		}
	}
	return(0);
}
				
