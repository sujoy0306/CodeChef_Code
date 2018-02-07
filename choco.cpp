#include<bits/stdc++.h>
#include<cstdio>
#define mod 4294967295
#define mp make_pair
#define pb push_back
#define sc second
#define fi first
#define ll long long
#define loop(i,a,b)for(int i=a;i<b;i++)
using namespace std;
const ll N = 1000100;
bool byX(const pair<int,int> &a, const pair<int,int> &b)
{
	return a.first < b.first;
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
	cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
		int n,k,s;
		int arr[20],i;
		for(i=0;i<20;i++){
			arr[i]=i;
		}
		
		cin>>n>>k>>s;
		ll res=(k*s);
		int d=res/n;
		//int r=;
		if(res%n>0)
			d++;
		if(k>n)
			cout<<-1<<endl;
		else if(d<=6)
			cout<<d<<endl;
		else{
			if(((n-k)*6)>=k)
	            cout<<d<<endl;
	        else
	            cout<<-1<<endl;
	   }
	}
	return(0);
}


