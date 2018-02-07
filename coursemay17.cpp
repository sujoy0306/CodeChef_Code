#include<bits/stdc++.h>
using namespace std;
int main(){
	std::ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int arr[n],maxm=0,c=0;
		for(int i=0;i<n;i++){
			cin>>arr[i];
			maxm=max(maxm,arr[i]);
		}
		for(int i=0;i<n;i++){
			if(arr[i]==maxm)
				c++;
		}
		cout<<c<<endl;
	}
	return(0);
}
	
