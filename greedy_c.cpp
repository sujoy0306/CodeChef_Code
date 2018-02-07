#include<bits/stdc++.h>
#define lli long long
using namespace std;
int main(){
	std::ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		lli v1,v2;
		vector<lli> min_sal,offr_sal,job_offer;
		vector<bool> com(m,false);
		for(int i=0;i<n;i++){
			cin>>v1;
			min_sal.push_back(v1);
		}
		for(int i=0;i<m;i++){
			cin>>v1>>v2;
			offr_sal.push_back(v1);
			job_offer.push_back(v2);
		}
		vector<string> q;
		string s;
		for(int i=0;i<n;i++){
			cin>>s;
			q.push_back(s);
		}
		lli placed=0,sal=0,no_req=0;
		for(int i=0;i<n;i++){
			lli max=0;
			int in=-1;
			for(int j=0;j<m;j++){
				if(q[i][j]=='1' && job_offer[j]>0 && min_sal[i]<offr_sal[j] && max<offr_sal[j]){
					max=offr_sal[j];
					in=j;
				}
			}
			if(in!=-1){
				placed++;
				sal+=max;
				job_offer[in]--;
				com[in]=true;
			}
		}
		for(int i=0;i<m;i++){
			if(com[i]==false)
				no_req++;
		}
		cout<<placed<<" "<<sal<<" "<<no_req<<endl;
	}
	return(0);
}
		
