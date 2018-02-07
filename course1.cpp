#include<bits/stdc++.h>
using namespace std;
int main() {
	std::ios::sync_with_stdio(false);
	int test_case,n,val;
	cin>>test_case;
	while(test_case--) {
		cin>>n;
		int maxm=0;
		for(int j=0;j<n;j++) {
			cin>>val;
			maxm=max(val,maxm);
		}
		cout<<n-maxm<<endl;
	}
	return 0;
}
