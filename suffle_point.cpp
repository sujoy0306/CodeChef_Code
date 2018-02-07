#include<iostream>
using namespace std;
struct crdnt{
	long long x,y;
};
int main(){
	std::ios::sync_with_stdio(false);
	long long N,i,j;
	cin>>N;
	crdnt list[N];
	long long dist,m_dist=0;
	for(i=0;i<N;i++){
		cin>>list[i].x>>list[i].y;
		for(j=0;j<i;j++){
				dist=((list[i].x-list[j].x)*(list[i].x-list[j].x)+(list[i].y-list[j].y)*(list[i].y-list[j].y));
				if(dist>m_dist)
					m_dist=dist;
		}
		cout<<m_dist<<endl;
	}
	return(0);
}
