#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct length{
	ll in,len;
}
int main(){
	ll n,p,k;
	scanf("%lld %lld %lld",&n,&k,&p);
	int arr[n];
	bool fl=false;
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
		if(!fl){
			if(arr[i]==0)
				in=i;
				fl=true;
			}
		}
			
	}
	string s;
	cin>>s;
	length l[n];
	ll counter=0,maxm=0,c=0,i_l=0,i_max,
	while(c<n){
		if(arr[in]==1){
			counter++;
		}
		else{
			l[i_l].len=counter;
			l[i_l].in=in;
			if(maxm<counter){
				maxm=counter;
				i_max=in;
			}
			i_l++;
			counter=0;
		}
		in++;
		in%=n;
		c++;
	}
	int m=0;
	for(i=0;i<n;i++){
		if(l[i].len>m && i!=i_max)
			m=i;
	}
	in=0;
	for(int i=0;i<p;i++){
		if(s[i]=='!')
			in++;
		else{
			if(in<=i_max || in>=i_max+maxm)
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
