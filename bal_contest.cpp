#include<bits/stdc++.h>
#include<cstdio>
#define mp make_pair
#define pb push_back
#define sc second
#define fi first
#define ll long long
using namespace std;
bool byX(const pair<int,int> &a, const pair<int,int> &b)
{
	return a.first < b.first;
}
int main(){
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n;
		ll p;
		cin>>n>>p;
		ll solved;
		int h=0,c=0;
		for(int i=0;i<n;i++){
			cin>>solved;
			if(solved<=p/10)
				h++;
			else if(solved>=p/2)
				c++;
		}
		//cout<<h<<"  "<<c<<endl;
		if(h==2 && c==1)
			cout<<"yes"<<endl;
		else
			cout<<"no"<<endl;
	}
		
	return(0);
}
