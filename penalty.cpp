#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	while(cin>>s){
		bool fl=1;
		int c1=0,c2=0,i;
		for(i=0;i<10;i++){
			if(i%2){
				if(s[i]=='1')
					c1++;
			}
			else{
				if(s[i]=='1')
					c2++;
			}
		}
		if(c1>c2)
			cout<<"TEAM-A"<<endl;
		else if(c2>c1)
			cout<<"TEAM-B"<<endl;
		else{
			for(;i<20;i+=2){
				if(s[i]!=s[i+1]){
					if(s[i]=='1')
						cout<<"TEAM-A"<<endl;
					else
						cout<<"TEAM-B"<<endl;
					
					fl=0;
				}
				
			}
			if(fl)
				cout<<"TIE"<<endl;
		}
	}
	return(0);
}
		
