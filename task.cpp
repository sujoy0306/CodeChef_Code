#include<bits/stdc++.h>
using namespace std;
int main(){
	int test_case;
	cin>>test_case;
	while(test_case--){
		int n;
		cin>>n;
		int xn[n],yn[n],i;
		for(i=0;i<n;i++)cin>>xn[i];
		for(i=0;i<n;i++)cin>>yn[i];
		int sum1=0,sum2=0;
		for(i=0;i<n;i++){
			if(i%2==0)
				sum1+=xn[i];
			else
				sum1+=yn[i];
			
			if(i%2==0)
				sum2+=yn[i];
			else
				sum2+=xn[i];
		}
		cout<<min(sum1,sum2)<<endl;
	}
	return(0);
}
