#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
typedef long long ll;
void input(ll *arr,ll n){
	for(ll i=0;i<n;i++){
		cin>>arr[i];
	}
}
void c_sum(ll *a,ll *cum,ll n){
	for(ll i=0;i<n;i++){
		if(i==0){
			cum[i]=a[i];
		//	cum[i]%=mod;
		}
		else{
			cum[i]=cum[i-1]+a[i];
	//		cum[i]%=mod;
		}
	}
}
int main(){
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	ll p,q,r,i,j,k;
	while(t--){
		cin>>p>>q>>r;
		ll a[p],b[q],c[r],cum_a[p],cum_c[r];
		input(a,p);
		input(b,q);
		input(c,r);
		sort(a,a+p);
		sort(b,b+q);
		sort(c,c+r);
		c_sum(a,cum_a,p);
		c_sum(c,cum_c,r);
		j=p-1;
		k=r-1;
		ll sum=0,val;
		for(i=q-1;i>=0;i--){
			
			while((b[i]<a[j] || b[i]<c[k]) && j>=0 && k>=0){
				if(b[i]<a[j])
					j--;
				if(b[i]<c[k])
					k--;
			}
			//cout<<j<<"  "<<k<<endl;
			
			if(j<0 || k<0){
				val=0;
				break;
			}
			else{
		//	if(b[i]>=a[j] || b[i]>=c[k])
				val=((((cum_a[j]+(j+1)*b[i])%mod)*((cum_c[k]+(k+1)*b[i])%mod))%mod);
			}
		//	cout<<a[j]<<"  "<<b[i]<<"  "<<c[k]<<endl;
			val%=mod;
			sum+=val;
			//sum%=mod;
		}
		cout<<sum%mod<<endl;
	}
	return(0);
}
