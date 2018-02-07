#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int tc;
	scanf("%d",&tc);
	while(tc--){
		int n,i,c_0=0,fl=1,in=-1;
		scanf("%d",&n);
		int s[100005];
		for(i=0;i<n;i++)
			cin>>s[i];
		for(i=0;i<n;i++){
			if(s[i]==0)
				c_0++;
			if(s[i]==0 && fl){
				in=i+1;
				fl=0;
			}
		}
		if(c_0==0)
			cout<<0<<endl;
		else{
			cout<<c_0*1000+(100*(n-in+1))<<endl;
		}
	}
	return(0);
}
