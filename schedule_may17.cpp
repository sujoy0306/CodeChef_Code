#include<bits/stdc++.h>
using namespace std;
int main(){
	int tc;
	cin>>tc;
	string s,s1;
	while(tc--){
		cin>>s;
		s1=s;
		sort(s1.begin(),s1.end());
	//	int fl1=0,fl2=0,fl3=0,fl=0,l=s.length();
		/*for(int i=0;i<l;i++){
			if(s[i]=='C')
				fl1=1;
			if(s[i]=='E')
				fl2=1;
			if(s[i]=='S')
				fl3=1;
			if(fl1 && fl2 && fl3){
				fl=1;
				break;
			}
		//	cout<<s[i]<<endl;
		}*/
	//	cout<<s1<<endl;
	//	cout<<(s==s1)<<endl;
		if(s1==s)
			cout<<"yes"<<endl;
		else
			cout<<"no"<<endl;
	}
	return(0);
}
