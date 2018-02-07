#include<bits/stdc++.h>
#include<cstdio>
#define mod 4294967295
#define mp make_pair
#define pb push_back
#define sc second
#define fi first
#define ll long long
using namespace std;
const int N = 62;
const int g=10002;
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
ll dp[N][g];
int arr[62];;
ll find_ans(int i,int cg,int n){
	if(i==n)
		return cg==1;
	if(dp[i][cg]!=-1)return dp[i][cg];
	dp[i][cg]=find_ans(i+1,cg,n)+find_ans(i+1,__gcd(cg,arr[i]),n);
	return dp[i][cg];
}
int main(){
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t,n;
	scanint(t);
	while(t--){
			memset(dp,-1,sizeof(dp));
			scanint(n);
			for(int i=0;i<n;i++)scanint(arr[i]);
			ll ans=0;
			for(int i=0;i<n;i++)ans+=find_ans(i+1,arr[i],n);
			cout<<ans<<endl;
		
	}	
	return(0);
}


