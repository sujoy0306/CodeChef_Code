#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
typedef long long ll;
/*struct greater
{
    template<class T>
    bool operator()(T const &a, T const &b) const { return a > b; }
};*/
int main(){
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	//cout<<"K";
	while(t--){
	//	cout<<"B";
		ll n,sum=0,tot=0,in=1,v;
		cin>>n;
		vector<ll > dish;
		for(ll i=0;i<n;i++){
			cin>>v;
			dish.push_back(v);
		//	cout<<"A";
		}
		sort(dish.begin(),dish.end(),greater<ll>());
		sum=dish[0];
		for(ll i=1;i<n;i++){
			while((sum*in+dish[i])<=(sum+dish[i])*(in+1) && i<n){
				in++;
			//	cout<<"sum"<<sum<<endl;
				sum+=dish[i];
				i++;
			}
			tot+=sum*in;
		//	cout<<tot<<endl;
			sum=dish[i];
			in=1;
		}
		tot+=sum;
		cout<<tot<<endl;	
	}
	return(0);
}

