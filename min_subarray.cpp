#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	ll t,n,d;
	cin>>t;
	while(t--){
		cin>>n>>d;
		ll a,pr[n+1];
		pr[0]=0;
		for(ll i=1;i<=n;i++){
			cin>>a;
			pr[i]=pr[i-1]+a;
		}
		priority_queue<pair<ll,ll>,vector<pair<ll,ll> >,greater<pair<ll,ll> > >p;
		p.push(make_pair(pr[0],0));
		ll length=n+2;
		for(ll i=1;i<=n;i++){
			while(!p.empty() && pr[i]-p.top().first>=d){
				length=min(length,i-p.top().second);p.pop();
			}
			p.push(make_pair(pr[i],i));
		}
		if(length==n+2)
			cout<<-1<<endl;
		else
			cout<<length<<endl;
	}
	return(0);
}
			
		
	
