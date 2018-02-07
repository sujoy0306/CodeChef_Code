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
int m,n;
int lcs(vector<char> x,vector<char> y){
	vector<int>arr[m+1];
	for(int i=0;i<=m;i++){
		arr[i].resize(n+1);
		for(int j=0;j<=n;j++){
			if(i==0 or j==0)
				arr[i][j]=0;
			else if(x[i-1]==y[j-1])
				arr[i][j]=arr[i-1][j-1]+1;
			else
				arr[i][j]=max(arr[i-1][j],arr[i][j-1]);
		}
	}
	return arr[m][n];
}

int main(){
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
    ll t;
    cin>>t;
    string x,y;
    
    while(t--){
		cin>>m>>n;
		cin>>x>>y;
		vector<char> s1,s2;
		for( int i=0;i<m-1;i++){
			if(x[i]!=x[i+1])
				s1.pb(x[i]);
		}
		s1.pb(x[m-1]);
		for( int i=0;i<n-1;i++){
			if(y[i]!=y[i+1])
				s2.pb(y[i]);
		}
		s2.pb(y[n-1]);
		m=s1.size();
		n=s2.size();
		cout<<m+n-lcs(s1,s2)<<endl;
	}
	return(0);
}


