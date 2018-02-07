#include<iostream>
#include<algortihm>
#include<vector>
#include<list>
#include<cstdlib>
#include<climts>
#define ll long long
using namespace std;
int main(){
	std::ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){	
		ll n,i;
		cin>>n;
		ll a[n];
		for(i=0;i<n;i++){
			cin>>a[i];
		if(n==2)
			cout<<min(a[0],a[1])<<endl;
		if(n==3){
			sort(a,a+n);
			cout<<a[0]<<endl;
		}
		if(n>3){
			sort(a,a+n);
			ll d=a[1]-a[0];
			for(i=
	
