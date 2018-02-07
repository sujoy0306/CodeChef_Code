#include<bits/stdc++.h>
#include<cstdio>
#define mod 4294967295
#define mp make_pair
#define pb push_back
#define sc second
#define fi first
#define ll long long
using namespace std;
bool byX(const pair<int,int> &a, const pair<int,int> &b)
{
	return a.first < b.first;
}
void print(ll n){
	for(int i=0;i<42949;i++){
		cout<<100000<<" ";
	}
	n-=42949;
	for(int i=0;i<n;i++){
		cout<<1<<" ";
	}
	cout<<endl;
}
int main(){
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		print(n);
		
	}
	return(0);
}
