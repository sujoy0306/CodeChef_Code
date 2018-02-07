#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#include<stack>
#include<climits>
#define ll long long 
#define pb push_back
using namespace std;
int main(){
	std::ios::sync_with_stdio(false);
	int tc;
	cin>>tc;
	while(tc--){
		int n,st,dst,i;
		cin>>st>>dst;
		n=st*dst;
		int a[n];
		for(i=0;i<n;i++){
			cin>>a[i];
		}
		int add[n];
		int k=(dst/2)+1,sum=0,k1=(st/2);
		add[0]=0;
		for(i=0;i<n;i++){
			if(i>0)
				add[i]=a[i]+add[i-1];
			else
				add[i]=a[i];
		//	cout<<add[i]<<" ";
		}
		//cout<<endl;
		//cout<<"INDEX  "<<in<<endl;
		int it,in,c_0=0,c_1=0,counter=0;
		for(in=0;in<dst;in++){
			c_0=0;
			c_1=0;
			counter=0;
			it=in;
			//cout<<"itarator "<<it<<endl;
			while(1){
				sum=0;
				if((it+dst-1)<n){
					sum=add[it+dst-1]-add[it-1];
					it+=dst;
				}
				else{
					sum=add[n-1]+add[in-1]-add[it-1];
				}
			//	cout<<"SUM  "<<sum<<endl;
				if(sum>=k)
					c_1++;
				else
					c_0++;			
			//	cout<<"\n0s   "<<c_0<<"  1s   "<<c_1<<endl;	
				//it%=n;
				counter+=dst;
				//cout<<"Counter "<<counter<<endl;
				if(counter==n || c_1>k1 || c_0>k1){
					//cout<<"C"<<endl;
					break;
				}
			}
			if(c_1>k1){
				cout<<1<<endl;
				break;
			}
		}
		if(c_0>k1){
			cout<<0<<endl;
		}
	}
	return(0);
}
