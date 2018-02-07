#include<iostream>
#include<cstdlib>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		long int n,i,*a,avg,min=6,max=0,s=0;
		cin>>n;
		a=(long int*)malloc(n*sizeof(long int));
		for(i=0;i<n;i++){
			cin>>a[i];
			s+=a[i];
			if(min>a[i])
				min=a[i];
			if(max<a[i])
				max=a[i];
		}
		avg=s/n;
		if(max==5 && min>2 && avg>=4)
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
	return(0);
}
	
	
