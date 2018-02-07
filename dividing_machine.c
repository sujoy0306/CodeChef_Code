#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
long int pr[100005],arr[100005],size,tree[100005];

void prime_div(){
	memset(pr,0,sizeof(pr));
 	long int p,i;
	pr[1]=1;
    for (p=2; p<=100005; p++) {
        if (pr[p] ==0){
            // Update all multiples of p
            for (i=p;i<=100005;i+=p){
		if(pr[i]==0)
                	pr[i]=p;
	    }
        }
    }
}

void build(int node, int start, int end)
{
    if(start == end)
    {
        // Leaf node will have a single element
        tree[node] = A[start];
    }
    else
    {
        int mid = (start + end) / 2;
        // Recurse on the left child
        build(2*node, start, mid);
        // Recurse on the right child
        build(2*node+1, mid+1, end);
        // Internal node will have the sum of both of its children
        tree[node] = tree[2*node] + tree[2*node+1];
    }
}
void update(int node, int start, int end, int idx, int val)
{
    if(start == end)
    {
        // Leaf node
        A[idx] += val;
        tree[node] += val;
    }
    else
    {
        int mid = (start + end) / 2;
        if(start <= idx and idx <= mid)
        {
            // If idx is in the left child, recurse on the left child
            update(2*node, start, mid, idx, val);
        }
        else
        {
            // if idx is in the right child, recurse on the right child
            update(2*node+1, mid+1, end, idx, val);
        }
        // Internal node will have the sum of both of its children
        tree[node] = tree[2*node] + tree[2*node+1];
    }
}
int query(int node, int start, int end, int l, int r)
{
    if(r < start or end < l)
    {
        // range represented by a node is completely outside the given range
        return 0;
    }
    if(l <= start and end <= r)
    {
        // range represented by a node is completely inside the given range
        return tree[node];
    }
    // range represented by a node is partially inside and partially outside the given range
    int mid = (start + end) / 2;
    int p1 = query(2*node, start, mid, l, r);
    int p2 = query(2*node+1, mid+1, end, l, r);
    return (p1 + p2);
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
		int type;
		while(query--){
			scanf("%d %ld %ld",&type,&lft,&rght);
			long int res=1;
			switch(type){
				case 0:update(lft,rght);
					break;
				case 1:for(i=lft-1;i<rght;i++)
						if(arr[i]!=i)res=max(res,pr[arr[i]]);
					printf("%ld ",res);
					break;
			}
		}
		//printf("\n");
	}
	return(0);
}
		
