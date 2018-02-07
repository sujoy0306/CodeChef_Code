#include<iostream>
using namespace std;
struct spd{
	int d,t;
};
int main(){
	std::ios_base::sync_with_stdio(false);
	int tc;
	cin>>tc;
	while(tc--){
		int n,k;
		cin>>n>>k;
		spd sp[n];
		for(int i=0;i<n;i++){
			cin>>sp[i].t>>sp[i].d;
		}
		int cost=0;
		for(int i=0;i<n;i++){
			if(sp[i].t<k){
				k-=sp[i].t;
			}
			else{
				int tm=sp[i].t-k;
				cost+=(tm*sp[i].d);
				k=0;
			}
		}
		cout<<cost<<endl;
	}
	return(0);
}
