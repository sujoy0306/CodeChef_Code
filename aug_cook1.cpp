#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int main(){
	//vector<long int>heap1;
	long int t,n,a[100];
	scanf("%ld",&t);
	while(t--){
		scanf("%ld",&n);
		char p[4];
		cin>>p;
		for(long int i=0;i<n;i++){
			scanf("%ld",&a[i]);
		}
		if((n==1) && ((strcmp(p,"Dee"))==0) && (a[0]%2==0))
			cout<<"Dee"<<endl;
		else
			cout<<"Dum"<<endl;
	}
	return(0);
}
			
