#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<stack>
#include<utility>
#include<queue>
#define ll long long

using namespace std;

int gcd(int a,int b){
	if(a<b){
		t=a;
		a=b;
		b=t;
	}
	while(b){
		t=a%b;
		a=b;
		b=t;
	}
	return a;
}
int main(){
	std::ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		string s;
		cin>>s;
		int dig,min_s,max_s;
		cin>>dig>>min_s>>max_s;
		int g[n];
		int gcd=s[0]-'0';
		for(int i=1;i<n;i++)
			int val=s[0]-'0';
			g[i]=val;
			gcd=gcd1(gcd,val);
		}
		for(i=1;i<n;i++){
			g[i]=max(
		
