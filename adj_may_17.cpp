#include<bits/stdc++.h>
using namespace std;
int main(){
	std::ios::sync_with_stdio(false);
	int tc;
	cin>>tc;
	while(tc--){
		int n;
		cin>>n;
		int a[2*n];
		for(int i=0;i<2*n;i++){
			cin>>a[i];
		}
		sort(a,a+2*n);
		cout<<a[(3*n)/2]<<endl;
		int in1=n-1,in2=n;
		for(int i=0;i<n;i++){
			cout<<a[in1]<<" "<<a[in2]<<" ";
			in1--;
			in2++;
		}
		cout<<endl;
	}
	return(0);
}
