#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<stack>
#define ll long long
using namespace std;
vector<ll>vr[100005];
void dfs(ll a,ll n){
	stack<ll> s;
	s.push(a);
	bool visit[n];
	memset(visit,0,sizeof(visit));
	while(!s.empty()){
		//cout<<s.top()<<" ";
		ll u=s.top();
	//	visit[u]=true;
		s.pop();
		//if(!visit[u]){
			visit[u]=true;
			for(auto j: vr[u]){
				if(!visit[j])
					s.push(j);
			}
			
		//}
	}
}
		
int main(){
	ll city,road;
	cin>>city>>road;
	
	ll vtx[city];
	memset(vtx,0,sizeof(vtx));
	for(ll i=0;i<road;i++){
		ll u,v;
		cin>>u>>v;
		vr[u].push_back(v);
		vr[v].push_back(u);
		vtx[u]++;
		vtx[v]++;
	}
	int fl=0;
	for(ll i=0;i<city;i++){
		if(vtx[i]%2)
			fl=1;
	}
	if(fl)
		cout<<"NO"<<endl;
	else{
		cout<<"YES"<<endl;
		dfs(1,city);
	}
	return(0);
}
