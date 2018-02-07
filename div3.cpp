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
		ll k,d0,d1;
		cin>>k>>d0>>d1;
		ll in=2,sum=0;
		sum=d0+d1;
		bool fl=true;
		while(in<=k && sum%10!=2){
			ll ans=(sum%10);
			if(ans==0){
				fl=false;
				break;
			}
			sum+=ans;
			in++;
		}
		if(fl){
		ll ans=(k-in)/4;
		ll r=(k-in)%4;
		sum+=(ans*20);
		if(r==1)
			sum+=2;
		else if(r==2)
			sum+=6;
		else if(r==3)
			sum+=14;
		
		if(sum%3==0)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
	}
	return(0);
}


