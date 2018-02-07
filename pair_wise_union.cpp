#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
unordered_map<int,int> h;
int main(){
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	int n,k,len,val;
	
	while(t--){
		cin>>n>>k;
		int count=0;
		vector<int > v[n];
		for(int i=0;i<n;i++){
			cin>>len;
			//vector<int >val(len);
			for(int j=0;j<len;j++){
				cin>>val;
				v[i].emplace_back(val);
			}
		}
		
		int repeat=0;
		for(int i=0;i<n;i++){
			for(unsigned int in=0;in<v[i].size();in++)
				h[v[i][in]]=v[i][in];
			for(int j=i+1;j<n;j++){
				for(unsigned int in=0;in<v[j].size();in++){
					if(h.find(v[j][in])==h.end()){}
					else{
						repeat++;
					}
				}
				if(v[i].size()+v[j].size()-repeat==k)
					count++;
				repeat=0;
			}
			h.clear();
		}
		cout<<count<<endl;
	}
	return(0);
}
