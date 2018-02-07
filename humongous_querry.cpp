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

ll count(string s){
  ll c_1=0,c_0=0;
  ll n=s.length();
  for(ll i=0;i<n;i++){
	  if(s[i]=='1')
		c_1+=(1+c_0);
	  else
		c_0+=c_1;
	}
	return c_0;
}

int main(){
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    int t;
    cin>>t;
    ll x;
    string s;
    while(t--){
		vector<string> arr;
		cin>>s;
		cin>>x;
		if(count(s)==x){
			cout<<"YES"<<endl;
			cout<<0<<endl;
		}
		else{
			string s1=s;
			
			for(ll k=1;k<=
			if(arr.size()==0)
				cout<<"NO"<<endl;
			else{
				ll c=0,min_c=INT_MAX;
				for(unsigned ll i=0;i<arr.size();i++){
					c=0;
					for(unsigned ll j=0;j<s.size();j++){
						if(arr[i][j]!=s[j])
							c++;
					}
					min_c=min(min_c,c);
				}
				cout<<"YES"<<endl;
				cout<<min_c<<endl;
			}
		}
	}		
	return(0);
}


