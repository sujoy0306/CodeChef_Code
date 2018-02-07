    #include<stdio.h>
    #include<stdlib.h>
    #include<math.h>
    #include<string.h>
    long int max(long int a,int b){
    	if((a-b)>0)
    		return a;
    	else
    		return b;
    }
    long int least_prime_div(long int val) {
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
    void update(long int *arr,long int l,long int r){
    	long int i;
    	for(i=l;i<=r;i++){
    		arr[i]=arr[i]/(least_prime_div(arr[i]));
    		//cout<<arr[i]<<endl;
    	}
    }
    void get(long int *arr,long int l,long int r){
    	long int res=1,i;
    	for(i=l;i<=r;i++){
    		//cout<<res<<endl;
    		//cout<<arr[i]<<" ";
    		res=max(res,least_prime_div(arr[i]));
    	}
    	printf("%ld ",res);
    }
    int main(){
    	int test_case;
    	scanf("%d",&test_case);
    	//memset(pr,0,sizeof(pr));
    	while(test_case--){
    		long int size,i,query,lft,rght;
    		scanf("%ld %ld",&size,&query);
    		long int *arr;
    		arr=(long int*)malloc(size*sizeof(long int));
    		for(i=0;i<size;i++){
    			scanf("%ld",&arr[i]);
    		}
    		int type;
    		while(query--){
    			scanf("%d %ld %ld",&type,&lft,&rght);
    			if(type==0)
    				update(arr,lft-1,rght-1);
    			else
    				get(arr,lft-1,rght-1);
    		}
    		printf("\n");
    	}
    	return(0);
    } 
