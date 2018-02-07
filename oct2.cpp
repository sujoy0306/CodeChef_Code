#include<bits/stdc++.h>
#include<cstdio>
#define mod 4294967295
#define mp make_pair
#define pb push_back
#define sc second
#define fi first
#define ll long long
using namespace std;
const ll N = 1000100;
bool byX(const pair<int,int> &a, const pair<int,int> &b)
{
	return a.first < b.first;
}
int min(int a,int b)
{
    return a<b?a:b;
}
int max(int a,int b){
	return a>b?a:b;
}
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
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	scanint(t);
	while(t--){
		int n,k;
		scanint(n);scanint(k);
		int arr[n];
		for(int i=0;i<n;i++)scanint(arr[i]);
		sort(arr,arr+n);
		int in=n/2;
		k/=2;
		cout<<arr[in+k]<<endl;
		
	}	
	return(0);
}


