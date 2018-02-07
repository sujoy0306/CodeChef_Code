#include<iostream>
#include<cstdlib>
#include<algorithm>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		long int n,m;
		cin>>n>>m;
		if((m*n)%2==0)	
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
	return(0);
}
