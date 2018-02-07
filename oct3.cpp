#include<bits/stdc++.h>
#include<cstdio>
#define mod 4294967295
#define numb 10000000010
#define mp make_pair
#define pb push_back
#define sc second
#define fi first
#define ll long long
using namespace std;
const ll N = 10000000010;
bool byX(const pair<int,int> &a, const pair<int,int> &b)
{
	return a.first < b.first;
}
int min(int a,int b)
{
    return a<b?a:b;
}
int max(int a,int b){
	return a>b?a:b;
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
	int t;
	//scanint(t);
	cin>>t;
	while(t--){
		ll y;
		cin>>y;
		ll count=0;
		//ll b=min(y-1,700);
		for(int i=1;i<701;i++){
			ll b=y-i;
			if(b>=0){
				ll ans=sqrt(b);
				if(ans*ans+i<=y)
					count+=ans;
			}
		}
		cout<<count<<endl;
	}	
	return(0);
}


