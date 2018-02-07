#inlude<iostream>
#include<algorithm>
#include<vector>
#include<cstdlib>
using namespace std;
struct road{
	long int src,dst;
};
struct ticket{
	long int cty,n_rd,cost;
};
int main(){
	std::ios::sync_with_stdio(false);
	long int city,tckt,i,frnd;
	cin>>city>>tckt;
	road *r;
	r=(road*)malloc((city-1)*sizeof(road));
	for(i=0;i<city-1;i++){
		cin>>r[i].src>>r[i].dst;
	}
	ticket *t;
	t=(ticket*)malloc(tckt*sizeof(ticket));
	for(i=0;i<tckt;i++){
		cin>>t[i].cty>>t[i].n_rd>>t[i].cost;
	}
	vector<long int>fr_cty;
	cin>>frnd;
	for(i=0;i<frnd;i++){
		long int f;
		cin>>f;
		fr_cty.push_back(f);
	}
	
