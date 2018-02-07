#include<bits/stdc++.h>
using namespace std;
inline void scanint(int &x)

{
    register  int c = getchar();

    x = 0;

    int neg = 0;

    for(;((c<48 || c>57) && c != '-');c = getchar());

    if(c=='-') {neg=1;c=getchar();}

    for(;c>47 && c<58;c = getchar()) {x = (x<<1) + (x<<3) + c - 48;}

    if(neg) x=-x;

}
int main(){
	int t;
	scanint(t);
	int n;
	while(t--){
		scanint(n);
		int arr[n];
		for(int i=0;i<n;i++)scanint(arr[i]);
		vector<pair<int,int> > dp(n);
		for(int i=0;i<n;i++){
			dp[i].first=0;
			dp[i].second=arr[i];
		}
		for(int i=1;i<n;i++){
			for(int j=0;j<i;j++){
				dp[j].second=__gcd(dp[i].second,dp[j].second);
				if(__gcd(arr[i],arr[j])==1 && dp[j].second==1){
					if(j==0)
						dp[i].first+=(dp[j].first+1);
					else
						dp[i].first+=(dp[j].first+2);
				}
				else{
					if(dp[j].second==1)
						dp[i].first+=(dp[j].first+1);
					if(__gcd(arr[i],arr[j])==1 && j!=0)
						dp[i].first+=(dp[j].first+1);
					if(dp[j].second!=1 &&  __gcd(arr[i],arr[j])!=1)
						dp[i].first+=dp[j].first;
				}
			}
		}
		int sum=0;
		for(int i=0;i<n;i++){
			sum+=dp[i].first;
			cout<<dp[i].first<<" ";
		}
		cout<<endl;
		cout<<sum<<endl;
	}
	return(0);
}	
		
