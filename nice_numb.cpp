#include<bits/stdc++.h>
using namespace std;
int main(){
	int test_case;
	cin>>test_case;
	while(test_case--){
		long long n,i;
		cin>>n;
		long long a[n],sum=0,minm=1e9+5,maxm=INT_MIN;
		for(i=0;i<n;i++){
			cin>>a[i];
			sum+=a[i];
			minm=min(minm,a[i]);
			maxm=max(maxm,a[i]);
		}
		long long sum1=minm*(n-1)+((n-1)*(n-2))/2;
		if(minm+(n-2)==maxm)
			cout<<sum-sum1<<endl;
		else{
			int f=0;
			for(i=0;i<n;i++){
				if(minm+1==a[i]){
					f=1;
					break;
				}
			}
			if(f==0)
				cout<<minm<<endl;
			else
				cout<<maxm<<endl;
		}
	}
	return(0);
}
