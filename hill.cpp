#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int> > vv;
#define pb push_back
#define lb lower_bound
#define ub upper_bound
vv input,sort_input;
int t;
inline void read(int &n) {
	n = 0;
	int c = getchar();
	while (!isdigit(c))
		c = getchar();
	do {
		n = (n << 3) + (n << 1) + c - '0';
	} while (isdigit(c = getchar()));
}
 
inline void get_char() {
	while (!isalpha(s = getchar()));
}

int main(){
	int n,q;
	read(n);read(q);
	int a,sq,sz=0;
	sq=(int) sqrt(n);
	for(int i=0;i<n;i++){
		read(a);
		if(i/sq>=sz){
			sz++;
			input.pb(vi ());
		}
		input[i/sq].pb(a);
	}
	sort_input=input;
	for(int i=0;i<sz;i++){
		sort(sort_input[i].begin(),sort_input[i].end());
	}
	for(int i=0;i<q;i++){
		read(t);
		if(t==1){
			int st,en,count=0,start,end,x;
			read(st);read(x);
			en=st+x;
			st--;en--;
			start=st/sq;
			end=en/sq;
			st-=start*sq;
			en-=end*sq;
			int cur=st,jump=0;
			if(start==end){
				for(int j=st;j<=en && jump<x;j++){
					if(input[start][cur]<input[start][j] && abs(cur-j)<=100){
						cur=j;
						jump++;
					}
						
				}
				printf("%d\n",cur+1);
			}
			else{
				for(unsigned int j=st;j<input[start].size() && jump<x;j++){
					if(input[start][cur]<input[start][j] && abs(cur-j)<=100){
						cur=j;
						jump++;
					}
				}
				for( int j=0;j<=en;j++){
					if(input[end][j]<=x)
						count++;
				}
				for(int j=start+1;j<end;j++){
					count+=(ub(sort_input[j].begin(),sort_input[j].end(),x)-sort_input[j].begin());
				}
				printf("%d\n",count);
			}
		}
		else{
			int x,pos;
			read(pos);read(x);
			pos--;
			int pos_b=pos/sq;
			pos-=pos_b*sq;
			input[pos_b][pos]=x;
			sort_input[pos_b]=input[pos_b];
			sort(sort_input[pos_b].begin(),sort_input[pos_b].end());
		}
	}
			
	return(0);
}
