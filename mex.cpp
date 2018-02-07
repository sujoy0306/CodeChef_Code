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
		int n,k;
		cin>>n>>k;
		int a;
		unordered_map<int,int> map1;
		for(int i=0;i<n;i++){
			cin>>a;
			map1[a]=0;
		}
		int i;
		n+=k;
		for(i=0;i<n;i++){
			if(map1.find(i)==map1.end()){
				if(k==0)
					break;
				else
					k--;
			}
		}
		cout<<i<<endl;
	}
	return(0);
}
