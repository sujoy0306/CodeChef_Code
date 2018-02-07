#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
	long int t;
	cin>>t;
	while(t--){
		long int n,i,strt,end,s_frwd=0,s_rev=0,sum=0,val;
		scanf("%ld",&n);
		vector<long int>cost;
		for(i=0;i<n;i++){
			scanf("%ld",&val);//cost of the road
			cost.push_back(val);
		}
		scanf("%ld %ld",&strt,&end);
		for(i=strt-1;i<end-1;i++){		//traverse start to end in forward direction
			s_frwd+=cost[i];
		}
		i=strt-2;
		if(i<0)
			i=n-1;		//traverse start to end rev direction
		while(i!=end-2){
			if(i<0){
				i=n-1;
			}
			s_rev+=cost[i];
			i--;
		}
		cout<<s_frwd<<" "<<s_rev<<endl;
		i=strt-1;			
		sum=0;
		while(i!=end-2){		//then traverse strt to end in forward dir 
			sum+=cost[i];
			if(cost[i]<0){		//if i find any neg number
				if(sum<0){
					s_rev+=(2*sum);	//added twice with rev sum
					sum=0;
				//	cout<<"S_rd="<<s_rd<<endl;
				}
			}
			i++;
		}
		i=strt-2;
		sum=0;
		while(i!=end-2){		//similar to above one
			if(i<0){
				i=n-1;
			}
			if(i!=end-2){
				sum+=cost[i];
				if(cost[i]<0){
					if(sum<0){
						s_frwd+=(2*sum);
						sum=0;
					//	cout<<"S_d="<<s_d<<endl;
					}
				}
			}
			i--;
			if(i<0){
				i=n-1;
			}
		}
		cout<<s_frwd<<" "<<s_rev<<endl;
		printf("%ld\n",min(s_frwd,s_rev));//result = minimum of this two	
	}
	return(0);
}
