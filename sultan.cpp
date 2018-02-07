#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		long long int m,i,f,a[1005],b[1005],count_m=0,count_f=0,ans=0;
		cin>>m>>f;
		for(i=0;i<n;i++){
			cin>>a[i];
			b[i]=0;
			if(a[i]%m==0){
				count_m++;
				b[i]=1;
			}
			if((a[i]%f==0) && (b[i]==0))
				count_f++;
			if (a[i]%f==0)||(a[i]%m==0)
				ans++;
		}
		for(i=0;i<n;i++){
			 
		}
		int prcntg=(100*(ans))/n;
		//cout<<prcntg<<endl;
		//cout<<count_m<<" "<<count_f<<endl;
		if(prcntg>=70){
			cout<<"Yes"<<endl;
			if(count_m>count_f)
				cout<<"Multan"<<endl;
			else if(count_m<count_f)
				cout<<"Fultan"<<endl;
			else
				cout<<"Both"<<endl;
		}
		else{
			cout<<"No"<<endl;
		}
	}
	return(0);
}
