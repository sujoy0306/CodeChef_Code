#include<bits/stdc++.h>
using namespace std;
inline void read(int &n) {
	n = 0;
	int c = getchar();
	while (!isdigit(c))
		c = getchar();
	do {
		n = (n << 3) + (n << 1) + c - '0';
	} while (isdigit(c = getchar()));
}
int main(){
	int n,q,val;
	read(n);read(q);
	vector<int> arr;
	for(int i=0;i<n;i++){
		read(val);
		arr.push_back(val);
	}
	for(int i=0;i<q;i++){
		int t;
		read(t);
		if(t==1){
			int st,j;
			read(st);read(j);
			int i=st,k=0,cur=st-1;
			while(i<n && k<j){
				if(arr[i]>arr[cur] && abs(cur-(i))<=100){
					cur=i;
					k++;
				}
				i++;
			}
			printf("%d\n",cur+1);
		}
		else{
			int l,r,x;
			read(l);read(r);
			scanf("%d",&x);
			for(int i=l-1;i<=r-1;i++){
					arr[i]+=x;
			}
		}
	}
	return(0);
}
