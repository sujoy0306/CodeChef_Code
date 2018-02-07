#include<iostream>
#include<algorithm>
using namespace std;
int main(){
		std::ios::sync_with_stdio(false);
		int t;
		cin>>t;
		while(t--){
			long long d;
			cin>>d;
			cout<<d%9+1<<endl;
		}
		return(0);
	}
