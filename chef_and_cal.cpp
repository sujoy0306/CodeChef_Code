#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<cstdio>
#include<cstring>
using namespace std;
struct storage{
	int type[110],cookies,pnts;
};
int box(int a[]){
	int i,min=100000;
	int zero=0;
	for(i=0;i<6;i++){
		if(a[i]==0)
			zero++;
		if(min>a[i] && a[i]>0)
			min=a[i];
	}
	if(zero>=3)
		return 0;
	for(i=0;i<6;i++){
		if(a[i]!=0)
			a[i]-=min;
	}
	
	if(zero==2)
		return min+box(a);
	if(zero==1)
		return 2*min+box(a);
	if(zero==0)
		return 4*min+box(a);
}
int main(){
	int test_case;
	scanf("%d",&test_case);
	while(test_case--){
		int no_player,i;
		scanf("%d",&no_player);
		storage strg[102];
		for(i=0;i<no_player;i++){
			scanf("%d",&strg[i].cookies);
			int n=strg[i].cookies;
			int data,j;
			int a[6];
			memset(a,0,sizeof(a));
			for(j=0;j<n;j++){
				scanf("%d",&data);
				a[data-1]++;
				strg[i].type[j]=data;
			}
			strg[i].pnts=n+box(a);
		}
		int max=0,pos,tie=0;
		for(i=0;i<no_player;i++){
			//cout<<strg[i].pnts<<endl;
			if(max<strg[i].pnts){
				max=strg[i].pnts;
				pos=i;
			}
		}	
		for(i=0;i<no_player;i++){
			if(pos==i)
				continue;
			else if(max==strg[i].pnts){
				tie=1;
			}
		}
		if(tie==1)
			printf("tie\n");
		else{
			if(pos==0)
				printf("chef\n");
			else
				printf("%d\n",pos+1);
		}
	}
	return(0);
}
