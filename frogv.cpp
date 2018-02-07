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
	int n,p,k,a,b;
	//cin>>n>>p>>k;
	scanf("%d %d %d",&n,&p,&k);
	vector<pair<int,int> >arr;
	for(int i=0;i<n;i++){
		scanf("%d",&a);
		arr.pb(mp(a,i));
	}
	sort(arr.begin(),arr.end(),byX);
	vector<int> max_dis(n+1,0);
	max_dis[arr[n-1].second]=arr[n-1].first+k;
	for(int i=n-2;i>=0;i--){
		if(arr[i+1].fi-arr[i].fi<=k)
			max_dis[arr[i].sc]=max_dis[arr[i+1].sc];
		else
			max_dis[arr[i].sc]=arr[i].fi+k;
	}
	for(int i=0;i<p;i++){
		//cin>>a>>b;
		scanf("%d %d",&a,&b);
		if(max_dis[a-1]==max_dis[b-1])
			printf("Yes\n");
		else
			printf("No\n");
	}
	return(0);
}
