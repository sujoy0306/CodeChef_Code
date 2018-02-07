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
bool sec(const pair<int,int> &a, const pair<int,int> &b)
{
	return a.second < b.second;
}
inline void scanint(ll &x)

{
    register  ll c = getchar();

    x = 0;

    ll neg = 0;

    for(;((c<48 || c>57) && c != '-');c = getchar());

    if(c=='-') {neg=1;c=getchar();}

    for(;c>47 && c<58;c = getchar()) {x = (x<<1) + (x<<3) + c - 48;}

    if(neg) x=-x;

}

int main(){
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    ll t;
    scanint(t);
    while(t--){
		ll n,k;
		scanint(n);
		scanint(k);
		ll arr[k];
		for(ll i=0;i<k;i++)
			scanint(arr[i]);
			
		sort(arr,arr+k);
		ll temp=0,sum=0;
		bool fl=false;
		for(ll i=0;i<k;i++){
			if(arr[i]==1){
				fl=true;
				cout<<"Chef"<<endl;
				break;
			}
			else if(arr[i]==2){
				fl=true;
				cout<<"Mom"<<endl;
				break;
			}
			sum+=(((arr[i]-1)*arr[i])/2-(temp*(temp+1))/2);
			if(arr[i]>sum){
				fl=true;
				if(arr[i]&1)
					cout<<"Chef"<<endl;
				else
					cout<<"Mom"<<endl;
					
				break;
			}
			else
				temp=arr[i];
		}
		if(!fl){
			sum+=(((n+1)*n)/2-(temp*(temp+1))/2);
			if((sum+1)&1)
				cout<<"Chef"<<endl;
			else
				cout<<"Mom"<<endl;
					
		}
	}
	return(0);
}



