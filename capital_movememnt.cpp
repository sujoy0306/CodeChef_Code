#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<climits>
#include<utility>
#define ll long long
using namespace std;
bool Cap[50005];
struct sort_pred {
    bool operator()(const std::pair<ll,int> &left, const std::pair<int,int> &right) {
        return left.first > right.first;
    }
};

int main(){
	std::ios::sync_with_stdio(false);
	int t;
//	cout<<"D";
	cin>>t;
	while(t--){
	//	cout<<"C";
		int n,i,k,fl=0;
		cin>>n;
		memset(Cap,true,sizeof(Cap));
		vector<pair<ll,int> >ppltn;
		for(i=0;i<n;i++){
			ll pop;
			cin>>pop;
			ppltn.push_back(make_pair(pop,i));	
		}
		std::sort(ppltn.begin(), ppltn.end(), sort_pred());
		vector<int>c[n];
		for(i=0;i<n-1;i++){
			int u,v;
			cin>>v>>u;
			c[v-1].push_back(u-1);
			c[u-1].push_back(v-1);
		//	cout<<"W";
		}
		for(i=0;i<n;i++){		
			for(k=0;k<n;k++){
			    fl=0;
				if(ppltn[k].second==i)
					fl=1;
				for(auto j: c[i]){
					if(ppltn[k].second==j){
						fl=1;
			//			cout<<"A";
						break;
					}
				}
				if(fl==0){
					cout<<ppltn[k].second+1<<" ";
					break;
				}
				
			}
			if(fl==1)
			    cout<<0<<" ";
			fl=0;
		}
		cout<<endl;
	}
	return(0);
}
