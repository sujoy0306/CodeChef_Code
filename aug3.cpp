#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#define newnode (node*)malloc(sizeof(node));
using namespace std;
struct node{
	long int cost,indx;
	node *prev;
	node *nxt;
};
int main(){
	int t;
	cin>>t;
	while(t--){
		long int n,i,strt,end,s1=0,s2=0;
		cin>>n;
		node *h,*p,*tmp;
		tmp=h=p=newnode;
		h->prev=h->nxt=NULL;
		scanf("%ld %ld",&strt,&end);
		scanf("%ld",&p->cost);
		p->indx=1;
		for(i=1;i<n;i++){
			p->nxt=newnode;
			p=p->nxt;
			p->prev=tmp;
			p->nxt=NULL;
			tmp=p;
			scanf("%ld",&p->cost);
			p->indx=i+1;
		}
		p->nxt=h;
		h->prev=p;
		p=tmp=h;
		long int s_d=0,s_rd=0,s=0;
		for(i=0;i<n;i++){
			if(p->indx==i+1)
				break;
			p=p->nxt;
		}
		tmp=p;
		while(p->indx!=end){
			s_d+=p->cost;
			p=p->nxt;
		}
		p=tmp;
		while(p->indx!=end){
			s_rd+=p->cost;
			p=p->prev;
		}
		p=tmp;
		while(p->indx!=end){
			s+=p->cost;
			if(p->cost<0){
				if(s<0){
					s_rd+=(2*s);
					s=0;
				}
			}
			p=p->nxt;
		}
		p=tmp;
		while(p->indx!=end){
			s+=p->cost;
			if(p->cost<0){
				if(s<0){
					s_d+=(2*s);
					s=0;
				}
			}
			p=p->prev;
		}
		printf("%ld\n",min(s_d,s_rd));
		tmp=p=h;
		for(i=0;i<n;i++){
			tmp=p->nxt;
			free(p);
			p=tmp;
		}
	}
	return(0);
}
				
					
					
					
			
