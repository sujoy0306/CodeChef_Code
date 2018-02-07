#include<bits/stdc++.h>
#define lli long long
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		lli arr[n],avg=0;
		for(int i=0;i<n;i++){
			cin>>arr[i];
			avg+=arr[i];
		}
		avg/=n;
		lli v,count=0;;
		for(int i=0;i<n-d;i++){
			if(arr[i]>avg){
				v=arr[i]-avg;
				arr[i]=avg;
				arr[i+d]+=v;
				count+=v;
			}
			else if(arr[i]<avg){
				v=avg-arr[i];
				arr[i]=avg;
				arr[i+d]-=v;
				count+=v;
			}
		}
		bool fl=true;
		for(int i=0;i<n-1;i++){
			if(arr[i]!=arr[i+1]){
				fl=false;
				break;
			}
		}
		if(fl)
			cout<<count<<endl;
		else
			cout<<-1<<endl;
	}
	return(0);
}
		
