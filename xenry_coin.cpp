#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	ll u,v,z,ans;
	while(t--){
		cin>>u>>v;
		z=u+v;
		ans=(z*(z+1))/2;
		ans+=(1+u);
		cout<<ans<<endl;
	}
	return(0);
}
	





