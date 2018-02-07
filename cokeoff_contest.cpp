#include<bits/stdc++.h>
#define vi vector<int> 
#define ll long long
#define clr(x,v) memset( x, v, sizeof(x) )
#define F first
#define S second
#define PB push_back
using namespace std;
int main(){
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	ll t;
	//scanf("%lld",&t);
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		string s[n];
		for(ll i=0;i<n;i++)cin>>s[i];
		
		bool arr[5];
		//memset(arr,false,sizeof(arr));
		for(int i=0;i<5;i++)
			arr[i]=false;
		for(ll i=0;i<n;i++){
			if(s[i]=="cakewalk")
				arr[0]=true;
			else if(s[i]=="simple")
				arr[1]=true;
			else if(s[i]=="easy")
				arr[2]=true;
			else if(s[i]=="easy-medium" || s[i]=="medium")
				arr[3]=true;
			else if(s[i]=="medium-hard" || s[i]=="hard")
				arr[4]=true;
		}
		
		if(arr[0]&&arr[1]&&arr[2]&&arr[3]&&arr[4])
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
	return 0;
}
			

