#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>	
#define ll long long 
using namespace std;
int main(){
	int n,m,i;
	scanf("%d %d",&n,&m);
	ll a[n];
	ll freq[n];
	memset(a,0,sizeof(a));
	for(i=0;i<n;i++){
		scanf("%lld",&a[i]);
	}
	
	for(i=0;i<n;i++){
		if(i>0){
			if(a[i-1]==a[i])
				freq[i]=freq[i-1]+1;
			else
				freq[i]=1;
		}
		else
			freq[i]=1;
			
		//cout<<freq[i]<<" ";
	}
//	cout<<endl;
	ll l,r,k;
	for(i=0;i<m;i++){
		scanf("%lld %lld %lld",&l,&r,&k);
		l--;
		r--;
		
		ll mid=(r-l+1)/2;
		ll v=freq[l+mid];
		v--;
		ll in=l+mid-v;
		if(in<l)
			in=l;
	//	cout<<"Index "<<in+1<<"  Frequency "<<freq[in]<<endl;
	//	cout<<"con  "<<freq[in+k-1]<<endl;
	
		if(in+k-1<=r && freq[in+k-1]>=k)
			printf("%lld\n",a[mid+l]);
		else
			printf("-1\n");
	}
	return(0);
}
	
