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
		int arr[n];
		for(ll i=0;i<n;i++)cin>>arr[i];
		bool f[20],visit[20];
		int ans[7];
		clr(f,false);
		clr(visit,false);
		if(n==2){
			f[arr[0]]=true;
			f[arr[1]]=true;
			if(f[5]==true && f[6]==true){
				ans[1]=4;
				ans[2]=5;
				ans[3]=6;
				ans[4]=1;
				ans[5]=2;
				ans[6]=3;
			}
			else{
			for(int i=1;i<=6;i++){
				for(int j=i+1;j<=6;j++){
					if(i!=j){
						if(f[i] && f[j]){}
						else{
							if(!visit[i] && !visit[j]){
							ans[i]=j;
							ans[j]=i;
							visit[i]=true;
							visit[j]=true;
							break;
							}
						}
					}
				}
			}
		}
		}
		else{	ans[1]=4;
			ans[2]=5;
			ans[3]=6;
			ans[4]=1;
			ans[5]=2;
			ans[6]=3;}
			for(int i=1;i<=6;i++){
				cout<<ans[i]<<" ";
			}
			cout<<endl;		
							
	}		
	return(0);
}
