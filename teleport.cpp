#include<bits/stdc++.h>
using namespace std;


int main(){
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	int tl,r,a,b;
	cin>>tl>>r;
	char c;
	vector<pair<int,int> >loc;
	for(int i=0;i<tl;i++){
		cin>>c>>a>>b;
		loc.push_back(make_pair(a,b));
		if(c=='+'){}
			
		else{
			if(abs(loc[a-1].first-loc[b-1].first)+abs(loc[a-1].second-loc[b-1].second)<=2*r)
				cout<<"DA"<<endl;
			else
				cout<<"NET"<<endl;
		}
	}
		
	return(0);
}
	



