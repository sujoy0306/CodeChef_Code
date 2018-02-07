//Sujoy kansabanik
//ju cse 2nd year
#include<iostream>
#define ll long long
using namespace std;
//MODULAR EXPONNENTION
ll power_exp(ll base, ll exp)
{
	ll p=1e9+7;
    int res = 1;  
    base = base % p; 
    while (exp)
    {
        if (exp&1)
            res =(res*base)%p;
        exp = exp>>1;
        base = (base*base)%p;  
    }
    return res;
}
int main(){
	std::ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		ll numb,ans;
		cin>>numb;
		//ans=1<<(numb-1);
		ans=power_exp(2,numb-1);
		//ans=ans%(ll)(1e9+7);
		if(numb>1)
			cout<<ans-2<<endl;
		else
			cout<<0<<endl;
	}
	return(0);
}
