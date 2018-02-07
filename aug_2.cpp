#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<cstring>
using namespace std;
long long int n,i,c=0;
long long int detect_cycle(long long int indx,long long int *a,long long int *b,long long int in){
if(b[indx]!=2){	
	if (b[indx] ==1 && in!=-2){
		c++;
		in=indx;
		b[indx]=2;
		return in;
		}
	if(b[indx]==0){
		long long int nxt_indx=indx+a[indx]+1;
		b[indx]=1;
		//cout<<indx+1<<" ";
		if(nxt_indx>n-1){
			nxt_indx%=n;
		//	cout<<nxt_indx+1<<" ";
		}
		//cout<<"Index="<<indx<<endl;				
		in=detect_cycle(nxt_indx,a,b,in);
		//cout<<"in="<<in<<endl;
		//cout<<"Index="<<indx<<endl;
		//cout<<"count="<<c<<endl;
	}
	if((in==indx && b[indx]!=2)){
		b[indx]=2;
		in=-2;
		//cout<<"B";
		return in;
	}
	if (b[indx]==1){
		if(in!=-2){	
			c++;
		//	cout<<"C"<<endl;
			b[indx]=2;
		}
		//cout<<"A"<<endl;
		b[indx]=2;
		return in;
	}
    }
	else{
		in=-2;
		return in;
	}
}
int main(){
	int t;
	cin>>t;
	while(t--){
		long long int *a,*b,i,nxt_indx,n1,in=-1;
		c=0;
		int fl=0;
		cin>>n;
		a=(long long int*)malloc(n*sizeof(long long int));
		b=(long long int*)malloc(n*sizeof(long long int));
		for(i=0;i<n;i++){	
			cin>>n1;
			//n1=n1%n;
			a[i]=n1;
			b[i]=0;
		}
		for(i=0;i<n;i++){
			in=-1;
			fl=detect_cycle(i,a,b,in);
		//	cout<<"\n"<<"nxt"<<endl;
		}
		cout<<c<<endl;
	}
	return(0);
}
