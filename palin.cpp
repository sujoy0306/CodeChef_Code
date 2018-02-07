#include<bits/stdc++.h>
using namespace std;
unordered_map<char,int> fir,sec;
bool check(bool flag){
	if(flag){
		for(auto it:sec){
			if(fir[it.first]==0)
				return false;
		}
		return true;
	}
	else return false;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		string a,b;
		cin>>a>>b;
		sort(a.begin(),a.end());
		sort(b.begin(),b.end());
		if(a.compare(b)==0){
			cout<<"B"<<endl;
			//cout<<"K";
		}
		else{
			
			for(unsigned int i=0;i<a.length();i++)
				fir[a[i]]++;
				
			for(unsigned int i=0;i<b.length();i++)
				sec[b[i]]++;
				
			bool fl=false,flag=false;
			for(auto it: fir){
				if(it.second>1 && sec[it.first]==0){
					fl=true;
					//break;
				}
				if(it.second==1 && sec[it.first]==0)
					flag=true;
			}
			bool fl1=true;
			for(auto it: sec){
				if( fir[it.first]==0){
					fl1=false;
					break;
				}
			}
			
				
			
		   //cout<<fl<<" "<<fl1<<endl;
			if(fl || fl1)
				cout<<"A"<<endl;
			else if(check(flag))
				cout<<"A"<<endl;
			else
				cout<<"B"<<endl;
			fir.clear();
			sec.clear();
		}
		
	}
	return(0);
}
