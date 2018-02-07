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
		string s;
		cin>>s;
		ll n=s.length();
		vector<ll>arr[26];
		for(ll i=0;i<n;i++){
			arr[s[i]-'a'].pb(i+1);
		}
		deque<ll> dq;
		if(n&1){
			int fl=0,in=-1;
			for(int i=0;i<26;i++){
				if(fl==1 and arr[i].size()&1){
					fl=2;
					cout<<-1<<endl;
					break;
				}
				if(arr[i].size()&1){
					in=i;
					fl=1;
				}
			}
			if(fl!=2){
				if(in!=-1){
					int l=arr[in].size();
					int j=0;
					while(j<l){
						dq.push_back(arr[in][j++]);
						if(j==l)
							break;
						dq.push_front(arr[in][j++]);
					}
					arr[in].clear();
				}
				for(int k=0;k<26;k++){
					if(arr[k].size()>0){
						int l=arr[k].size();
						int j=0;
						while(j<l){
							dq.push_back(arr[k][j++]);
							dq.push_front(arr[k][j++]);
						}
					}
				}
			}
		}
		else{
			int fl=0;;
			for(int i=0;i<26;i++){
				if(arr[i].size()&1){
					fl=1;
					cout<<-1<<endl;
					break;
				}	
			}
			if(fl==0){
			for(int k=0;k<26;k++){
				if(arr[k].size()>0){
					int l=arr[k].size();
					int j=0;
					while(j<l){
						dq.push_back(arr[k][j++]);
						dq.push_front(arr[k][j++]);
					}
				}
			}
			}
		}
		if(dq.size()>0){
			for(auto it: dq){
				cout<<it<<" ";
			}
			cout<<endl;
		}
	}

	return(0);
}


