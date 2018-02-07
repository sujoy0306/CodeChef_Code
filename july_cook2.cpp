#include<iostream>
using namespace std;
int s(long long int n){
	int r,s=0;
	while(n){
		r=n%10;
		s+=r;
		n/=10;
	}
	return s;
}
int main(){
	long long int n,i,count=0,range;
	cin>>n;
	range=n-110;//since max of s(x)=9*10=90 and max of s(s(x))=9*2=18,so range can be started from n-108.....
	if(range<0)
		range=0;
	for(i=range;i<n;i++){
		if (i+s(i)+s(s(i))==n){
			//cout<<i<<endl;
			count++;
		}
	}
	cout<<count<<endl;
	return(0);
}
