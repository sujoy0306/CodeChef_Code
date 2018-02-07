#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int h=n/2,st;
		if(n%2==0)
			st=n-(h-1);
		else
			st=n-h;
		for(int i=0;i<n;i++){
			cout<<st++<<" ";
		}
		cout<<endl;
	}
	return(0);
}
