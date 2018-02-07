#include<bits/stdc++.h>
using namespace std;

int main(){
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n,m,u,v,single;
		cin>>n>>m;
		for(int i=0;i<m;i++){
			cin>>u>>v;
		}
		single=n-m*2;
		if(single%2==0)
			cout<<"yes"<<endl;
		else
			cout<<"no"<<endl;
	}
	return(0);
}
	




