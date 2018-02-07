#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	int n;
	while(t--){
		cin>>n;
		ll arr[n],maxm=0,in,count=0,dif=0;
		for(int i=0;i<n;i++){
			cin>>arr[i];
			if(arr[i]>maxm){
				maxm=arr[i];
				in=i;
			}	
		}
		for(int i=in-1;i>=0;i--){
			dif=arr[i+1]-arr[i];
			
			if(dif==0)dif+=2;
			dif--;
			count+=dif;
		}
		for(int i=in;i<n-1;i++){
			dif=arr[i]-arr[i+1];
			if(dif==0)dif+=2;
			dif--;
			count+=dif;
		}
		cout<<count<<endl;
	}
	return(0);
}
	





