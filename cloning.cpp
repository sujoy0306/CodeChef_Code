#include<bits/stdc++.h>
#define limit 1000002
using namespace std;
typedef long long ll;

int main(){
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	int n,q,a,b,c,d;
	while(t--){
		cin>>n>>q;
		int arr[n];
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}
		while(q--){
			cin>>a>>b>>c>>d;
			int count=0;
			vector<int >srt,fin;
			for(int j=a-1;j<b;j++){
				srt.push_back(arr[j]);
			}
			sort(srt.begin(),srt.end());
			for(int j=c-1;j<d;j++){
				fin.push_back(arr[j]);
				//cout<<"final  "<<fin[j]<<endl;
			}
			sort(fin.begin(),fin.end());
			for(unsigned int j=0;j<srt.size();j++){
			//	cout<<srt[j]<<"  "<<fin[j]<<endl;
				if(srt[j]!=fin[j])
					count++;
			}
			if(count>1)
				cout<<"NO"<<endl;
			else
				cout<<"YES"<<endl;
	}
}
	return(0);
}
