#include<iostream>
using namespace std;
int main(){
	//std::ios::sync_with_stdio(false);
	int t_c;
	cin>>t_c;
	while(t_c--){
		long long int prob,b_t,t_p,time,tot=0,p;
		cin>>prob>>b_t>>t_p;
		while(prob>0){
			if(prob%2==0){
				p=(prob/2);
			}
			else{
				p=(prob+1)/2;
			}
			time=p*t_p;
		//	cout<<prob<<"	 "<<time<<endl;
			tot+=time;
			t_p*=2;
			prob-=p;
			if(prob>0)
				tot+=b_t;
		}
		cout<<tot<<endl;
	}
	return(0);
}
