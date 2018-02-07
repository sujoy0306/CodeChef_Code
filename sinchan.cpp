#include<iostream>
#include<algorithm>
using namespace std;
int main(){
   ios::sync_with_stdio(false);
   int t;
    cin>>t;
    while(t--){
    	int n,l,b,a[2];
    	cin>>n;
    	cin>>a[0]>>a[1];
    	while((n--) && (a[0]*a[1]>0)){
    		sort(a,a+2);
    		a[1]-=a[0];
    	}
		//cout<<a[0]*a[1];
    	if(a[1]*a[0]>0){
    		cout<<"Yes "<<a[0]*a[1]<<endl;
	}
    	else{
    		cout<<"No"<<endl;
	}	
    }
    return(0);
} 
