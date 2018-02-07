#include<iostream>
#include<algorithm>
#include<climits>
#define ll long long
using namespace std;
ll gcd(ll a,ll b){
	while(a){
		ll t=a;
		a=b%a;
		b=t;
	}
	return b;
}
int main(){
	std::ios::sync_with_stdio(false);
	int test_case;
	cin>>test_case;
	while(test_case--){
		ll numb,i,j;
		ll arr[502],gcd1=-1;
		cin>>numb;
		for(i=0;i<numb;i++){
			cin>>arr[i];
		}
		for(i=0;i<numb-1;i++){
			for(j=i+1;j<numb;j++){
				ll a,b;
				if(arr[i]>arr[j]){
					a=arr[i];
					b=arr[j];
				}
				else{
					a=arr[j];
					b=arr[i];
				}
				ll g=(arr[j]*arr[i])/gcd(b,a);
				if(gcd1==-1)gcd1=g;
				else gcd1=min(gcd1,g);
			}	
		}
		cout<<gcd1<<endl;
	}
	return(0);
}
