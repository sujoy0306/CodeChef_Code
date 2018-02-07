#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	if(n%(m+1)!=0)
		cout<<"1st candidate"<<endl;
	else
		cout<<"2nd candidate"<<endl;
	return(0);
}
