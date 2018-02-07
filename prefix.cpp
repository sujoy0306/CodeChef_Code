#include<bits/stdc++.h>
using namespace std;


int main(){
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	cin>>s;
	int count=0;
	for(unsigned int i=1;i<s.length();i++){
		if(s[i]!=s[i-1])
			count++;
	}		
	cout<<count+1<<endl;		
	return(0);
}
	



