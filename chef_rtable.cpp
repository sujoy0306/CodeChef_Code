#include<iostream>
#include<cstdlib>
#include<algorithm>
using namespace std;
long long int in,n,cycle;
long long int detect_cycle(long long int indx,long long int *a,long long int *b){
	
	if(b[indx]==0){
		if(cycle>100){
			return b[indx];
		}	
		int nxt_indx=indx+a[indx]+1;
		//cout<<indx+1<<" ";
		if(nxt_indx>n-1){
			cycle++;
			nxt_indx-=n;
		//	cout<<nxt_indx+1<<" ";
			if(nxt_indx==in){
				b[indx]=1;
				return b[indx];
			}
			if(b[nxt_indx]==1){
				return b[indx];
			}
		}
		b[indx]=detect_cycle(nxt_indx,a,b);
		//cout<<indx<<"	"<<b[indx]<<endl;
		return b[indx];
	}
	else
		return b[indx];
}
int main(){
	long long int t;
	cin>>t;
	while(t--){
		long long int *a,*b,i,nxt_indx,count=0;
		cin>>n;
		a=(long long int*)malloc(n*sizeof(long long int));
		b=(long long int*)malloc(n*sizeof(long long int));
		//c=(long long int*)malloc(n*sizeof(long long int));
		for(i=0;i<n;i++){	
			cin>>a[i];
			b[i]=0;
			//c[i]=0;
		}
		for(i=0;i<n;i++){
			in=i;
			cycle=0;
			nxt_indx=detect_cycle(i,a,b);
		//	cout<<"\n"<<"nxt"<<endl;
		}
		for(i=0;i<n;i++){
			if(b[i]==1)
				count++;
		//	cout<<b[i]<<"	";
		}
		cout<<count<<endl;
	}
	return(0);
}
			
