#include<iostream>
#include<cstdlib>
#include<algorithm>
using namespace std;
int main(){
	long int n,j,i,*a,sum=0,max1;
	cin>>n;
	a=(long int*)malloc(n*sizeof(long int));
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	for(i=0;i<n-1;i++){
		max1=a[i];
		for(j=i+1;j<n;j++){
			max1=max(max1,a[j]);
			long int p=a[i]&a[j];
			if(p==a[i] || p==a[j]){
				sum+=max1;
			//	cout<<sum<<"	";
			}
		}
	}
	cout<<sum<<endl;
	return(0);
		
}
