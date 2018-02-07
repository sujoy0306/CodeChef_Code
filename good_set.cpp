#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	int n;
	while(t--){
		cin>>n;
		int v=1;
		for(int i=0;i<n;i++){
			cout<<v<<" ";
			v+=2;
		}
		cout<<endl;
	}
	return(0);
}
	





