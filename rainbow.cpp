#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int arr[n];
		for(int i=0;i<n;i++)
			cin>>arr[i];
		int l=0,r=n-1;
		bool fl=true;
		while(l<r){
			if(arr[l]!=arr[r]){
				fl=false;
				break;
			}
			l++;
			r--;
		}
		if(arr[l]!=7)
			fl=false;
		if(fl)
			cout<<"yes"<<endl;
		else
			cout<<"no"<<endl;
	}
	return(0);
}
