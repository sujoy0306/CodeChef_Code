#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;
int main(){
	std::ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		ll c,d,l;
		cin>>c>>d>>l;
		l=l-4*d;
		if((l>=0) && (l<=4*c) && (l>=4*(c-2*d)) &&(l%4==0))
			cout<<"yes"<<endl;
		else
			cout<<"no"<<endl;
	}
	return(0);
}

