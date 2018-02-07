#include<iostream>
#include<cstdlib>
#include<cmath>
using namespace std;
//long int pwr(long int x,long int n){
	
int main(){
	long long int n,*a,q,s,i;
	cin>>n;
	a=(long long int*)malloc((n+1)*sizeof(long long int));
	for(i=0;i<=n;i++){
		cin>>a[i];
	}
	cin>>q;
	while(q--){
		long long int key,trm;
		cin>>key;
		s=a[0];
		//s%=786433;
		for(i=1;i<=n;i++){
			trm=(a[i]*pow(key,i));
			//trm%=786433;
			s+=trm;
		}
		s%=786433;
		cout<<s<<endl;
	}
	return(0);
}
