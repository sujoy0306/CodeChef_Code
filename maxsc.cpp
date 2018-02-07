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
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<ll> arr[n];
		for(int i=0;i<n;i++){
			arr[i].resize(n);
			for(int j=0;j<n;j++){
				cin>>arr[i][j];
			}
			sort(arr[i].begin(),arr[i].end());
		}
		ll sum=arr[n-1][n-1],last=arr[n-1][n-1];
		bool fl=false;
		for(int i=n-2;i>=0;i--){
			fl=false;
			for(int j=n-1;j>=0;j--){
				if(arr[i][j]<last){
					fl=true;
					last=arr[i][j];
					sum+=last;
					break;
				}
			}
			if(!fl)
				break;
		}
		if(fl)
			cout<<sum<<endl;
		else if(n==1)
			cout<<arr[0][0]<<endl;
		else
			cout<<-1<<endl;		
	}
	return(0);
}
