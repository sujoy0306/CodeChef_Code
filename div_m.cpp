#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
long int pr[100005],arr[100005],size,tree[100005];

void prime_div(){
	memset(pr,0,sizeof(pr));
 	long int p,i;
	pr[1]=1;
    for (p=2; p<=100002; p++) {
        if (pr[p] ==0){
            // Update all multiples of p
            for (i=p;i<=100002;i+=p){
		if(pr[i]==0)
                	pr[i]=p;
	    }
        }
    }
}
void build_tree(long int l,long int h,long int pos){
	if(h==l){
		tree[pos]=pr[arr[l]];
		return;
	}
	long int m=l+(h-l)/2;
	build_tree(l,m,pos);
	build_tree(l,m+1,pos);
	tree[pos]=max(tree[2*pos+1],tree[2*pos+2]);
}
long int r_query(long int ql,long int qh,long int pos,long int l,long int h){
	if(ql<=l && qh>=h)
		return tree[pos];
	if(ql>h || qh <l)
		return 1;
	long int m=l+(h-l)/2;
	return(max(r_query(ql,qh,l,m,2*pos+1),r_query(ql,qh,m+1,h,2*pos+2)));
}
void update_tree(long int node,long int a,long int b,long int i,long int j,long int value) {
     
    	if(a > b || a > j || b < i) // Current segment is not within range [i, j]
    		return;
     
      	if(a == b) { // Leaf node
      			arr[a] /= pr[arr[a]];
        		tree[node] = pr[arr[a]];
        		return;
    	}
     
    	update_tree(node*2, a, (a+b)/2, i, j, value); // Updating left child
    	update_tree(1+node*2, 1+(a+b)/2, b, i, j, value); // Updating right child
     
    	tree[node] = max(tree[node*2], tree[node*2+1]); // Updating root with max value
  }
int main(){
	 int test_case;
	scanf("%d",&test_case);
	prime_div();
	while(test_case--){
		long int i,query,lft,rght;
		scanf("%ld %ld",&size,&query);
		//long int *arr;
		//arr=(long int*)malloc(size*sizeof(long int));
		for(i=0;i<size;i++){
			scanf("%ld",&arr[i]);
		}
		build_tree(0,size-1,0);
		int type;
		while(query--){
			scanf("%d %ld %ld",&type,&lft,&rght);
			long int res=1;
			switch(type){
				case 0:update_tree(0,0,size-1,lft-1,rght-1,0);
					break;
				case 1:printf("%ld ",r_query(lft,rght,0,0,size-1));
					break;
			}
		}
		printf("\n");
	}
	return(0);
}

