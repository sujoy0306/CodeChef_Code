#include<iostream>
#include<algorithm>
#include<cmath>
#define ll long long
using namespace std;
void factor(ll n){
	for(ll i=1;i<=sqrt(n);i++){
		if(n%i==0){
			if(i*i!=n){
				
			
int main(){
	std::ios::sync_with_stdio(false);
	ll t,n;
	cin>>t;
	while(t--){
		cin>>n;
		factor(n);
