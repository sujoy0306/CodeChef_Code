#include<iostream>
#include<cstdlib>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		long long int n,i,crdnt[100005],dis[100005],s=0;
		cin>>n;
		char s[100009];
		cin>>s;
		for(i=0;i<n;i++){
			cin>>crdnt[i];
		}
		for(i=0;i<n-1;i++){
			dis[i]=crdnt[i+1]-crdnt[i];
		}
		for(i=0;i<n;i++){
			if(s[i]==1
