#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int pr[100005];
int max(int a,int b){
	if(a>b)
		return a;
	else
		return b;
}
    int least_prime_div(long int val) {
    		long int i;
    		if(val==1){
    			return 1;
    		}
    		if(val%2==0){
    			return 2;
    		}
		long int sqroot=sqrt(val);
    		for(i=3;i<=sqroot;i+=2){
    			if(val%i==0){
    				return i;
    			}
    		}
    		return val;
    }
int main(){
	int test_case;
	scanf("%d",&test_case);
	memset(pr,0,sizeof(pr));
	while(test_case--){
		int size,i,query,lft,rght;
		scanf("%d %d",&size,&query);
		 int *arr;
		arr=(int*)malloc(size*sizeof(int));
		for(i=0;i<size;i++){
			scanf("%d",&arr[i]);
		}
		int type;
		while(query--){
			scanf("%d %d %d",&type,&lft,&rght);
			if(type==0){
				for(i=lft-1;i<rght;i++){
					if(arr[i]!=1)
						arr[i]=arr[i]/(least_prime_div(arr[i]));
					//cout<<arr[i]<<endl;
				}
			}
			else{
				int res=1;
				for(i=lft-1;i<rght;i++){
					//cout<<res<<endl;
					//cout<<arr[i]<<" ";
					if(arr[i]!=1)
						res=max(res,least_prime_div(arr[i]));
				}
				printf("%d ",res);
			}
		}
		printf("\n");
	}
	return(0);
}
