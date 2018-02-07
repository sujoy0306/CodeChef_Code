#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
long int maxSubArraySum(vector<long int>& a, int size)
{
    int max_so_far = 0, max_ending_here = 0;
 
    for (int i = 0; i < size; i++)
    {
        max_ending_here = max_ending_here + a[i];
        if (max_ending_here < 0)
            max_ending_here = 0;
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;
    }
    return max_so_far;
}
int main(){
	long int t;
	cin>>t;
	while(t--){
		long int n,i,strt,end,s_rev=0,s_frwd=0,val,size1=0,size2=0,res1,res2;
		scanf("%ld",&n);
		vector<long int>c,c_frwd,c_rev;
		for(i=1;i<=n;i++){
			scanf("%ld",&val);
			c.push_back(val);
		}
		scanf("%ld %ld",&strt,&end);
		for(i=strt-1;i<end-1;i++){
			val=c[i];
			s_frwd+=val;
			c_frwd.push_back(val);
			size1++;
		}
		i=strt-2;
		if(i<0)
			i=n-1;		//traverse start to end rev direction
		while(i!=end-2){
			if(i<0){
				i=n-1;
			}
			val=c[i];
			s_rev+=val;
			c_rev.push_back(val);
			size2++;
			i--;
		}
		//cout<<s_frwd<<" "<<s_rev<<endl;
		//cout<<size1<<" "<<size2<<endl;
		long int max1,max2;
		max1=maxSubArraySum(c_frwd,size1);
		max2=maxSubArraySum(c_rev,size2);
		res1=2*(s_frwd-max1);
		res1+=s_rev;
		res2=2*(s_rev-max2);
		res2+=s_frwd;
		printf("%ld\n",min(res1,res2));
		//cout<<res1<<" "<<res2<<endl;
	}	
	return(0);
}		
