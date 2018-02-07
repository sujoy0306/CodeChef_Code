#include<bits/stdc++.h>
#include<cstdio>
#define mod 4294967295
#define mp make_pair
#define pb push_back
#define sc second
#define fi first
#define ll long long
using namespace std;
int main(){
	int t,arr[4];
	cin>>t;
	while(t--){
		for(int i=0;i<4;i++)
			cin>>arr[i];
		
		sort(arr,arr+4);
		if(arr[0]!=arr[1] or arr[2]!=arr[3])
			cout<<"NO"<<endl;
		else
			cout<<"YES"<<endl;
	}
	return(0);
}
