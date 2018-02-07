#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;
long int *arr,pr[1000005],tree[1000005],size;
void prime_div(){
	memset(pr,0,sizeof(pr));
 	long int p,i;
	pr[1]=1;
	pr[0]=1;
    for (p=2; p<=1000002; p++) {
        if (pr[p] ==0){
            // Update all multiples of p
            for (i=p;i<=1000002;i+=p){
		if(pr[i]==0)
                	pr[i]=p;
	    }
        }
    }
}
void build_tree(long int l,long int h,long int pos){
	//cout<<"A";
	if(h==l){
		tree[pos]=pr[arr[l]];
	//	cout<<tree[pos]<<"		"<<pos<<endl;
		return;
	}
	long int m=ceil(l+(h-l)/2);
	build_tree(l,m,2*pos+1);
	build_tree(m+1,h,2*pos+2);
	tree[pos]=max(tree[2*pos+1],tree[2*pos+2]);
//	cout<<tree[pos]<<"		"<<pos<<endl;
}
long int r_query(long int ql,long int qh,long int pos,long int l,long int h){
	if(ql<=l && qh>=h){
	//	cout<<tree[pos]<<"		"<<pos<<endl;
		return tree[pos];
	}	
	if(ql>h || qh <l){
	//	cout<<"A"<<endl;
		return 1;	
	}
	long int m=(l+(h-l)/2);
	long int m1=r_query(ql,qh,l,m,2*pos+1);
	//cout<<m1<<endl;
	long int m2=r_query(ql,qh,m+1,h,2*pos+2);
	//cout<<m2<<endl;
	return(max(m1,m2));
}
void update_tree(long int node,long int l,long int h,long int ql,long int qh) {
     
    	if(l > h || l > qh || h < ql) // Current segment is not within range [i, j]
    		return;
     
      	if(l == h) { // Leaf node
      			arr[l] /= pr[arr[l]];
        		tree[node] = pr[arr[l]];
        		return;
    	}
     
    	update_tree(node*2+1, l, (l+h)/2, ql, qh); // Updating left child
    	update_tree(2+node*2, 1+(l+h)/2, h, ql, qh); // Updating right child
     
    	tree[node] = max(tree[node*2+2], tree[node*2+1]); // Updating root with max value
  }
int main(){
	 int test_case;
	scanf("%d",&test_case);
	prime_div();
	while(test_case--){
		long int i,query,lft,rght;
		scanf("%ld %ld",&size,&query);
		//long int *arr;
		arr=(long int*)malloc(size*sizeof(long int));
		for(i=0;i<size;i++){
			scanf("%ld",&arr[i]);
		}
		long int x = (int)(ceil(log2(size)));
		long int max_size = (int)pow(2, x) - 1;
		//max_size=7;
		memset(tree,0,sizeof(tree));
		build_tree(0,max_size,0);
		int type;
		//for(i=0;i<20;i++){
		//	cout<<tree[i]<<endl;
			//cout<<pr[i]<<endl;
		//}
			
		while(query--){
			scanf("%d %ld %ld",&type,&lft,&rght);
			long int res=1;
			if(type==0){
					update_tree(0,0,max_size,lft-1,rght-1);
					//for(i=0;i<15;i++){
					//	cout<<tree[i]<<endl;
						//cout<<pr[i]<<endl;
					//}
				}
				else{
						printf("%ld ",r_query(lft-1,rght-1,0,0,max_size));
				}
			}
			printf("\n");
		}
		return(0);	
	}
