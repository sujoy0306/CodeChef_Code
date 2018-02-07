#include<iostream>
#include<algorithm>
#include<vector>
#define pb push_back
#define ll long long
using namespace std;
vector<ll >val;
bool count(ll P,ll N){
	ll i;
	sort(val.begin(),val.end());
	for(i=0;i<N;i++)
		if(P<val[i])
			break;
	}
	ll indx=i-1;
	
int main(){
	ll N,L,R,i,c=0;
	cin>>N>>L>>R;
	for(i=0;i<N;i++){
		ll u;
		val.pb(u);
	}
	for(i=L;i<=R;i++){
		bool st=count(i,N);
		if(st)
			c++;
	}
	cout<<c<<endl;
	return(0);
}
