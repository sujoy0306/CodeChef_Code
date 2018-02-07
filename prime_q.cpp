#include<bits/stdc++.h>
#define limit 1000002
using namespace std;
typedef long long ll;
bool mark[limit];
vector<ll >prime;
void simpleSieve(){
	ll count=0;
    memset(mark, true, sizeof(mark));
    for (ll p=2; p*p<limit; p++){
        if (mark[p] == true) {
            for (int i=p*2; i<limit; i+=p)
                mark[i] = false;
        }
    }
    for (int p=2; p<limit; p++){
        if (mark[p] == true){
            prime.push_back(p);
            count++;
        }
    }
    cout<<count<<endl;
}
int main(){
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	simpleSieve();
	ll n;
	cin>>n;
	ll arr[n];
	vector<unordered_map<int,int> >p_f;
	for(ll i=0;i<n;i++){
		cin>>arr[i];
		unordered_map<int,int> h;
		for(ll j=0;prime[j]<=arr[i];j++){
			if(arr[i]%prime[j]==0){
				int count=0;
				ll val=arr[i];
				while(val%prime[j]==0){
					val/=prime[j];
					count++;
				}
				h[prime[j]]=count;
			//	cout<<prime[j]<<"  "<<h[prime[j]]<<endl;
			}
		}
		p_f.push_back(h);
	}
/*	for (auto m: p_f) {
		for (auto n: m)
			cout << n.first<<"  " << n.second<< '\t';
		cout << "-\n";
	}*/
	ll q,l,r,x,y;
	cin>>q;
	while(q--){
		ll exponent=0;
		cin>>l>>r>>x>>y;
		l--;r--;
		auto l_b=lower_bound(prime.begin(),prime.end(),x);
		//cout<<"LOwer Bound  "<<*(l_b)<<endl;
		for(auto i=l_b;*i<=y;i++){
			for(int j=l;j<=r;j++){
				if(p_f[j].find(*i)!=p_f[j].end())
					exponent+=p_f[j][*i];
			}
		}
		cout<<exponent<<endl;
	}
	return(0);
}
	

		




