#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int arr[26];
		for(int i=0;i<26;i++)
			cin>>arr[i];
		bool visit[26];
		memset(visit,false,sizeof(visit));
		string s;
		cin>>s;
		for(auto it: s){
			visit[it-'a']=true;
		}
		int ans=0;
		for(int i=0;i<26;i++){
			if(visit[i]==false)
				ans+=arr[i];
		}
		cout<<ans<<endl;
	}
	return(0);
}
