#include<bits/stdc++.h>
using namespace std;
int main(){
	int tc;
	cin>>tc;
	while(tc--){
		int n,i,c_1=0,no;
		cin>>n;
		for(i=1;i<=n*n;i++){
			cin>>no;
			if(no==1)
				c_1++;
		}
		//int f=0;
		if(c_1<=n)
			cout<<0<<endl;
		else{
			c_1-=n;
			for(i=n-1;i>=1;i--){
				if(c_1<=2*i){
					cout<<n-i<<endl;
					break;
				}
				else{
					c_1-=(2*i);
				}
			}
		}
	}
	return(0);
}
		
