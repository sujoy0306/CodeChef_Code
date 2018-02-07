#include<bits/stdc++.h>
#include<cstdio>
#define mod 4294967295
#define mp make_pair
#define pb push_back
#define sc second
#define fi first
#define ll long long
using namespace std;
const int N = 62;
const int g=10002;
bool desc(const pair<int,int> &a, const pair<int,int> &b)
{
	return abs(a.first-a.second) > abs(b.first-b.second);
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
	int t=1;
	//scanint(t);
	while(t--){
		int n,a,x,y;
		scanint(n);scanint(x);scanint(y);
		vector<pair<int,int> >arr(n);
		for(int i=0;i<n;i++){
			scanint(a);
			arr[i].first=a;
		}
		for(int i=0;i<n;i++){
			scanint(a);
			arr[i].second=a;
		}
		sort(arr.begin(),arr.end(),desc);
		int tot=0,b=0;
		a=0;
		for(int i=0;i<n;i++){
			if(arr[i].first>arr[i].second){
				if(a+1<=x){
					a++;
					tot+=arr[i].first;
				}
				else{
					b++;
					tot+=arr[i].second;
				}
			}
			else{
				if(b+1<=y){
					b++;
					tot+=arr[i].second;
				}
				else{
					a++;
					tot+=arr[i].first;
				}
			}
		}
		cout<<tot<<endl;
	}	
	return(0);
}


