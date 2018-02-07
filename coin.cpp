#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int g;
		cin>>g;
		while(g--){
			ll i,n,q;
			cin>>i>>n>>q;
			if(i==1){
				if(q==1)
					cout<<n/2<<endl;
				else
					cout<<((n%2)?(n/2)+1:(n/2))<<endl;
			}
			else{
				if(q==2)
					cout<<n/2<<endl;
				else
					cout<<((n%2)?(n/2)+1:(n/2))<<endl;
			}
		}
	}
	return(0);
}
